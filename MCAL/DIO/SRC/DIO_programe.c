/*
 * DIO_programe.c
 *
 *  Created on: Aug 21, 2022
 *      Author: mhmd waleed
 */
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"

#include "../HEADER/DIO_interface.h"
#include "../HEADER/DIO_register.h"
#include "../HEADER/DIO_private.h"
#include "../HEADER/DIO_config.h"

/*==============================================================================================================================================
 * Direction modules /////////// USE PORT DRIVER INSTEAD
 *==============================================================================================================================================*/

/*
 * Prototype   : u8 DIO_u8SetPortDirection(u8 Local_u8Port, u8 Local_u8Direction)
 * Description : Set direction of the whole register (PORT)
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *               Direction  : takes PORT_INPUT sets whole reg i/p,PORT_OUTPUT sets whole reg o/p,
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 DIO_u8SetPortDirection(u8 Local_u8Port, u8 Local_u8Direction)
{
	u8 Local_ErrorState=0;
			switch(Local_u8Port)
			{
			case PORT_A :  	DDRA=Local_u8Direction ;break;
			case PORT_B :   DDRB=Local_u8Direction ;break;
			case PORT_C :   DDRC=Local_u8Direction ;break;
			case PORT_D :  	DDRD=Local_u8Direction ;break;
			default:Local_ErrorState=1 ;break;
			}
	return Local_ErrorState ;
}
/*
 * Prototype   : u8 DIO_u8SetPinDirection(u8 Local_u8Port, u8 Local_u8Pin, u8 Local_u8Direction)
 * Description : Set direction of PIN
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *               Direction  : takes PORT_INPUT sets whole reg i/p,PORT_OUTPUT sets whole reg o/p,
 *               PIN: takes pin number from 0 to 7
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument ,(2) means Undefined PIN Argument
 */
u8 DIO_u8SetPinDirection(u8 Local_u8Port, u8 Local_u8Pin, u8 Local_u8Direction)
{
	u8 Local_ErrorState=0;
	if(Local_u8Pin <= PIN_D7)
		{
			if(Local_u8Direction == PIN_INPUT)
			{
				switch(Local_u8Port)
				{
				case PORT_A :  	CLEAR_BIT(DDRA,Local_u8Pin);break;
				case PORT_B :   CLEAR_BIT(DDRB,Local_u8Pin);break;
				case PORT_C :   CLEAR_BIT(DDRC,Local_u8Pin);break;
				case PORT_D :  	CLEAR_BIT(DDRD,Local_u8Pin);break;
				default:Local_ErrorState=1 ;break;
				}
			}
			else if(Local_u8Direction == PIN_OUTPUT)
			{
				switch(Local_u8Port)
				{
				case PORT_A :  	SET_BIT(DDRA,Local_u8Pin);break;
				case PORT_B :   SET_BIT(DDRB,Local_u8Pin);break;
				case PORT_C :   SET_BIT(DDRC,Local_u8Pin);break;
				case PORT_D :  	SET_BIT(DDRD,Local_u8Pin);break;
				default:Local_ErrorState=1 ;break;
				}
			}
		}
	else
	{
		Local_ErrorState =2 ;
	}

return Local_ErrorState ;
}
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
u8 DIO_u8SetPortValue(u8 Local_u8Port, u8 Local_u8Value)
{
	u8 Local_ErrorState =0;
	switch(Local_u8Port)
		{
		case PORT_A :   PORTA = Local_u8Value ;break;
		case PORT_B :   PORTB = Local_u8Value ;break;
		case PORT_C :   PORTC = Local_u8Value ;break;
		case PORT_D :  	PORTD = Local_u8Value ;break;
		default:Local_ErrorState=1 ;break;
		}
return Local_ErrorState ;
}
/*
 * Prototype   : u8 DIO_u8SetPinValue(u8 Local_u8Port, u8 Local_u8Pin, u8 Local_u8Value)
 * Description : get VALUE of the pin
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *               VALUE  : takes DIO_LOW sets whole reg to low ,DIO_HIGH sets whole reg to high
 *               PIN: takes pin number from 0 to 7
 * return      : u8 number used for error handling
 *			    (0) means no error,(1) means Undefined PORT Argument ,(2) means Undefined PIN Argument
 */
u8 DIO_u8SetPinValue(u8 Local_u8Port, u8 Local_u8Pin, u8 Local_u8Value)
{
	u8 Local_ErrorState =0;

	if(Local_u8Pin <= PIN_D7)
		{
			if(Local_u8Value == DIO_LOW)
			{
				switch(Local_u8Port)
				{
				case PORT_A :  	CLEAR_BIT(PORTA,Local_u8Pin);break;
				case PORT_B :   CLEAR_BIT(PORTB,Local_u8Pin);break;
				case PORT_C :   CLEAR_BIT(PORTC,Local_u8Pin);break;
				case PORT_D :  	CLEAR_BIT(PORTD,Local_u8Pin);break;
				default:Local_ErrorState=1 ;break;
				}
			}
			else if(Local_u8Value == DIO_HIGH)
			{
				switch(Local_u8Port)
				{
				case PORT_A :  	SET_BIT(PORTA,Local_u8Pin);break;
				case PORT_B :   SET_BIT(PORTB,Local_u8Pin);break;
				case PORT_C :   SET_BIT(PORTC,Local_u8Pin);break;
				case PORT_D :  	SET_BIT(PORTD,Local_u8Pin);break;
				default:Local_ErrorState=1 ;break;
				}
			}
		}
	else
	{
		Local_ErrorState=2;
	}
	return Local_ErrorState ;
}
/*
 * Prototype   : u8 DIO_u8GetPinValue(u8 Local_u8Port,u8 Local_u8Pin, u8* Local_u8Value)
 * Description : Read value of one bit of the register
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *               PIN: takes pin number from 0 to 7
 *               Value: to store the value in it
 * return      :void
 */
u8 DIO_u8GetPinValue(u8 Local_u8Port,u8 Local_u8Pin)
{
			switch(Local_u8Port)
			{
			case PORT_A :  return GET_BIT(PINA,Local_u8Pin) ;break;
			case PORT_B :  return GET_BIT(PINB,Local_u8Pin) ;break;
			case PORT_C :  return GET_BIT(PINC,Local_u8Pin) ;break;
			case PORT_D :  return GET_BIT(PIND,Local_u8Pin) ;break;
			}
			return '?';
}
/*
 * Prototype   : u8 DIO_u8TogglePinValue(u8 Local_u8Port,u8 Local_u8Pin)
 * Description : toggle pin value of the register
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *               PIN: takes pin number from 0 to 7
 * return      : (0) means no error,(1) means Undefined PORT Argument or PIN Argument
 */
u8 DIO_u8TogglePinValue(u8 Local_u8Port,u8 Local_u8Pin)
{
	u8 Local_ErrorState =0;

		if(Local_u8Pin <= PIN_D7)
			{

					switch(Local_u8Port)
					{
					case PORT_A :  	TOGGLE_BIT(PORTA,Local_u8Pin);break;
					case PORT_B :   TOGGLE_BIT(PORTB,Local_u8Pin);break;
					case PORT_C :   TOGGLE_BIT(PORTC,Local_u8Pin);break;
					case PORT_D :  	TOGGLE_BIT(PORTD,Local_u8Pin);break;
					default:Local_ErrorState=1 ;break;
					}
			}
		else
		{
			Local_ErrorState=2;
		}
		return Local_ErrorState ;
}
/*
 * Prototype   : u8 DIO_u8TogglePinValue(u8 Local_u8Port,u8 Local_u8Pin)
 * Description : toggle port value
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *
 * return      : (0) means no error,(1) means Undefined PORT Argument
 */
u8 DIO_u8TogglePortValue(u8 Local_u8Port)
{
	u8 Local_ErrorState =0;
		switch(Local_u8Port)
			{
			case PORT_A :   PORTA ^= PORT_OUTPUT ;break;
			case PORT_B :   PORTB ^= PORT_OUTPUT ;break;
			case PORT_C :   PORTC ^= PORT_OUTPUT ;break;
			case PORT_D :  	PORTD ^= PORT_OUTPUT ;break;
			default:Local_ErrorState=1 ;break;
			}
	return Local_ErrorState ;
}
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
u8 DIO_u8PullUpPort(u8 Local_Port ,u8 Local_u8PullUpResStatus)
{
	u8 Local_Error =0;
	if(Local_u8PullUpResStatus == DIO_EN_PULL_UP_RES){
		Local_Error= DIO_u8SetPortDirection(Local_Port,PORT_INPUT);
		Local_Error=DIO_u8SetPortValue(Local_Port,PORT_HIGH);
	}
	else if (Local_u8PullUpResStatus == DIO_DIS_PULL_UP_RES){
		Local_Error= DIO_u8SetPortDirection(Local_Port,PORT_INPUT);
		Local_Error= DIO_u8SetPortValue(Local_Port,PORT_LOW);
	}
	else
	{
		 Local_Error =1 ;
	}
return Local_Error ;
}
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
u8 DIO_u8PullUpPin(u8 Local_Port ,u8 Local_u8Pin,u8 Local_u8PullUpResStatus)
{
	u8 Local_Error =0;
		if(Local_u8PullUpResStatus == DIO_EN_PULL_UP_RES){
			Local_Error= DIO_u8SetPinDirection(Local_Port,Local_u8Pin,PIN_INPUT);
			Local_Error= DIO_u8SetPinValue(Local_Port,Local_u8Pin,DIO_HIGH);
		}
		else if (Local_u8PullUpResStatus == DIO_DIS_PULL_UP_RES){
			Local_Error= DIO_u8SetPinDirection(Local_Port,Local_u8Pin,PIN_INPUT);
			Local_Error= DIO_u8SetPinValue(Local_Port,Local_u8Pin,DIO_LOW);
		}
		else
		{
			 Local_Error =1 ;
		}
	return Local_Error ;

}


