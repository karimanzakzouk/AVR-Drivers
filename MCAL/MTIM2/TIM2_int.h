/*
 * TIMER2_int.h
 *
 *  Created on: Jan 31, 2019
 *      Author: kimoz
 */

#ifndef MCAL_MTIM2_TIM2_INT_H_
#define MCAL_MTIM2_TIM2_INT_H_

#include"../../LIB/STD_TYPES.h"

void TIM2_init(void);

void TIM2_start(u8 u8prescaler);

void TIM2_stop(void);


void TIM2_enable_interrupt( u8 u8EN, u8 u8INT_case );


void TIM2_SET_OCR(u16 u16OCR_VAL);


void TIM2_SET_TCNT(u8 u8TCNT_VAL);



void TIM2_OV_callback(void);

void TIM2_CTC_callback(void);



void TIM2_OV_func_setter (void(*TIM2_OV_callback)(void));

void TIM2_CTC_func_setter (void(*TIM2_CTC_callback)(void));


#endif /* MCAL_MTIM1_TIM1_INT_H_ */
