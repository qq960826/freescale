/******************** (C) COPYRIGHT 2011 ������ӹ����� ********************
 * �ļ���       ��main.c
 * ����         ������ģ��ʵ��
 *
 * ʵ��ƽ̨     ��landzo���ӿ�����
 * ��汾       ��
 * Ƕ��ϵͳ     ��
 *
 * ����         ��landzo ������
 * �Ա���       ��http://landzo.taobao.com/

**********************************************************************************/
#include "commen.h"

#include "includes.h"
#include "calculation.h"


/*
*********************************************************************************************************
* Description: Data
*********************************************************************************************************
*/
extern uint8_t Timer1sFlag;
extern uint8_t Timer20msFlag;
extern uint8_t Timer10msFlag;
extern uint8_t Timer5msFlag;

int16_t ATurnPWM ;

uint16_t SpeedCount ;
uint16_t ASPeed1 ;
uint16_t PWMCount ;

/*
*********************************************************************************************************
* Description: main
*********************************************************************************************************
*/
void main(void) {

    DisableInterrupts
          
  /*********************************************************
  ��ʼ��ȫ�ֱ���
  *********************************************************/
  
      


    
    SCI0_Init();
    /*************************************
    ��ʼ�����
    *************************************/
    Manget_init() ;
    PIT_Init();
    
    EnableInterrupts;

    for(;;) {
    

            
//1S Timer
        if(Timer1sFlag!=0) {
         Timer1sFlag = 0;

     } 
 
      
//20ms Timer
        if(Timer20msFlag!=0) {
            Timer20msFlag = 0;
            ATurnPWM = EMC_CAC()  ;
      }
      

//10ms Timer
        if(Timer10msFlag!=0) {
         // SCI0_SendChar1(5);
         
            Timer10msFlag = 0;

       

        } 
        
//10ms Timer
        if(Timer5msFlag!=0) {
            Timer5msFlag = 0; 


        }

    }
}



  
  

  
  
  
  

  












