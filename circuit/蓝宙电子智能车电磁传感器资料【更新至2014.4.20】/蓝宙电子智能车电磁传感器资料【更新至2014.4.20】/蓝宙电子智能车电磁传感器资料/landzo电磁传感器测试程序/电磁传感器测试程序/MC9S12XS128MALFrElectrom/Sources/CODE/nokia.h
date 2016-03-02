/******************** (C) COPYRIGHT 2011 ������ӹ����� ********************
 * �ļ���       �  
 * ����         ������ģ��ʵ��
 *
 * ʵ��ƽ̨     ��landzo���ӿ�����
 * ��汾       ��
 * Ƕ��ϵͳ     ��
 *
 * ����         ��landzo ������
 * �Ա���       ��http://landzo.taobao.com/

**********************************************************************************/

#ifndef _NOKIA_H
#define _NOKIA_H


/********************************************************************/
/*-----------------------------------------------------------------------
LCD_init          : 5110LCD��ʼ��

��д����          ��2012-11-01
����޸�����      ��2012-11-01
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
