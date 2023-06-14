/*
 * LED_interface.h
 *
 *  Created on: Aug 22, 2022
 *      Author: mhmd waleed
 */

#ifndef HAL_LED_HEADER_LED_INTERFACE_H_
#define HAL_LED_HEADER_LED_INTERFACE_H_


u8 HLED_u8LedToggle(u8 Local_u8Port, u8 Local_u8Bit);
/*
 * Prototype   : u8 HLED_u8InitOneLed(u8 Local_u8Port,u8 Local_u8Bit);
 * Description : Initialize one LED on specific port and bit
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *                PIN: takes pin number from 0 to 7
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range
 */

u8 HLED_u8InitOneLed(u8 Local_u8Port, u8 Local_u8Bit);

/*
 * Prototype   : u8 HLED_u8InitLedString(u8 Local_u8Port);
 * Description : Initialize string of 8 LEDs on specific port
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 HLED_u8InitLedString(u8 Local_u8Port);

/*
 * Prototype   : u8 HLED_u8LedOnOff(u8 Local_u8Port,u8 Local_u8Bit,u8 Local_u8State);
 * Description : Turn one Led on and off
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *                PIN: takes pin number from 0 to 7
 *               State   : takes only ON OFF
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range, (3) means Bit value out of range
 */
u8 HLED_u8LedOnOff(u8 Local_u8Port, u8 Local_u8Bit, u8 Local_u8State);

/*
 * Prototype   : u8 HLED_u8LedStringOnOff(u8 Local_u8Port,u8 Local_u8Value);
 * Description : Turn string of 8 Leds on and off
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *               Value   : takes only ON OFF or custom value
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 HLED_u8LedStringOnOff(u8 Local_u8Port, u8 Local_u8Value);



#endif /* HAL_LED_HEADER_LED_INTERFACE_H_ */
