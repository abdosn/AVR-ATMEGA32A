/*
 * EXTI_private.h
 *
 *  Created on: 25 Aug 2021
 *      Author: mymorning017
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#define NULL 0


#define GICR_REG   *((volatile u8 *)0x5B)
#define GIFR_REG   *((volatile u8 *)0x5A)
#define MCUCR_REG  *((volatile u8 *)0x55)
#define MCUCSR_REG *((volatile u8 *)0x54)


void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));

#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
