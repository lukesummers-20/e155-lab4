// Luke Summers lsummers@g.hmc.edu
// implimentation for TIM67.h

#include "TIM67.h"
#include "GPIO.h"

void enableCounter(TIM67* TIM) {
  TIM->CR1 |= (1 << 0);
}

void resetFlag(TIM67* TIM) {
  TIM->SR &= ~(1 << 0);
}

void resetCount(TIM67* TIM) {
  TIM->CNT = 0;
}

void setPrsc(TIM67 *TIM, uint32_t val) {
  TIM->PSC = val;
}

void setArr(TIM67 *TIM, uint32_t val) {
  TIM->ARR = val;
}

void delay(TIM67* TIM, int ms) {
  setArr(TIM, ms);
  resetFlag(TIM);
  resetCount(TIM);
  // wait on counter overflow
  while (!(TIM->SR)) {}
}

void genSqWave(int freq, int dur, int pin, GPIO* GPIO, TIM67 *TIM1, TIM67* TIM2) {
  if (freq == 0) {
    delay(TIM1, dur);
  } else {
    setArr(TIM1, dur);
    setArr(TIM2, 1000000 / (2 * freq));
    resetFlag(TIM1);
    resetFlag(TIM2);
    resetCount(TIM1);
    resetCount(TIM2);
    // wait on counter overflow
    while (!(TIM1->SR)) {
      digitalWrite(pin, 1, GPIO);
      // wait on counter overflow
      while (!(TIM2->SR)) {}
      resetFlag(TIM2);
      digitalWrite(pin, 0, GPIO);
      // wait on counter overflow
      while (!(TIM2->SR)) {}
      resetFlag(TIM2);
    }
  }
}