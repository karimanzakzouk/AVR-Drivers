/*
 *  Created on: Jan 31, 2019
 *      Author: kariman
 */


#include"../../LIB/STD_TYPES.h"
#include"../../LIB/MACROS.h"
#include"../MDIO/DIO_int.h"
#include"../MDIO/DIO_priv.h"

#include "ICU_int.h"
#include "ICU_cfg.h"
#include "ICU_priv.h"

#include "../MINT/INT_int.h"
#include "../MINT/INT_priv.h"

volatile u8     C_TON=0 , C_TOFF=0;
volatile u8     DutyCycle=0 , Cperiod =0 ;
volatile u32    freq=0  ;


/************************** ICU HW ******************************/

void ICU_init_HW(void)
{
	//START TIMER1 , NORMAL MODE with prescaler 8
	TCCR1A_Reg =  TIM1_mode_ICU  ;

	TCCR1B_Reg = TIM1_prescaler ; //8

	//////ICP >INPUT
	DIO_SetPinDirection ( PIN30, INPUT);  //HW  >>>>>>>>  PD6


	/// EN FOR ICP INT
	 SET_BIT(TIMSK_Reg,5);

}

ISR(TIMER1_CAPT_vect) //HW
 {
 	static u8 counter_state = 0;

	 if(counter_state == 0)
	 {
		//RESET
		 TCNT1L_Reg= 0;
		 TCNT1H_Reg= 0;
		//FALLING
			CLR_BIT( TCCR1B_Reg ,6);

			//CS ++
			counter_state = 1;
	 }

	 else if(counter_state ==1 )
	 {
			C_TON =  ICR1L_Reg;
			//RESET
		   TCNT1L_Reg= 0;
			TCNT1H_Reg= 0;

			counter_state = 2;

			//RISING
			SET_BIT( TCCR1B_Reg ,6);

	 }
	 else if(counter_state ==2)
	 {
		 C_TOFF =  ICR1L_Reg;
			//RESET
		   TCNT1L_Reg= 0;
			TCNT1H_Reg= 0;


		counter_state = 1;
		//FALLING
		CLR_BIT( TCCR1B_Reg ,6);

	 }
}

/************************** ICU SW ******************************/

void EXTint0_callback(void)
{
 	static u8 counter_state = 0;

 if(counter_state == 0)
 {
	//RESET TCNT1
	    TCNT1L_Reg= 0;
		TCNT1H_Reg= 0;
 	//FALLING
 	//	SET_BIT( MCUCR_Reg ,1);
 	//	CLR_BIT( MCUCR_Reg ,0);

 		 ExtInt0_change_SENSE ( ExtInt0_falling);

 		//CS ++
 		counter_state = 1;
 }

 else if(counter_state ==1 )
 {
 	   C_TON= TCNT1L_Reg;

 		counter_state = 2;
 		//RISING
 		//SET_BIT( MCUCR_Reg ,1);
 		//SET_BIT( MCUCR_Reg ,0);

		 ExtInt0_change_SENSE ( ExtInt0_rising);

 		    //RESET TCNT1
 		    TCNT1L_Reg= 0;
 			TCNT1H_Reg= 0;
 }
 else if(counter_state ==2 )
 {
 	 C_TOFF = TCNT1L_Reg;

 	counter_state = 1;
 	//FALLING
 		//SET_BIT( MCUCR_Reg ,1);
 		//CLR_BIT( MCUCR_Reg ,0);

		 ExtInt0_change_SENSE ( ExtInt0_falling);

 		//RESET TCNT1
 		    TCNT1L_Reg= 0;
 			TCNT1H_Reg= 0;
 }
}

void ICU_init_SW(void)
{
	//START TIMER1 ,  NORMAL MODE with prescalar 8
	TCCR1A_Reg =  TIM1_mode_ICU  ;

	TCCR1B_Reg = TIM1_prescaler ; //8

}



u8 ICU_GET_dutyCycle(void)
{
	 Cperiod=   C_TON + C_TOFF ;

	 DutyCycle	 =  ( C_TON  * 100)  / (Cperiod)  ;

	 return  DutyCycle;
}

u32 ICU_GET_freq(void)
{
	 Cperiod=   C_TON + C_TOFF ;

	 freq  = (  1000000 /  (Cperiod)  );

	 return freq;

}


u8 ICU_GET_Ton(void)
{
	 return    C_TON  ;
}
u8 ICU_GET_Toff(void)
{
	 return C_TOFF;
}
u8 ICU_GET_Tperiod(void)
{
	 return  Cperiod;
}
