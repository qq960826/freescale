#include "common.h"
#include "port_cfg.h"
#include "include.h"

//���Ŷ���
#define pin_accelerometer1_X ADC1_SE4a//E0
#define pin_accelerometer1_Y ADC1_SE5a//E1
#define pin_accelerometer1_Z ADC1_SE6a//E2

#define pin_gyroscope1_AR2 ADC1_SE7a//E3

//#define 
unsigned long long system_time_ms;
long long omrom_encoder1=0;
void pit_hander_time_recoder(){
  PIT_Flag_Clear(PIT0);
  system_time_ms++;
}
void pit_hander_omron_encoder(){
  PIT_Flag_Clear(PIT1);
  omrom_encoder1+=FTM_QUAD_get(FTM1);
  FTM_QUAD_clean(FTM1);
  printf("%lld\n",omrom_encoder1);

}
unsigned long long mills(){
  return system_time_ms;

}
void car_init(){
//ADC_init
  adc_init(pin_accelerometer1_X);//���ٶȼ�1���ٶȼ�X,E0
  adc_init(pin_accelerometer1_Y);//���ٶȼ�1���ٶȼ�Y,E1
  adc_init(pin_accelerometer1_Z);//���ٶȼ�1���ٶȼ�Z,E2
  adc_init(pin_gyroscope1_AR2);//������1���ٶȼ�zero,E3

  
//UART_init
  uart_init(UART0,9600);//D6=RX,D7=TX
  
  
//PTM_Init
  
  //FTM_init
  FTM_QUAD_Init(FTM1);                                    //FTM1 ���������ʼ�������õĹܽſɲ� vcan_port_cfg.h ��
  
  
  
//PIT_init
  //��ʱ��һ��ϵͳ��ʱ
  system_time_ms=0;
  pit_init_ms(PIT0,1);
  set_vector_handler(PIT0_VECTORn,pit_hander_time_recoder);
  enable_irq(PIT0_IRQn);
  
  //��ʱ�����������ٶ�
  pit_init_ms(PIT1,500);
  set_vector_handler(PIT1_VECTORn,pit_hander_omron_encoder);
  enable_irq(PIT1_IRQn);
  
  

  
  
}

