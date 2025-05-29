/*
 * GIE_program.c
 *
 *  Created on: 26 Aug 2021
 *      Author: mymorning017
 */

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_private.h"



void GIE_voidEnable(void){

	SET_BIT(SREG_REG , 7); //Enable GIE

}

void GIE_voidDisable(void){


	CLR_BIT(SREG_REG , 7); //Disable GIE

}
