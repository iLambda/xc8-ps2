# xc8-ps2
A xc8 library for PIC16-18f to simulate the behaviour of any PS/2 controller.

To use in a project, add :
```c
#include "ps2.h"
```
**⚠️IMPORTANT⚠️** You MUST redefine \_XTAL\_FREQ in ps2.h for the program to work at the correct clock speed.

## api

The following methods are available:

#### ps2_init
```c
void ps2_init(uint8_t* datapin, uint8_t databit, uint8_t* clockpin, uint8_t clockbit);
```
Initialize the ps2 simulator. **datapin** and **clockpin** should respectively point to the registers describing the states of the chosen data output pin (respectively clock output pin) ; for instance, *&PORTA*. **databit** et **clockbit** should respectively be the number of the bit representing the chosen data output pin (respectively clock output pin) inside the corresponding register ; for instance, *databit == 3* would represent the third bit of the **databit** register.

#### ps2_send
```c
void ps2_send(uint8_t buffer);
```
Send a message to the PS/2 output. Its duration is 2\*10\*PS2_CLOCK_LENGTH_HALF, or 10\*PS2_CLOCK_LENGTH.
**PS2_CLOCK_LENGTH_HALF** is defined at line 9 of ps2.h.

A list of keycodes be found [here](http://www.computer-engineering.org/ps2keyboard/scancodes2.html).
