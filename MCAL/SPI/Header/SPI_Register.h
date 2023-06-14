/*
 * SPI_Register.h
 *
 *  Created on: Dec 24, 2022
 *      Author: mhmd waleed
 */

#ifndef MCAL_SPI_HEADER_SPI_REGISTER_H_
#define MCAL_SPI_HEADER_SPI_REGISTER_H_


#define SPI_SPDR                        (*(volatile u8 *)(0x2F))  //SPI DATA Reg



#define SPI_SPSR                        (*(volatile u8 *)(0x2E))  //SPI STATUS Reg
#define SPSR_SPIF               7             //SPI INTERRUPT FLAG
#define SPSR_WCOL               6            //COLLISION FLAG
#define SPSR_SPI2X              0            // PRE SCALER BIT 2




#define SPI_SPCR                        (*(volatile u8 *)(0x2D))  //SPI CONTROL Reg
#define SPCR_SPIE               7              // INTERRUPT ENABLE
#define SPCR_SPE                6              // SPI ENABLE
#define SPCR_DORD               5              // DATA ORDER
#define SPCR_MSTR               4              //MASTER SLAVE SELECT
#define SPCR_CPOL               3              // CLOCK POLARITY
#define SPCR_CPHA               2              // CLOCK PHASE
#define SPCR_SPRI1              1              // PRE SCALER BIT 1
#define SPCR_SPRI0              0              // PRE SCALER BIT 0




















#endif /* MCAL_SPI_HEADER_SPI_REGISTER_H_ */
