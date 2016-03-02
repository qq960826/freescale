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
#include "commen.h"
#include  "PIT.h"


/*
*********************************************************************************************************
* Description: PIT_Init
* Note: Fbus = 40M
*********************************************************************************************************
*/
void PIT_Init(void) {
    PITCE_PCE0 = 1;             //Enable Timer Channel0
    PITMUX_PMUX0 = 0;           //16-bit timer counts with micro time base 0
//time-out period = (PITMTLD + 1) * (PITLD + 1) / fBUS
//5ms
    PITMTLD0 = 199;             //PIT Micro Timer Load Register
    PITLD0 = 999;               //PIT Load Register
    PITINTE_PINTE0 = 1;         //Enable Timer Channel0 Interrupt
    PITCFLMT_PITE = 1;          //Enable Timer
}