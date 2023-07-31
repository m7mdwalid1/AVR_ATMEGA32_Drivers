/*
 * USART_interface.h
 *
 *  Created on: Dec 18, 2022
 *      Author: mhmd waleed
 */

#ifndef MCAL_USART_HEADER_USART_INTERFACE_H_
#define MCAL_USART_HEADER_USART_INTERFACE_H_
/*==============================================================================================================================================
 * SYNCHRONOUS FUNCTIONS
 *==============================================================================================================================================*/
/*==============================================================================================================================================
 *@fn void USART_voidInit(void)
 *@brief  This function is used to initialize USART
 *@paramter[in]  void
 *@retval void
 *==============================================================================================================================================*/
void USART_voidInit(void);
/*==============================================================================================================================================
 *@fn   u8 USART_voidSendCharSynch(u16 Copy_u16Data)
 *@brief  This function is used to send a character synchronously
 *@paramter[in]  Copy_u16Data : The Data to be sent
 *@retval ErrorStatus
 *==============================================================================================================================================*/
u8 USART_voidSendCharSynch(u16 Copy_u16Data);
/*==============================================================================================================================================
 *@fn   u8 USART_voidRecieveCharSynch(void)
 *@brief  This function is used to receive a character synchronously
 *@paramter[in]  void
 *@retval  Local_u16ReceivedData : The Received Data
 *==============================================================================================================================================*/
u16 USART_u8RecieveCharSynch(void);
/*==============================================================================================================================================
 *@fn   u8 USART_voidSendStringSynch(char *Copy_charString)
 *@brief  This function is used to send a string synchronously
 *@paramter[in]  Copy_charString : The String to be sent
 *@retval void
 *==============================================================================================================================================*/
void USART_voidSendStringSynch(char *Copy_charString);
/*==============================================================================================================================================
 *@fn   void USART_voidRecieveStringSynch(char *Copy_p8Buffer, u8 Copy_u8BufferSize)
 *@brief  This function is used to receive a string synchronously
 *@paramter[in]  Copy_p8Buffer : Pointer to the Buffer which the received string will be written to
 *@paramter[in]  Copy_u8BufferSize : The Size of the Buffer
 *@retval void
 *==============================================================================================================================================*/
void USART_voidRecieveBufferSynch(char *Copy_p8Buffer, u8 Copy_u8BufferSize);
/*==============================================================================================================================================
 * ASYNCHRONOUS FUNCTIONS
 *==============================================================================================================================================*/
/*==============================================================================================================================================
 *@fn   u8 USART_voidSendCharASynch(char *Copy_p8Buffer, u8 Copy_u8BufferSize, void (*Copy_pvNotificationFunc)(void))
 *@brief  This function is used to send a character asynchronously
 *@paramter[in] Copy_p8Buffer : Pointer to the Buffer which the received string will be written to
 *@paramter[in] Copy_u8BufferSize : The Size of the Buffer
 *@paramter[in] Copy_pvNotificationFunc : Pointer to the Function which will be called when the sending is completed
 *@retval ErrorStatus
 *==============================================================================================================================================*/
u8 USART_voidRecieveBufferASynch(char *Copy_p8Buffer, u8 Copy_u8BufferSize, void (*Copy_pvNotificationFunc)(void));
#endif /* MCAL_USART_HEADER_USART_INTERFACE_H_ */
