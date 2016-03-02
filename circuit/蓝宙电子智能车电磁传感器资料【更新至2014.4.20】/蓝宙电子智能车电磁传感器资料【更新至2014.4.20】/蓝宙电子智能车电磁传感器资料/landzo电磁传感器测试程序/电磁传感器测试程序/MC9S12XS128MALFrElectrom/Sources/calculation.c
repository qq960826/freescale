/******************** (C) COPYRIGHT 2011 ������ӹ����� ********************
 * �ļ���       ��
 * ����         ������ģ��ʵ��
 *
 * ʵ��ƽ̨     ��landzo���ӿ�����
 * ��汾       ��
 * Ƕ��ϵͳ     ��
 * ����         ��landzo ������
 * �Ա���       ��http://landzo.taobao.com/

**********************************************************************************/
#include "commen.h"
#include "includes.h"
#include "calculation.h"

/*********************************************************** 
�������ƣ�LCD_KEY_init
�������ܣ�
��ڲ�����
���ڲ������� 
�� ע�� 
***********************************************************/
//void LCD_KEY_init (void){
  
  
 //     pit_init_ms(PIT2, 5);                                  //��ʼ��PIT2����ʱʱ��Ϊ�� 5ms ,�����ö�ʱ��
     /************************
     Һ������ʼ��
    ************************/
   // gpio_init (PORTC , 14, GPO, HIGH) ;
                                                          
  //  LCD_init() ;  
     /************************
     ������ʼ��
    ************************/
  //  gpio_Interrupt_init(PORTD , 8, GPI, EITHER) ;

//}

/*********************************************************** 
�������ƣ�Manget_init
�������ܣ�
��ڲ�����
���ڲ������� 
�� ע��   ��Ŵ�������ʼ��
***********************************************************/

void Manget_init(void) {

    ATD0CTL4 = 0x04;                    /* Set sample time and prescaler */
    ATD0CTL3 = 0x88;                    /* Right justified data,Conversion Sequence Length = 1 */
    ATD0CTL0 = 0x0F;                    /* Set wrap around */
    ATD0CTL1 = 0x4F;                    /* 12-bit data */
    ATD0CTL2 = 0x40;                    /* Fast Flag Clear */
     
                              
}

/*********************************************************** 
�������ƣ�EMC_CAC
�������ܣ�
��ڲ�����
���ڲ������� 
�� ע�� 
***********************************************************/

int16_t EMC_CAC(void){
  int16_t  LeftAD ,RingtAD ;
  int16_t  LeftSt ,RingtSt ;
  int16_t  Mind ,TrunKP ,Apwm;
  TrunKP = 10 ;
    LeftAD = 0 ;
    RingtAD = 0;
    LeftAD = AD_Measure12(3) ;
    RingtAD = AD_Measure12(4) ;
    SCI0_SendChar1(0xaa);
    SCI0_SendChar1(LeftAD);
    SCI0_SendChar1(RingtAD);
    
    
    return Apwm ;
    
}
/*********************************************************** 
�������ƣ� SpeedIN_init
�������ܣ�
��ڲ�����
���ڲ������� 
�� ע�� ���������ʼ��
***********************************************************/
void SpeedIN_init(void) {
     
     TIOS_IOS0 = 0 ;
     TCTL4_EDG0A = 1 ;          //�½��ز���
     TCTL4_EDG0B = 0 ;          //�½��ز���
     PACTL_CLK0 = 0 ;
     PACTL_CLK1 = 0 ;
     
     TSCR2_PR = 1;       //Bus Clock / 1,40M / 1 = 40M
     TIE_C0I = 1;        //Enable Ch0 interrupt.
  //   TSCR2_TOI = 1;      //Main timer overflow interrupt enable.
     TSCR1_TEN = 1;      //Enable Timer.
  
}


/*********************************************************** 
�������ƣ�LCD_KEY
�������ܣ�Һ����ʾ�Ͱ�������
��ڲ�����c	:  ��ʾ���ַ�
���ڲ������� 
�� ע�� 
***********************************************************/
extern uint8_t key8flg ;
extern uint8_t key9flg ;
extern uint8_t key10flg ;
extern uint8_t key11flg ;
extern uint8_t keyflg  ;
extern uint8_t TIME0flag_80ms  ;
extern int16_t ASPeed0 ,ASPeed1 ,ASPeed2;
extern int16_t ASPeed3 ,ASPeed4 ,ASPeed5 ;
void KYELCD(void){
  

static uint8_t t8rmp0 = 0,t8rmp1 = 0;
static uint8_t AupDown  ;
uint8_t AspeedS0, AspeedS1, AspeedS2, AspeedS3;

   if(key8flg >= 1)  {
         
          keyflg = 0 ;
          key8flg -- ;
          if(AupDown > 0)
          {
            AupDown -- ;
          }
        }
      

         if(key11flg >= 1)  {
          if(AupDown < 5)
          {
            AupDown ++ ;
          }
          keyflg = 0 ;
          key11flg -- ;
        }

      /*********************
      160ms����ִ�д����
      *********************/
      if(TIME0flag_80ms == 1)
      {
        TIME0flag_80ms = 0 ; 
        
     
           if(AupDown == 0)
           {
                if(key9flg >= 1)  {
                 keyflg = 0 ;
                 ASPeed0 += key9flg ;
                 key9flg = 0 ;            
              }
              if(key10flg >= 1){
                  keyflg = 0 ; 
                  if((ASPeed0-key10flg) < 0)
                  {
                    ASPeed0 = 0 ; 
                    key10flg = 0 ;
                  } else 
                  {
                    ASPeed0 -= key10flg ; 
                    key10flg = 0 ;
                  }
              }
           }           
           else if(AupDown == 1)
           {

             
              if(key9flg >= 1)  {
                 keyflg = 0 ;
                 ASPeed1 += key9flg ;
                 key9flg = 0 ;            
              }
              if(key10flg >= 1){
                  keyflg = 0 ; 
                  if((ASPeed1-key10flg) < 0)
                  {
                    ASPeed1 = 0 ; 
                    key10flg = 0 ;
                  } else 
                  {
                    ASPeed1 -= key10flg ; 
                    key10flg = 0 ;
                  }
              }
           }
           else if(AupDown == 2)
           {
                if(key9flg >= 1)  {
                 keyflg = 0 ;
                 ASPeed2 += key9flg ;
                 key9flg = 0 ;            
              }
              if(key10flg >= 1){
                  keyflg = 0 ; 
                  if((ASPeed2-key10flg) < 0)
                  {
                    ASPeed2 = 0 ; 
                    key10flg = 0 ;
                  } else 
                  {
                    ASPeed2 -= key10flg ; 
                    key10flg = 0 ;
                  }
              }
           }
           else if(AupDown == 3)
           {
                if(key9flg >= 1)  {
                 keyflg = 0 ;
                 ASPeed3 += key9flg ;
                 key9flg = 0 ;            
              }
              if(key10flg >= 1){
                  keyflg = 0 ; 
                  if((ASPeed3-key10flg) < 0)
                  {
                    ASPeed3 = 0 ; 
                    key10flg = 0 ;
                  } else 
                  {
                    ASPeed3 -= key10flg ; 
                    key10flg = 0 ;
                  }
              }
           }
           else if(AupDown == 4)
           {
                if(key9flg >= 1)  {
                 keyflg = 0 ;
                 ASPeed4 += key9flg ;
                 key9flg = 0 ;            
              }
              if(key10flg >= 1){
                  keyflg = 0 ; 
                  if((ASPeed4-key10flg) < 0)
                  {
                    ASPeed4 = 0 ; 
                    key10flg = 0 ;
                  } else 
                  {
                    ASPeed4 -= key10flg ; 
                    key10flg = 0 ;
                  }
              }
           }
           else if(AupDown == 5)
           {
                if(key9flg >= 1)  {
                 keyflg = 0 ;
                 ASPeed5 += key9flg ;
                 key9flg = 0 ;            
              }
              if(key10flg >= 1){
                  keyflg = 0 ; 
                  if((ASPeed5-key10flg) < 0)
                  {
                    ASPeed5 = 0 ; 
                    key10flg = 0 ;
                  } else 
                  {
                    ASPeed5 -= key10flg ; 
                    key10flg = 0 ;
                  }
              }
           }
        
        
           



              
        if(t8rmp0 == 1)
        {
             
          t8rmp0 = 0 ;

           if(AupDown == 0)
            LCD_set_XY(0, 0) ;
           else if(AupDown == 1)
            LCD_set_XY(0, 1) ; 
           else if(AupDown == 2)
            LCD_set_XY(0, 2) ; 
           else if(AupDown == 3)
            LCD_set_XY(0, 3) ; 
           else if(AupDown == 4)
            LCD_set_XY(0, 4) ; 
           else if(AupDown == 5)
            LCD_set_XY(0, 5) ; 
            for(t8rmp1 = 0 ; t8rmp1 < 83 ;t8rmp1 ++)
                  {  LCD_write_byte(0, 1);   }   
        }
        else{
 
             t8rmp0 = 1 ; 
 
              LCD_set_XY(0, 0) ;
              LCD_write_char('L');
              LCD_write_char('a');
              LCD_write_char('n');
              LCD_write_char('d');
              LCD_write_char('z');
              LCD_write_char('o');                      
             /**************
              �ڶ�����ʾ����
             ************* */
       
              AspeedS0 = (uint8_t) ((ASPeed1/1000)  + 48 );
              AspeedS1 = (uint8_t) (((ASPeed1%1000)/100) +48 ) ;
              AspeedS2 = (uint8_t) (((ASPeed1%100)/10)  + 48 ); 
              AspeedS3 = (uint8_t) ((ASPeed1%10)  + 48 );

              LCD_set_XY(0, 1) ;
              LCD_write_char('S');
              LCD_write_char('p');
              LCD_write_char('e');
              LCD_write_char('e');
              LCD_write_char('d');
              LCD_write_char('0');
              LCD_write_char(':');
              LCD_write_char(AspeedS0);
              LCD_write_char(AspeedS1);
              LCD_write_char(AspeedS2);
              LCD_write_char(AspeedS3);
             /**************
              ��������ʾ����
            **************/ 

              AspeedS0 = (uint8_t) ((ASPeed2/1000)  + 48 );
              AspeedS1 = (uint8_t) (((ASPeed2%1000)/100) +48 ) ;
              AspeedS2 = (uint8_t) (((ASPeed2%100)/10)  + 48 ); 
              AspeedS3 = (uint8_t) ((ASPeed2%10)  + 48 );
              

             LCD_set_XY(0, 2) ;  
              LCD_write_char('S');
              LCD_write_char('p');
              LCD_write_char('e');
              LCD_write_char('e');
              LCD_write_char('d');
              LCD_write_char('1');
              LCD_write_char(':');
              LCD_write_char(AspeedS0);
              LCD_write_char(AspeedS1);
              LCD_write_char(AspeedS2);
              LCD_write_char(AspeedS3);
             /**************
              ��������ʾ����
             **************/ 
              AspeedS0 = (uint8_t) ((ASPeed3/1000)  + 48 );
              AspeedS1 = (uint8_t) (((ASPeed3%1000)/100) +48 ) ;
              AspeedS2 = (uint8_t) (((ASPeed3%100)/10)  + 48 ); 
              AspeedS3 = (uint8_t) ((ASPeed3%10)  + 48 );
             LCD_set_XY(0, 3) ;
              LCD_write_char('S');
              LCD_write_char('p');
              LCD_write_char('e');
              LCD_write_char('e');
              LCD_write_char('d');
              LCD_write_char('2');
              LCD_write_char(':');
              LCD_write_char(AspeedS0);
              LCD_write_char(AspeedS1);
              LCD_write_char(AspeedS2);
              LCD_write_char(AspeedS3);
             /**************
              ��������ʾ����
             **************/ 
              AspeedS0 = (uint8_t) ((ASPeed4/1000)  + 48 );
              AspeedS1 = (uint8_t) (((ASPeed4%1000)/100) +48 ) ;
              AspeedS2 = (uint8_t) (((ASPeed4%100)/10)  + 48 ); 
              AspeedS3 = (uint8_t) ((ASPeed4%10)  + 48 );
             LCD_set_XY(0, 4) ;
              LCD_write_char('S');
              LCD_write_char('p');
              LCD_write_char('e');
              LCD_write_char('e');
              LCD_write_char('d');
              LCD_write_char('3');
              LCD_write_char(':');
              LCD_write_char(AspeedS0);
              LCD_write_char(AspeedS1);
              LCD_write_char(AspeedS2);
              LCD_write_char(AspeedS3);
             /**************
              ��������ʾ����
             **************/  
              AspeedS0 = (uint8_t) ((ASPeed5/1000)  + 48 );
              AspeedS1 = (uint8_t) (((ASPeed5%1000)/100) +48 ) ;
              AspeedS2 = (uint8_t) (((ASPeed5%100)/10)  + 48 ); 
              AspeedS3 = (uint8_t) ((ASPeed5%10)  + 48 );
              LCD_set_XY(0, 5) ;
              LCD_write_char('S');
              LCD_write_char('p');
              LCD_write_char('e');
              LCD_write_char('e');
              LCD_write_char('d');
              LCD_write_char('4');
              LCD_write_char(':');
              LCD_write_char(AspeedS0);
              LCD_write_char(AspeedS1);
              LCD_write_char(AspeedS2);
              LCD_write_char(AspeedS3);
        }
      }

}
/*********************************************************** 
�������ƣ�LCDTIME
�������ܣ�Һ����ʾ��
��ڲ�����c	:  ��ʾ���ַ�
���ڲ������� 
�� ע�� 
***********************************************************/
void LCDTIME(void){
  
              
              uint8_t AspeedS0, AspeedS1, AspeedS2, AspeedS3;
              LCD_set_XY(0, 0) ;
              LCD_write_char('L');
              LCD_write_char('a');
              LCD_write_char('n');
              LCD_write_char('d');
              LCD_write_char('z');
              LCD_write_char('o'); 
             /**************
              �ڶ�����ʾ����
             ************* */
       
              AspeedS0 = (uint8_t) ((ASPeed1/1000)  + 48 );
              AspeedS1 = (uint8_t) (((ASPeed1%1000)/100) +48 ) ;
              AspeedS2 = (uint8_t) (((ASPeed1%100)/10)  + 48 ); 
              AspeedS3 = (uint8_t) ((ASPeed1%10)  + 48 );

              LCD_set_XY(0, 1) ;
              LCD_write_char('S');
              LCD_write_char('p');
              LCD_write_char('e');
              LCD_write_char('e');
              LCD_write_char('d');
              LCD_write_char('0');
              LCD_write_char(':');
              LCD_write_char(AspeedS0);
              LCD_write_char(AspeedS1);
              LCD_write_char(AspeedS2);
              LCD_write_char(AspeedS3);
             /**************
              ��������ʾ����
            **************/ 

              AspeedS0 = (uint8_t) ((ASPeed2/1000)  + 48 );
              AspeedS1 = (uint8_t) (((ASPeed2%1000)/100) +48 ) ;
              AspeedS2 = (uint8_t) (((ASPeed2%100)/10)  + 48 ); 
              AspeedS3 = (uint8_t) ((ASPeed2%10)  + 48 );
              

             LCD_set_XY(0, 2) ;  
              LCD_write_char('S');
              LCD_write_char('p');
              LCD_write_char('e');
              LCD_write_char('e');
              LCD_write_char('d');
              LCD_write_char('1');
              LCD_write_char(':');
              LCD_write_char(AspeedS0);
              LCD_write_char(AspeedS1);
              LCD_write_char(AspeedS2);
              LCD_write_char(AspeedS3);
             /**************
              ��������ʾ����
             **************/ 
              AspeedS0 = (uint8_t) ((ASPeed3/1000)  + 48 );
              AspeedS1 = (uint8_t) (((ASPeed3%1000)/100) +48 ) ;
              AspeedS2 = (uint8_t) (((ASPeed3%100)/10)  + 48 ); 
              AspeedS3 = (uint8_t) ((ASPeed3%10)  + 48 );
             LCD_set_XY(0, 3) ;
              LCD_write_char('S');
              LCD_write_char('p');
              LCD_write_char('e');
              LCD_write_char('e');
              LCD_write_char('d');
              LCD_write_char('2');
              LCD_write_char(':');
              LCD_write_char(AspeedS0);
              LCD_write_char(AspeedS1);
              LCD_write_char(AspeedS2);
              LCD_write_char(AspeedS3);
             /**************
              ��������ʾ����
             **************/ 
              AspeedS0 = (uint8_t) ((ASPeed4/1000)  + 48 );
              AspeedS1 = (uint8_t) (((ASPeed4%1000)/100) +48 ) ;
              AspeedS2 = (uint8_t) (((ASPeed4%100)/10)  + 48 ); 
              AspeedS3 = (uint8_t) ((ASPeed4%10)  + 48 );
             LCD_set_XY(0, 4) ;
              LCD_write_char('S');
              LCD_write_char('p');
              LCD_write_char('e');
              LCD_write_char('e');
              LCD_write_char('d');
              LCD_write_char('3');
              LCD_write_char(':');
              LCD_write_char(AspeedS0);
              LCD_write_char(AspeedS1);
              LCD_write_char(AspeedS2);
              LCD_write_char(AspeedS3);
             /**************
              ��������ʾ����
             **************/  
              AspeedS0 = (uint8_t) ((ASPeed5/1000)  + 48 );
              AspeedS1 = (uint8_t) (((ASPeed5%1000)/100) +48 ) ;
              AspeedS2 = (uint8_t) (((ASPeed5%100)/10)  + 48 ); 
              AspeedS3 = (uint8_t) ((ASPeed5%10)  + 48 );
              LCD_set_XY(0, 5) ;
              LCD_write_char('S');
              LCD_write_char('p');
              LCD_write_char('e');
              LCD_write_char('e');
              LCD_write_char('d');
              LCD_write_char('4');
              LCD_write_char(':');
              LCD_write_char(AspeedS0);
              LCD_write_char(AspeedS1);
              LCD_write_char(AspeedS2);
              LCD_write_char(AspeedS3);
        
      
}







