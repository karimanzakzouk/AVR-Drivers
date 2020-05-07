/*
 * KPD_int.h
 *
 *  Created on: Jan 10, 2019
 *      Author: kariman
 */

#ifndef KPD_INT_H_
#define KPD_INT_H_

#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/MDIO/DIO_int.h"




void KPD_Init(void);

u8 kPD_Get_SwitchNumber(void);


#define KPD_COL1    PIN8
#define KPD_COL2    PIN9
#define KPD_COL3    PIN10
#define KPD_COL4    PIN31

#define KPD_ROW1   PIN12
#define KPD_ROW2   PIN13
#define KPD_ROW3   PIN14
#define KPD_ROW4   PIN15



#endif /* KPD_INT_H_ */
