/*
 * SERVO_cfg.h
 *
 *  Created on: Feb 1, 2019
 *      Author: kariman
 */

#ifndef HAL_HMOT_SERVO_SERVO_CFG_H_
#define HAL_HMOT_SERVO_SERVO_CFG_H_

#include "SERVO_priv.h"


/*
TCCR0
MODE :
 *    Bit 7 � FOC0: Force Output Compare    >>>>>>>>>  0
 *    -----------------------------------------------------------------------------
 *    Bit 6, 3 � WGM01:0: Waveform Generation Mode  :
 *     0 >> 0 0 >>>   Normal
 *     1 >> 0 1 >>>   PWM, Phase Correct
 *     2 >> 1 0 >>>   CTC
 *     3 >> 1 1 >>>   Fast PWM
 *--------------------------------------------------------------------------
 * Bit 5:4 � COM01:0: Compare Match Output Mode
 *
 *                     Compare Output Mode, non-PWM Mode:
 *
 *                     COM01 COM00    Description
                           0    0     Normal port operation, OC0 disconnected.
                           0    1     Toggle OC0 on compare match
                           1    0     Clear OC0 on compare match
                           1    1     Set OC0 on compare match
                      ------------------------------------------------------

                           Compare Output Mode, Fast PWM Mode:

							COM01    COM00  	Description
							0  		0 			Normal port operation, OC0 disconnected.
							0 		1 			Reserved
							1		0 			Clear OC0 on compare match, set OC0 at TOP
							1 		1 			Set OC0 on compare match, clear OC0 at TOP
                      ------------------------------------------------------

							Compare Output Mode, Phase Correct PWM Mode:

						COM01	 COM00 		Description
							0 		0 		Normal port operation, OC0 disconnected.
							0 		1 		Reserved
							1 		0   	Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.

							1 		1 		Set OC0 on compare match when up-counting. Clear OC0 on compare 	match when downcounting.
-----------------------------------------------------------------------------

Bit 2:0 � CS02:0: Clock Select:

CS02 CS01 CS00 Description
0 		0 		 0 No clock source (Timer/Counter stopped).
0 		0 		 1 clkI/O/(No prescaling)
0 		1		 0 clkI/O/8 (From prescaler)
0 		1		 1 clkI/O/64 (From prescaler)
1 		0 		 0 clkI/O/256 (From prescaler)
1 		0		 1 clkI/O/1024 (From prescaler)
1		1 	   	 0 External clock source on T0 pin. Clock on falling edge.
1 		1		 1 External clock source on T0 pin. Clock on rising edge.
---------------------------------------------------------------------------------------------------
 *
*/
// select mode :

#define TIM0_mode            TIM0_mode3   // fast pwm

#define TIM0_COM0_1          TIM0_clear   //OC0

//#define TIM0_prescaler       TIM0_prescaler2    /////////////// PWM GEN //PRE = 8

#define TIM0_prescaler       TIM0_prescaler5      // 1024   SERVOOOOOOOOOOOOOOOOOOS



#endif /* HAL_HMOT_SERVO_SERVO_CFG_H_ */
