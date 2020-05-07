/*
 * LDR_prog.c
 *
 *  Created on: Jan 24, 2019
 *      Author: kariman
 */

#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/MACROS.h"
#include "LDR_int.h"


u16 LDR_u32Read(u8 u8Analog)
{
	u16 LDR_reading =0 ;

	LDR_reading = ( u8Analog * 5000ul ) / 256 ; /// 0>>> 5000 mV


	return  LDR_reading;
}
