/*
 * TIMER2_cfg.h
 *
 *  Created on: Jan 31, 2019
 *      Author: kimoz
 */


#ifndef MCAL_MTIM2_TIM2_CFG_H_
#define MCAL_MTIM2_TIM2_CFG_H_

#include "TIM2_priv.h"

/*
MODES   >> bits 6, 3
#define TIM2_mode0   0     // normal
#define TIM2_mode1   64    //PWM, Phase Correct
#define TIM2_mode2   8      // CTC
#define TIM2_mode3   72    // fast pwm

//bits 5,4
#define TIM2_Normal 			   0
#define TIM2_Toggle_reserved      16
#define TIM2_clear                32
#define TIM2_set 			      48

 */

#define TIM2_mode          TIM2_mode0
#define TIM2_COM0_1        TIM2_Normal


#endif /* MCAL_MTIM2_TIM2_CFG_H_ */
