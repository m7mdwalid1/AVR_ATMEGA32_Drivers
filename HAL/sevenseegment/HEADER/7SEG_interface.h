/*
 * 7SEG_interface.h
 *
 *  Created on: Aug 22, 2022
 *      Author: mhmd waleed
 */

#ifndef HAL_SEVENSEEGMENT_HEADER_7SEG_INTERFACE_H_
#define HAL_SEVENSEEGMENT_HEADER_7SEG_INTERFACE_H_
/*
 * Prototype   : u8 H7SEG_u8Init(u8 Copy_u8Reg);
 * Description : Initialize one 7-Segment of 8 LEDs on specific port
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 H7SEG_u8Init(u8 Copy_u8Reg);

/*
 * Prototype   : u8 H7SEG_u8DisplayNumber(u8 Copy_u8Reg,u8 Copy_u8DisblayNumber);
 * Description : Display a number on a given 7-segment
 * Arguments   : Port: takes only PORT_A,PORT_B,PORT_C,PORT_D
 *               Number  : takes only from 0 to 9
 * return      : u8 number for error handling
 *               (0) means no error, (1) means Undefined PORT, (2) means Display Number out of range error
 */
u8 H7SEG_u8DisplayNumber(u8 Copy_u8Reg, u8 Copy_u8DisblayNumber);


#endif /* HAL_SEVENSEEGMENT_HEADER_7SEG_INTERFACE_H_ */
