/*
 * DIO_interface.h
 *
 *  Created on: Aug 21, 2022
 *      Author: mhmd waleed
 */

#ifndef MCAL_DIO_HEADER_DIO_INTERFACE_H_
#define MCAL_DIO_HEADER_DIO_INTERFACE_H_
#include"DIO_private.h"
#include"../../../LIB/STD_TYPES.h"
/*==============================================================================================================================================
 * Direction modules
 *==============================================================================================================================================*/

/*
 * Prototype   : u8 DIO_u8SetPortDirection(u8 Local_u8Port, u8 Local_u8Direction)
 * Description : Set direction of the whole register (PORT)
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *               Direction  : takes PORT_INPUT sets whole reg i/p,PORT_OUTPUT sets whole reg o/p,
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 DIO_u8SetPortDirection(u8 Local_u8Port, u8 Local_u8Direction);
/*
 * Prototype   : u8 DIO_u8SetPinDirection(u8 Local_u8Port, u8 Local_u8Pin, u8 Local_u8Direction)
 * Description : Set direction of PIN
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *               Direction  : takes PORT_INPUT sets whole reg i/p,PORT_OUTPUT sets whole reg o/p,
 *               PIN: takes pin number from 0 to 7
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument or PIN Argument
 */
u8 DIO_u8SetPinDirection(u8 Local_u8Port, u8 Local_u8Pin, u8 Local_u8Direction);
/*==============================================================================================================================================
 * values modules
 *==============================================================================================================================================*/
/*
 * Prototype   : u8 DIO_u8SetPortValue(u8 Local_u8Port, u8 Local_u8Value)
 * Description : Set VALUE of the whole register (PORT)
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *               VALUE  : takes DIO_LOW sets whole reg to low ,DIO_HIGH sets whole reg to high,
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument or unknown value
 */
u8 DIO_u8SetPortValue(u8 Local_u8Port, u8 Local_u8Value);
/*
 * Prototype   : u8 DIO_u8SetPinValue(u8 Local_u8Port, u8 Local_u8Pin, u8 Local_u8Value)
 * Description : get VALUE of the pin
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *               VALUE  : takes DIO_LOW sets whole reg to low ,DIO_HIGH sets whole reg to high
 *               PIN: takes pin number from 0 to 7
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument or PIN Argument or unknown value
 */
u8 DIO_u8SetPinValue(u8 Local_u8Port, u8 Local_u8Pin, u8 Local_u8Value);
/*
 * Prototype   : u8 DIO_u8GetPinValue(u8 Local_u8Port,u8 Local_u8Pin, u8* Local_u8Value)
 * Description : Read value of one bit of the register
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *               PIN: takes pin number from 0 to 7
 * return      : u8
 */
u8 DIO_u8GetPinValue(u8 Local_u8Port,u8 Local_u8Pin);
/*
 * Prototype   : u8 DIO_u8TogglePinValue(u8 Local_u8Port,u8 Local_u8Pin)
 * Description : toggle pin value of the register
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *               PIN: takes pin number from 0 to 7
 * return      : (0) means no error,(1) means Undefined PORT Argument or PIN Argument
 */
u8 DIO_u8TogglePinValue(u8 Local_u8Port,u8 Local_u8Pin);
/*
 * Prototype   : u8 DIO_u8TogglePinValue(u8 Local_u8Port,u8 Local_u8Pin)
 * Description : toggle port value of
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *
 * return      : (0) means no error,(1) means Undefined PORT Argument
 */
u8 DIO_u8TogglePortValue(u8 Local_u8Port);
/*==============================================================================================================================================
 * Configure pullup res modules
 *==============================================================================================================================================*/

/*
 * Prototype   : u8 DIO_u8PullUpPort(u8 Local_Port ,u8 Local_u8PullUpResStatus);
 * Description : Configure pullup Res status for the whole register
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *               pull up res : takes only DIO_EN_PULL_UP_RES (will enable it for the whole reg) or
 *                                        DIO_DIS_PULL_UP_RES (will disable it for the whole reg)
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 DIO_u8PullUpPort(u8 Local_Port ,u8 Local_u8PullUpResStatus);
/*
 * Prototype   : u8 DIO_u8PullUpPort(u8 Local_Port ,u8 Local_u8PullUpResStatus);
 * Description : Configure pullup Res status for the whole register
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *               pull up res : takes only DIO_EN_PULL_UP_RES
 *                                        DIO_DIS_PULL_UP_RES
 *               PIN: takes pin number from 0 to 7
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 DIO_u8PullUpPin(u8 Local_Port ,u8 Local_u8Pin,u8 Local_u8PullUpResStatus);
#endif
