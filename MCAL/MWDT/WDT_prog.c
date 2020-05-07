/*
 *  Created on: Jan 31, 2019
 *      Author: kariman
 */


#include"../../LIB/STD_TYPES.h"
#include"../../LIB/MACROS.h"
#include "../MWDT/WDT_int.h"
#include "../MWDT/WDT_cfg.h"
#include "../MWDT/WDT_priv.h"

//WDT

void WDT_EN (void)
{
	 //EN , PRE 2 MSEC
	WDTCR_Reg =  WDT_Enable + WDT_prescaler    ;
}

void WDT_DIS (void)
{

	WDTCR_Reg = WDT_Disable1 + WDT_prescaler ;

	WDTCR_Reg = WDT_Disable2;
}



