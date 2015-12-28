/******************** (C) COPYRIGHT 2011 蓝宙电子工作室 ********************
 * 文件名       ：delay.c
 * 描述         ：延时函数定义
 *
 * 实验平台     ：
 * 库版本       ：
 * 嵌入系统     ：
 *
 * 作者         ：蓝宙电子工作室
 * 淘宝店       ：http://landzo.taobao.com/
**********************************************************************************/

#include  "delay.h"


/*************************************************************************
*                             蓝宙电子工作室
*
*  函数名称：delay
*  功能说明：延时函数（不准确）
*  参数说明：无
*  函数返回：无
*  修改时间：2012-2-1    已测试
*  备    注：
*************************************************************************/
void  delay(void)
{
    delayms(500);
}

/*************************************************************************
*                             蓝宙电子工作室
*
*  函数名称：delayms
*  功能说明：延时函数（不准确），内核频率为100M时较为准确
*  参数说明：无
*  函数返回：无
*  修改时间：2012-2-1    已测试
*  备    注：
*************************************************************************/
void  delayms(uint32  ms)
{

    uint32  i, j;
    for(i = 0; i < ms; i++)
    {
        for(j = bus_clk_khz; j > 0; j--)
        {
            asm("nop");
        }
    }
}
