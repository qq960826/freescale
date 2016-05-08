#include "math.h"
#include "io.h"
#define kp_motor_left 15
#define ki_motor_left 4
#define kd_motor_left 8


#define kp_motor_right 30
#define ki_motor_right 4
#define kd_motor_right 8


#define kp_angle 0.5
#define ki_angle 0.1
#define kd_angle 0.25
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


float motor_right_speed_error; //理想与实际速度偏差值
float motor_right_pre_error; //速度PID 前一次的速度误差值ideal_speed- pulse_count
float motor_right_pre_d_error; //速度PID 前一次的速度误差之差d_error-pre_d_error?
//long motor_right_ideal_speed=-20;
float motor_right_pk=0;


long motor_left_speed_error; //理想与实际速度偏差值
long motor_left_pre_error; //速度PID 前一次的速度误差值ideal_speed- pulse_count
long motor_left_pre_d_error; //速度PID 前一次的速度误差之差d_error-pre_d_error?
//long motor_left_ideal_speed=-20;
long motor_left_pk=0;

float angle_error=0;
float angle_pre_error=0;
float angle_pre_d_error=0;
float angle_pk=0;
extern float angle_offset;
//float angle_offset=61.6;

extern unsigned long long system_time_ms;
extern float angle;

void sensor_accelerator_calculate(){
  
  float vol_x,vol_y,vol_z,angle_accZ,vol_gyro;
  float delta;
  time_last=time_now;
  time_now=mills();
  delta=time_now-time_last;
  vol_gyro=((float)gyroscope1_AR1/65535)*3.3-1.35;
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
void motor_right_pid(int motor_right_ideal_speed){
  long error,d_error,dd_error;
  error = motor_right_ideal_speed - (omron_encoder_right_now-omron_encoder_right_last);
  d_error = error - motor_right_pre_error;
  dd_error = d_error - motor_right_pre_d_error;
  motor_right_pre_error = error;
  motor_right_pre_d_error = d_error;
  motor_right_pk +=kp_motor_right * d_error + ki_motor_right * error + kd_motor_right * dd_error;

  //motor_right_pk = kp_motor * d_error + ki_motor * error ;
  pwm_right_write(motor_right_pk);
    char buffer [100] ;

  sprintf(buffer,"%d",omron_encoder_right_now-omron_encoder_right_last);
  //OLED_P8x16Str(5,0,"    ");

  OLED_P8x16Str(6,0,buffer);
}
void motor_left_pid(int motor_left_ideal_speed){
  long error,d_error,dd_error;
  error = motor_left_ideal_speed - (omron_encoder_left_now-omron_encoder_left_last);
  d_error = error - motor_left_pre_error;
  dd_error = d_error - motor_left_pre_d_error;
  motor_left_pre_error = error;
  motor_left_pre_d_error = d_error;
  motor_left_pk +=kp_motor_left * d_error + ki_motor_left * error + kd_motor_left * dd_error;

  //motor_right_pk = kp_motor * d_error + ki_motor * error ;
  pwm_left_write(motor_left_pk);
  //char buffer [100] ;

  //sprintf(buffer,"%d",omron_encoder_left_now-omron_encoder_left_last);
  //OLED_P8x16Str(5,0,"    ");

 // OLED_P8x16Str(5,0,buffer);
}
void angle_control(float angle_ideal){
  float vol_gyro;
  vol_gyro=((float)gyroscope1_AR1/65535)*3.3-1.35;
  vol_gyro=vol_gyro*0.67;
  float ang=angle_offset+angle;
  ang=-ang;
  
  
  //float Speed_L = (0-ang)*15 - vol_gyro*0.27;//直立PID
  //motor_left_pid(Speed_L);
  //pwm_right_write((int)Speed_L);
  //pwm_left_write((int)Speed_L);
  //print_fraction(Speed_L);
  float error=0,d_error=0,dd_error=0;
  error=angle_ideal-ang;//角度
  int a=error;
  d_error=error-angle_pre_error;//角速度
  dd_error=d_error-angle_pre_d_error;
  angle_pre_error=error;
  angle_pre_d_error=d_error;
  ////angle_pk+=kp_angle*error+kd_motor_left*d_error;
  angle_pk=-kp_angle*error+kd_angle*vol_gyro;
  motor_left_pid((int)angle_pk);
  motor_right_pid((int)angle_pk);
  
      
    
  


}