#include "math.h"
#include "io.h"
#include "common.h"
#define kp_motor_left 4
#define ki_motor_left 5
//#define kd_motor_left 2
#define kd_motor_left 0

#define kp_motor_right 4
#define ki_motor_right 5
#define kd_motor_right 0


#define kp_angle 4.7
#define ki_angle 0.2
#define kd_angle 0



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

extern long long time_now_speed;
extern long long time_last_speed;

extern int Speed_R;
extern int Speed_L;
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
  angle= (angle +vol_gyro * (delta/1000))*0.75155-0.24845*angle_accZ;
  //float  OutData[4];

  //OutData[0] = angle;
    //OutData[1] = -angle_accZ;
    //OutData[2] = 3 ;
    //OutData[3] = 4;
    //vcan_sendware((uint8_t *)OutData,sizeof(OutData));


}
void motor_right_pid(int motor_right_ideal_speed){
  long error,d_error,dd_error;
  error = motor_right_ideal_speed - (omron_encoder_right_now-omron_encoder_right_last);
  d_error = error - motor_right_pre_error;
  dd_error = d_error - motor_right_pre_d_error;
  motor_right_pre_error = error;
  motor_right_pre_d_error = d_error;
  motor_right_pk +=kp_motor_right * d_error + ki_motor_right * error + kd_motor_right * dd_error;
  pwm_right_write(motor_right_pk);
}
void motor_left_pid(int motor_left_ideal_speed){
  long error,d_error,dd_error;
  error = motor_left_ideal_speed - (omron_encoder_left_now-omron_encoder_left_last);
  d_error = error - motor_left_pre_error;
  dd_error = d_error - motor_left_pre_d_error;
  motor_left_pre_error = error;
  motor_left_pre_d_error = d_error;
  motor_left_pk +=kp_motor_left * d_error + ki_motor_left * error + kd_motor_left * dd_error;
  pwm_left_write(motor_left_pk);
}
void angle_control(float angle_ideal){
  float vol_gyro;
  vol_gyro=((float)gyroscope1_AR1/65535)*3.3-1.35;
  vol_gyro=vol_gyro*0.67;
  float ang=angle_offset+angle;
  ang=-ang;
  
  
  Speed_L = (0-ang)*kp_angle-vol_gyro*ki_angle;//直立PID
  Speed_R = (0-ang)*kp_angle-vol_gyro*ki_angle;
  
      
    
  


}