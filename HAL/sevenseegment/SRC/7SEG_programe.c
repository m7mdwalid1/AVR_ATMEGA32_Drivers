/*
 * 7SEG_programe.c
 *
 *  Created on: Aug 22, 2022
 *      Author: mhmd waleed
 */
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../HEADER/7SEG_interface.h"
#include "../HEADER/7SEG_private.h"
#include "../../led/HEADER/LED_interface.h"
/*
 * Prototype   : u8 H7SEG_u8Init(u8 Local_u8Port);
 * Description : Initialize one 7-Segment of 8 LEDs on specific port
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 H7SEG_u8Init(u8 Local_u8Port)
{
	/*initialize 7-segment led string at desired port and return error value*/
	return HLED_u8InitLedString(Local_u8Port);

} /*end of H7SEG_u8Init()*/

/*
 * Prototype   : u8 H7SEG_u8DisplayNumber(u8 Local_u8Port,u8 Local_u8DisblayNumber)
 * Description : Display a number on a given 7-segment
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *               Number  : takes only from 0 to 9
 * return      : u8 number for error handling
 *               (0) means no error, (1) means Undefined PORT, (2) means Display Number out of range error
 */
u8 H7SEG_u8DisplayNumber(u8 Local_u8Port, u8 Local_u8DisblayNumber)
{
	/*Disblay Number check condition*/
	if ((Local_u8DisblayNumber >= 0) || (Local_u8DisblayNumber < 10))
	{
		/*Disblay number from seven segment array and return error value*/
		return HLED_u8LedStringOnOff(Local_u8Port, H7SEG_u8SevenSegArray[Local_u8DisblayNumber]);
	}
	else
	{
		/*Disblay Number out of range error*/
		return 2;

	} /*End of Disblay Number check condition*/

}

