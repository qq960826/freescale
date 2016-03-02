/******************** (C) COPYRIGHT 2011 蓝宙电子工作室 ********************
 * 文件名       ：main.c
 * 描述         ：工程模版实验
 *
 * 实验平台     ：landzo电子开发版
 * 库版本       ：
 * 嵌入系统     ：
 *
 * 作者         ：landzo 蓝电子
 * 淘宝店       ：http://landzo.taobao.com/

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
  初始化全局变量
  *********************************************************/
  
      


    
    SCI0_Init();
    /*************************************
    初始化电机
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



  
  

  
  
  
  

  












