#include<MsTimer2.h>
#define pin_bianmaA_intA 0//马达B的编码器A相(中断)
#define pin_bianmaA_intB 12//马达B的编码器B相
#define pin_bianmaB_intA 1//马达B的编码器A相(中断)
#define pin_bianmaB_intB 12//马达B的编码器B相
#define pin_motorA_1 9//马达A的PWM1
#define pin_motorA_2 6//马达A的PWM2
#define pin_motorB_1 10//马达B的PWM1
#define pin_motorB_2 11//马达B的PWM2
#define time_interval 100//计算速度间隔，单位为毫秒
/*working variables*/
unsigned long lastTime;
double Input, Output, Setpoint;
double errSum, lastErr;
double kp, ki, kd;
void Compute()
{
   /*How long since we last calculated*/
   unsigned long now = millis();
   double timeChange = (double)(now - lastTime);

   /*Compute all the working error variables*/
   double error = Setpoint - Input;
   errSum += (error * timeChange);
   double dErr = (error - lastErr) / timeChange;
    
   /*Compute PID Output*/
//   Output = kp * error + ki * errSum + kd * dErr;
   Output = kp * error;
Serial.print("Output");Serial.print(Output);
   /*Remember some variables for next time*/
   lastErr = error;
   lastTime = now;
}

void SetTunings(double Kp, double Ki, double Kd)
{
   kp = Kp;
   ki = Ki;
   kd = Kd;
}
long bianmaB_record1=0;//用于测速
long bianmaB_record2=0;//用于锁定位置
double motorB_speed=0;
int motorB_PWM1=0;
int motorB_PWM2=0;
int time_now;
int time_last;
double pwm_temp;
void motorB_PWM_zhuanhuan(int value) {//将正负PWM转换到具体PWM
  if (value > 0) {
    if (value > 255) {
      motorB_PWM1 = 255;
      motorB_PWM2 = 0;
    } else {
      motorB_PWM1 = value; motorB_PWM2 = 0;
    }
  } else {
    if (abs(value) > 255) {
      motorB_PWM1 = 0;
      motorB_PWM2 = 255;
    } else {
      motorB_PWM1 = 0; motorB_PWM2 = abs(value);
    }

  }
    analogWrite(pin_motorB_1, motorB_PWM1);
    analogWrite(pin_motorB_2, motorB_PWM2);
}
void motor_speed_calculate() {//马达B测速
  motorB_speed =( (double)bianmaB_record1 / 500)/((double)time_interval/1000);
  Serial.print("maichong:");Serial.print(bianmaB_record1);
  Serial.print("speed:");Serial.println(motorB_speed);
  bianmaB_record1 = 0;
//
//  Serial.print("carspeed="); Serial.print(carspeed);
//  Serial.print("angle="); Serial.print(angle);
//  Serial.print("angle_speed="); Serial.println(angle_speed);
//  Serial.println(PWM_IN1);
//  Serial.println(PWM_IN2);
}
void interrupt_bianmaB() {//编码器B的中断
  if (digitalRead(pin_bianmaB_intB) == HIGH) { //此处用A相正转为正
//    Serial.print("interrupt");
    bianmaB_record1++;
    bianmaB_record2++;
  } else {
    bianmaB_record1--;
    bianmaB_record2--;
  }
}
void setup() {
  Serial.begin(9600);
  pinMode(pin_bianmaB_intA, INPUT);
  pinMode(pin_bianmaB_intB, INPUT);
  pinMode(pin_motorA_1, OUTPUT);
  pinMode(pin_motorA_2, OUTPUT);
  pinMode(pin_motorB_1, OUTPUT);
  pinMode(pin_motorB_2, OUTPUT);
  analogWrite(pin_motorA_1, 0);
  analogWrite(pin_motorA_2, 0);
  analogWrite(pin_motorB_1, 0);
  analogWrite(pin_motorB_2, 0);
  Setpoint=63;
  SetTunings(1.4,0,0);


  attachInterrupt(pin_bianmaB_intA, interrupt_bianmaB, FALLING);
  time_now=millis();
//  MsTimer2::set(time_interval, motor_speed_calculate);
//  MsTimer2::start();
}
void dingsu_motorB(double purpose){
  pwm_temp=(purpose-motorB_speed);
  Serial.print("pwm_temp1:");Serial.print(pwm_temp);
  pwm_temp=pwm_temp*2.3+30;
  Serial.print("pwm_temp2:");Serial.println(pwm_temp);
  motorB_PWM_zhuanhuan(pwm_temp);
  
  }

void loop() {

  time_last=time_now;
  time_now=millis();
////  delay(time_interval);
  motorB_speed =( (double)bianmaB_record1 / 500)/((double)(time_now-time_last)/1000);
  //bianmaB_record1=0;
  Serial.print("speed:");Serial.print(motorB_speed);
  Serial.print("Output");Serial.println(Output);
 Input=motorB_speed;
 Compute();
 motorB_PWM_zhuanhuan(Output);

}


