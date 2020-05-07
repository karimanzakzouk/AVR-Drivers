/*
 * SPI_piv.h
 *
 *  Created on: Jan 31, 2019
 *      Author: kariman
 */

#ifndef  MCAL_MSPI_SPI_PRIV_H_
#define  MCAL_MSPI_SPI_PRIV_H_

#include"../../LIB/STD_TYPES.h"


#define  SPDR_Reg   *((volatile u8*)0x2F)

#define  SPSR_Reg   *((volatile u8*)0x2E)

#define  SPCR_Reg    *((volatile u8*)0x2D)



#define SPIE  128    //Bit 7 � SPE: SPI INTERRUPT Enable

#define SPE  64    //Bit 6 � SPE: SPI Enable

#define DORD  32    //Bit 5 � DORD: Data Order

// Bit 4 � MSTR: Master/Slave Select
#define MSTR  16

// Bit 3 � CPOL: Clock Polarity
#define CPOL  8

// Bit 2 � CPHA: Clock Phase
#define CPHA  4

//Bits 1, 0 � SPR1, SPR0: SPI Clock Rate Select 1 and 0
/*
 * Relationship Between SCK and the Oscillator Frequency
SPI2X SPR1 SPR0 SCK Frequency
0 0 0 fosc/4
0 0 1 fosc/16
0 1 0 fosc/64
0 1 1 fosc/128
1 0 0 fosc/2
1 0 1 fosc/8
1 1 0 fosc/32
1 1 1 fosc/64
 */
#define SPR1  2

#define SPR0  1




#endif /* MCAL_MSPI_SPI_PRIV_H_ */
