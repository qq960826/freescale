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
#ifndef   EVENTS_H
#define   EVENTS_H


/*
*********************************************************************************************************
* Description: No
*********************************************************************************************************
*/
#pragma CODE_SEG __NEAR_SEG NON_BANKED

__interrupt void PTHintIntISR(void);
__interrupt void PITCh0IntISR(void);
__interrupt void TIMCh0IntISR(void);


#pragma CODE_SEG DEFAULT

//Timer


#endif