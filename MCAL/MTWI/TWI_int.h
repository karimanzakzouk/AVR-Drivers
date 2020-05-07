/*
 *  Created on: Jan 31, 2019
 *      Author: kariman
 */

#ifndef MCAL_WTWI_TWI_INT_H_
#define MCAL_MTWI_TWI_INT_H_

#include"../../LIB/STD_TYPES.h"

#include "../MINT/INT_priv.h"

void TWI_Init(void);

void TWI_Start(void);

void TWI_Stop(void);

void TWI_Send(u8 data);


u8 TWI_ReadNACK(void);

u8 TWI_ReadACK(void);

u8 TWIGetStatus(void);

#endif /*  MCAL_WTWI_TWI_INT_H_ */
