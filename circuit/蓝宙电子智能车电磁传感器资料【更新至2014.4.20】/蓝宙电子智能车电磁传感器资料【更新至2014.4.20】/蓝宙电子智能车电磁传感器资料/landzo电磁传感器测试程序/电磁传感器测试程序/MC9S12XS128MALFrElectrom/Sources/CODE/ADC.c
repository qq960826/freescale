/******************** (C) COPYRIGHT 2011 蓝宙电子工作室 ********************
 * 文件名       ?
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
#include  "adc.h"


/*
*********************************************************************************************************
* Description: ADC0_Init
* Note: Fbus = 
*********************************************************************************************************
*/
void ADC0_Init(void)     
{
  
    ATD0CTL4 = 0x04;                    /* Set sample time and prescaler */
    ATD0CTL3 = 0x88;                    /* Right justified data,Conversion Sequence Length = 1 */
    ATD0CTL0 = 0x0F;                    /* Set wrap around */
    ATD0CTL1 = 0x4F;                    /* 12-bit data */
    ATD0CTL2 = 0x40;                    /* Fast Flag Clear */
}

/*
** ===================================================================
** AD_Measure12
** ===================================================================
*/
uint16_t AD_Measure12(uint8_t Channel) {
    ATD0CTL5_Cx = Channel;
    while(ATD0STAT0_SCF == 0);
    return ATD0DR0;
}


