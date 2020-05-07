/*
 * EEPROM_prog.c
 *
 *  Created on: Feb 21, 2019
 *      Author: kariman
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/MACROS.h"
#include<util/delay.h>

#include"../../MCAL/MDIO/DIO_int.h"

#include"../../MCAL/MTWI/TWI_int.h"
#include"../../MCAL/MTWI/TWI_priv.h"

#include "EEPROM_cfg.h"
#include "EEPROM_int.h"
#include "EEPROM_priv.h"

#include"../HLCD/LCD_int.h"
#include"../HLCD/LCD_cfg.h"
#include"../HLCD/LCD_priv.h"

void EEPROM_Init(void)
{
	 TWI_Init();
}


void EEPROM_Send(u8 data , u8 block , u8 location )
{

	TWI_Start();

    TWI_Send( EEPROM_ADD + block + Write );  // slave add + E + BLOCK NUMBER + w


    TWI_Send( location );  // location

    TWI_Send( data );  // location

    TWI_Stop();

    _delay_ms(10);
}


u8 EEPROM_ReadNACK( u8 block , u8 location )
{

u8 Result = 0;

TWI_Start();

TWI_Send( EEPROM_ADD + block +  Write);  // slave add + E + BLOCK NUMBER + W

TWI_Send( location );  // location

//REPEAT START
TWI_Start();

TWI_Send( EEPROM_ADD + block  +  readd );  // slave add + E + BLOCK NUMBER + R

Result = TWI_ReadNACK();

TWI_Stop();
_delay_ms(10);

	return Result ;
}

void EEPROM_SendString (u8* arr1 , u8 size )
{
    u8 i =0;
	EEPROM_Send( size , 0 , i );

	for( i=0 ; i< size ; i++ )
	{

			EEPROM_Send( arr1[i] , 0 , i+1 );

	}

}

u8* EEPROM_ReadString( u8* arr2 )
{

	    u8 i =0;
	    u8 size ;

	   size = EEPROM_ReadNACK( 0 , i );


	for( i=0 ; i< size ; i++ )
	{

		arr2[i]	= EEPROM_ReadNACK(  0 , i+1 );

	}

	return arr2 ;

}
