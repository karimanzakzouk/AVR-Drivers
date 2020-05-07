/*
 * LM35_prog.c
 *
 *  Created on: Jan 24, 2019
 *      Author: kariman
 */

#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/MACROS.h"
#include "LM35_int.h"



u8 LM35_u32Read(u8 u8Analog)
{

	u8 LM35_reading =0 ;


	LM35_reading = ( u8Analog * 50 ) / 256 ; // 0 >>> 50 C

	return  LM35_reading;

}
