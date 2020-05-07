/*
 *  Created on: Jan 31, 2019
 *      Author: kariman
 */

#ifndef  MCAL_MWDT_WDT_PRIV_H_
#define  MCAL_MWDT_WDT_PRIV_H_

#include"../../LIB/STD_TYPES.h"


//Registers  >>>>  WDT

#define WDTCR_Reg   *((volatile u8*)0x41)


#define WDT_Enable  8


#define WDT_Disable1  24


#define WDT_Disable2  0

//PRESCALER

#define   WDT_prescaler0   0    ///NO PRE
#define   WDT_prescaler1   1   // 1
#define   WDT_prescaler2   2   // 8
#define   WDT_prescaler3   3   //64
#define   WDT_prescaler4   4   // 256
#define   WDT_prescaler5   5   // 1024
#define   WDT_prescaler6   6
#define   WDT_prescaler7   7




#endif /* MCAL_MTIM1_TIM1_PRIV_H_ */
