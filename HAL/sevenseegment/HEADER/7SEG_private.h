/*
 * 7SEG_private.h
 *
 *  Created on: Aug 22, 2022
 *      Author: mhmd waleed
 */

#ifndef HAL_SEVENSEEGMENT_HEADER_7SEG_PRIVATE_H_
#define HAL_SEVENSEEGMENT_HEADER_7SEG_PRIVATE_H_
/* array that contains seven segment numbers' representation in binary that will be
 * used to display corresponding number when assigned to a given port
 */
const u8 H7SEG_u8SevenSegArray[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
#endif /* HAL_SEVENSEEGMENT_HEADER_7SEG_PRIVATE_H_ */
