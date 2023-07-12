/*
 * EXTI_config.h
 *
 *  Created on: 25 Aug 2021
 *      Author: mymorning017
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

/*
 * EXTI_LINE options:-
 *
 * 1-EXTI_LINE_0
 * 2-EXTI_LINE_1
 * 3-EXTI_LINE_2
 *
 */

#define EXTI_LINE     EXTI_LINE_0


/*
 * EXTI_SENSE_MODE options:-
 *
 * 1-EXTI_FALLING_EDGE
 * 2-EXTI_RISING_EDGE
 * 3-EXTI_LOW_LEVEL
 * 4-EXTI_ON_CHANGE
 *
 */


#define EXTI_SENSE_MODE     EXTI_FALLING_EDGE

/*
 * EXTI_INPUT_MODE options:-
 *
 * 1-EXTI_INPUT_PULLUP
 * 2-EXTI_INPUT_FLOATING
 *
 */

#define EXTI_INPUT_MODE EXTI_INPUT_PULLUP


#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
