/**
 * @file GPIO_program.c
 * @brief Implementation of GPIO functions for ATMEGA32A microcontroller.
 * 
 * This file contains the implementation of GPIO functions, including setting
 * port/pin directions, setting port/pin values, and reading port/pin values.
 * 
 * @author Abdelrahman Nassar
 * @date 2025-05-27
 */
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "../atmega32.h"
#include "GPIO_interface.h"


void GPIO_vSetPortDirection(GPIO_t* Copy_pGpio, GPIO_Direction_t Copy_u8Direction)
{
    
    assert_param(IS_GPIO_VALID(Copy_pGpio));
    
	if( Copy_u8Direction == OUTPUT )
	{
		Copy_pGpio->DDR = 0xff;
	}
	else if (Copy_u8Direction == INPUT_FLOATING)
	{
		Copy_pGpio->DDR = 0;
		Copy_pGpio->PORT = 0;
	}
	else if (Copy_u8Direction == INPUT_PULLUP)
	{
		Copy_pGpio->DDR = 0;
		Copy_pGpio->PORT = 0xff;
	}
}


void GPIO_vSetPortValue(GPIO_t* Copy_pGpio, GPIO_Output_t Copy_u8Value)
{
    
    assert_param(IS_GPIO_VALID(Copy_pGpio));
    if(Copy_u8Value == HIGH)
		Copy_pGpio->PORT = 0xff;
	else
		Copy_pGpio->PORT = 0;
}


void GPIO_vSetPinDirection(GPIO_t* Copy_pGpio, GPIO_Pins_t Copy_u8PinNumber, GPIO_Direction_t Copy_u8Direction)
{
    
    assert_param(IS_GPIO_VALID(Copy_pGpio) && IS_GPIO_PIN_VALID(Copy_u8PinNumber) && IS_GPIO_DIRECTION_VALID(Copy_u8Direction));
        if (Copy_u8Direction == OUTPUT)
        {
            SET_BIT(Copy_pGpio->DDR, Copy_u8PinNumber);
        }
        else if (Copy_u8Direction == INPUT_FLOATING)
        {
            CLR_BIT(Copy_pGpio->DDR, Copy_u8PinNumber);
            CLR_BIT(Copy_pGpio->PORT,Copy_u8PinNumber);
        }
        else if( Copy_u8Direction == INPUT_PULLUP)
        {
            CLR_BIT(Copy_pGpio->DDR, Copy_u8PinNumber);
            SET_BIT(Copy_pGpio->PORT,Copy_u8PinNumber);
        }
    }



void GPIO_vSetPinValue(GPIO_t* Copy_pGpio, GPIO_Pins_t Copy_u8PinNumber, GPIO_Output_t Copy_u8Value)
{
    
    assert_param(IS_GPIO_VALID(Copy_pGpio) && IS_GPIO_PIN_VALID(Copy_u8PinNumber) && IS_GPIO_OUTPUT_VALID(Copy_u8Value));
    
        if (Copy_u8Value == HIGH)
        {
            SET_BIT(Copy_pGpio->PORT, Copy_u8PinNumber);
        }
        else if (Copy_u8Value == LOW)
        {
            CLR_BIT(Copy_pGpio->PORT, Copy_u8PinNumber);
        }
    }


u8 GPIO_u8GetPortValue(GPIO_t* Copy_pGpio)
{
    
    assert_param(IS_GPIO_VALID(Copy_pGpio));
	return Copy_pGpio->PIN;
    
}


u8 GPIO_u8GetPinValue(GPIO_t* Copy_pGpio, GPIO_Pins_t Copy_u8PinNumber)
{
    
    assert_param( IS_GPIO_VALID(Copy_pGpio) && IS_GPIO_PIN_VALID(Copy_u8PinNumber) );
    
        return GET_BIT(Copy_pGpio->PIN, Copy_u8PinNumber);

}
