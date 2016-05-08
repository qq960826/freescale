#ifndef _APP_INIT
#define _APP_INIT
//Òý½Å¶¨Òå
//¼ÓËÙ¶È£¬ÍÓÂÝÒÇ1
#define pin_accelerometer1_X ADC1_SE4a//E0
#define pin_accelerometer1_Y ADC1_SE5a//E1
#define pin_accelerometer1_Z ADC1_SE6a//E2
#define pin_gyroscope1_AR1 ADC0_SE17//E24
#define pin_gyroscope1_AR2 ADC1_SE7a//E3

//µç´Å´«¸ÐÆ÷
#define pin_electromagnet_L1 ADC1_SE9//PTB1
#define pin_electromagnet_L2 ADC1_SE10//PTB4
#define pin_electromagnet_L3 ADC1_SE11//PTB5
#define pin_electromagnet_L4 ADC1_SE12//PTB6
#define pin_electromagnet_L5 ADC1_SE13//PTB7
#define pin_electromagnet_L6 ADC1_SE14//PTB10



//Å·Ä·Áú±àÂëÆ÷ÓÒ
#define pin_encoder_right_A FTM1_QDPHA//PTA12
#define pin_encoder_right_B FTM1_QDPHB//PTA13

//Å·Ä·Áú±àÂëÆ÷×ó
#define pin_encoder_left_A FTM2_QDPHA//PTA10
#define pin_encoder_left_B FTM2_QDPHB//PTA11

//´®¿Ú
#define pin_uart UART0 //PTA15=RX,PTA14=TX

//PWM
#define pin_PWM_right1 FTM_CH4//D4£¬FTM0_CH4
#define pin_PWM_right2 FTM_CH5//D5£¬FTM0_CH5
#define pin_PWM_left1 FTM_CH1//C2£¬FTM0_CH1
#define pin_PWM_left2 FTM_CH0//C3£¬FTM0_CH2

//OLED
#define pin_OLED_D0  PTC4_OUT//PTC4
#define pin_OLED_D1  PTC5_OUT//PTC5
#define pin_OLED_RST  PTC6_OUT//PTC6
#define pin_OLED_DC   PTC7_OUT//PTC7
#define pin_OLED_CS   PTC8_OUT//PTC8




//SDCARD
#define pin_SDCARD_CS PTC9_OUT
#define pin_SDCARD_CLK PTC10_OUT
#define pin_SDCARD_MOSI PTC11_OUT
#define pin_SDCARD_MISO PTC12_IN

#define pin_SDCARD_CS_init PTC9
#define pin_SDCARD_CLK_init PTC10
#define pin_SDCARD_MOSI_init PTC11
#define pin_SDCARD_MISO_init PTC12

//button
#define pin_button1 PTC13
#define pin_button2 PTC14
#define pin_button3 PTC15
#define pin_button4 PTC16
#define pin_button5 PTC17
#define pin_button6 PTC18
#define pin_button7 PTC19

#endif
void car_init();
void pit_hander_time_recoder();