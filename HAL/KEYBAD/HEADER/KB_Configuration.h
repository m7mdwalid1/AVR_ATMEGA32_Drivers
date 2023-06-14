/*
 * KB_Configuration.h
 *
 *  Created on: ???/???/????
 *      Author: mhmd waleed
 */

#ifndef KB_CONFIGURATION_H_
#define KB_CONFIGURATION_H_
#include "../../../MCAL/DIO/HEADER/DIO_private.h"
#include "../../../LIB/STD_TYPES.h"


/*pin connections on keypad register*/
/*choose keypad port*/
#define KEYPAD_PORT  PORT_B
/*Column connections*/
#define C1 4
#define C2 5
#define C3 6
#define C4 7
/*Row connections*/
#define R1 3
#define R2 2
#define R3 1
#define R4 0

/*Keypad buttons assigned values array*/
const u8 KeyPadArr[4][4]={{ '7', '8' , '9' ,  '/'},
					      { '4',  '5', '6' ,  '*'},
					      { '1',  '2', '3' ,  '-'},
					      { 'c', '0' , '=' ,  '+'}
                                                 };

#define No_Pressed    0xff
#endif
