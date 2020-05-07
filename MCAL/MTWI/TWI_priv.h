/*
 *  Created on: Jan 31, 2019
 *      Author: kariman
 */

#ifndef  MCAL_MTWI_TWI_PRIV_H_
#define  MCAL_MTWI_TWI_PRIV_H_

#include"../../LIB/STD_TYPES.h"




#define  TWCR_Reg   *((volatile u8*)0x56)

#define  TWDR_Reg   *((volatile u8*)0x23)

#define  TWAR_Reg   *((volatile u8*)0x22)

#define  TWSR_Reg   *((volatile u8*)0x21)

#define  TWBR_Reg   *((volatile u8*)0x20)


//TWI Control Register � TWCR

#define TWINT  7  // FLAG   BIT 7

#define TWEA  6  // ACK EN BIT   6

#define TWSTA  5  // START BIT  5

#define TWSTO  4  // STOP BIT  4

#define TWWC  3  // Write Collision Flag  BIT 3

#define TWEN   2 //  Enable Bit  2

//BIT 1 RESERVED XXXX

#define TWIE  0  //INT  Enable Bit   0

/*
#define TWINT  128  // FLAG   BIT 7

#define TWEA  64  // ACK EN BIT   6

#define TWSTA  32  // START BIT  5

#define TWSTO  16  // STOP BIT  4

#define TWWC  8  // Write Collision Flag  BIT 3

#define TWI   4 //  Enable Bit  2

//BIT 1 RESERVED XXXX

#define TWIE  1  //INT  Enable Bit   0
*/
//TWI Status Register � TWSR


//PRESCALER Bits (0 , 1)  ----------   0,0  >( 0 >> 1)  ,   0,1  > (1 >> 4 ) ,   1,0 > ( 2  >> 16)   ,   1 , 1  > (3  >>> 64)
// bit number
#define TWPS0  0
#define TWPS1  1



#endif /* MCAL_MTWI_TWI_PRIV_H_ */
