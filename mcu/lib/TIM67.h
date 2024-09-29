// Luke Summers lsummers@g.hmc.edu
// TIM67.h
// Header for timer 6 and 7

#ifndef TIM67_H
#define TIM67_H

#include <stdint.h> // Include stdint header
#include "GPIO.h"

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

// Base addresses for TIM6 and TIM7 ports
#define TIM6_BASE (0x40001000UL)
#define TIM7_BASE (0x40001400UL)

///////////////////////////////////////////////////////////////////////////////
// Bitfield struct for GPIO
///////////////////////////////////////////////////////////////////////////////

// TIM6 and TIM7 register structs here
typedef struct {
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t res1;
  volatile uint32_t DIER;
  volatile uint32_t SR;
  volatile uint32_t EGR;
  volatile uint32_t res2;
  volatile uint32_t res3;
  volatile uint32_t res4;
  volatile uint32_t CNT;
  volatile uint32_t PSC;
  volatile uint32_t ARR;
} TIM67;
// Pointers to GPIO-sized chunks of memory for each peripheral
#define TIM6 ((TIM67 *) TIM6_BASE)
#define TIM7 ((TIM67 *) TIM7_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void enableCounter(TIM67* TIM);
void delay(TIM67* TIM, int ms);
void resetFlag(TIM67* TIM);
void resetCount(TIM67* TIM);
void setPrsc(TIM67* TIM, uint32_t val);
void setArr(TIM67* TIM, uint32_t val);
void genSqWave(int freq, int dur, int pin, GPIO* GPIO, TIM67 *TIM1, TIM67* TIM2);

#endif
