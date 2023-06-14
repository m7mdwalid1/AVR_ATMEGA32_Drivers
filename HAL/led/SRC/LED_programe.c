/*
 * LED_programe.c
 *
 *  Created on: Aug 22, 2022
 *      Author: mhmd waleed
 */
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"
#include "../../../MCAL/DIO/HEADER/DIO_interface.h"
#include "../../../HAL/led/HEADER/LED_interface.h"
/*
 * Prototype   : u8 HLED_u8InitOneLed(u8 Local_u8Port,u8 Local_u8Bit);
 * Description : Initialize one LED on specific port and bit
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *                PIN: takes pin number from 0 to 7
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range
 */
u8 HLED_u8InitOneLed(u8 Local_u8Port, u8 Local_u8Bit){
	/*initialize desired bit as output and return error value*/
	return DIO_u8SetPinDirection(Local_u8Port,Local_u8Bit,PIN_OUTPUT);
}
/*
 * Prototype   : u8 HLED_u8InitLedString(u8 Local_u8Port);
 * Description : Initialize string of 8 LEDs on specific port
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 HLED_u8InitLedString(u8 Local_u8Port){
	/*initialize desired port  as output and return error value*/
	return DIO_u8SetPortDirection(Local_u8Port,PORT_OUTPUT);
}
/*
 * Prototype   : u8 HLED_u8LedOnOff(u8 Local_u8Port,u8 Local_u8Bit,u8 Local_u8State);
 * Description : Turn one Led on and off
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *                PIN: takes pin number from 0 to 7
 *               State   : takes only ON OFF
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range, (3) means Bit value out of range
 */
u8 HLED_u8LedOnOff(u8 Local_u8Port, u8 Local_u8Bit, u8 Local_u8State){
	/*write led value on desired bit and return error value*/
	return DIO_u8SetPinValue(Local_u8Port,Local_u8Bit,Local_u8State);
}
u8 HLED_u8LedToggle(u8 Local_u8Port, u8 Local_u8Bit)
{

	return DIO_u8TogglePinValue(Local_u8Port,Local_u8Bit);
}
/*
 * Prototype   : u8 HLED_u8LedStringOnOff(u8 Local_u8Port,u8 Local_u8Value);
 * Description : Turn string of 8 Leds on and off
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *               Value   : takes only ON OFF or custom value
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 HLED_u8LedStringOnOff(u8 Local_u8Port, u8 Local_u8Value){
	/*write led values on Register and return error value*/
	return DIO_u8SetPortValue(Local_u8Port,Local_u8Value);
}
