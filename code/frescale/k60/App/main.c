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
unsigned long long system_time_ms=0;
float angle;


void  main(void)
{
  
 // OLED_Init();
  //OLED_Fill(0x00);//����
  car_init();
  //OLED_P8x16Str(5,0,"test");
  
  
  
  //setup();
  //sd_read();
  
  while(1){
  //sensor_accelerator_read();
  //sensor_accelerator_calculate();
  //motor_left_pid(10);
  //motor_right_pid(10);
  
  sensor_electromagnet_read();
  
  printf("%lld\n",electromagnet_L6);
  
  }

 
}