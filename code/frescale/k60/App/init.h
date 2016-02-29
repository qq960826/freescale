#ifndef _APP_INIT
#define _APP_INIT
//引脚定义
//加速度，陀螺仪1
#define pin_accelerometer1_X ADC1_SE4a//E0
#define pin_accelerometer1_Y ADC1_SE5a//E1
#define pin_accelerometer1_Z ADC1_SE6a//E2
#define pin_gyroscope1_AR1 ADC0_SE17//E24
#define pin_gyroscope1_AR2 ADC1_SE7a//E3

//加速度，陀螺仪2
#define pin_accelerometer2_X ADC1_SE9//PTB1
#define pin_accelerometer2_Y ADC1_SE10//PTB4
#define pin_accelerometer2_Z ADC1_SE11//PTB5
#define pin_gyroscope2_AR1 ADC1_SE12//PTB6
#define pin_gyroscope2_AR2 ADC1_SE13//PTB7

//欧姆龙编码器右
#define pin_encoder_right_A FTM1_QDPHA//PTA12
#define pin_encoder_right_B FTM1_QDPHB//PTA13

//欧姆龙编码器左
#define pin_encoder_left_A FTM2_QDPHA//PTA10
#define pin_encoder_left_B FTM2_QDPHB//PTA11

//串口
#define pin_uart UART0 //PTA15=RX,PTA14=TX

//PWM
#define pin_PWM_right1 FTM_CH4//D4，FTM0_CH4
#define pin_PWM_right2 FTM_CH5//D5，FTM0_CH5
#define pin_PWM_left1 FTM_CH1//C2，FTM0_CH1
#define pin_PWM_left2 FTM_CH2//C3，FTM0_CH2

//
#endif
void car_init();
void pit_hander_time_recoder();