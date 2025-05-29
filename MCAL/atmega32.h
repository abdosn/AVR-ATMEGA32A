#ifndef ATMEGA32_H_
#define ATMEGA32_H_

#include <stdlib.h>
#include "../SERVICES/STD_TYPES.h"
#define USE_ASSERT
#ifdef USE_ASSERT
#define assert_param(expr) (expr) ? ((void)0) : (exit(EXIT_FAILURE))
#else
#define assert_param(expr) ((void)0)
#endif


/* Register Description */
/* GPIO */
#define GPIOA_BASE_ADDR (0x39)
#define GPIOB_BASE_ADDR (0x36)
#define GPIOC_BASE_ADDR (0x33)
#define GPIOD_BASE_ADDR (0x30)

/**
 * @brief GPIO register structure.
 * 
 * This structure represents the GPIO registers for a port, including:
 * - PIN: Input register.
 * - DDR: Data direction register.
 * - PORT: Output register.
 */
typedef struct 
{
    volatile u8 PIN;  /**< Input register */
    volatile u8 DDR;  /**< Data direction register */
    volatile u8 PORT; /**< Output register */
} GPIO_t;


/**
 * @defgroup GPIO_Registers GPIO Registers
 * @brief Definitions for GPIO port base addresses.
 * @{
 */
#define GPIOA ((GPIO_t *)GPIOA_BASE_ADDR) /**< GPIOA base address */
#define GPIOB ((GPIO_t *)GPIOB_BASE_ADDR) /**< GPIOB base address */
#define GPIOC ((GPIO_t *)GPIOC_BASE_ADDR) /**< GPIOC base address */
#define GPIOD ((GPIO_t *)GPIOD_BASE_ADDR) /**< GPIOD base address */
/** @} */


#endif