/*
 * TWI_Privater.h
 *
 *  Created on: Feb 4, 2023
 *      Author: mhmd waleed
 */

#ifndef MCAL_TWI_HEADER_TWI_PRIVATE_H_
#define MCAL_TWI_HEADER_TWI_PRIVATE_H_

#define START_ACK						0X08  /*START HAS BEEN SENT*/
#define REP_START_ACK                   0X10  /*REPEATED START*/
#define SLAVE_ADD_AND_WR_ACK            0X18  /*MASTER TRANSMIT (SLAVE ADDRESS + WRITE REQUEST) ACK*/
#define SLAVE_ADD_AND_RD_ACK            0X40  /*MASTER TRANSMIT (SLAVE ADDRESS + READ REQUEST) ACK*/
#define MSTR_WR_BYTE_ACK                0X28  /*MASTER TRANSMIT DATA ACK*/
#define MSTR_RD_BYTE_WITH_ACK           0X50  /*MASTER RECIEVED DATA WITH ACK*/
#define MSTR_RD_BYTE_WITH_NACK          0X58  /*MASTER RECIEVED DATA WITH NACK*/
#define SLAVE_ADD_RCVD_RD_REQ           0XA8  /*MEANS THAT THE SLAVE ADDRESS IS RECIEVED WITH READ REQUEST*/
#define SLAVE_ADD_RCVD_WR_REQ           0X60  /*MEANS THAT THE SLAVE ADDRESS IS RECIEVED WITH WRITE REQUEST*/
#define SLAVE_DATA_RECIEVED             0X80  /*MEANS THAT A BYTE IS RECIEVED*/
#define SLAVE_BYTE_TRANSMITTED          0XB8  /*MEANS THAT THE WRRITEN BYTE HAS TRANSMITTED*/


#endif /* MCAL_TWI_HEADER_TWI_PRIVATE_H_ */
