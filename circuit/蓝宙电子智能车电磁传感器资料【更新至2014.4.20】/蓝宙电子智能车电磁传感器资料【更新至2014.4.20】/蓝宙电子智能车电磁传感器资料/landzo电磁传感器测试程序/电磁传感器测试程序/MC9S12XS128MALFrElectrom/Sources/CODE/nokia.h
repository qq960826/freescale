/******************** (C) COPYRIGHT 2011 蓝宙电子工作室 ********************
 * 文件名       �  
 * 描述         ：工程模版实验
 *
 * 实验平台     ：landzo电子开发版
 * 库版本       ：
 * 嵌入系统     ：
 *
 * 作者         ：landzo 蓝电子
 * 淘宝店       ：http://landzo.taobao.com/

**********************************************************************************/

#ifndef _NOKIA_H
#define _NOKIA_H


/********************************************************************/
/*-----------------------------------------------------------------------
LCD_init          : 5110LCD初始化

编写日期          ：2012-11-01
最后修改日期      ：2012-11-01
-----------------------------------------------------------------------*/
#define LCD_RST   PTJ_PTJ6 
#define LCD_CE    PTS_PTS7
#define SDIN      PTS_PTS5
#define SCLK      PTS_PTS6
#define LCD_DC    PTS_PTS4


void delay_1us(void)  ;
void delay_1ns(void)  ;
void LCD_clear(void);
void LCD_write_byte(uint8_t dat, uint8_t command);
void LCD_init(void) ;
void LCD_write_char(uint8_t c) ;
void LCD_set_XY(uint8_t X, uint8_t Y);



    

/********************************************************************/

#endif
