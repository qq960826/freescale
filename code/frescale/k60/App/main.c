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
#include "math.h"
#include "port_cfg.h"
#include "include.h"
#include "MK60_ftm.h"
#include "init.h"
#define BUFF_SIZE   100


   
unsigned long long time_last,time_now;
int flag_accelerometer=0;
//开始变量声明
//两个加速度计
long long accelerometer1_X;
long long accelerometer1_Y;
long long accelerometer1_Z;
long long accelerometer1_zero;
long long accelerometer2_X;
long long accelerometer2_Y;
long long accelerometer2_Z;
long long accelerometer2_zero;

//两个陀螺仪
long long gyroscope1_AR1;
long long gyroscope1_AR2;
long long gyroscope1_AR3;
long long gyroscope2_AR1;
long long gyroscope2_AR2;
long long gyroscope2_AR3;

//两个双路PWM
long long motor1_pwm1;
long long motor1_pwm2;
long long motor2_pwm1;
long long motor2_pwm2;

//两个欧姆龙编码器
long long omron_encoder1;
long long omron_encoder2;

//结束变量声明

extern unsigned long long system_time_ms;
float angle;

/*!
 *  @brief      main函数
 *  @since      v5.0
 *  @note       山外SD卡 FatFS实验
 */
unsigned long long iii=0;
void FTM1_Input_test(void){
  
  //FTM1_STATUS=0;
      int8 s = FTM0_STATUS;             //读取捕捉和比较状态  All CHnF bits can be checked using only one read of STATUS.
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
      //FTM_QUAD_Init(FTM1);                                    //FTM1 正交解码初始化（所用的管脚可查 vcan_port_cfg.h ）
//FTM_Input_init(FTM0, FTM_CH6, FTM_Falling,FTM_PS_1);
//port_init_NoALT(FTM0_CH6 ,PULLUP); //配置端口为上拉(保留原先的复用配置)
//set_vector_handler(FTM0_VECTORn ,FTM1_Input_test);
//enable_irq (FTM0_IRQn);
  while(1){
  sensor_accelerator_read();
  sensor_accelerator_calculate();
  
  //printf("test");
  
  }

 
}