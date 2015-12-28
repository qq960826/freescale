
#include "common.h"
#include "include.h"
#include "calculation.h"

/*********************************************************** 
�������ƣ�LCD_KEY_init
�������ܣ�
��ڲ�����
���ڲ������� 
�� ע�� 
***********************************************************/
void LCD_KEY_init (void){
  
  
      pit_init_ms(PIT2, 5);                                  //��ʼ��PIT2����ʱʱ��Ϊ�� 5ms ,�����ö�ʱ��
     /************************
     Һ������ʼ��
    ************************/
    gpio_init (PORTC , 14, GPO, HIGH) ;
    gpio_init (PORTC , 15, GPO, HIGH) ;
    gpio_init (PORTC , 6,  GPO, HIGH) ;
    gpio_init (PORTC , 7,  GPO, HIGH) ;
    gpio_init (PORTB , 21, GPO, HIGH) ;
    gpio_init (PORTB , 22, GPO, HIGH) ;
    LCD_init() ;  
     /************************
     ������ʼ��
    ************************/
    gpio_Interrupt_init(PORTD , 8, GPI, EITHER) ;
    gpio_Interrupt_init(PORTD , 9, GPI, EITHER) ;
    gpio_Interrupt_init(PORTD , 10, GPI, EITHER) ;
    gpio_Interrupt_init(PORTD , 11, GPI, EITHER) ;
}






/*********************************************************** 
�������ƣ�LCD_KEY
�������ܣ�Һ����ʾ�Ͱ�������
��ڲ�����c	:  ��ʾ���ַ�
���ڲ������� 
�� ע�� 
***********************************************************/
extern u8 key8flg ;
extern u8 key9flg ;
extern u8 key10flg ;
extern u8 key11flg ;
extern u8 keyflg  ;
extern u8 TIME0flag_80ms  ;
extern u16 ASPeed0 ,ASPeed1 ,ASPeed2;
extern u16 ASPeed3 ,ASPeed4 ,ASPeed5 ;
void KYELCD(void){
  

static u8 t8rmp0 = 0,t8rmp1 = 0;
static u8 AupDown  ;
u8 AspeedS0, AspeedS1, AspeedS2, AspeedS3;

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
       
              AspeedS0 = (u8) ((ASPeed1/1000)  + 48 );
              AspeedS1 = (u8) (((ASPeed1%1000)/100) +48 ) ;
              AspeedS2 = (u8) (((ASPeed1%100)/10)  + 48 ); 
              AspeedS3 = (u8) ((ASPeed1%10)  + 48 );

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

              AspeedS0 = (u8) ((ASPeed2/1000)  + 48 );
              AspeedS1 = (u8) (((ASPeed2%1000)/100) +48 ) ;
              AspeedS2 = (u8) (((ASPeed2%100)/10)  + 48 ); 
              AspeedS3 = (u8) ((ASPeed2%10)  + 48 );
              

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
              AspeedS0 = (u8) ((ASPeed3/1000)  + 48 );
              AspeedS1 = (u8) (((ASPeed3%1000)/100) +48 ) ;
              AspeedS2 = (u8) (((ASPeed3%100)/10)  + 48 ); 
              AspeedS3 = (u8) ((ASPeed3%10)  + 48 );
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
              AspeedS0 = (u8) ((ASPeed4/1000)  + 48 );
              AspeedS1 = (u8) (((ASPeed4%1000)/100) +48 ) ;
              AspeedS2 = (u8) (((ASPeed4%100)/10)  + 48 ); 
              AspeedS3 = (u8) ((ASPeed4%10)  + 48 );
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
              AspeedS0 = (u8) ((ASPeed5/1000)  + 48 );
              AspeedS1 = (u8) (((ASPeed5%1000)/100) +48 ) ;
              AspeedS2 = (u8) (((ASPeed5%100)/10)  + 48 ); 
              AspeedS3 = (u8) ((ASPeed5%10)  + 48 );
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
  
              
              u8 AspeedS0, AspeedS1, AspeedS2, AspeedS3;
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
       
              AspeedS0 = (u8) ((ASPeed1/1000)  + 48 );
              AspeedS1 = (u8) (((ASPeed1%1000)/100) +48 ) ;
              AspeedS2 = (u8) (((ASPeed1%100)/10)  + 48 ); 
              AspeedS3 = (u8) ((ASPeed1%10)  + 48 );

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

              AspeedS0 = (u8) ((ASPeed2/1000)  + 48 );
              AspeedS1 = (u8) (((ASPeed2%1000)/100) +48 ) ;
              AspeedS2 = (u8) (((ASPeed2%100)/10)  + 48 ); 
              AspeedS3 = (u8) ((ASPeed2%10)  + 48 );
              

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
              AspeedS0 = (u8) ((ASPeed3/1000)  + 48 );
              AspeedS1 = (u8) (((ASPeed3%1000)/100) +48 ) ;
              AspeedS2 = (u8) (((ASPeed3%100)/10)  + 48 ); 
              AspeedS3 = (u8) ((ASPeed3%10)  + 48 );
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
              AspeedS0 = (u8) ((ASPeed4/1000)  + 48 );
              AspeedS1 = (u8) (((ASPeed4%1000)/100) +48 ) ;
              AspeedS2 = (u8) (((ASPeed4%100)/10)  + 48 ); 
              AspeedS3 = (u8) ((ASPeed4%10)  + 48 );
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
              AspeedS0 = (u8) ((ASPeed5/1000)  + 48 );
              AspeedS1 = (u8) (((ASPeed5%1000)/100) +48 ) ;
              AspeedS2 = (u8) (((ASPeed5%100)/10)  + 48 ); 
              AspeedS3 = (u8) ((ASPeed5%10)  + 48 );
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



/*
** ===================================================================
** SpeedPID
   ���룺speedCount�ɼ����٣�AmSpeed Ŀ�공��  ��  
   ��� ��SpeedPWMOUT  ���㳵�� ��
** ===================================================================
*/


int16_t  SpeedKP = 0 ;
int16_t  SpeedKI = 0 ;
int16_t  SpeedKD = 0 ;
//int16_t  SpeedPWM = 0 ;
      
 int16_t SpeedPID(uint16_t speedCount,uint16_t AmSpeed){
 //  uint8_t i;

     static int16_t LastSpeedCut0,LastSpeedCut1,LastSpeedCut2 ,SpeedLastPWMK ;
     int16_t  SpeedPWMKP ,SpeedPWMKI ,SpeedPWMKD,SpeedPWMK ;
     int16_t  SpeedPWMOUT;    
     int16_t  SpeedDifference0=0;
     int16_t  speedDEARE1,speedDEARE2,DSpeed ;              

     SpeedKP = 2;
     SpeedKI = 0;
     SpeedKD = 1; 
     
     LastSpeedCut0 = (int16_t) speedCount ;
     DSpeed =(int16_t) AmSpeed ;
     
     SpeedDifference0 = DSpeed - LastSpeedCut0  ;
     speedDEARE1 = LastSpeedCut0 - LastSpeedCut1;
     speedDEARE2 = LastSpeedCut2+LastSpeedCut0-2*LastSpeedCut1;
     LastSpeedCut2  = LastSpeedCut1;
     LastSpeedCut1  = LastSpeedCut0;

          
          SpeedPWMKP = SpeedKP*SpeedDifference0;
          if(SpeedPWMKP>KPPLUSMAX){
           SpeedPWMKP = KPPLUSMAX;
          }else if (SpeedPWMKP <KPNEGATIVEMAX){
          SpeedPWMKP = KPNEGATIVEMAX;                       
          }
          
       //   uart_putchar(UART0,SpeedDifference0);
       //   uart_putchar(UART0,SpeedPWMKP);  
          
          SpeedPWMKI = SpeedKI* speedDEARE1;
          if(SpeedPWMKI > KIPLUSMAX){
          SpeedPWMKI = KIPLUSMAX;
          } else if(SpeedPWMKI < KINEGATIVEMAX){
          SpeedPWMKI = KINEGATIVEMAX;
          }
          
          SpeedPWMKD = SpeedKD* speedDEARE2;
          if(SpeedPWMKD > KDPLUSMAX){
             SpeedPWMKD = KDPLUSMAX;
          } else if(SpeedPWMKD < KDNEGATIVEMAX){
            SpeedPWMKD = KDNEGATIVEMAX;
          }
          
          SpeedPWMK = SpeedPWMKD+SpeedPWMKI+SpeedPWMKP ;
          if(SpeedPWMK > KWPLUSMAX){
          SpeedPWMK = KWPLUSMAX;
          }else if(SpeedPWMK < KWNEGATIVEMAX){
          SpeedPWMK = KWNEGATIVEMAX;
          
          }
          
 
          
         SpeedPWMOUT = SpeedLastPWMK + SpeedPWMK ;
         if(SpeedPWMOUT < 0 ){
            SpeedPWMOUT = 0 ;
         } else if(SpeedPWMOUT > KOUPLUSMAX){
           SpeedPWMOUT = KOUPLUSMAX ;
         
         }
         SpeedLastPWMK = SpeedPWMOUT ;
       //   uart_putchar(UART0,SpeedPWMOUT);
       //   uart_putchar(UART0,SpeedPWMK);        
         return  SpeedPWMOUT ;
            
}





 