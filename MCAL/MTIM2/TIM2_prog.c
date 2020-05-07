/*
 * TIMER2_prog.c
 *
 *  Created on: Jan 31, 2019
 *      Author: kariman
 */


#include"../../LIB/STD_TYPES.h"
#include"../../LIB/MACROS.h"

#include"../MDIO/DIO_int.h"

#include "TIM2_int.h"
#include "TIM2_cfg.h"
#include "TIM2_priv.h"

#include "../MINT/INT_int.h"
#include "../MINT/INT_priv.h"


 u8  TIM2_prescaler=0;

void TIM2_init(void)
{
	DIO_SetPinDirection ( PIN31  , OUTPUT);  // OCR2   //PD7

	TCCR2_Reg =    TIM2_mode + TIM2_COM0_1 +  TIM2_prescaler;
}

void TIM2_start(u8 u8prescaler)
{
	 //select prescaler
		if(u8prescaler !=  TIM2_prescaler0 )
		{
		   TIM2_prescaler = u8prescaler;
		}
		TCCR2_Reg += TIM2_prescaler ;
}

void TIM2_stop(void)
{
	  TIM2_prescaler = TIM2_prescaler0;

}

void TIM2_SET_OCR(u16 u16OCR_VAL)
{
	//FOR PWM GEN
     // 0 >>> 255

	OCR2_Reg = u16OCR_VAL;

}

void TIM2_SET_TCNT(u8 u8TCNT_VAL)
{
	/// 0>> 255

	TCNT2_Reg = u8TCNT_VAL;
}



 void TIM2_enable_interrupt(  u8 u8EN ,u8 u8INT_case)  // o.v >> 1 // ctc >>> 2  ////// EN 1 OR DISABLE 0
 {
u8 TIM2_OV_INT_Enable  , TIM2_CTC_INT_Enable;

	if(u8EN == TIM2_INT_EN  )
	{
			// SREG = 0X80;  // GIE

			 if(u8INT_case == TIM2_OV_INT_En )
			 {
				    TIM2_OV_INT_Enable = TIM2_OV_INT_En; // EN >> INT   OR   0 TO  DISABLE >> INT    >>>>>>>>>>>>Overflow Interrupt Enable
					TIM2_CTC_INT_Enable = 0 ;
			 }
			 else if(u8INT_case ==  TIM2_CTC_INT_En )
			 {
				 TIM2_CTC_INT_Enable = TIM2_CTC_INT_En ; // EN >> INT   OR   0 TO  DISABLE >> INT    >>>>>>>>>>>>Output Compare Match Interrupt Enable
				 TIM2_OV_INT_Enable = 0 ;
			 }
	}
	else
	{
		TIM2_OV_INT_Enable = 0 ; // disable
		TIM2_CTC_INT_Enable = 0 ;
	}

	 TIMSK_Reg +=   ( TIM2_OV_INT_Enable + 	TIM2_CTC_INT_Enable );

 }
ISR (TIMER2_OVF_vect )
{
	//TIM2_OV_callback();

}

ISR (TIMER2_COMP_vect )
{
//	 TIM2_CTC_callback();

}


