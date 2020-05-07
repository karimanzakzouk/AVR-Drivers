/*
 *
 *  Created on: Jan 24, 2019
 *      Author: kariman
 */

#ifndef HAL_HMOT_STEPPER_STP_INT_H_
#define HAL_HMOT_STEPPER_STP_INT_H_

#include"../../../MCAL/MDIO/DIO_int.h"
#define   blue     PIN8
#define   pink     PIN9
#define   yellow   PIN10
#define   orange   PIN11





void STP_vidInit(void);

void STP_vidCW(u8 u8speed);

void STP_vidCCW(u8 u8speed);




#endif /* HAL_HMOT_STEPPER_STP_INT_H_ */
