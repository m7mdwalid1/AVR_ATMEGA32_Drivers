/*
 * LCD_programe.c
 *
 *  Created on: Aug 27, 2022
 *      Author: mhmd waleed
 */
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"
#include "../HEADER/LCD_config.h"
#include "../HEADER/LCD_private.h"
#include "../HEADER/LCD_register.h"
#include "../HEADER/LCD_interface.h"
#include "../../../MCAL/DIO/HEADER/DIO_interface.h"
#include <util/delay.h>


#if(LCD_Type == LCD_16x2)
#if(LCD_MODE == LCD_8Bit)
void LCD_voidSendCommand(u8 Local_u8Command)
{
	/*set RS pin to low for command*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_LOW);
	/*set RW pin to low for command*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);
	/*send command to data pins*/
	DIO_u8SetPortValue(LCD_DATA_PORT,Local_u8Command);
	/*send enable pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_LOW);
}
void LCD_voidSendData(u8 Local_u8Data)
{
	/*set RS pin to HIGH for command*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_HIGH);
	/*set RW pin to low for command*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);
	/*send command to data pins*/
	DIO_u8SetPortValue(LCD_DATA_PORT,Local_u8Data);
	/*send enable pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_LOW);
}
#elif(LCD_MODE == LCD_4Bit)
void LCD_voidSendCommand(u8 Local_u8Command)
{
	u8 counter=4;
	/*set RS pin to low for command*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_LOW);
	/*set RW pin to low for command*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);
	/*send command to data pins*/
	for(counter=4;counter<8;counter++)
	{
		DIO_u8SetPinValue(LCD_DATA_PORT,counter,GET_BIT(Local_u8Command,counter));
	}
	/*send enable pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_LOW);
	for(counter=0;counter<4;counter++)
	{
		DIO_u8SetPinValue(LCD_DATA_PORT,counter,GET_BIT(Local_u8Command,counter));
	}
	/*send enable pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_LOW);
}
void LCD_voidSendData(u8 Local_u8Data)
{
	u8 counter=4;
		/*set RS pin to low for command*/
		DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_LOW);
		/*set RW pin to low for command*/
		DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_HIGH);
		/*send command to data pins*/
		for(counter=4;counter<8;counter++)
		{
			DIO_u8SetPinValue(LCD_DATA_PORT,counter,GET_BIT(Local_u8Data,counter));
		}
		/*send enable pulse*/
		DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_LOW);
		for(counter=0;counter<4;counter++)
		{
			DIO_u8SetPinValue(LCD_DATA_PORT,counter,GET_BIT(Local_u8Data,counter));
		}
		/*send enable pulse*/
		DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_LOW);
}

#endif
void LCD_voidInit(void)
{
#if(LCD_MODE == LCD_8Bit)
	DIO_u8SetPortDirection(LCD_DATA_PORT,PORT_OUTPUT);
	DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_E_PIN,PIN_OUTPUT);
	/*Wait for more than 30 ms*/
	_delay_ms(50);
	/*Function set command: 2 lines, 5*8 Font size*/
	LCD_voidSendCommand(0b00111000);
	/*Display on off control: display enable, disable cursor, no blink cursor*/
	LCD_voidSendCommand(0b00001100);
	/*Clear display*/
	LCD_voidSendCommand(1);
#elif (LCD_MODE == LCD_4Bit)
	DIO_u8SetPortDirection(LCD_DATA_PORT,PORT_OUTPUT);
		DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,PIN_OUTPUT);
		DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,PIN_OUTPUT);
		DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_E_PIN,PIN_OUTPUT);
		/*Wait for more than 30 ms*/
		_delay_ms(50);
		/*Function set command: 2 lines, 5*8 Font size*/
		LCD_voidSendCommand(0b00100010);
		/*Display on off control: display enable, disable cursor, no blink cursor*/
		LCD_voidSendCommand(0b00001100);
		_delay_ms(1);
		/*Clear display*/
		LCD_voidSendCommand(1);
		_delay_ms(2);
		/*entry mode*/
		LCD_voidSendCommand(0b00000110);
		_delay_ms(2);
#endif
}
void LCD_voidSendString(const char * Local_String)
{
	u8 Local_counter=0;
	while(Local_String[Local_counter]!='\0')
	{
		LCD_voidSendData(Local_String[Local_counter]);
		Local_counter++;
	}
}
void LCD_voidGoToXY(u8 Local_u8XPos,u8 Local_u8YPos)
{
	u8 Local_u8Address =0 ;
	if(Local_u8XPos == 0 )
	{
		Local_u8Address = Local_u8YPos ;
	}
	else if (Local_u8XPos == 1)
	{
		Local_u8Address = Local_u8YPos +0x40 ;  // or +64 in decimal
	}
	LCD_voidSendCommand(Local_u8Address+128);    // 1000 0000 = 128
}
void LCD_WriteSpecialChar(u8 * Local_u8Pattern,u8 Local_u8PatternNumber,u8 Local_u8XPos,u8 Local_u8YPos)
{
	u8 Local_u8CGRAMAddress=0,Local_u8Iterator=0;
	/*calculate cgram address whose each block is 8 bytes*/
	Local_u8CGRAMAddress=Local_u8PatternNumber*8;
	/*send cgram command to lcd ith set bitting 6 , clearing bit 7 */
	LCD_voidSendCommand(Local_u8CGRAMAddress+64);
	/*write a pattern into cgram*/
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		LCD_voidSendData(Local_u8Pattern[Local_u8Iterator]);
	}
	/*go back to ddram*/
	LCD_voidGoToXY(Local_u8XPos,Local_u8YPos);
	/*display the pattern written in CGram*/
	LCD_voidSendData(Local_u8PatternNumber);
}
void LCD_VoidSendNumber(s32 Local_S32Number)
{
	s32 Local_S32Nu = 1;
	if(Local_S32Number == 0)
	{
		LCD_voidSendData('0');
	}
	else if(Local_S32Number <0)
	{
		LCD_voidSendData('-');
		Local_S32Number *=-1 ;
	}
	while(Local_S32Number != 0)
	{
		Local_S32Nu = ((Local_S32Nu * 10) + (Local_S32Number % 10));
		Local_S32Number = (Local_S32Number / 10);
	}
	while(Local_S32Nu !=1 )
	{
		LCD_voidSendData((Local_S32Nu % 10) + 48);
		Local_S32Nu = (Local_S32Nu/10);
	}
}
void LCD_ShiftRight(void)
{
	LCD_voidSendCommand(0b00011100);

}
void LCD_ShiftLeft(void)
{
	LCD_voidSendCommand(0b00011000);
}
#elif(LCD_Type == LCD_20x4)
#if(LCD_MODE == LCD_8Bit)
void LCD_voidSendCommand(u8 Local_u8Command)
{
	/*set RS pin to low for command*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_LOW);
	/*set RW pin to low for command*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);
	/*send command to data pins*/
	DIO_u8SetPortValue(LCD_DATA_PORT,Local_u8Command);
	/*send enable pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_LOW);
}
void LCD_voidSendData(u8 Local_u8Data)
{
	/*set RS pin to HIGH for command*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_HIGH);
	/*set RW pin to low for command*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);
	/*send command to data pins*/
	DIO_u8SetPortValue(LCD_DATA_PORT,Local_u8Data);
	/*send enable pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_LOW);
}
#elif(LCD_MODE == LCD_4Bit)
void LCD_voidSendCommand(u8 Local_u8Command)
{
	u8 counter=4;
	/*set RS pin to low for command*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_LOW);
	/*set RW pin to low for command*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);
	/*send command to data pins*/
	for(counter=4;counter<8;counter++)
	{
		DIO_u8SetPinValue(LCD_DATA_PORT,counter,GET_BIT(Local_u8Command,counter));
	}
	/*send enable pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_LOW);
	for(counter=0;counter<4;counter++)
	{
		DIO_u8SetPinValue(LCD_DATA_PORT,counter,GET_BIT(Local_u8Command,counter));
	}
	/*send enable pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_LOW);
}
void LCD_voidSendData(u8 Local_u8Data)
{
	u8 counter=4;
		/*set RS pin to low for command*/
		DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_LOW);
		/*set RW pin to low for command*/
		DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_HIGH);
		/*send command to data pins*/
		for(counter=4;counter<8;counter++)
		{
			DIO_u8SetPinValue(LCD_DATA_PORT,counter,GET_BIT(Local_u8Data,counter));
		}
		/*send enable pulse*/
		DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_LOW);
		for(counter=0;counter<4;counter++)
		{
			DIO_u8SetPinValue(LCD_DATA_PORT,counter,GET_BIT(Local_u8Data,counter));
		}
		/*send enable pulse*/
		DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_LOW);
}

#endif
void LCD_voidInit(void)
{
#if(LCD_MODE == LCD_8Bit)
	DIO_u8SetPortDirection(LCD_DATA_PORT,PORT_OUTPUT);
	DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_E_PIN,PIN_OUTPUT);
	/*Wait for more than 30 ms*/
	_delay_ms(20);
	/*Function set command: 8 bit lenght*/
	LCD_voidSendCommand(0b00110000);
	_delay_ms(5);
	LCD_voidSendCommand(0b00110000);
	_delay_ms(1);
	LCD_voidSendCommand(0b00110000);
	//1
	LCD_voidSendCommand(0b00111000);
	//2
	LCD_voidSendCommand(0b00001100);
	//3
	LCD_voidSendCommand(1);
	//4(entery mode)
	//LCD_voidSendCommand(0b00110000);

#elif (LCD_MODE == LCD_4Bit)
	DIO_u8SetPortDirection(LCD_DATA_PORT,PORT_OUTPUT);
		DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,PIN_OUTPUT);
		DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,PIN_OUTPUT);
		DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_E_PIN,PIN_OUTPUT);
		/*Wait for more than 30 ms*/
		_delay_ms(50);
		/*Function set command: 2 lines, 5*8 Font size*/
		LCD_voidSendCommand(0b00100010);
		/*Display on off control: display enable, disable cursor, no blink cursor*/
		LCD_voidSendCommand(0b00001100);
		_delay_ms(1);
		/*Clear display*/
		LCD_voidSendCommand(1);
		_delay_ms(2);
		/*entry mode*/
		LCD_voidSendCommand(0b00000110);
		_delay_ms(2);
#endif
}
void LCD_voidSendString(const char * Local_String)
{
	u8 Local_counter=0;
	while(Local_String[Local_counter]!='\0')
	{
		LCD_voidSendData(Local_String[Local_counter]);
		Local_counter++;
	}
}
void LCD_voidGoToXY(u8 Local_u8XPos,u8 Local_u8YPos)
{
	 if (Local_u8YPos<20   && Local_u8XPos<4)
	  {
	    u8 Local_Addres=0 ;
	    switch(Local_u8XPos)
	    {
	    case 0 : Local_Addres  = 0x00;   break;
	    case 1 : Local_Addres  = 0x40;   break;
	    case 2 : Local_Addres  = 0x14;   break;
	    case 3 : Local_Addres  = 0x54;   break;
	    }
	    LCD_voidSendCommand(Local_Addres +128+Local_u8YPos);
	  }
}
void LCD_WriteSpecialChar(u8 * Local_u8Pattern,u8 Local_u8PatternNumber,u8 Local_u8XPos,u8 Local_u8YPos)
{
	u8 Local_u8CGRAMAddress=0,Local_u8Iterator=0;
	/*calculate cgram address whose each block is 8 bytes*/
	Local_u8CGRAMAddress=Local_u8PatternNumber*8;
	/*send cgram command to lcd ith set bitting 6 , clearing bit 7 */
	LCD_voidSendCommand(Local_u8CGRAMAddress+64);
	/*write a pattern into cgram*/
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		LCD_voidSendData(Local_u8Pattern[Local_u8Iterator]);
	}
	/*go back to ddram*/
	LCD_voidGoToXY(Local_u8XPos,Local_u8YPos);
	/*display the pattern written in CGram*/
	LCD_voidSendData(Local_u8PatternNumber);
}
void LCD_VoidSendNumber(s32 Local_S32Number)
{
	s32 Local_S32Nu = 1;
	if(Local_S32Number == 0)
	{
		LCD_voidSendData('0');
	}
	else if(Local_S32Number <0)
	{
		LCD_voidSendData('-');
		Local_S32Number *=-1 ;
	}
	while(Local_S32Number != 0)
	{
		Local_S32Nu = ((Local_S32Nu * 10) + (Local_S32Number % 10));
		Local_S32Number = (Local_S32Number / 10);
	}
	while(Local_S32Nu !=1 )
	{
		LCD_voidSendData((Local_S32Nu % 10) + 48);
		Local_S32Nu = (Local_S32Nu/10);
	}
}
void LCD_ShiftRight(void)
{
	LCD_voidSendCommand(0b00011100);

}
void LCD_ShiftLeft(void)
{
	LCD_voidSendCommand(0b00011000);
}











#endif




