/*
 * TIMER1_cfg.h
 *
 *  Created on: Jan 31, 2019
 *      Author: kariman
 */

#ifndef MCAL_MTIM1_TIM1_CFG_H_
#define MCAL_MTIM1_TIM1_CFG_H_

#include "TIM1_priv.h"



/*
//TCCR1
MODE :
 * Bit 7:6 � COM1A1:0: Compare Output Mode for Channel A
   Bit 5:4 � COM1B1:0: Compare Output Mode for Channel B

 *    -----------------------------------------------------------------------------

 * Bit 5:4 � COM01:0: Compare Match Output Mode
 *
 *                     Compare Output Mode, non-PWM Mode:
 *
 *             COM1A1/COM1B1  COM1A0/COM1B0   Description
                           0    0     		Normal port operation, OC0 disconnected.
                           0    1     		Toggle OC0 on compare match
                           1    0    		 Clear OC0 on compare match
                           1    1     		Set OC0 on compare match
                      ------------------------------------------------------

                           Compare Output Mode, Fast PWM Mode:

				COM1A1/COM1B1   COM1A0/COM1B0     	Description
							0  		0 			Normal port operation, OC0 disconnected.
							0 		1 			Reserved
							1		0 			Clear OC0 on compare match, set OC0 at TOP
							1 		1 			Set OC0 on compare match, clear OC0 at TOP
                      ------------------------------------------------------

							Compare Output Mode, Phase Correct PWM Mode:

				COM1A1/COM1B1   COM1A0/COM1B0		Description
							0 		0 		Normal port operation, OC0 disconnected.
							0 		1 		Reserved
							1 		0   	Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.

							1 		1 		Set OC0 on compare match when up-counting. Clear OC0 on compare 	match when downcounting.
-----------------------------------------------------------------------------
 � Bit 3 � FOC1A: Force Output Compare for Channel A
 � Bit 2 � FOC1B: Force Output Compare for Channel B
 *--------------------------------------------------------------------------

� Bit 1:0 � WGM11:10: Waveform Generation Mode    TCCR1A
� Bit 4:3 � WGM13:12: Waveform Generation Mode    TCCR1B

Waveform Generation Mode Bit Description(1)

Mode WGM13 WGM12  WGM11  WGM10     Timer/Counter Mode of

0 	0	 0		 0 		0 		Normal 0xFFFF Immediate MAX
1 	0	 0		 0	 	1 		PWM, Phase Correct, 8-bit 0x00FF TOP BOTTOM
2 	0 	 0	 	 1	    0 		PWM, Phase Correct, 9-bit 0x01FF TOP BOTTOM
3 	0	 0		 1 		1 		PWM, Phase Correct, 10-bit 0x03FF TOP BOTTOM
4 	0 	 1		 0 		0 		CTC OCR1A Immediate MAX
5 	0	 1	 	 0 		1 		Fast PWM, 8-bit 0x00FF TOP TOP
6 	0 	 1	 	 1 		0 		Fast PWM, 9-bit 0x01FF TOP TOP
7 	0 	 1	 	 1	 	1 		Fast PWM, 10-bit 0x03FF TOP TOP
8 	1 	 0		 0		0		 PWM, Phase and Frequency Correct ICR1 BOTTOM BOTTOM
9 	1 	 0  	 0		1 		PWM, Phase and Frequency Correct OCR1A BOTTOM BOTTOM
10 	1 	 0		 1		 0 	 	PWM, Phase Correct ICR1 TOP BOTTOM
11 	1 	 0		 1		 1 		PWM, Phase Correct OCR1A TOP BOTTOM
12 	1	 1	 	 0		 0 		CTC ICR1 Immediate MAX
13 	1 	 1 		 0 		1 		Reserved � � �
14 	1 	 1		 1		 0 		Fast PWM ICR1 TOP TOP
15 	1 	 1 		 1 		1 		Fast PWM OCR1A TOP TOP
--------------------------------------------------------------------------

//TCCR1B

Bit 7 � ICNC1: Input Capture Noise Canceler
Bit 6 � ICES1: Input Capture Edge Select
Bit 5 � Reserved Bit
Bit 4:3 � WGM13:2: Waveform Generation Mode

//Bit 2:0 � CS02:0:       Clock Select:

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
*/


/*
#define TIM1_mode_A            TIM1_mode0_A
#define TIM1_mode_B            TIM1_mode0_B


#define TIM1_COM0_1_A           TIM1_Normal_A   //OCIA
#define TIM1_COM0_1_B           TIM1_Normal_B   //0C1B

*/

//PWM MODE
#define TIM1_modeA   TIM1_mode5_A
#define TIM1_modeB   TIM1_mode5_B

#define  TIM1_COM0_1A   TIM1_clear_A
#define  TIM1_COM0_1B   TIM1_clear_B


//ICU USING HW OR  SW
#define   TIM1_mode_ICU             0
#define   TIM1_prescaler         TIM1_prescaler2   //8



#endif /* MCAL_MTIM1_TIM1_CFG_H_ */
