/******************** (C) COPYRIGHT 2011 ������ӹ����� ********************
 * �ļ���       ��
 * ����         ������ģ��ʵ��
 *
 * ʵ��ƽ̨     ��landzo���ӿ�����
 * ��汾       ��
 * Ƕ��ϵͳ     ��
 *
 * ����         ��landzo ������
 * �Ա���       ��http://landzo.taobao.com/

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