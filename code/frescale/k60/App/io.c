#include "init.h"
#include "common.h"
#include "port_cfg.h"
#include "include.h"
//加速度计
extern long long accelerometer1_X;
extern long long accelerometer1_Y;
extern long long accelerometer1_Z;
extern long long accelerometer1_zero;

//陀螺仪
extern long long gyroscope1_AR1;
extern long long gyroscope1_AR2;
extern long long gyroscope1_AR3;

//两个双路PWM
extern long long motor_left_pwm1;
extern long long motor_left_pwm2;
extern long long motor_right_pwm1;
extern long long motor_right_pwm2;

//电磁传感器
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

void pwm_left_write(int pwm){
  
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