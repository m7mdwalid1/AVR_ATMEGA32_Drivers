/*
 * SPI_Program.c
 *
 *  Created on: Dec 24, 2022
 *      Author: mhmd waleed
 */
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../Header/SPI_Config.h"
#include "../Header/SPI_Interface.h"
#include "../Header/SPI_Private.h"
#include "../Header/SPI_Register.h"


void SPI_VoidMasterInit(void)
{
	/*Send MSB OR LSB FIRST*/
	SET_BIT_VALUE(SPI_SPCR,SPCR_DORD,SendFirst);
	/*SET MSTR TO MASTER MODE*/
	SET_BIT(SPI_SPCR,SPCR_MSTR);
	/*Set CLOCK POLARITY*/
	SET_BIT_VALUE(SPI_SPCR,SPCR_CPOL,CPOL_FUNCTIONALITY);
	/*SET CLOCK PHASE*/
	SET_BIT_VALUE(SPI_SPCR,SPCR_CPHA,CLOCK_PHASE_FUNCTIONALITY);
	/*SPI CLOCK RATE SELECT */
#if(Clock_Select < 4 && Clock_Select >=0)
	SPI_SPCR &= Clock_Select_Mask ;
	SPI_SPCR |= Clock_Select;
#elif(Clock_Select < 8 && Clock_Select >3)
	SET_BIT(SPI_SPSR,SPSR_SPI2X);
	SPI_SPCR &= Clock_Select_Mask;
	SPI_SPCR |= (Clock_Select -4);
#endif
/*Enable SPI Module*/
	SET_BIT(SPI_SPCR,SPCR_SPE);
}
void SPI_VoidSlaveInit(void)
{
	/*Send MSB OR LSB FIRST*/
	SET_BIT_VALUE(SPI_SPCR,SPCR_DORD,SendFirst);
	/*SET MSTR TO Slave MODE*/
	CLEAR_BIT(SPI_SPCR,SPCR_MSTR);
	/*Set CLOCK POLARITY*/
	SET_BIT_VALUE(SPI_SPCR,SPCR_CPOL,CPOL_FUNCTIONALITY);
	/*SET CLOCK PHASE*/
	SET_BIT_VALUE(SPI_SPCR,SPCR_CPHA,CLOCK_PHASE_FUNCTIONALITY);
	/*SPI CLOCK RATE SELECT */
#if(Clock_Select < 4 && Clock_Select >=0)
	SPI_SPCR &= Clock_Select_Mask ;
	SPI_SPCR |= Clock_Select;
#elif(Clock_Select < 8 && Clock_Select >3)
	SET_BIT(SPI_SPSR,SPSR_SPI2X);
	SPI_SPCR &= Clock_Select_Mask;
	SPI_SPCR |= (Clock_Select -4);
#endif
/*Enable SPI Module*/
	SET_BIT(SPI_SPCR,SPCR_SPE);
}
u8 SPI_U8Transcieve(u8 Local_u8Data)
{
	/*Send the DATA*/
	SPI_SPDR = Local_u8Data;
	/*Busy Waiting until Transfer Complete*/
	while(GET_BIT(SPI_SPSR,SPSR_SPIF) == 0);
	return SPI_SPDR;
}
