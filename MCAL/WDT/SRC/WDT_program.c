/*
 * WDT_program.c
 *
 *  Created on: Dec 13, 2022
 *      Author: mhmd waleed
 */
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../HEADER/WDT_inrterface.h"
#include "../HEADER/WDT_register.h"






void WDT_voidSleep(u8 Local_u8SleepTime)
{
	/*Clear The prescaler Mask*/
	WDTCR &= 0b11111000;

	/*Set the requered prescaler*/
	WDTCR |= Local_u8SleepTime;
}
void WDT_voidEnable(void)
{
	SET_BIT(WDTCR,WDTCR_WDE);
}
void WDT_voidDisable(void)
{
	WDTCR |= 0b00011000;
	WDTCR=0;
}

