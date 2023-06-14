/*
 * USART_Progarm.c
 *
 *  Created on: Dec 18, 2022
 *      Author: mhmd waleed
 */
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../../USART/Header/USART_Private.h"
#include "../../USART/Header/USART_Register.h"
#include "../../USART/Header/USART_config.h"
#include "../../USART/Header/USART_interface.h"




/*
 * Prototype   : void USART_VoidInit(void)
 * Description : initialize UART with Pre configured parameter
 * Arguments   : void
 * return      : void
 */
void USART_VoidInit(void)
{
	u8 local_u8UCSRC_Value =0;

	SET_BIT_VALUE(UCSRB,UCSRB_TXCIE,UART_TX_INTERRUPT_ENABLE);
	/*Receive interrupt enable config*/
	SET_BIT_VALUE(UCSRB,UCSRB_RXCIE,UART_RX_INTERRUPT_ENABLE);

	/*UDR empty interrupt enable config*/
	SET_BIT_VALUE( UCSRB,UCSRB_UDRIE,UART_UDR_INTERRUPT_ENABLE);

	/*Mode config (Asynchronous-Synchronous)*/
	SET_BIT_VALUE(local_u8UCSRC_Value,UCSRC_UMSEL,UART_MODE_SELECT);

	/*Parity Mode config*/
	local_u8UCSRC_Value|=(UART_PARITY_MODE<<4);

	/*Clock polarity config*/
	SET_BIT_VALUE(local_u8UCSRC_Value,UCSRC_UCPOL,UART_CLOCK_POLARITY);

	/*Stop Bits config*/
	SET_BIT_VALUE(local_u8UCSRC_Value,UCSRC_USBS,UART_STOP_BIT_NO);

	/*Character size config*/
	if (UART_CHAR_SIZE != UART_9_BITS)
	{
		/*config char size(5,6,7,8)*/
		local_u8UCSRC_Value |= (UART_CHAR_SIZE<<1);
	}
	else if (UART_CHAR_SIZE == UART_9_BITS)
	{
		/*9 bit Mode*/
		local_u8UCSRC_Value |= (UART_8_BITS<<1);
		SET_BIT(UCSRB,UCSRB_UCSZ2);

	}/*end of char size check*/

	/*Load configuration values in UCSrC Register*/
	/*Set URSEL to access UCSRC Reg*/
	SET_BIT(local_u8UCSRC_Value,7);
	/*Load value of UCSRC*/
	UCSRC = local_u8UCSRC_Value ;

	/*Baud Rate Value Config*/
	UBRRH = 0;
	UBRRL = UART_BAUD_RATE;
	/*Receive enable config*/
	SET_BIT_VALUE(UCSRB,UCSRB_RXEN,UART_RIECEVE_ENABLE);
	/*Transmit enable config*/
	SET_BIT_VALUE(UCSRB,UCSRB_TXEN,UART_SEND_ENABLE);
	/*Send interrupt enable config*/
}
/*
 * Prototype   : void USART_VoidSendData(u8 Local_u8Data)
 * Description : send 1 byte over UART
 * Arguments   : u8 Local_u8Data
 * return      : void
 */
void USART_VoidSendData(u8 Local_u8Data)
{
	/*wait while previous sending is complete*/
	while (GET_BIT(UCSRA,UCSRA_UDRE)==0);
	/*send byte*/
	UDR = Local_u8Data;
}
/*
 * Prototype   : void USART_VoidRecieveData(void);
 * Description : Receive 1 byte over UART
 * Arguments   : u8 Local_u8Data
 * return      : u8
 */
u8 USART_u8RecieveDataSync(void)
{
	u32 Local_u32TimeCounter=0;
	/*wait while previous Recieve is complete*/
	while((GET_BIT(UCSRA,UCSRA_RXC) == 0) && Local_u32TimeCounter<Time_Out  ){
		Local_u32TimeCounter++;
	}
	if(GET_BIT(UCSRA,UCSRA_RXC) == 1)
	{
		/*Return Received data*/
		return UDR;
	}
	else if (Local_u32TimeCounter == Time_Out)
	{
		//Do Nothing
	}
	return UDR;
}

