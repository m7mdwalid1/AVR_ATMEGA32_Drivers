/*
 * USART_Register.h
 *
 *  Created on: Dec 18, 2022
 *      Author: mhmd waleed
 */

#ifndef MCAL_USART_HEADER_USART_REGISTER_H_
#define MCAL_USART_HEADER_USART_REGISTER_H_
/*=================================================================================
 * UART Registers
 *=================================================================================*/
#define UDR                   *((volatile u8 *) 0x2C)
#define UCSRA                 *((volatile u8 *) 0x2B)
#define UCSRB                 *((volatile u8 *) 0x2A)
#define UCSRC                 *((volatile u8 *) 0x40)
#define UBRRL                *((volatile u8 *) 0x29)
#define UBRRH                *((volatile u8 *) 0x40)
/*=================================================================================
 * UART Registers Pins
 *=================================================================================*/
/*UCSRA Register*/
#define UCSRA_RXC                 7
#define UCSRA_TXC                 6
#define UCSRA_UDRE                5
#define UCSRA_FE                  4
#define UCSRA_DOR                 3
#define UCSRA_PE                  2
#define UCSRA_U2x                 1
#define UCSRA_MPCM                0

/*UCSRB Register*/
#define UCSRB_RXCIE               7
#define UCSRB_TXCIE               6
#define UCSRB_UDRIE               5
#define UCSRB_RXEN                4
#define UCSRB_TXEN                3
#define UCSRB_UCSZ2               2
#define UCSRB_RXB8                1
#define UCSRB_TXB8                0

/*UCSRC Register*/
#define UCSRC_URSEL               7
#define UCSRC_UMSEL               6
#define UCSRC_UPM1                5
#define UCSRC_UPM0                4
#define UCSRC_USBS                3
#define UCSRC_UCSZ1               2
#define UCSRC_UCSZ0               1
#define UCSRC_UCPOL               0

/*=================================================================================
 * Config macros
 *=================================================================================*/
#define UART_DISABLED            0
#define UART_ENABLED             1

#define UART_ASYNCHRONOUS        0
#define UART_SYNCHRONOUS         1

#define UART_EVEN_PARITY         2
#define UART_ODD_PARITY          3

#define UART_1_STOP_BIT          0
#define UART_2_STOP_BIT          1

#define UART_5_BITS              0
#define UART_6_BITS              1
#define UART_7_BITS              2
#define UART_8_BITS              3
#define UART_9_BITS              7

#define UART_BAUDRATE_2400       207
#define UART_BAUDRATE_4800       103
#define UART_BAUDRATE_9600       51

#define UART_SAMPLE_FALLING_EDGE 0
#define UART_SAMPLE_RISING_EDGE  1



#endif /* MCAL_USART_HEADER_USART_REGISTER_H_ */
