#include "common.h"
#include "port_cfg.h"
#include "include.h"
#include "init.h"



extern long long omron_encoder_left_now;
extern long long omron_encoder_left_last;
extern long long omron_encoder_right_now;
extern long long omron_encoder_right_last;

//#define 
extern  unsigned long long system_time_ms;
void pit_hander_time_recoder(){
  PIT_Flag_Clear(PIT0);
  system_time_ms++;
}
void pit_hander_omron_encoder(){
  if(omron_encoder_right_now>1<<29) omron_encoder_right_now=0;//��ֹ���
  omron_encoder_right_last=omron_encoder_right_now;
  omron_encoder_right_now+=FTM_QUAD_get(FTM1);
  omron_encoder_left_last=omron_encoder_left_now;
  omron_encoder_left_now+=FTM_QUAD_get(FTM2);
  
FTM_QUAD_clean(FTM1);
FTM_QUAD_clean(FTM2);
  PIT_Flag_Clear(PIT1);
  
  //printf("%lld\n",omrom_encoder1);

}
unsigned long long mills(){
  return system_time_ms;

}
void PORTC_IRQHandler(){
  PORTC_ISFR  = ~0;
  PORTC_ISFR  = ~0;
printf("wzq");



}

void car_init(){
//ADC_init
  adc_init(pin_accelerometer1_X);//���ٶȼ�1���ٶȼ�X,E0
  adc_init(pin_accelerometer1_Y);//���ٶȼ�1���ٶȼ�Y,E1
  adc_init(pin_accelerometer1_Z);//���ٶȼ�1���ٶȼ�Z,E2
  adc_init(pin_gyroscope1_AR2);//������1���ٶȼ�zero,E3

  adc_init(pin_electromagnet_L1);//
  adc_init(pin_electromagnet_L2);//
  adc_init(pin_electromagnet_L3);//
  adc_init(pin_electromagnet_L4);// 
  adc_init(pin_electromagnet_L5);//
  adc_init(pin_electromagnet_L6);// 
  
  
//UART_init
  uart_init(pin_uart,9600);//D6=RX,D7=TX
  
  
//PWM_Init
  FTM_PWM_init(FTM0,pin_PWM_right1,10*1000,0);
  FTM_PWM_init(FTM0,pin_PWM_right2,10*1000,0);
  FTM_PWM_init(FTM0,pin_PWM_left1,10*1000,0);
  FTM_PWM_init(FTM0,pin_PWM_left2,10*1000,100);

  //FTM_init
  FTM_QUAD_Init(FTM1);                                    //FTM1 ���������ʼ�������õĹܽſɲ� vcan_port_cfg.h ��
  FTM_QUAD_Init(FTM2);
  
  
//PIT_init
  //��ʱ��һ��ϵͳ��ʱ
  system_time_ms=0;
  pit_init_ms(PIT0,1);
  set_vector_handler(PIT0_VECTORn,pit_hander_time_recoder);
  enable_irq(PIT0_IRQn);
  
  //��ʱ�����������ٶ�
  pit_init_us(PIT1,1000);
  set_vector_handler(PIT1_VECTORn,pit_hander_omron_encoder);
  enable_irq(PIT1_IRQn);
  
  
//SD_init
  
  
  //button_init
  port_init(pin_button1, ALT1 | IRQ_FALLING | PULLUP );
  port_init(pin_button2, ALT1 | IRQ_FALLING | PULLUP );
  port_init(pin_button3, ALT1 | IRQ_FALLING | PULLUP );
  port_init(pin_button4, ALT1 | IRQ_FALLING | PULLUP );
  port_init(pin_button5, ALT1 | IRQ_FALLING | PULLUP );
  port_init(pin_button6, ALT1 | IRQ_FALLING | PULLUP );
  port_init(pin_button7, ALT1 | IRQ_FALLING | PULLUP );
  set_vector_handler(PORTC_VECTORn ,PORTC_IRQHandler);
  enable_irq (PORTC_IRQn);
  
  
  
  
}

