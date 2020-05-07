/*
 *  Created on: Jan 31, 2019
 *      Author: kariman
 */


#include"../../LIB/STD_TYPES.h"
#include"../../LIB/MACROS.h"
#include "../MTWI/TWI_int.h"
#include "../MTWI/TWI_cfg.h"
#include "../MTWI/TWI_priv.h"

#include"../MDIO/DIO_int.h"

#include "../MINT/INT_int.h"
#include "../MINT/INT_priv.h"

void TWI_Init(void)
{
	// TWI initialization
   // Bit Rate: 400.000 kHz
   //Set BIT Rate
   TWBR_Reg = 2;

   // MY ADD  0x01    << SHIFTED    +    NO Call Recognition >> 0  in LSB
   TWAR_Reg = 0X02 ;  //+1

   // CONTROL REG
   TWCR_Reg =  (1 << TWEN) ;  //   EN  ONLY     >>>         0X04

   // PRESCALER  + STATUS
   TWSR_Reg &= (~((1 << TWPS1) | (1 << TWPS0)));

   DIO_SetPinValue( PIN16, HIGH); // SCL
   DIO_SetPinValue( PIN17, HIGH);// SDA
}

void TWI_Start(void)
{

	TWCR_Reg =  (1 <<TWINT) | (1 <<TWSTA)  | (1 << TWEN)  ;  //  CLEAR FLAG + START + EN      >>>  0b10100100

	  // Wait for TWINT flag set in TWCR Register
    while((TWCR_Reg & 0x80) == 0x00);

}

void TWI_Stop(void)
{

	TWCR_Reg = (1 <<TWINT) | (1 <<TWSTO) | (1 << TWEN)  ;  // CLEAR FLAG + STOP + EN    >>>> 0b10010100

}

void TWI_Send(u8 data)
{

  TWDR_Reg  =   data ;

  //send
  TWCR_Reg =  (1 <<TWINT)  |  (1 <<TWEN ) ;  // CLEAR FLAG  +  EN  >>>>>>  0b10010100

  // Wait for TWINT flag set in TWCR Register
  while((TWCR_Reg & 0x80) == 0x00);

}


u8 TWI_ReadNACK(void)
{

  TWCR_Reg =   (1 <<TWINT)  |  (1 <<TWEN )  ;  // CLEAR FLAG  +  EN  , no ACK    >>>>>>  0b10010100

  // Wait for TWINT flag set in TWCR Register
  while((TWCR_Reg & 0x80) == 0x00);

  return  TWDR_Reg;
}


u8 TWI_ReadACK(void)
{

	u8 Result = 0;

  TWCR_Reg =   (1 <<TWINT)  |  (1 <<TWEN ) |  (1 <<TWEA )  ;  // CLEAR FLAG  +  EN   + ACK   >>>>>>  0b10010100


  Result = TWDR_Reg;

  // Wait for TWINT flag set in TWCR Register
  while((TWCR_Reg & 0x80) == 0x00);

  return  Result;
}


u8 TWIGetStatus(void)
{

 u8 status;

  status =   ( TWSR_Reg  & 0xF8  );

  return status;


}



