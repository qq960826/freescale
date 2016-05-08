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
#include "port_cfg.h"
#include "include.h"
#include "init.h"
#include "calculate.h"
#include "io.h"
#include "sdcard.h"
#include "stdio.h"
#define BUFF_SIZE   100


   
unsigned long long time_last,time_now;
int flag_accelerometer=0;
//��ʼIO������������
//�������ٶȼ�
long long accelerometer1_X;
long long accelerometer1_Y;
long long accelerometer1_Z;
long long accelerometer1_zero;

//����������
long long gyroscope1_AR1;
long long gyroscope1_AR2;
long long gyroscope1_AR3;

//����˫·PWM
long long motor_left_pwm1;
long long motor_left_pwm2;
long long motor_right_pwm1;
long long motor_right_pwm2;

//����ŷķ��������
long long omron_encoder_left_now=0;
long long omron_encoder_left_last=0;
long long omron_encoder_right_now=0;
long long omron_encoder_right_last=0;
//����IO������������

//��Ŵ�����

long long electromagnet_L1;
long long electromagnet_L2;
long long electromagnet_L3;
long long electromagnet_L4;
long long electromagnet_L5;
long long electromagnet_L6;



//��ʼ�����������

float angle_offset=62.0;

unsigned long long system_time_ms=0;
float angle;
void print_fraction( float aaaa);

void main(){
car_init();
while(1){
    sensor_accelerator_read();
  sensor_accelerator_calculate();
  angle_control(0);
  
  float ang=angle_offset+angle;
  //char buffer [100] ;
  //sprintf(buffer,"%d\n",(int)omron_encoder_right_now);
  //angle_control(0);
 //motor_right_pid(1 );
  //pwm_left_write(100);
 //motor_left_pid(10);
  //printf(buffer);
  print_fraction(angle);
  //FTM_PWM_Duty(FTM0,pin_PWM_left1,1000);
  //FTM_PWM_Duty(FTM0,pin_PWM_left2,1000);
 ///pwm_right_write(300);
  //sensor_electromagnet_read();
 // printf("%lld\n",motor_right_pwm1);


}


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
void  main1(void)
{
  
 OLED_Init();
  OLED_Fill(0x00);//����
  car_init();
  
  OLED_P8x16Str(5,0,"test");
  
  
  
  //setup();
  //sd_read();
  
  while(1){
  sensor_accelerator_read();
  sensor_accelerator_calculate();
  char buffer [100] ;

  sprintf(buffer,"%d",(int)angle);
  //OLED_P8x16Str(5,0,"    ");

  //OLED_P8x16Str(6,0,buffer);
 //motor_left_pid(1);
 //motor_right_pid(0);
  angle_control(20);
  //sensor_electromagnet_read();
  
  //printf("%lld\n",electromagnet_L6);
  
  }

 
}
#define main test