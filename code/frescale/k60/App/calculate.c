#include "math.h"
#include "io.h"
#define kp_motor 100
#define ki_motor 16//1
#define kd_motor 8//10 
extern unsigned long long time_last,time_now;
extern int flag_accelerometer;
//开始变量声明
//两个加速度计
extern long long accelerometer1_X;
extern long long accelerometer1_Y;
extern long long accelerometer1_Z;
extern long long accelerometer1_zero;
extern long long accelerometer2_X;
extern long long accelerometer2_Y;
extern long long accelerometer2_Z;
extern long long accelerometer2_zero;

//两个陀螺仪
extern long long gyroscope1_AR1;
extern long long gyroscope1_AR2;
extern long long gyroscope1_AR3;
extern long long gyroscope2_AR1;
extern long long gyroscope2_AR2;
extern long long gyroscope2_AR3;

//两个双路PWM
extern long long motor_left_pwm1;
extern long long motor_left_pwm2;
extern long long motor_right_pwm1;
extern long long motor_right_pwm2;

//两个欧姆龙编码器
extern long long omron_encoder_left_now;
extern long long omron_encoder_left_last;
extern long long omron_encoder_right_now;
extern long long omron_encoder_right_last;
//结束变量声明


long motor_right_speed_error; //理想与实际速度偏差值
long motor_right_pre_error; //速度PID 前一次的速度误差值ideal_speed- pulse_count
long motor_right_pre_d_error; //速度PID 前一次的速度误差之差d_error-pre_d_error?
long motor_right_ideal_speed=-20;
long motor_right_pk=0;


long motor_left_speed_error; //理想与实际速度偏差值
long motor_left_pre_error; //速度PID 前一次的速度误差值ideal_speed- pulse_count
long motor_left_pre_d_error; //速度PID 前一次的速度误差之差d_error-pre_d_error?
long motor_left_ideal_speed=-20;
long motor_left_pk=0;


extern unsigned long long system_time_ms;
extern float angle;

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
}
void motor_right_pid(){
  long error,d_error,dd_error;
  error = motor_right_ideal_speed - omron_encoder_left_now;
  d_error = error - motor_right_pre_error;
  dd_error = d_error - motor_right_pre_d_error;
  motor_right_pre_error = error;
  motor_right_pre_d_error = d_error;
  motor_right_pk = kp_motor * d_error + ki_motor * error + kd_motor * dd_error;
  pwm_right_write(motor_right_pk);
}
void motor_left_pid(){
  long error,d_error,dd_error;
  error = motor_right_ideal_speed - omron_encoder_left_now;
  d_error = error - motor_right_pre_error;
  dd_error = d_error - motor_right_pre_d_error;
  motor_right_pre_error = error;
  motor_right_pre_d_error = d_error;
  motor_right_pk = kp_motor * d_error + ki_motor * error + kd_motor * dd_error;
  pwm_left_write(motor_right_pk);
}