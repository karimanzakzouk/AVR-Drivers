/*
 * SERVO_priv.h
 *
 *  Created on: Feb 1, 2019
 *      Author: kariman
 */

#ifndef HAL_HMOT_SERVO_SERVO_PRIV_H_
#define HAL_HMOT_SERVO_SERVO_PRIV_H_


// Registers  >>>>timer 0

#define TCCR0_Reg   *((volatile u8*)0x53)

#define TCNT0_Reg   *((volatile u8*)0x52)

#define OCR0_Reg    *((volatile u8*)0x5C)

#define TIMSK_Reg   *((volatile u8*)0x59)


//   MODES
#define TIM0_mode0   0
#define TIM0_mode1   64
#define TIM0_mode2   8
#define TIM0_mode3   72    // fast pwm


#define TIM0_Normal 			   0
#define TIM0_Toggle_reserved      16
#define TIM0_clear                32
#define TIM0_set 			      48


#define   TIM0_prescaler0   0    ///NO PRE
#define   TIM0_prescaler1   1   // 1
#define   TIM0_prescaler2   2   // 8
#define   TIM0_prescaler3   3   //64
#define   TIM0_prescaler4   4   // 256
#define   TIM0_prescaler5   5   // 1024
#define   TIM0_prescaler6   6   //Clock on falling edge.
#define   TIM0_prescaler7   7   //Clock on rising  edge.



#endif /* HAL_HMOT_SERVO_SERVO_PRIV_H_ */
