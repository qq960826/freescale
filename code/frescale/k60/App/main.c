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
#define BUFF_SIZE   100


   
unsigned long long time_last,time_now;
int flag_accelerometer=0;
//��ʼIO������������
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



//��ʼ�����������
unsigned long long system_time_ms=0;
float angle;


void  main(void)
{
  
  car_init();
  

  while(1){
  sensor_accelerator_read();
  sensor_accelerator_calculate();
  motor_right_pid();
  
  printf("%lld\n",omron_encoder_right_now-omron_encoder_right_last);
  
  }

 
}