


#ifndef  calculation_H
#define  calculation_H  


void LCD_KEY_init (void) ;

int16_t SpeedPID(uint16_t speedCount,uint16_t AmSpeed) ;

void KYELCD(void) ;
void LCDTIME(void) ;

/*********************************************************************************************************
* Description: define
*********************************************************************************************************
*/

 /**********************
 * PID
 *********************/
#define  KPPLUSMAX      (170)
#define  KPNEGATIVEMAX  (-170)
#define  KIPLUSMAX      (170)
#define  KINEGATIVEMAX  (-170)
#define  KDPLUSMAX      (170)
#define  KDNEGATIVEMAX  (-170)
#define  KWPLUSMAX      (170)
#define  KWNEGATIVEMAX  (-170)
#define  KOUPLUSMAX     (300)

#define  LIN_COUT    100


#endif
