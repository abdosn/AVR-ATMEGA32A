/*
 * EXTI_program.c
 *
 *  Created on: 25 Aug 2021
 *      Author: mymorning017
 */

#include "SERVICES/STD_TYPES.h"
#include "SERVICES/BIT_MATH.h"

#include "GPIO/GPIO_interface.h"

#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"

void (* EXTI_CallBack[3])(void) = {NULL};


void EXTI_voidInit(void){




}

void EXTI_voidEnable(u8 Copy_u8Line , u8 Copy_u8SenseMode){



	switch( Copy_u8Line ){       //Enable PIE

	case EXTI_LINE_0:
	{
		GPIO_enSetPinDirection( GPIOD , Pin2 , INPUT_PULLUP );

		switch (Copy_u8SenseMode ){

		case EXTI_FALLING_EDGE:
		{
			CLR_BIT( MCUCR_REG , 0);
			SET_BIT( MCUCR_REG , 1);
			break;
		}
		case EXTI_RISING_EDGE:
		{
			SET_BIT( MCUCR_REG , 0 );
			SET_BIT( MCUCR_REG , 1 );
			break;
		}
		case EXTI_LOW_LEVEL:
		{
			CLR_BIT( MCUCR_REG , 0);
			CLR_BIT( MCUCR_REG , 1);
			break;
		}
		case EXTI_ON_CHANGE:
		{
			SET_BIT( MCUCR_REG , 0);
			CLR_BIT( MCUCR_REG , 1);
			break;
		}

		}
		SET_BIT(GICR_REG , 6 );
		break;
	}
	case EXTI_LINE_1:
	{
		GPIO_enSetPinDirection( GPIOD , Pin3 , INPUT_PULLUP );

		switch (Copy_u8SenseMode ){

		case EXTI_FALLING_EDGE:
		{
			CLR_BIT( MCUCR_REG , 2);
			SET_BIT( MCUCR_REG , 3);
			break;
		}
		case EXTI_RISING_EDGE:
		{
			SET_BIT( MCUCR_REG , 2 );
			SET_BIT( MCUCR_REG , 3 );
			break;
		}
		case EXTI_LOW_LEVEL:
		{
			CLR_BIT( MCUCR_REG , 2);
			CLR_BIT( MCUCR_REG , 3);
			break;
		}
		case EXTI_ON_CHANGE:
		{
			SET_BIT( MCUCR_REG , 2);
			CLR_BIT( MCUCR_REG , 3);
			break;
		}

		}
		SET_BIT(GICR_REG , 7 );
		break;
	}
	case EXTI_LINE_2:
	{
		GPIO_enSetPinDirection( GPIOB , Pin2 , INPUT_PULLUP );
		switch (Copy_u8SenseMode ){

		case EXTI_FALLING_EDGE:
		{
			CLR_BIT( MCUCSR_REG , 6);
			break;
		}
		case EXTI_RISING_EDGE:
		{
			SET_BIT( MCUCSR_REG , 6 );
			break;
		}


		}

		SET_BIT(GICR_REG , 5 );
		break;
	}

	}




}

void EXTI_voidDisable(u8 Copy_u8Line){

	switch (Copy_u8Line){

	case EXTI_LINE_0:
	{
		CLR_BIT(GICR_REG , 6 );
		break;
	}
	case EXTI_LINE_1:
	{
		CLR_BIT(GICR_REG , 7 );
		break;
	}
	case EXTI_LINE_2:
	{
		CLR_BIT(GICR_REG , 5 );
		break;
	}

	}

}

void EXTI_voidClearFlag(u8 Copy_u8Line){

	switch (Copy_u8Line){

	case EXTI_LINE_0:
	{
		SET_BIT(GIFR_REG , 6 );
		break;
	}
	case EXTI_LINE_1:
	{
		SET_BIT(GIFR_REG , 7 );
		break;
	}
	case EXTI_LINE_2:
	{
		SET_BIT(GIFR_REG , 5 );
		break;
	}

	}

}

void EXTI_voidSetCallBack(  u8 Copy_u8Line , void(* Copy_pvoidCallBack)(void) ){

	if( Copy_pvoidCallBack != NULL )
	{
		EXTI_CallBack[ Copy_u8Line ] = Copy_pvoidCallBack ;
	}
}


void __vector_1(void){

	EXTI_CallBack[0]();

}

void __vector_2(void){

	EXTI_CallBack[1]();

}

void __vector_3(void){

	EXTI_CallBack[2]();

}
