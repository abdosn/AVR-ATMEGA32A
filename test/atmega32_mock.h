#ifndef ATMEGA32_MOCK_H_
#define ATMEGA32_MOCK_H_

#include "../MCAL/atmega32.h"
// Mock instances for GPIO registers
static GPIO_t MockGPIOA = {0};  // Mock GPIOA
static GPIO_t MockGPIOB = {0};  // Mock GPIOB
static GPIO_t MockGPIOC = {0};  // Mock GPIOC
static GPIO_t MockGPIOD = {0};  // Mock GPIOD

#undef GPIOA_BASE_ADDR
#undef GPIOB_BASE_ADDR
#undef GPIOC_BASE_ADDR
#undef GPIOD_BASE_ADDR

#define GPIOA_BASE_ADDR (&MockGPIOA)
#define GPIOB_BASE_ADDR (&MockGPIOB)
#define GPIOC_BASE_ADDR (&MockGPIOC)
#define GPIOD_BASE_ADDR (&MockGPIOD)




#endif // ATMEGA32_MOCK_H_