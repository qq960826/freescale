/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ���ѧ��̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       main.c
 * @brief      ɽ��K60 ƽ̨������
 * @author     ɽ��Ƽ�
 * @version    v5.0
 * @date       2013-08-28
 */

#include "common.h"
#include "math.h"
#include "port_cfg.h"
#include "include.h"
#include "MK60_ftm.h"
#include "init.h"
#define BUFF_SIZE   100


   
unsigned long long time_last,time_now;
int flag_accelerometer=0;
//��ʼ��������
//�������ٶȼ�
long long accelerometer1_X;
long long accelerometer1_Y;
long long accelerometer1_Z;
long long accelerometer1_zero;
long long accelerometer2_X;
long long accelerometer2_Y;
long long accelerometer2_Z;
long long accelerometer2_zero;

//����������
long long gyroscope1_AR1;
long long gyroscope1_AR2;
long long gyroscope1_AR3;
long long gyroscope2_AR1;
long long gyroscope2_AR2;
long long gyroscope2_AR3;

//����˫·PWM
long long motor1_pwm1;
long long motor1_pwm2;
long long motor2_pwm1;
long long motor2_pwm2;

//����ŷķ��������
long long omron_encoder1;
long long omron_encoder2;

//������������

extern unsigned long long system_time_ms;
float angle;

/*!
 *  @brief      main����
 *  @since      v5.0
 *  @note       ɽ��SD�� FatFSʵ��
 */
unsigned long long iii=0;
void FTM1_Input_test(void){
  
  //FTM1_STATUS=0;
      int8 s = FTM0_STATUS;             //��ȡ��׽�ͱȽ�״̬  All CHnF bits can be checked using only one read of STATUS.
   // uint8 CHn;
   // CHn=7;
      
FTM0_STATUS = 0x00;
iii++;

}

void sensor_accelerator_read(){
  accelerometer1_X=adc_once(pin_accelerometer1_X,ADC_16bit);
  accelerometer1_Y=adc_once(pin_accelerometer1_Y,ADC_16bit);
  accelerometer1_Z=adc_once(pin_accelerometer1_Z,ADC_16bit);
   gyroscope1_AR2=adc_once(pin_gyroscope1_AR2,ADC_16bit);

  
}
void sensor_accelerator_calculate(){
  
  float vol_x,vol_y,vol_z,angle_accZ,vol_gyro;
  float delta;
  
  
  time_last=time_now;
  time_now=mills();
  delta=time_now-time_last;
  vol_gyro=((float)gyroscope1_AR2/65535)*3.3-1.35;
  vol_gyro=vol_gyro*0.67;
  vol_x=((float)accelerometer1_X/65535)*3.3-1.65;
  vol_y=((float)accelerometer1_Y/65535)*3.3-1.65;
  vol_z=((float)accelerometer1_Z/65535)*3.3-1.65;
  angle_accZ=(atan(vol_z / sqrt(vol_x * vol_x + vol_y * vol_y)) / 3.1415) * 180;
  
  if(flag_accelerometer==0){
  angle=-angle_accZ;
  flag_accelerometer=1;
  return;
  }
  angle= (angle +vol_gyro * (delta/1000))*0.95-0.05*angle_accZ;
  
  //char *buffer;
  //printf("%d\n",(int)angle);
  //printf("%lld\n",system_time_ms);
  //buffer=sprintf("%d\n",(int)angle);
  //uart_putstr(UART0,buffer);

}

void  main(void)
{
  
  car_init();
  

  
  
  //micros();
      //FTM_QUAD_Init(FTM1);                                    //FTM1 ���������ʼ�������õĹܽſɲ� vcan_port_cfg.h ��
//FTM_Input_init(FTM0, FTM_CH6, FTM_Falling,FTM_PS_1);
//port_init_NoALT(FTM0_CH6 ,PULLUP); //���ö˿�Ϊ����(����ԭ�ȵĸ�������)
//set_vector_handler(FTM0_VECTORn ,FTM1_Input_test);
//enable_irq (FTM0_IRQn);
  while(1){
  sensor_accelerator_read();
  sensor_accelerator_calculate();
  
  //printf("test");
  
  }

 
}