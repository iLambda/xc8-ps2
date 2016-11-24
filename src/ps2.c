#include "../inc/ps2.h" 


void ps2sim_setdata(unsigned char value) {
  if (value) {
    *data_pin |= 1 << data_bit;
  } else {
    *data_pin &= ~(1 << data_bit);
  }
}

void ps2sim_setclock(unsigned char value) {
  if (value) {
    *clock_pin |= 1 << clock_bit;
  } else {
    *clock_pin &= ~(1 << clock_bit);
  }
  __delay_us(5);
} 

void ps2sim_init(unsigned char* datapin, unsigned char databit, unsigned char* clockpin, unsigned char clockbit) {
    // gather data_pin and clock_pin
    data_pin = datapin;
    data_bit = databit;
    clock_pin = clockpin;
    clock_bit = clockbit;
    // default them to high
    ps2sim_setclock(1);
    ps2sim_setdata(1);
}

void ps2sim_send(unsigned char buffer) {
  // put the clock and the data down
  ps2sim_setclock(1);
  ps2sim_setdata(0);
  __delay_us(PS2_CLOCK_LENGTH_HALF);
  ps2sim_setclock(0);
  ps2sim_setdata(0);
  __delay_us(PS2_CLOCK_LENGTH_HALF);
  
  // start sending bits
  uint8_t i = 0;
  uint8_t parity = 0xFF;
  while (i < 8) {
    // set clock up
    ps2sim_setclock(1);
    // getting the right bit
    uint8_t tempbit = buffer & (1 << i);
    parity = tempbit ? ~parity : parity;
    ps2sim_setdata(tempbit);
    __delay_us(PS2_CLOCK_LENGTH_HALF);
    // down
    ps2sim_setclock(0);
    __delay_us(PS2_CLOCK_LENGTH_HALF);
    // increment
    i++;
  }

  // parity bit
  ps2sim_setclock(1);
  ps2sim_setdata(parity);
  __delay_us(PS2_CLOCK_LENGTH_HALF);
  ps2sim_setclock(0);
  __delay_us(PS2_CLOCK_LENGTH_HALF);

  // end
  ps2sim_setclock(1);
  ps2sim_setdata(1);
  __delay_us(PS2_CLOCK_LENGTH_HALF);
  ps2sim_setclock(0);
  ps2sim_setdata(1);
  __delay_us(PS2_CLOCK_LENGTH_HALF);

  // put line back to high
  ps2sim_setclock(1);
  ps2sim_setdata(1);
}
