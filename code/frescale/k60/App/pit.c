void PIT_Init(void) {
  PITCFLMT_PITE=0; //��ʱ�ж�ͨ��0 ��
  PITCE_PCE0=1;//��ʱ��ͨ��0 ʹ��
  PITMTLD0=80-1;//8 λ��ʱ����ֵ�趨��80 ��Ƶ����80MHzBusClock �£�Ϊ1MHz����1us.
  PITLD0=54321-1;//16 λ��ʱ����ֵ�趨��50ms���
  PITINTE_PINTE0=1;//��ʱ���ж�ͨ��0 �ж�ʹ��
  PITCFLMT_PITE=1;//��ʱ��ͨ��0 ʹ��
  
  PITLD1=5000-1;//16 λ��ʱ����ֵ�趨��2ms���
  PITCE_PCE1=1;//��ʱ��ͨ��1 ʹ��
  PITINTE_PINTE1=0; //��ʱ���ж�ͨ��1 �ж�
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