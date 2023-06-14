/*
 * USART_interface.h
 *
 *  Created on: Dec 18, 2022
 *      Author: mhmd waleed
 */

#ifndef MCAL_USART_HEADER_USART_INTERFACE_H_
#define MCAL_USART_HEADER_USART_INTERFACE_H_



/*
 * Prototype   : void USART_VoidInit(void)
 * Description : initialize UART with Pre configured parameter
 * Arguments   : void
 * return      : void
 */
void USART_VoidInit(void);
/*
 * Prototype   : void USART_VoidSendData(u8 Local_u8Data)
 * Description : send 1 byte over UART
 * Arguments   : u8 Local_u8Data
 * return      : void
 */
void USART_VoidSendData(u8 Local_u8Data);
/*
 * Prototype   : void USART_VoidRecieveData(void);
 * Description : Receive 1 byte over UART
 * Arguments   : u8 Local_u8Data
 * return      : u8
 */
u8 USART_u8RecieveDataSync(void);


#endif /* MCAL_USART_HEADER_USART_INTERFACE_H_ */
