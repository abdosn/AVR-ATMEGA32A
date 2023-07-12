/*
 * EXTI_interface.h
 *
 *  Created on: 25 Aug 2021
 *      Author: mymorning017
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_


#define EXTI_LINE_0   		0
#define EXTI_LINE_1   		1
#define EXTI_LINE_2			2


#define EXTI_FALLING_EDGE	0
#define EXTI_RISING_EDGE	1
#define EXTI_LOW_LEVEL		2
#define EXTI_ON_CHANGE		3


#define EXTI_INPUT_PULLUP   0
#define EXTI_INPUT_FLOATING 1

void EXTI_voidInit();

void EXTI_voidEnable(u8 Copy_u8Line , u8 Copy_u8SenseMode);
void EXTI_voidDisable(u8 Copy_u8Line);
void EXTI_voidClearFlag(u8 Copy_u8Line);
void EXTI_voidSetCallBack(  u8 Copy_u8Line , void(* Copy_pvoidCallBack)(void));

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
