#ifndef XC8_PS2_
#define XC8_PS2_

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define _XTAL_FREQ  48000000

#define PS2_CLOCK_LENGTH_HALF 35
#define PS2_CLOCK_LENGTH      2*PS2_CLOCK_LENGTH_HALF

static uint8_t* data_pin = NULL;
static uint8_t* clock_pin = NULL;
static uint8_t data_bit = 0;
static uint8_t clock_bit = 0;

void ps2_init(uint8_t* datapin, uint8_t databit, uint8_t* clockpin, uint8_t clockbit);
void ps2_send(uint8_t buffer);

#endif