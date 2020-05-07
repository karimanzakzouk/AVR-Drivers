/*
 *  Created on: Jan 31, 2019
 *      Author: kariman
 */

#ifndef MCAL_MTIM1_TIM1_INT_H_
#define MCAL_MTIM1_TIM1_INT_H_

#include"../../LIB/STD_TYPES.h"


void TIM1_init(void);

void TIM1_start(u8 u8prescaler);

void TIM1_stop(void);


void TIM1_enable_interrupt( u8 u8EN, u8 u8INT_case );


void TIM1_SET_OCRA(u16 u16OCRA_VAL);

void TIM1_SET_OCRB(u16 u16OCRB_VAL);

void TIM1_SET_TCNT(u16 u16TCNT_VAL);



void ICU_init_HW(void);

void ICU_init_SW(void);



u8 ICU_GET_dutyCycle(void);

u32 ICU_GET_freq(void);

u8 ICU_GET_Ton(void);

u8 ICU_GET_Toff(void);

u8 ICU_GET_Tperiod(void);





#endif /* MCAL_MTIM1_TIM1_INT_H_ */
