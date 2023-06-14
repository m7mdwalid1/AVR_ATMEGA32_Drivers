/*
 * SPI_Config.h
 *
 *  Created on: Dec 23, 2022
 *      Author: mhmd waleed
 */

#ifndef MCAL_SPI_HEADER_SPI_CONFIG_H_
#define MCAL_SPI_HEADER_SPI_CONFIG_H_

#define SendFirst          MSB


/*
 * 0  --- Leading edge Rising Trailing edge Failing
 * 1  --- Leading edge Failing Trailing edge Raising
 * */
#define CPOL_FUNCTIONALITY    0
/*
 * 0  --- Leading edge SAMPLE Trailing edge SETUP
 * 1  --- Leading edge SETUP Trailing edge SAMPLE
 * */
#define CLOCK_PHASE_FUNCTIONALITY     0


#define Clock_Select                   F_DevideBy32


#endif /* MCAL_SPI_HEADER_SPI_CONFIG_H_ */
