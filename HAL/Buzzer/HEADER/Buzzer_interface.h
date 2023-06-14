/*
 * Buzzer_interface.h
 *
 *  Created on: Oct 8, 2022
 *      Author: mhmd waleed
 */

#ifndef HAL_BUZZER_HEADER_BUZZER_INTERFACE_H_
#define HAL_BUZZER_HEADER_BUZZER_INTERFACE_H_

u8 Buzzer_U8Init(u8 Local_Port , u8 Local_Pin);
u8 Buzzer_U8on(u8 Local_Port , u8 Local_Pin);
u8 Buzzer_U8off(u8 Local_Port , u8 Local_Pin);

#endif /* HAL_BUZZER_HEADER_BUZZER_INTERFACE_H_ */
