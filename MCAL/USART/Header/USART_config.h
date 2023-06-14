/*
 * USART_config.h
 *
 *  Created on: Dec 18, 2022
 *      Author: mhmd waleed
 */

#ifndef MCAL_USART_HEADER_USART_CONFIG_H_
#define MCAL_USART_HEADER_USART_CONFIG_H_

/*
 * Baud rate config (UART_BAUDRATE_2400,UART_BAUDRATE_4800,UART_BAUDRATE_9600)
 */
 #define UART_BAUD_RATE               UART_BAUDRATE_9600

/*
 * Receive enable config (UART_DISABLED - UART_ENABLED)
 */
 #define UART_RIECEVE_ENABLE          UART_ENABLED

/*
 * Send enable config (UART_DISABLED - UART_ENABLED)
 */
 #define UART_SEND_ENABLE             UART_ENABLED

/*
 * Mode select config (UART_ASYNCHRONOUS - UART_SYNCHRONOUS)
 */
 #define UART_MODE_SELECT             UART_ASYNCHRONOUS

/*
 * Character size config (UART_5_BITS,UART_6_BITS,UART_7_BITS,UART_8_BITS,UART_9_BITS)
 */
 #define UART_CHAR_SIZE               UART_8_BITS

/*
 * receive interrupt enable config (UART_DISABLED - UART_ENABLED)
 */
 #define UART_RX_INTERRUPT_ENABLE     UART_DISABLED

/*
 * Send interrupt enable config (UART_DISABLED - UART_ENABLED)
 */
 #define UART_TX_INTERRUPT_ENABLE     UART_DISABLED

/*
 * UDR empty interrupt enable config (UART_DISABLED - UART_ENABLED)
 */
 #define UART_UDR_INTERRUPT_ENABLE    UART_DISABLED

/*
 * Parity Mode enable config (UART_DISABLED,UART_EVEN_PARITY,UART_ODD_PARITY)
 */
 #define UART_PARITY_MODE             UART_DISABLED

/*
 * Number of stop bits config (UART_1_STOP_BIT - UART_2_STOP_BIT)
 */
 #define UART_STOP_BIT_NO             UART_1_STOP_BIT

/*
 * Clock polarity config (UART_SAMPLE_FALLING_EDGE,UART_SAMPLE_RISING_EDGE)
 */
 #define UART_CLOCK_POLARITY          UART_SAMPLE_FALLING_EDGE


 #define Time_Out          5000


#endif /* MCAL_USART_HEADER_USART_CONFIG_H_ */
