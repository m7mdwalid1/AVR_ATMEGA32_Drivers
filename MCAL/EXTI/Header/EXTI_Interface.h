/*
 * EXTI_Interface.h
 *
 *  Created on: May 6, 2022
 *      Author: MoWael
 */

#ifndef MCAL_EXTI_HEADER_EXTI_INTERFACE_H_
#define MCAL_EXTI_HEADER_EXTI_INTERFACE_H_
#include "../../../LIB/STD_TYPES.h"
#include "EXTI_Private.h"
#include "EXTI_Configuration.h"


void EXTI0_VoidInit0(void);
void EXTI1_VoidInit1(void);
void EXTI2_VoidInit2(void);
/*post build configurations*/
void EXTI_VoidInt0SetSenseControl(u8 Local_u8Sense);
void EXTI_VoidInt1SetSenseControl(u8 Local_u8Sense);
void EXTI_VoidInt2SetSenseControl(u8 Local_u8Sense);
void EXTI_u8IntEnable(u8 Local_u8Int);
void EXTI_u8IntDisable(u8 Local_u8Int);



void EXTI_u8Int0SetCallBack(void(*Local_P_Int0Func)(void));
#endif /* MCAL_EXTI_HEADER_EXTI_INTERFACE_H_ */
