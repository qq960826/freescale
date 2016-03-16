/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外初学论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       main.c
 * @brief      山外K60 平台主程序
 * @author     山外科技
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
//开始IO操作变量声明
//两个加速度计
long long accelerometer1_X;
long long accelerometer1_Y;
long long accelerometer1_Z;
long long accelerometer1_zero;

//两个陀螺仪
long long gyroscope1_AR1;
long long gyroscope1_AR2;
long long gyroscope1_AR3;

//两个双路PWM
long long motor_left_pwm1;
long long motor_left_pwm2;
long long motor_right_pwm1;
long long motor_right_pwm2;

//两个欧姆龙编码器
long long omron_encoder_left_now=0;
long long omron_encoder_left_last=0;
long long omron_encoder_right_now=0;
long long omron_encoder_right_last=0;
//结束IO操作变量声明

//电磁传感器

long long electromagnet_L1;
long long electromagnet_L2;
long long electromagnet_L3;
long long electromagnet_L4;
long long electromagnet_L5;
long long electromagnet_L6;



//开始计算变量声明
unsigned long long system_time_ms=0;
float angle;



void  main(void)
{
  
 // OLED_Init();
  //OLED_Fill(0x00);//黑屏
  car_init();
  //OLED_P8x16Str(5,0,"test");
  
  
  
  //setup();
  //sd_read();
  
  while(1){
  sensor_accelerator_read();
  sensor_accelerator_calculate();
  //motor_left_pid(10);
  motor_right_pid(10);
  
  //sensor_electromagnet_read();
  
  printf("%lld\n",electromagnet_L6);
  
  }

 
}