// Luke Summers lsummers@g.hmc.edu
// implementation for RCC.h

#include "RCC.h"

void enableBasicTimer(RCC_type* RCC_in, int num) {
  if (num == 6) {
    RCC_in->APB1ENR1 |= (1 << 4);
  } else {
    RCC_in->APB1ENR1 |= (1 << 5);
  }
}

void enableGPIO(RCC_type* RCC_in, int num) {
  switch(num) {
    case 0: // GPIO A
      RCC_in->AHB2ENR |= (1 << 0);
      break;
    case 1: // GPIO B
      RCC_in->AHB2ENR |= (1 << 1);
    case 2: // GPIO C
      RCC_in->AHB2ENR |= (1 << 2);
    case 3: // GPIO D
      RCC_in->AHB2ENR |= (1 << 3);
    case 4: // GPIO E
      RCC_in->AHB2ENR |= (1 << 4);
  }
}