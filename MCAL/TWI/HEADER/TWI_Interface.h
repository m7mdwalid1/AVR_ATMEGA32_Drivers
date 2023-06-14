/*
 * TWI_Interface.h
 *
 *  Created on: Feb 4, 2023
 *      Author: mhmd waleed
 */

#ifndef MCAL_TWI_HEADER_TWI_INTERFACE_H_
#define MCAL_TWI_HEADER_TWI_INTERFACE_H_

typedef enum
{
	NoError,
		StartConditionErr,
		RepeatedStartErr,
		SlaveAddressWithWriteErr,
		SlaveAddressWithReadErr,
		MasterWriteByteErr,
		MasterReadByteErr
}TWI_ErrorStratus;

/* pass 0 in the slave adress argument if masterwill not be adressed  */
void TWI_voidMasterInit(u8 Local_u8SlaveAddress);

void TWI_voidSlaveInit(u8 Local_u8SlaveAddress);

TWI_ErrorStratus TWI_SendStartCondition(void);

TWI_ErrorStratus TWI_SendRepeatedStart(void);

TWI_ErrorStratus TWI_SendSlaveAdressWithWrite(u8 Local_u8SlaveAdress);

TWI_ErrorStratus TWI_SendSlaveAdressWithRead(u8 Local_u8SlaveAdress);

TWI_ErrorStratus TWI_MasterWriteDataByte(u8 Local_u8DataByte);

TWI_ErrorStratus TWI_MasterReadDataByte(u8 *Local_pu8DataByte);

void TWI_SendStopCondition(void);
#endif /* MCAL_TWI_HEADER_TWI_INTERFACE_H_ */
