# xc8-ps2
A xc8 library for PIC16-18f to simulate the behaviour of any PS/2 controller.

To use in a project, just add :
```c
#include "ps2simulator.h"
```

## api

The following methods are available:

#### ps2sim_init
```c
void ps2sim_init(unsigned char* datapin, unsigned char databit, unsigned char* clockpin, unsigned char clockbit);
```
Initialize the ps2 simulator. **datapin** and **clockpin** should respectively point to the registers describing the states of the chosen data output pin (respectively clock output pin) ; for instance, *&PORTA*. **databit** et **clockbit** should respectively be the number of the bit representing the chosen data output pin (respectively clock output pin) inside the corresponding register ; for instance, *databit == 3* would represent the third bit of the **databit** register.

#### ps2sim_send
```c
void ps2sim_send(unsigned char buffer);
```
Send a message to the PS/2 output. Its duration is 2\*10\*CLOCK_LENGTH_2.
**CLOCK_LENGTH_2** is defined at line 4 of ps2simulator.h.

A list of keycodes be found [here](http://www.computer-engineering.org/ps2keyboard/scancodes2.html).
