/*
 *  Created on: Jan 5, 2019
 *      Author: kariman
 */

#ifndef _7SEG_INT_H_
#define _7SEG_INT_H_

#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/MDIO/DIO_int.h"



#define _7SEG_A  PIN8
#define _7SEG_B  PIN9
#define _7SEG_C  PIN10
#define _7SEG_D  PIN11
#define _7SEG_E  PIN12
#define _7SEG_F  PIN13
#define _7SEG_G  PIN14


void _7SEG_vidInit(void);
void _7_SEG_vidWriteNum(u8 u8num);



#endif /* 7SEG_INT_H_ */
