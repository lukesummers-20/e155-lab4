// Luke Summers lsummers@g.hmc.edu
// header file for GPIO

#ifndef GPIO_H
#define GPIO_H

#include <stdint.h> // Include stdint header

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

// Values for GPIO pins ("val" arguments)
#define GPIO_LOW    0
#define GPIO_HIGH   1

// Base addresses for GPIO ports
#define GPIOA_BASE (0x48000000UL)
#define GPIOB_BASE  (0x48000400UL)
#define GPIOC_BASE  (0x48000800UL)
#define GPIOD_BASE  (0x48000C00UL)
#define GPIOE_BASE  (0x48001000UL)

// Arbitrary GPIO functions for pinMode()
#define GPIO_INPUT  0
#define GPIO_OUTPUT 1
#define GPIO_ALT    2
#define GPIO_ANALOG 3

///////////////////////////////////////////////////////////////////////////////
// Bitfield struct for GPIO
///////////////////////////////////////////////////////////////////////////////

// GPIO register structs here
typedef struct {
    volatile uint32_t MODER;   // GPIO Offset 0x00 GPIO port mode register
    volatile uint32_t OTYPER;  // GPIO Offset 0x04
    volatile uint32_t OSPEEDR; // GPIO Offset 0x08
    volatile uint32_t PURPDR;  // GPIO Offset 0x0C
    volatile uint32_t IDR;     // GPIO Offset 0x10
    volatile uint32_t ODR;     // GPIO Offset 0x14
    volatile uint32_t BSRR;    // GPIO Offset 0x18
    volatile uint32_t LCKR;    // GPIO Offset 0x1C
    volatile uint32_t AFRL;    // GPIO Offset 0x20
    volatile uint32_t AFRH;    // GPIO Offset 0x24
} GPIO;

// Pointers to GPIO-sized chunks of memory for each peripheral
#define GPIOA ((GPIO *) GPIOA_BASE)
#define GPIOB ((GPIO *) GPIOB_BASE)
#define GPIOC ((GPIO *) GPIOC_BASE)
#define GPIOD ((GPIO *) GPIOD_BASE)
#define GPIOE ((GPIO *) GPIOE_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void pinMode(int pin, int function, GPIO* GPIO);

int digitalRead(int pin, GPIO* GPIO);

void digitalWrite(int pin, int val, GPIO* GPIO);

void togglePin(int pin, GPIO* GPIO);

void enablePullUp(int pin, GPIO* GPIO);

#endif