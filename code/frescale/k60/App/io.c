#include "init.h"
#include "common.h"
#include "port_cfg.h"
#include "include.h"
//���ٶȼ�
extern long long accelerometer1_X;
extern long long accelerometer1_Y;
extern long long accelerometer1_Z;
extern long long accelerometer1_zero;

//������
extern long long gyroscope1_AR1;
extern long long gyroscope1_AR2;
extern long long gyroscope1_AR3;

//����˫·PWM
extern long long motor_left_pwm1;
extern long long motor_left_pwm2;
extern long long motor_right_pwm1;
extern long long motor_right_pwm2;

//��Ŵ�����
extern long long electromagnet_L1;
extern long long electromagnet_L2;
extern long long electromagnet_L3;
extern long long electromagnet_L4;
extern long long electromagnet_L5;
extern long long electromagnet_L6;


void sensor_accelerator_read(){
  accelerometer1_X=adc_once(pin_accelerometer1_X,ADC_16bit);
  accelerometer1_Y=adc_once(pin_accelerometer1_Y,ADC_16bit);
  accelerometer1_Z=adc_once(pin_accelerometer1_Z,ADC_16bit);
  gyroscope1_AR2=adc_once(pin_gyroscope1_AR2,ADC_16bit);
}
void sensor_electromagnet_read(){
  electromagnet_L1=adc_once(pin_electromagnet_L1,ADC_16bit);
  electromagnet_L2=adc_once(pin_electromagnet_L2,ADC_16bit);
  electromagnet_L3=adc_once(pin_electromagnet_L3,ADC_16bit);
  electromagnet_L4=adc_once(pin_electromagnet_L4,ADC_16bit);
  electromagnet_L5=adc_once(pin_electromagnet_L5,ADC_16bit);
  electromagnet_L6=adc_once(pin_electromagnet_L6,ADC_16bit);

}
void pwm_right_write(int pwm){
  pwm=-pwm;
  if(pwm>=1000){ 
    motor_right_pwm1=0;motor_right_pwm2=1000;
  }
  if(pwm<=-1000){ 
    motor_right_pwm1=1000;motor_right_pwm2=0;
  }
  if(pwm<1000&&pwm>0){
    motor_right_pwm1=0;motor_right_pwm2=pwm;
  }
  if(pwm>-1000&&pwm<=0){
    motor_right_pwm1=-pwm;motor_right_pwm2=0;
  }
  FTM_PWM_Duty(FTM0,pin_PWM_right1,motor_right_pwm1);
  FTM_PWM_Duty(FTM0,pin_PWM_right2,motor_right_pwm2);
  
}
void vcan_sendware(uint8 *wareaddr, uint32 waresize)
{
#define CMD_WARE     3
    uint8 cmdf[2] = {CMD_WARE, ~CMD_WARE};    //���ڵ��� ʹ�õ�ǰ����
    uint8 cmdr[2] = {~CMD_WARE, CMD_WARE};    //���ڵ��� ʹ�õĺ�����

    uart_putbuff(UART0, cmdf, sizeof(cmdf));    //�ȷ���ǰ����
    uart_putbuff(UART0, wareaddr, waresize);    //��������
    uart_putbuff(UART0, cmdr, sizeof(cmdr));    //���ͺ�����

}
void pwm_left_write(int pwm){
  pwm=-pwm;
  if(pwm>=1000){ 
    motor_left_pwm1=0;motor_left_pwm2=1000;
  }
  if(pwm<=-1000){ 
    motor_left_pwm1=1000;motor_left_pwm2=0;
  }
  if(pwm<1000&&pwm>0){
    motor_left_pwm1=0;motor_left_pwm2=pwm;
  }
  if(pwm>-1000&&pwm<=0){
    motor_left_pwm1=-pwm;motor_left_pwm2=0;
  }
  FTM_PWM_Duty(FTM0,pin_PWM_left1,motor_left_pwm1);
  FTM_PWM_Duty(FTM0,pin_PWM_left2,motor_left_pwm2);
  
}
void print_fraction(float aaaa){
   //char buffer [100] ;
  int temp=(int)aaaa;
  printf("%d.",(int)temp);
  aaaa-=temp;
  aaaa=fabs(aaaa);
  temp=aaaa*10;
  printf("%d\n",(int)temp);
  
  //sprintf(buffer,"%d\n",(int)angle);
  

}

float SDS_OutData[4] = { 0 };//��Ӧͨ�� ��Ҫ���͵ĸ�ֵ���� �ٵ���SDS_OutPut_Data���� �ȴ�����ʾ���� ���������

unsigned short CRC_CHECK(unsigned char *Buf, unsigned char CRC_CNT)
{
    unsigned short CRC_Temp;
    unsigned char i,j;
    CRC_Temp = 0xffff;

    for (i=0;i<CRC_CNT; i++){      
        CRC_Temp ^= Buf[i];
        for (j=0;j<8;j++) {
            if (CRC_Temp & 0x01)
                CRC_Temp = (CRC_Temp >>1 ) ^ 0xa001;
            else
                CRC_Temp = CRC_Temp >> 1;
        }
    }
    return(CRC_Temp);
}

void SDS_OutPut_Data(float S_Out[])
{
  int temp[4] = {0};
  unsigned int temp1[4] = {0};
  unsigned char databuf[10] = {0};
  unsigned char i;
  unsigned short CRC16 = 0; 
  float SDS_OutData[4];
  for(i=0;i<4;i++) {
  SDS_OutData[i]=S_Out[i];
  }
  for(i=0;i<4;i++)
   {
    
    temp[i]  = (int)SDS_OutData[i];
    temp1[i] = (unsigned int)temp[i];
    
   }
   
  for(i=0;i<4;i++) 
  {
    databuf[i*2]   = (unsigned char)(temp1[i]%256);
    databuf[i*2+1] = (unsigned char)(temp1[i]/256);
  }
  
  CRC16 = CRC_CHECK(databuf,8);
  databuf[8] = CRC16%256;
  databuf[9] = CRC16/256;
  
  for(i=0;i<10;i++)
    uart_putchar(UART0, databuf[i]);  //��Ӧ����K60�ײ��ķ����ַ������� 
}