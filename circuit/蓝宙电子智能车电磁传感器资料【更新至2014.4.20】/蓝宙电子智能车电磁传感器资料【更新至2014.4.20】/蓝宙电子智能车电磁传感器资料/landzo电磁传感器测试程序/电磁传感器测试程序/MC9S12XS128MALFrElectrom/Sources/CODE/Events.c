/*
/******************** (C) COPYRIGHT 2011 蓝宙电子工作室 ********************
 * 文件名       ：
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
#include  "Events.h"
                                      

/*
*********************************************************************************************************
* Description: Global variable
*********************************************************************************************************
*/

extern uint16_t SpeedCount ;

//Timer
uint8_t Timer1sFlag = 0;
uint16_t Timer1sCnt  = 0;
uint8_t Timer5msFlag = 0;
uint8_t Timer5msCnt  = 0;
uint8_t Timer10msFlag = 0;
uint8_t Timer10msCnt  = 0;
uint8_t Timer20msFlag = 0;
uint8_t Timer20msCnt  = 0;


/*
*********************************************************************************************************
* Description: PTHinterrupt
* Note: 5ms at 40M
*********************************************************************************************************
*/
#pragma CODE_SEG __NEAR_SEG NON_BANKED

__interrupt void PTHintIntISR(void) {


  if(PIFH & 0x80)  {
  
      PIFH = 0X80 ;
     
  } else  if((PIFH & 0x40)){
      
      PIFH = 0X40 ;  
  }                                

}


   
#pragma CODE_SEG DEFAULT


/*
*********************************************************************************************************
* Description: PITCh0IntISR
* Note: 5ms at 40M
*********************************************************************************************************
*/
#pragma CODE_SEG __NEAR_SEG NON_BANKED

__interrupt void PITCh0IntISR(void) {

    PITTF_PTF0 = 1;

    if(++Timer1sCnt == 200) {
        Timer1sCnt  = 0;
        Timer1sFlag = 1;
    }

    if(++Timer20msCnt == 4) {
        Timer20msCnt  = 0;
        Timer20msFlag = 1;
    }

    if(++Timer10msCnt == 2) {
        Timer10msCnt  = 0;
        Timer10msFlag = 1;
    }


    if(++Timer5msCnt == 1) {
        Timer5msCnt  = 0;
        Timer5msFlag = 1;
    }
}

#pragma CODE_SEG DEFAULT



/*
*********************************************************************************************************
* Description: TIMCh0IntISR
* 
*********************************************************************************************************
*/
#pragma CODE_SEG __NEAR_SEG NON_BANKED


__interrupt void TIMCh0IntISR(void){

            TFLG1_C0F = 1 ;
            TC0 = 0 ;
            SpeedCount ++ ;

}


#pragma CODE_SEG DEFAULT


