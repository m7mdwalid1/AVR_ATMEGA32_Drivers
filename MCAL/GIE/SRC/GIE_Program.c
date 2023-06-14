/*
 * GIE_Program.c
 *
 *  Created on: May 6, 2022
 *      Author: MoWael
 */
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../Header/GIE_Register.h"
#include "../Header/GIE_Interface.h"


void GIE_VoidEnable(void)
{
	SET_BIT(SREG,I);
}


void GIE_VoidDisable(void)
{
	CLEAR_BIT(SREG,I);
}

