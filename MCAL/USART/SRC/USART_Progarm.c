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
/* BAUD RATE DIVISOR DEFINTIONS */
#if (TRANSMISSION_SPEED == NORMAL_SPEED) && (USART_MODE == ASYNCHRONOUS)

#define DIVISOR 16

#elif (TRANSMISSION_SPEED == DOUBLE_SPEED) && (USART_MODE == ASYNCHRONOUS)

#define DIVISOR 8

#endif

#if USART_MODE == SYNCHRONOUS

#define DIVISOR 2

#endif
/* Global Variable to Store Buffer Size ( ASYCH ) */
u8 USART_BufferSize = 0;

/* Global Pointer to Function to Store Notification Function ( ASYCH ) */
void (*USART_PvNotificationFunc)(void) = NULL;

/* Global Variable to Store Buffer Elements */
char *USART_Buffer = 0;

/* Global Variable to Store Bit Index When Sending or Recieving String */
u8 USART_BitIndex = 0;

/* Variable to Check in ISR The Source of Interrupt is which Function */
u8 USART_ISR_SOURCE = 0;

u8 USART_BUSY_STATE = USART_IDLE;

/*==============================================================================================================================================
 * SYNCHRONOUS FUNCTIONS
 *==============================================================================================================================================*/
/*==============================================================================================================================================
 *@fn void USART_voidInit(void)
 *@brief  This function is used to initialize USART
 *@paramter[in]  void
 *@retval void
 *==============================================================================================================================================*/
void USART_voidInit(void)
{
	u8 Local_u8UCSRC = 0;
	u8 Local_u16UBRR = (u16)(((F_CPUUU / (DIVISOR * (u32)BAUD_RATE_VALUE)) - 1) + 0.5);
	/*Select USART Transmission Speed */
#if ((USART_MODE == SYNCHRONOUS) || (TRANSMISSION_SPEED == NORMAL_SPEED))
	UCSRA &= ~(1 << UCSRA_U2x);
#elif ((USART_MODE == ASYNCHRONOUS) && (TRANSMISSION_SPEED == DOUBLE_SPEED))
	UCSRA |= (1 << UCSRA_U2x);
#endif
	/* Multi Processor Communication Mode Select */
	UCSRA |= (MULTI_PROCECCOR_COMMUNICATION_MODE);
/* Recieve Complete Interrupt */
#if (RECIEVE_COMPLETE_INTERRUPT == ENABLED)
	UCSRB |= (1 << UCSRB_RXCIE);
#elif (RECIEVE_COMPLETE_INTERRUPT == DISABLED)
	UCSRB &= ~(1 << UCSRB_RXCIE);
#endif
/* Transmitter Complete Interrupt */
#if (TRANSMIT_COMPLETE_INTERRUPT == ENABLED)
	UCSRB |= (1 << UCSRB_TXCIE);
#elif (TRANSMIT_COMPLETE_INTERRUPT == DISABLED)
	UCSRB &= ~(1 << UCSRB_TXCIE);
#endif
/* Data Register Empty Interrupt */
#if (DATA_REGISTER_EMPTY_INTERRUPT == ENABLED)
	UCSRB |= (1 << UCSRB_UDRIE);
#elif (DATA_REGISTER_EMPTY_INTERRUPT == DISABLED)
	UCSRB &= ~(1 << UCSRB_UDRIE);
#endif
/* Selecting Mode*/
#if (USART_MODE == SYNCHRONOUS)
	Local_u8UCSRC |= (1 << UCSRC_UMSEL);
#elif (USART_MODE == ASYNCHRONOUS)
	Local_u8UCSRC &= ~(1 << UCSRC_UMSEL);
#endif
/* Parity Mode Select */
#if (PARITY_MODE == DISABLED)
	Local_u8UCSRC &= ~((1 << UCSRC_UPM0) | (1 << UCSRC_UPM1));
#elif (PARITY_MODE == EVEN_PARITY)
	Local_u8UCSRC |= (1 << UCSRC_UPM1);
	Local_u8UCSRC &= ~(1 << UCSRC_UPM0);
#elif (PARITY_MODE == ODD_PARITY)
	Local_u8UCSRC |= ((1 << UCSRC_UPM0) | (1 << UCSRC_UPM1));
#endif
/* Stop Bit Select */
#if (STOP_BIT_SELECT == _1_BIT)
	Local_u8UCSRC &= ~(1 << UCSRC_USBS);
#elif (STOP_BIT_SELECT == _2_BIT)
	Local_u8UCSRC |= (1 << UCSRC_USBS);
#endif
/* Character Size Select */
/* SET DATA BITS ( CHARACTER SIZE ) */
#if (DATA_BITS >= _5_BIT) && (DATA_BITS <= _8_BIT)

	/* BIT MASKING */
	Local_u8UCSRC &= (CHARACTER_SIZE_MASK);
	Local_u8UCSRC |= (DATA_BITS << UCSRC_UCSZ0);
#elif DATA_BITS == _9_BIT

	UCSRB |= (1 << UCSRB_UCSZ2);
	/* BIT MASKING */
	Local_u8UCSRC &= (CHARACTER_SIZE_MASK);
	Local_u8UCSRC |= (_8_BIT << UCSRC_UCSZ0);
#endif
/* Clock Polarity Select */
#if (CLOCK_POLARITY_SELECT == RISING_EDGE)
	Local_u8UCSRC &= ~(1 << UCSRC_UCPOL);
#elif (CLOCK_POLARITY_SELECT == FALLING_EDGE)
	Local_u8UCSRC |= (1 << UCSRC_UCPOL);
#endif
	/*Set Clock Polarity*/
#if (CLOCK_POLARITY == SEND_ON_RISING_RECIEVE_ON_FALLING) || (USART_MODE == ASYNCHRONOUS)
	Local_u8UCSRC &= (~(1 << UCSRC_UCPOL));
#elif (CLOCK_POLARITY == SEND_ON_FALLING_RECIEVE_ON_RISING)
	Local_u8UCSRC |= (1 << UCSRC_UCPOL);
#endif
	/* Assigning UCSRC */
	UCSRC = Local_u8UCSRC;
	/* Send on UBRR Value */
	if ((Local_u16UBRR >= 0) && (Local_u16UBRR <= 255))
	{
		UBRRL = (u8)Local_u16UBRR;
	}
	else if ((Local_u16UBRR > 255) && (Local_u16UBRR <= 4095UL))
	{
		/* To Get The First 8 Bits */
		UBRRL = (u8)Local_u16UBRR;

		/* To Get The 4 Last Bits , the Bit 7 in UBRRH is Zero to Access UBRRH */
		UBRRH = (u8)(Local_u16UBRR >> 8);
	}

	/* Enable USART */
	UCSRB |= (1 << UCSRB_RXEN) | (1 << UCSRB_TXEN);
}
/*==============================================================================================================================================
 *@fn   u8 USART_voidSendCharSynch(u16 Copy_u16Data)
 *@brief  This function is used to send a character synchronously
 *@paramter[in]  Copy_u16Data : The Data to be sent
 *@retval ErrorStatus
 *==============================================================================================================================================*/
u8 USART_voidSendCharSynch(u16 Copy_u16Data)
{
	u8 Local_u8ErrorStatus = 0;
	u8 Local_u8TimerCounter = 0; /* Counter to Check Timeout */
	if (USART_BUSY_STATE == USART_IDLE)
	{
		USART_BUSY_STATE = USART_BUSY;
		/* Waiting Until Data Register Empty Flag is Set OR Timeout is Reached */
		while ((GET_BIT(UCSRA, UCSRA_UDRE) == 0) && (Local_u8TimerCounter < USART_TIMEOUT))
		{
			Local_u8TimerCounter++;
		}

#if DATA_BITS == _9_BIT

		UCSRB |= (GET_BIT(Copy_u16Data, 8));

		UDR = (u8)Copy_u16Data;

#elif (DATA_BITS >= _5_BIT) && (DATA_BITS <= _8_BIT)

		/* Putting Data in UDR */
		UDR = (u8)Copy_u16Data;

#endif

		/* Return Back USART to IDLE */
		USART_BUSY_STATE = USART_IDLE;
	}
	else
	{
		/* USART is Busy */
		Local_u8ErrorStatus = 1;
	}

	return Local_u8ErrorStatus;
}
/*==============================================================================================================================================
 *@fn   u8 USART_voidRecieveCharSynch(void)
 *@brief  This function is used to receive a character synchronously
 *@paramter[in]  void
 *@retval  Local_u16ReceivedData : The Received Data
 *==============================================================================================================================================*/
u16 USART_u8RecieveCharSynch(void)
{
	/* Variable to Store the Received Data */
	u16 Local_u16ReceivedData = 0;
	/* Counter to Check Timeout */
	u8 Local_u8TimerCounter = 0;
	/* Waiting Until Receicve is Completed or Timeout*/
	while ((GET_BIT(UCSRA, UCSRA_RXC) == 0) && (Local_u8TimerCounter < USART_TIMEOUT))
	{
		Local_u8TimerCounter++;
	}

#if DATA_BITS == _9_BIT

	Local_u16ReceivedData = GET_BIT(UCSRB, UCSRB_RXB8) << 8;

	Local_u16ReceivedData |= UDR;

#elif (DATA_BITS >= _5_BIT) && (DATA_BITS <= _8_BIT)

	/* Read UDR Register */
	Local_u16ReceivedData = UDR;

#endif

	return Local_u16ReceivedData;
}
/*==============================================================================================================================================
 *@fn   u8 USART_voidSendStringSynch(char *Copy_charString)
 *@brief  This function is used to send a string synchronously
 *@paramter[in]  Copy_charString : The String to be sent
 *@retval void
 *==============================================================================================================================================*/
void USART_voidSendStringSynch(char *Copy_charString)
{
	u8 Local_u8Counter = 0;
	while (Copy_charString[Local_u8Counter] != '\0')
	{
		USART_voidSendCharSynch(Copy_charString[Local_u8Counter]);
		Local_u8Counter++;
	}
}
/*==============================================================================================================================================
 *@fn   void USART_voidRecieveStringSynch(char *Copy_p8Buffer, u8 Copy_u8BufferSize)
 *@brief  This function is used to receive a string synchronously
 *@paramter[in]  Copy_p8Buffer : Pointer to the Buffer which the received string will be written to
 *@paramter[in]  Copy_u8BufferSize : The Size of the Buffer
 *@retval void
 *==============================================================================================================================================*/
void USART_voidRecieveBufferSynch(char *Copy_p8Buffer, u8 Copy_u8BufferSize)
{
	u8 Local_u8Counter = 0;
	for (Local_u8Counter = 0; Local_u8Counter < Copy_u8BufferSize; Local_u8Counter++)
	{
		Copy_p8Buffer[Local_u8Counter] = USART_u8RecieveCharSynch();
	}
}
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
u8 USART_voidRecieveBufferASynch(char *Copy_p8Buffer, u8 Copy_u8BufferSize, void (*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorStatus = 0;
	if (Copy_pvNotificationFunc != NULL)
	{
		USART_ISR_SOURCE = RECIEVE_BUFFER;
		USART_Buffer = Copy_p8Buffer;
		USART_BufferSize = Copy_u8BufferSize;
		USART_BitIndex = 0;
		USART_PvNotificationFunc = Copy_pvNotificationFunc;
		/* Enable Recieve Complete Interrupt */
		SET_BIT(UCSRB, UCSRB_RXCIE);
	}
	else
	{
		Local_u8ErrorStatus = 1;
	}
	return Local_u8ErrorStatus;
}

/*==============================================================================================================================================
 * INTERRUPT SERVICE ROUTINES
 *==============================================================================================================================================*/

/* RECIEVE COMPLETE ISR ( RXC ) */
void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if (USART_ISR_SOURCE == RECIEVE_BUFFER)
	{

		/* Recieve Buffer */
		/* Assuming 8 data Bits */
		USART_Buffer[USART_BitIndex] = UDR;

		/* Increment Index */
		USART_BitIndex++;

		if (USART_BufferSize == USART_BitIndex)
		{
			/* Buffer is Finished */

			/* Disable Recieve Complete Interrupt */
			CLEAR_BIT(UCSRB, UCSRB_RXCIE);

			/* Call Notification Function */
			USART_PvNotificationFunc();
		}
		else
		{
			/* Buffer is Not Finished */

			/* Continue Receiving */
		}
	}
}