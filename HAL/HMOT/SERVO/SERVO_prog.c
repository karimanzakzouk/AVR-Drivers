/*
 * SERVO_prog.c
 *
 *  Created on: Feb 1, 2019
 *      Author: kariman
 */


#include<avr/interrupt.h>
#include"../../../LIB/STD_TYPES.h"
#include"../../../LIB/MACROS.h"
#include"../../../MCAL/MDIO/DIO_int.h"
#include "SERVO_int.h"
#include "SERVO_cfg.h"
#include "SERVO_priv.h"


void SERVO_init(void)
{

	DIO_SetPinDirection ( PIN11  , OUTPUT);  // OCR 0   //PB3

	TCCR0_Reg =    TIM0_mode + TIM0_COM0_1 +  TIM0_prescaler ;    // PWM +  clear + PRE 1024


	TCNT0_Reg = 157 ; /// 20 m sec

}

void ServoSetAngle(u8 u8angle )  //0>>>180 degree  >>    OCR0 =  3>>>>>18
{

	OCR0_Reg  = ( (u8angle * 15)  / 180  )   + 3 ;   ///BETTER

	//OCR0_Reg  = ( (u8angle * 14)  / 180  )   + 2 ;

/*
angles :

 	 0 >>> 2
	45 >>> 5
	90 >>> 7 or 9
	135  >>> 12
	180  >>> 16

*/
}







