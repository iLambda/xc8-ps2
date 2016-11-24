#define _XTAL_FREQ  48000000

#include <xc.h>
#include "../inc/ps2.h"

void main(void) {  
  // setup I/O
  ADCON1 = 0x0F;
  TRISB = 0x00;
  PORTB = 0x00;
  
  // setup XC8-PS2
  ps2_init(&PORTB, 7, &PORTB, 6);

  // program loop
  while(1) {
    // send msg
    ps2_send(0x1C);   // send make key 'a'
    // wait
    __delay_ms(10);
    // send msg
    ps2_send(0xF0);   // send break code
    ps2_send(0x1C);   // send break key 'a'
    // wait
    __delay_ms(10);
  }
}
