#include "sdcard.h"
int SPI_SCLK = 15;
int SPI_CS = 14;
int SPI_MISO = 17;
unsigned long long a=1;
int SPI_MOSI = 16;

void pin_SPI_SCLK_HIGH(){
  pin_SDCARD_CLK=1;}
void pin_SPI_SCLK_LOW(){
  pin_SDCARD_CLK=0;}
void pin_SPI_CS_HIGH(){
  pin_SDCARD_CS=1;}
void pin_SPI_CS_LOW(){
  pin_SDCARD_CS=0;}
void pin_MOSI_HIGH(){
  pin_SDCARD_MOSI=1;}
void pin_MOSI_LOW(){
  pin_SDCARD_MOSI=0;}
void setup() {
     gpio_init (pin_SDCARD_CLK_init, GPO,LOW);
   gpio_init (pin_SDCARD_CS_init, GPO,HIGH);
   gpio_init (pin_SDCARD_MOSI_init, GPO,HIGH);
   gpio_init (pin_SDCARD_MISO_init, GPI,LOW);
  pin_SPI_SCLK_LOW();
  pin_SPI_CS_HIGH();
  pin_MOSI_HIGH();
  
  card_init();
  DELAY_MS(100);
  //test_write();
//test_erase();
 // test_write(); 
   DELAY_MS(100);
  test_read();
  
   
  
  // put your setup code here, to run once:

}
void card_init(){



  pin_SPI_CS_LOW();
  pin_MOSI_HIGH();
  for(int i=0;i<500;i++){
    spi_read();}
   card_command_0();
  //DELAY_MS(10);
   card_command_0();
  // DELAY_MS(10);
   card_command_8();
  // DELAY_MS(10);
   while(card_acommand_41()==1){DELAY_MS(100);}
   card_command_58();
  // DELAY_MS(10);
   //card_command_10();
   //card_write();
  pin_SPI_CS_HIGH();
//  
  }
  
void card_command_0(){
  //digitalWrite(SPI_CS,LOW)
  spi_command(0,0,0,0,0,0x95);
  pin_MOSI_HIGH();
  while(spi_read()!=1){}
  
  
  
  }

void card_command_8(){
  //digitalWrite(SPI_CS,LOW)
  spi_command(8,0,0,0x01,0xAA,0x87);
  pin_MOSI_HIGH();
  while(spi_read()!=1){}
  
    for(int i=0;i<4;i++){
    spi_read();}
  
  
  }

void card_command_58(){//read OCR register
  //digitalWrite(SPI_CS,LOW)
  spi_command(58,0,0,0,0,0xff);
  pin_MOSI_HIGH();
  while(spi_read()!=0){}
    for(int i=0;i<4;i++){
    spi_read();}
  }

void card_command_10(){//read CID register
  //digitalWrite(SPI_CS,LOW)
  spi_command(10,0,0,0,0,0xff);
  pin_MOSI_HIGH();
  while(spi_read()!=0){}
  
    for(int i=0;i<19;i++){
    spi_read();}
  
  
  }
void card_command_55(){
  //digitalWrite(SPI_CS,LOW)
  spi_command(55,0,0,0,0,0xff);
  pin_MOSI_HIGH();
  while(spi_read()!=1){}
  }
int card_acommand_41(){
  card_command_55();
  spi_command(41,0x40,0,0,0,0xff);
  pin_MOSI_HIGH();
  int temp;
  while(1){
    temp=spi_read();
    if(temp==1){
      return 1;
      
      }
      if(temp==0){
      return 0;
      
      }}
  
  }
void spi_delay_short() {
  //DELAY_MS(1);
}
void spi_delay_long() {
 // DELAY_MS(1);
}
int spi_read(){
  int result=0;
  for(int i=0;i<8;i++){
    result=result<<1;
    result|=pin_SDCARD_MISO;
    pin_SPI_SCLK_HIGH();
   // DELAY_US(500);
    pin_SPI_SCLK_LOW();
   // DELAY_US(500);
    }
    spi_delay_long();
    return result;
  }
void spi_command(int commandid, int arg1, int arg2, int arg3, int arg4,int crc) {
  pin_MOSI_HIGH();
    for (int i = 0; i < 8; i++) {
    //digitalWrite(SPI_MOSI,1);
    pin_SPI_SCLK_HIGH();
  //  DELAY_US(500);

    pin_SPI_SCLK_LOW();
 //   DELAY_US(500);
    //rg4 = arg4 << 1;
  }

  spi_delay_long();
  int mcommand = commandid | 64;
  int temp1 = 0x80;
card_char_write(mcommand);
card_char_write(arg1);
card_char_write(arg2);
card_char_write(arg3);
card_char_write(arg4);
card_char_write(crc);
pin_MOSI_HIGH();
}

void card_read(){
  spi_command(17,0,0,0,1,0xff);
  while(spi_read()!=0){}
  while(spi_read()!=0xfe){}
    for(int i=0;i<512;i++){
    spi_read();}
  for(int i=0;i<2;i++){
    spi_read();}
  }
 
void card_write(){
  spi_command(24,0,0,0,1,0xff);
  while(spi_read()!=0){}
  card_char_write(0xfe);
   pin_MOSI_HIGH();
  char str []="WZQ is handsome!";
  int j=0;
    for(int i=0;i<512;i++){
     card_char_write(str[j]);
     j++;
     if(j>14){
      j=0;
      }
    }
    pin_MOSI_HIGH();
    while(spi_read()!=0xe5);
    while(spi_read()!=0xff);
  }
  
  void test_write(){
  pin_SPI_CS_LOW();
  card_write();
  pin_SPI_CS_HIGH();
  //spi_read();
  }
  
void card_char_write(char a){
  int temp1=0x80;
    for (int i = 0; i < 8; i++) {
      if(temp1 & a){pin_MOSI_HIGH();}
      else{pin_MOSI_LOW();}
      DELAY_US(500);
    //digitalWrite(SPI_MOSI, );
    pin_SPI_SCLK_HIGH();
 //   DELAY_US(500);
    pin_SPI_SCLK_LOW();
 //   DELAY_US(500);
    a = a << 1;
  }
  pin_MOSI_HIGH();
  spi_delay_long();
  }
  void card_erase(){
 spi_command(32,0,0,0,1,0xff);
  while(spi_read()!=0){}
   spi_command(33,0,0,0,1,0xff);
  while(spi_read()!=0){}
   spi_command(38,0,0,0,0,0xff);
  while(spi_read()!=0){}
    
    }
void test_read(){
  
  pin_SPI_CS_LOW();
  card_read();
  pin_SPI_CS_HIGH();
  }
void test_erase(){
  pin_SPI_CS_LOW();
  card_erase();
  pin_SPI_CS_HIGH();
  }