#ifndef _APP_INIT
#define _APP_INIT
#define pin_accelerometer1_X ADC1_SE4a//E0
#define pin_accelerometer1_Y ADC1_SE5a//E1
#define pin_accelerometer1_Z ADC1_SE6a//E2
#define pin_gyroscope1_AR2 ADC1_SE7a//E3
#define pin_PWM_right1 FTM_CH0//A10
#define pin_PWM_right2 FTM_CH1//A11
#endif
void car_init();
void pit_hander_time_recoder();