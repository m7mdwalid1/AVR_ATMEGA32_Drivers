/*
 * Buzzer_program.c
 *
 *  Created on: Oct 8, 2022
 *      Author: mhmd waleed
 */
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../../../MCAL/DIO/HEADER/DIO_interface.h"
#include "../HEADER/Buzzer_interface.h"

u8 Buzzer_U8Init(u8 Local_Port , u8 Local_Pin)
{
 	return DIO_u8SetPinDirection(Local_Port,Local_Pin,PIN_OUTPUT);
}
u8 Buzzer_U8on(u8 Local_Port , u8 Local_Pin)
{
	return DIO_u8SetPinValue(Local_Port,Local_Pin,DIO_HIGH);
}
u8 Buzzer_U8off(u8 Local_Port , u8 Local_Pin)
{
	return DIO_u8SetPinValue(Local_Port,Local_Pin,DIO_LOW);
}
