/*
 * ADC_interface.h
 *
 *  Created on: Sep 25, 2022
 *      Author: mhmd waleed
 */

#ifndef MCAL_ADC_SRC_ADC_INTERFACE_H_
#define MCAL_ADC_SRC_ADC_INTERFACE_H_
typedef struct
{
u8 * Channel ;
u16 * Result ;
u8 Size ;
void (*NotificationFunc)(void);
}Chain_t;
void ADC_voidInit(void);
u8 ADC_u8StartConversionSynch(u8 Local_u8Channel, u8 * Local_u8Reading);
u8 ADC_u8StartConversionAsynch(u8 Local_u8Channel, u8 * Local_u8Reading , void (*Local_pNotificationFunc)(void));
u8 ADC_u8StartChainAsynch(Chain_t *Local_Chain);
#endif /* MCAL_ADC_SRC_ADC_INTERFACE_H_ */
