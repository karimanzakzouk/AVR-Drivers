/*
 * SPI_prog.c
 *
 *  Created on: Jan 31, 2019
 *      Author: kariman
 */


#include"../../LIB/STD_TYPES.h"
#include"../../LIB/MACROS.h"
#include "../MSPI/SPI_int.h"
#include "../MSPI/SPI_cfg.h"
#include "../MSPI/SPI_priv.h"

#include"../MDIO/DIO_int.h"
#include"../MDIO/DIO_priv.h"

#include "../MINT/INT_int.h"
#include "../MINT/INT_priv.h"

void SPI_Init(void)
{
//	CLR_BIT(DDRB , 4 ); // I/P
//	CLR_BIT(DDRB , 5 ); // MOSI >> I/P
//	CLR_BIT(DDRB , 7 ); // SCK >> I/P
//	SET_BIT(PORTB , 5 ); // PULL UP
//	SET_BIT(PORTB , 7 ); // PULL UP
//	SET_BIT(DDRB , 6 ); // MISO >> O/P

	//DDRB_Reg = 0B01000000;
	DDRB_Reg +=64 ;
	//PORTB_Reg  = 0B10110000;
	PORTB_Reg += 176;

    //SPCR_Reg  = 0b01000000;
	SPCR_Reg  = SPE ;

    //CLR_BIT(SPCR , 0 );

	//CLR_BIT(PORTB , 4 ); // L
}

u8 SPI_Exchange(u8 data)
{
	SPDR_Reg  = data;

 // while(! ( (GET_BIT (SPSR, 7 ) )&& 0X01 ));

  while((SPSR_Reg  &0x80) == 0x00);

  /* Clear Flag */
  SET_BIT( SPSR_Reg , 7);

 return SPDR_Reg  ;

}

ISR(   SPI_STC_vect  )
{
	// Clear Flag
	// SET_BIT(UCSRA_Reg,7);
	//DIO_SetPinValue( PIN9, HIGH);
}

