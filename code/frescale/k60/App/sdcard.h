#include "common.h"
#include "port_cfg.h"
#include "include.h"
#include "init.h"
void spi_clock(int num);
void sd_delay();
void card_command_0();
void card_command_8() ;
void card_command_58() ;
void spi_command(int commandid, int arg1, int arg2, int arg3, int arg4,int crc);
void test_write();
void card_char_write(char a);
void test_read();
void card_init();
