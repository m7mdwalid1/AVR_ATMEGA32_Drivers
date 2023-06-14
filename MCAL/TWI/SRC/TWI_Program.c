/*
 * TWI_Program.c
 *
 *  Created on: Feb 4, 2023
 *      Author: mhmd waleed
 */
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../HEADER/TWI_Register.h"
#include "../HEADER/TWI_Config.h"
#include "../HEADER/TWI_Interface.h"
#include "../HEADER/TWI_Private.h"



/* pass 0 in the slave adress argument if masterwill not be adressed  */
void TWI_voidMasterInit(u8 Local_u8SlaveAddress)
{
	/*Set Clock frequency to 400KBPS*/
		/*Set TWDR =2*/
		TWDR=2;

		/*Clear 2 bits of TWPS to set prescaler reg to 0*/
		CLR_BIT(TWSR,TWSR_TWPS0);
		CLR_BIT(TWSR,TWSR_TWPS1);
		/*Set Address to master in case he will be a slave @ any time*/
		if (Local_u8SlaveAddress !=0)
		{
			TWAR = Local_u8SlaveAddress<<1;
		}
		/*Enable TWI*/
		SET_BIT(TWCR,TWCR_TWEN);

}

void TWI_voidSlaveInit(u8 Local_u8SlaveAddress)
{
	/*Set Slave Address*/
		TWAR = Local_u8SlaveAddress<<1;
		/*Enable TWI*/
		SET_BIT(TWCR,TWCR_TWEN);


}

TWI_ErrorStratus TWI_SendStartCondition(void)
{
	TWI_ErrorStratus Local_ErrorStatus =NoError;

		/*Send Start condition on the bus*/
		SET_BIT(TWCR,TWCR_TWSTA);

		/*Low The interrupt flag to start the previous action (Must be cleared after every operation)*/
		SET_BIT(TWCR,TWCR_TWINT);

		/*Waiting until flag raised again (The previous operation is done)*/
		while(GET_BIT(TWCR,TWCR_TWINT)==0);

		/*Check the Operation if its done correctly*/
		if ( (TWSR & 0xf8) != START_ACK )
		{
			Local_ErrorStatus = StartConditionErr;
		}

		return Local_ErrorStatus;


}

TWI_ErrorStratus TWI_SendRepeatedStart(void)
{
	TWI_ErrorStratus Local_ErrorStatus =NoError;

		/*Send Start condition on the bus*/
		SET_BIT(TWCR,TWCR_TWSTA);

		/*Low The interrupt flag to start the previous action (Must be cleared after every operation)*/
		SET_BIT(TWCR,TWCR_TWINT);

		/*Waiting until flag raised again (The previous operation is done)*/
		while(GET_BIT(TWCR,TWCR_TWINT)==0);

		/*Check the Operation if its done correctly*/
		if ( (TWSR & 0xf8) != REP_START_ACK )
		{
			Local_ErrorStatus = RepeatedStartErr;
		}
		else
		{
			/* Do Nothing  */

		}

		return Local_ErrorStatus;

}

TWI_ErrorStratus TWI_SendSlaveAdressWithWrite(u8 Local_u8SlaveAdress)
{
	TWI_ErrorStratus Local_ErrorStatus =NoError;

		/*Clear the start condition bit*/
		CLR_BIT(TWCR,TWCR_TWSTA);

		/*Set the slave address in the 7 MSB in data register*/
		TWDR = Local_u8SlaveAdress<<1;

		/*Send Write Request*/
		CLR_BIT(TWDR,0);

		/*Low The interrupt flag to start the previous action (Must be cleared after every operation)*/
		SET_BIT(TWCR,TWCR_TWINT);

		/*Waiting until flag raised again (The previous operation is done)*/
		while(GET_BIT(TWCR,TWCR_TWINT)==0);

		/*Check the Operation if its done correctly*/
		if ( (TWSR & 0xf8) != SLAVE_ADD_AND_WR_ACK )
		{
			Local_ErrorStatus = SlaveAddressWithWriteErr;
		}


		return Local_ErrorStatus;
}

TWI_ErrorStratus TWI_SendSlaveAdressWithRead(u8 Local_u8SlaveAdress)
{
	TWI_ErrorStratus Local_ErrorStatus =NoError;
		/*Clear the start condition bit*/
			CLR_BIT(TWCR,TWCR_TWSTA);

			/*Set the slave address in the 7 MSB in data register*/
			TWDR = Local_u8SlaveAdress<<1;

			/*set bit 0 to send read Request*/
			SET_BIT(TWDR,0);

			/*Low The interrupt flag to start the previous action (Must be cleared after every operation)*/
			SET_BIT(TWCR,TWCR_TWINT);

			/*Waiting until flag raised again (The previous operation is done)*/
			while(GET_BIT(TWCR,TWCR_TWINT)==0);

			/*Check the Operation status on status register if its done correctly*/
			if ( (TWSR & 0xf8) != SLAVE_ADD_AND_RD_ACK )
			{
				Local_ErrorStatus = SlaveAddressWithReadErr;
			}

		return Local_ErrorStatus;

}

TWI_ErrorStratus TWI_MasterWriteDataByte(u8 Local_u8DataByte)
{
	TWI_ErrorStratus Local_ErrorStatus =NoError;

		/*Write the data byte*/
		TWDR = Local_u8DataByte;
		/*Low The interrupt flag to start the previous action (Must be cleared after every operation)*/
		SET_BIT(TWCR,TWCR_TWINT);

		/*Waiting until flag raised again (The previous operation is done)*/
		while(GET_BIT(TWCR,TWCR_TWINT)==0);

		/*Check the Operation if its done correctly*/
		if ( (TWSR & 0xf8) != MSTR_WR_BYTE_ACK )
		{
			Local_ErrorStatus = MasterWriteByteErr;
		}

		return Local_ErrorStatus;

}

TWI_ErrorStratus TWI_MasterReadDataByte(u8 *Local_u8DataByte)
{
	TWI_ErrorStratus Local_ErrorStatus =NoError;
		/*Enable Master generating ack after receiving data*/
		SET_BIT(TWCR,TWCR_TWEA);

		/*Low The interrupt flag to start the slave sending data (Must be cleared after every operation)*/
			SET_BIT(TWCR,TWCR_TWINT);

			/*Waiting until flag raised again (The previous operation is done)*/
			while(GET_BIT(TWCR,TWCR_TWINT)==0);

			/*Check the Operation if its done correctly*/
			if ( (TWSR & 0xf8) != MSTR_RD_BYTE_WITH_ACK )
			{
				Local_ErrorStatus = MasterReadByteErr;
			}
			else
			{
				/*Read the received data*/
				* Local_u8DataByte = TWDR ;
			}

		return Local_ErrorStatus;

}

void TWI_SendStopCondition(void)
{
	/*Generate Stop Condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTO);
	/*Low The interrupt flag to start the slave sending data (Must be cleared after every operation)*/
	SET_BIT(TWCR,TWCR_TWINT);

}
