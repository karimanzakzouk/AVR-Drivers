/*
 * TIMER2_piv.h
 *
 *  Created on: Jan 31, 2019
 *      Author: kariman
 */

#ifndef MCAL_MTIM2_TIM2_PRIV_H_
#define MCAL_MTIM2_TIM2_PRIV_H_

#include"../../LIB/STD_TYPES.h"


// Registers  >>>>timer 2

#define TCCR2_Reg   *((volatile u8*)0x45)

#define TCNT2_Reg   *((volatile u8*)0x44)

#define OCR2_Reg    *((volatile u8*)0x43)

#define TIMSK_Reg   *((volatile u8*)0x59)




//    MODES   >> bits 6, 3
#define TIM2_mode0   0     // normal
#define TIM2_mode1   64    //PWM, Phase Correct
#define TIM2_mode2   8      // CTC
#define TIM2_mode3   72    // fast pwm

// bits 5,4
#define TIM2_Normal 			   0
#define TIM2_Toggle_reserved      16
#define TIM2_clear                32
#define TIM2_set 			      48


//PRESCALER

#define   TIM2_prescaler0   0    ///NO PRE
#define   TIM2_prescaler1   1   // 1
#define   TIM2_prescaler2   2   // 8
#define   TIM2_prescaler3   3   //32
#define   TIM2_prescaler4   4    //64
#define   TIM2_prescaler5   5    //128
#define   TIM2_prescaler6   6   // 256
#define   TIM2_prescaler7   7    // 1024


// INTERRUPT
// TIMSK REG  >>>>bits 7 >> CTC INT ,6  >> OV INT

#define TIM2_OV_INT_En     64
#define TIM2_CTC_INT_En   128
#define TIM2_INT_EN  1
#define TIM2_INT_DIS  0





#endif /* MCAL_MTIM1_TIM1_PRIV_H_ */
