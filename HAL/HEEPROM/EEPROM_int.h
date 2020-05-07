/*
 * EEPROM_int.h
 *
 *  Created on: Jan 5, 2019
 *      Author: kariman
 */

#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/MDIO/DIO_int.h"
#include"../../MCAL/MTWI/TWI_int.h"


void EEPROM_Init(void);

void EEPROM_Send(u8 data , u8 block , u8 location );

u8 EEPROM_ReadNACK( u8 block , u8 location );


void EEPROM_SendString (u8* arr1 , u8 size );


u8*  EEPROM_ReadString( u8* arr2  );





#endif /*EEPROM_INT_H_ */
