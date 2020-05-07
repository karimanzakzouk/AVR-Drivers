/*
 *  Created on: Jan 31, 2019
 *      Author: kariman
 */

#ifndef MCAL_MTIM1_TIM1_PRIV_H_
#define MCAL_MTIM1_TIM1_PRIV_H_

#include"../../LIB/STD_TYPES.h"



#define TCNT1H_Reg   *((volatile u8*)0x4D)
#define TCNT1L_Reg   *((volatile u8*)0x4C)

#define TCNT1_Reg      (*(volatile u16 *)((0x4D) + 0x4C))

#define TCCR1A_Reg   *((volatile u8*)0x4F)
#define TCCR1B_Reg   *((volatile u8*)0x4E)



#define OCR1AH_Reg    *((volatile u8*)0x4B)
#define OCR1AL_Reg    *((volatile u8*)0x4A)

#define OCR1A_Reg      (*(volatile u16 *)((0x4B) + 0x4A))


#define OCR1BH_Reg    *((volatile u8*)0x49)
#define OCR1BL_Reg    *((volatile u8*)0x48)

#define OCR1B_Reg      (*(volatile u16 *)((0x49) + 0x48))


#define ICR1H_Reg   *((volatile u8*)0x47)
#define ICR1L_Reg   *((volatile u8*)0x46)

#define ICR1_Reg      (*(volatile u16 *)((0x47) + 0x46))

#define TIMSK_Reg   *((volatile u8*)0x59)



//MODES

#define TIM1_mode0_A   0
#define TIM1_mode1_A   1
#define TIM1_mode2_A   2
#define TIM1_mode3_A   3
#define TIM1_mode4_A   0
#define TIM1_mode5_A   1
#define TIM1_mode6_A   2
#define TIM1_mode7_A   3
#define TIM1_mode8_A   0
#define TIM1_mode9_A   1
#define TIM1_mode10_A  2
#define TIM1_mode11_A  3
#define TIM1_mode12_A  0
#define TIM1_mode13_A  1
#define TIM1_mode14_A  2
#define TIM1_mode15_A  3

#define TIM1_mode0_B   0
#define TIM1_mode1_B   0
#define TIM1_mode2_B   0
#define TIM1_mode3_B   0
#define TIM1_mode4_B   8
#define TIM1_mode5_B   8
#define TIM1_mode6_B   8
#define TIM1_mode7_B   8
#define TIM1_mode8_B   16
#define TIM1_mode9_B   16
#define TIM1_mode10_B  16
#define TIM1_mode11_B  16
#define TIM1_mode12_B  24
#define TIM1_mode13_B  24
#define TIM1_mode14_B  24
#define TIM1_mode15_B  24



//BITS 7,6
#define TIM1_Normal_A 			  0
#define TIM1_Toggle_reserved_A     64
#define TIM1_clear_A              128
#define TIM1_set_A  			     192


//BIT5,4
#define TIM1_Normal_B 			   0
#define TIM1_Toggle_reserved_B     16
#define TIM1_clear_B              32
#define TIM1_set_B  			     48



////PRESCALER

#define   TIM1_prescaler0   0    ///NO PRE
#define   TIM1_prescaler1   1   // 1
#define   TIM1_prescaler2   2   // 8
#define   TIM1_prescaler3   3   //64
#define   TIM1_prescaler4   4   // 256
#define   TIM1_prescaler5   5   // 1024
#define   TIM1_prescaler6   6
#define   TIM1_prescaler7   7

//ICU USING HW OR  SW
#define   TIM1_mode_ICU             0
#define   TIM1_prescaler         TIM1_prescaler2   //8




#endif /* MCAL_MTIM1_TIM1_PRIV_H_ */
