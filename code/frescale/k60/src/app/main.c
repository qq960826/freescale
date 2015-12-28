#include "include.h"
#include "gpio.h"
void main()
{
  int a=0;
  gpio_init(PORTC,17,GPO,1);
  while(1){
    a=1;
  }
}


  
