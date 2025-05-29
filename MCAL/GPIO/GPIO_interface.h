/**
 * @file GPIO_interface.h
 * @brief Interface of GPIO functions for ATMEGA32A microcontroller.
 * 
 * This file contains the interface of GPIO functions, including setting
 * port/pin directions, setting port/pin values, and reading port/pin values.
 * 
 * @author Abdelrahman Nassar
 * @date 2025-05-27
 */

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "../atmega32.h"


/**
 * @brief GPIO direction options.
 * 
 * This enum defines the possible directions for GPIO pins or ports:
 * - INPUT_FLOATING: Input without pull-up.
 * - INPUT_PULLUP: Input with pull-up enabled.
 * - OUTPUT: Output mode.
 */
typedef enum 
{
    INPUT_FLOATING, /**< Input without pull-up */
    INPUT_PULLUP,   /**< Input with pull-up enabled */
    OUTPUT          /**< Output mode */
} GPIO_Direction_t;

#define IS_GPIO_DIRECTION_VALID(DIR) (((DIR) == (OUTPUT)) || ((DIR) == (INPUT_FLOATING)) || ((DIR) == (INPUT_PULLUP)))

/**
 * @brief GPIO output value options.
 * 
 * This enum defines the possible output values for GPIO pins or ports:
 * - LOW: Logic low (0).
 * - HIGH: Logic high (1).
 */
typedef enum 
{
    LOW,  /**< Logic low (0) */
    HIGH  /**< Logic high (1) */
} GPIO_Output_t;

#define IS_GPIO_OUTPUT_VALID(OUT) (((OUT) == (LOW)) || ((OUT) == (HIGH)))


#define IS_GPIO_VALID(PERIPH) ( ((PERIPH) == (GPIOA)) || \
                                ((PERIPH) == (GPIOB)) || \
                                ((PERIPH) == (GPIOC)) || \
                                ((PERIPH) == (GPIOD)) )

/**
 * @brief GPIO pin options.
 * 
 * This enum defines the possible pin numbers for GPIO ports:
 * - Pin0 to Pin7: Correspond to the 8 pins of a GPIO port.
 */
typedef enum 
{
    Pin0, /**< Pin 0 */
    Pin1, /**< Pin 1 */
    Pin2, /**< Pin 2 */
    Pin3, /**< Pin 3 */
    Pin4, /**< Pin 4 */
    Pin5, /**< Pin 5 */
    Pin6, /**< Pin 6 */
    Pin7  /**< Pin 7 */
} GPIO_Pins_t;

#define IS_GPIO_PIN_VALID(PIN) 	( ((PIN) >= (Pin0)) && ((PIN) <= (Pin7)) )

/* Function Prototypes */

/**
 * @brief Sets the direction of an entire GPIO port.
 * 
 * @param Copy_pGpio Pointer to the GPIO port structure - can be a value from @ref GPIO_Registers.
 * @param Copy_u8Direction Desired direction (OUTPUT, INPUT_FLOATING, INPUT_PULLUP). See @ref GPIO_Direction_t.
 */
void GPIO_vSetPortDirection(GPIO_t* Copy_pGpio, GPIO_Direction_t Copy_u8Direction);

/**
 * @brief Sets the output value of an entire GPIO port.
 * 
 * @param Copy_pGpio Pointer to the GPIO port structure - can be a value from @ref GPIO_Registers.
 * @param Copy_u8Value Desired output value (HIGH or LOW). See @ref GPIO_Output_t.
 */
void GPIO_vSetPortValue(GPIO_t* Copy_pGpio, GPIO_Output_t Copy_u8Value);

/**
 * @brief Sets the direction of a specific GPIO pin.
 * 
 * @param Copy_pGpio Pointer to the GPIO port structure - can be a value from @ref GPIO_Registers.
 * @param Copy_u8PinNumber Pin number to configure. See @ref GPIO_Pins_t.
 * @param Copy_u8Direction Desired direction (OUTPUT, INPUT_FLOATING, INPUT_PULLUP). See @ref GPIO_Direction_t.
 */
void GPIO_vSetPinDirection(GPIO_t* Copy_pGpio, GPIO_Pins_t Copy_u8PinNumber, GPIO_Direction_t Copy_u8Direction);

/**
 * @brief Sets the output value of a specific GPIO pin.
 * 
 * @param Copy_pGpio Pointer to the GPIO port structure - can be a value from @ref GPIO_Registers.
 * @param Copy_u8PinNumber Pin number to configure. See @ref GPIO_Pins_t.
 * @param Copy_u8Value Desired output value (HIGH or LOW). See @ref GPIO_Output_t.
 */
void GPIO_vSetPinValue(GPIO_t* Copy_pGpio, GPIO_Pins_t Copy_u8PinNumber, GPIO_Output_t Copy_u8Value);

/**
 * @brief Reads the input value of an entire GPIO port.
 * 
 * @param Copy_pGpio Pointer to the GPIO port structure - can be a value from @ref GPIO_Registers.
 * @return The value of the input register (PIN) for the specified port.
 */
u8 GPIO_u8GetPortValue(GPIO_t* Copy_pGpio);

/**
 * @brief Reads the input value of a specific GPIO pin.
 * 
 * @param Copy_pGpio Pointer to the GPIO port structure - can be a value from @ref GPIO_Registers.
 * @param Copy_u8PinNumber Pin number to read. See @ref GPIO_Pins_t.
 * @return The value of the specified pin (0 or 1).
 */
u8 GPIO_u8GetPinValue(GPIO_t* Copy_pGpio, GPIO_Pins_t Copy_u8PinNumber);

#endif
