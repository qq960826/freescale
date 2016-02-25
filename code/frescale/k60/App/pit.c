void PIT_Init(void) {
  PITCFLMT_PITE=0; //定时中断通道0 关
  PITCE_PCE0=1;//定时器通道0 使能
  PITMTLD0=80-1;//8 位定时器初值设定。80 分频，在80MHzBusClock 下，为1MHz。即1us.
  PITLD0=54321-1;//16 位定时器初值设定。50ms溢出
  PITINTE_PINTE0=1;//定时器中断通道0 中断使能
  PITCFLMT_PITE=1;//定时器通道0 使能
  
  PITLD1=5000-1;//16 位定时器初值设定。2ms溢出
  PITCE_PCE1=1;//定时器通道1 使能
  PITINTE_PINTE1=0; //定时器中断通道1 中断
}
unsigned long micros() {
return time_us+(54321-PITCNT0);
}
unsigned long millis() {
unsigned long mm=micros();
if(mm>500)
return (54321-PITCNT0)/1000+time_ms+1;
return (54321-PITCNT0)/1000+time_ms;
}
     
#pragma CODE_SEG __NEAR_SEG NON_BANKED
void interrupt 66 PIT0(void)
{
    PITTF_PTF0 = 1; //clear interrupts flag
    time_ms_mod+=321;
    if(time_ms_mod>=1000){
     time_ms_mod-=1000;
     time_ms+=1;
    }
    time_ms+=54;
    time_us+=54321;
      
}