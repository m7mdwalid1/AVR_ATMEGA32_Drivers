/*
 * WDT_register.h
 *
 *  Created on: Dec 13, 2022
 *      Author: mhmd waleed
 */

#ifndef MCAL_WDT_HEADER_WDT_REGISTER_H_
#define MCAL_WDT_HEADER_WDT_REGISTER_H_

#define WDTCR            *((volatile u8*)0x41)

#define WDTCR_WDTOE                4
#define WDTCR_WDE                  3
#define WDTCR_WDP2                 2
#define WDTCR_WDP1                 1
#define WDTCR_WDP0                 0

#endif /* MCAL_WDT_HEADER_WDT_REGISTER_H_ */
