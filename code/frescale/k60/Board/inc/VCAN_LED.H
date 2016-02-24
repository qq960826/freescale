 /*!
  *     COPYRIGHT NOTICE
  *     Copyright (c) 2013,ɽ��Ƽ�
  *     All rights reserved. 
  *     �������ۣ�ɽ���ѧ��̳ http://www.vcan123.com
  *
  *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ������������������ҵ��;��
  *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
  *
  * @file       VCAN_LED.h
  * @brief      led����ͷ�ļ�
  * @author     ɽ��Ƽ�
  * @version    v5.0
  * @date       2013-07-9
  */

#ifndef __VCAN_LED_H__
#define __VCAN_LED_H__


/*! ö��LED��� */
typedef enum
{
  LED0,
  LED1,
  LED2,
  LED3,
  LED_MAX,
}LED_e;

/*! ö��LED����״̬ */
typedef enum LED_status
{
  LED_ON  =   0,            //����(��Ӧ�͵�ƽ)
  LED_OFF =   1             //�ư�(��Ӧ�ߵ�ƽ)
}LED_status; 


extern void    led_init(LED_e);            //��ʼ��LED�˿�
extern void    led(LED_e,LED_status);      //����LED������
extern void    led_turn(LED_e);            //����LED������ת

#endif  //__VCAN_LED_H__