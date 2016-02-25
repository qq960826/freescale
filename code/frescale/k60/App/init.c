//引脚定义
#define pin_accelerometer1_X ADC1_SE4a//E0
#define pin_accelerometer1_Y ADC1_SE5a//E1
#define pin_accelerometer1_Z ADC1_SE6a//E2
#define pin_gyroscope1_AR2 ADC1_SE7a//E3


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
extern long long motor1_pwm1;
extern long long motor1_pwm2;
extern long long motor2_pwm1;
extern long long motor2_pwm2;

//两个欧姆龙编码器
extern long long omron_encoder1;
extern long long omron_encoder2;

//结束变量声明