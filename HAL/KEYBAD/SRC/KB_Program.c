/*
 * KB_Program.c
 *
 *  Created on: ???/???/????
 *      Author: mhmd waleed
 */
#include "../HEADER/KB_Configuration.h"
#include "../../../MCAL/DIO/HEADER/DIO_interface.h"
#include "../HEADER/KB_Interface.h"
#include "../HEADER/KB_Private.h"
#include "../HEADER/KB_Register.h"
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"
#include <util/delay.h>
void HKB_VoidInit(void)
{
	u8 counter = 0;
	/*for loop to scan all keypad columns and rows*/
	for (counter = 0 ; counter<4 ; counter++)
	{
		/*set column current bit in ColumnArray[] OUTPUT*/
		DIO_u8SetPinDirection(KEYPAD_PORT,KB_u8ColumnArray[counter],PIN_OUTPUT);
		/*set current bit in RowArray[] INPUT*/
		DIO_u8SetPinDirection(KEYPAD_PORT,KB_u8RowArray[counter],PIN_INPUT);

		/*Enable pull up resistor for current bit in RowArray[]*/
		DIO_u8PullUpPin(KEYPAD_PORT,KB_u8RowArray[counter],DIO_EN_PULL_UP_RES);

	}
}
u8 HKB_PressedKey(void)
{
	u8 counter1 =0,counter2=0 ;
	u8 Local_PressedKey=0;
	/*for loop to set all column pins HIGH*/
	for(counter1=0;counter1<4 ; counter1++)
	{
		DIO_u8SetPinValue(KEYPAD_PORT,KB_u8ColumnArray[counter1],DIO_HIGH);
	}
	/*for loop to scan all keypad columns*/
	for(counter1=0;counter1<4 ; counter1++)
	{
		DIO_u8SetPinValue(KEYPAD_PORT,KB_u8ColumnArray[counter1],DIO_LOW);
		for(counter2=0;counter2<4;counter2++)
		{
			/*check current row pin value*/
			if( DIO_u8GetPinValue(KEYPAD_PORT,KB_u8RowArray[counter2]) ==  DIO_LOW   )
			{
				while(DIO_u8GetPinValue(KEYPAD_PORT,KB_u8RowArray[counter2]) ==  DIO_LOW);
				Local_PressedKey =KeyPadArr[counter2][counter1];
				_delay_ms(100);
				return Local_PressedKey;
			}
		}
		/*set current column pin HIGH again*/
		DIO_u8SetPinValue(KEYPAD_PORT,KB_u8ColumnArray[counter1],DIO_HIGH);
	}
return No_Pressed ;
}
