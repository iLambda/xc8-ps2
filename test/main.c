#define _XTAL_FREQ  48000000

#include <xc.h>
#include "../inc/ps2.h"

void main(void) {  
  // setup I/O
  ADCON1 = 0x0F;
  TRISB = 0x00;
  PORTB = 0x00;
  
  // setup XC8-PS2
  ps2_init(&PORTB, (1 << 7), &PORTB, (1 << 6));
  
  // send messages
  ps2_send(0x02); 
  ps2_send(0x04);
  ps2_send(0x06); 
  
  // program loop
  while(1);
}
