/*
 * LCD_interface.h
 *
 *  Created on: Aug 27, 2022
 *      Author: mhmd waleed
 */


#ifndef HAL_LCD_HEADER_LCD_INTERFACE_H_
#define HAL_LCD_HEADER_LCD_INTERFACE_H_

#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"
#include "LCD_config.h"
void LCD_voidSendCommand(u8 Local_u8Command);
void LCD_voidSendData(u8 Local_u8Data);
void LCD_voidInit(void);
void LCD_voidSendString(const char * Local_String);
void LCD_voidGoToXY(u8 Local_u8XPos,u8 Local_u8YPos);
void LCD_WriteSpecialChar(u8 * Local_u8Pattern,u8 Local_u8PatternNumber,u8 Local_u8XPos,u8 Local_u8YPos);
void LCD_VoidSendNumber(s32 Local_S32Number);
void LCD_ShiftLeft(void);
void LCD_ShiftRight(void);






#endif /* HAL_LCD_HEADER_LCD_INTERFACE_H_ */
