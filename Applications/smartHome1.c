/*
 * smartHome1.c
 *
 *  Created on: Feb 23, 2019
 *      Author: kariman
 */


#include<util/delay.h>
#include"../LIB/STD_TYPES.h"
#include"../LIB/MACROS.h"
#include"../HAL/HLCD/LCD_int.h"
#include"../HAL/HLCD/LCD_cfg.h"
#include"../HAL/HLCD/LCD_priv.h"
#include"../HAL/HKPD/KPD_int.h"
#include"../HAL/HMOT/SERVO/SERVO_int.h"
#include"../HAL/HMOT/SERVO/SERVO_cfg.h"
#include"../HAL/HMOT/SERVO/SERVO_priv.h"
#include"../MCAL/MDIO/DIO_int.h"
#include"../MCAL/MDIO/DIO_priv.h"
#include"../MCAL/MADC/ADC_int.h"
#include"../MCAL/MADC/ADC_priv.h"
#include"../MCAL/MTIM1/TIM1_int.h"
#include"../MCAL/MTIM1/TIM1_cfg.h"
#include"../MCAL/MTIM1/TIM1_priv.h"
#include"../MCAL/MINT/INT_int.h"
#include"../MCAL/MINT/INT_priv.h"


/************* PASSWARD TO OPEN A DOOR ( lcd + keypad + servo ) **********************/

void main (void)
{
	 u8 switch_press=0, i=0, num1=0 ,num2=0 ,num3=0, password = 0 ;
	  u32 light_read_val=0, light_actual_val=0;
	  u32 temp_read_val=0, temp_actual_val=0;
	  u8  ch = 0;

	   KPD_Init();
	   LCD_vidInit();
	   LCD_vidWriteExtraChar();
       SERVO_init();
	   GlobalInt_EN();
   	   ADC_Init();
       TIM1_init();


		ServoSetAngle(0);
		LCD_vidGotoxy(1,1);
		LCD_vidWriteString("Enter password");

	 while(1)
	{


		  switch ( ch)
				{
			                    case 1:
			    							    light_read_val  = ADC_Read(1);
			    							    break;
			    				case 0:
			    							    temp_read_val  = ADC_Read( 0);    break;
			    			  default:           break;
				}
			        light_actual_val = ( (light_read_val * 5 * 1000) / 256 )  ; //0>5000MV
					temp_actual_val = ( ( (temp_read_val * 5 * 1000) / 256 ) / 100   ); //0>50 C

					LCD_vidGotoxy(6,2);
					LCD_vidWriteString("temp");
					LCD_vidPrintNum(temp_actual_val);
					LCD_vidWriteData('C');

					 if(light_actual_val>=0 && light_actual_val<= 1500)   ///led
					 {
						 TIM1_SET_OCRB(250);  // PD4
					 }
					 else if(light_actual_val>=1700 && light_actual_val<= 3000)
					 {
						 TIM1_SET_OCRB(100);  // PD4
					 }
					 else if(light_actual_val>=3200 && light_actual_val<= 5000)
					 {
						 TIM1_SET_OCRB(5);  // PD4
					 }
					 else{}

					 if(  temp_actual_val>=0 &&  temp_actual_val<= 18)   ///FAN
					 {
						     TIM1_SET_OCRA(150);  // PD5
							LCD_vidGotoxy(15,2);
							LCD_vidPrintNum(1);
							LCD_vidWriteData('X');
					 }
					 else if( temp_actual_val>=20 &&  temp_actual_val<= 27)
					 {
						              TIM1_SET_OCRA(200);  // PD5
							          LCD_vidGotoxy(15,2);
										LCD_vidPrintNum(2);
										LCD_vidWriteData('X');
					 }
					 else if( temp_actual_val>=30 &&  temp_actual_val<= 50)
					 {
						             TIM1_SET_OCRA(250);  // PD5
							           LCD_vidGotoxy(15,2);
										LCD_vidPrintNum(3);
										LCD_vidWriteData('X');
					 }
					 else{}

					               ch  ^=1 ;


		 	if(i==0)
		 	{
		 		// 0>>>>9
		 		switch_press= kPD_Get_SwitchNumber();
		 			_delay_ms(300);
		 			if (switch_press!=0)
		 			{
		 					 LCD_vidGotoxy(1+i,2);
		 					 _delay_ms(2);
		 					 LCD_vidWriteData(2);/////
		 					 num1 = switch_press-1;
		 					 i++;
		 			}
		 	}
		 	if(i==1)
		 	{
		 		switch_press= kPD_Get_SwitchNumber();
		 			_delay_ms(300);
		 			if (switch_press!=0)
		 			{
		 				    LCD_vidGotoxy(1+i,2);
		 					_delay_ms(2);
		 					LCD_vidWriteData(2);//////
		 					 num2 = switch_press-1;
		 					 i++;
		 			}
		 	}
		 	if(i==2)
		 	{
		 		    switch_press= kPD_Get_SwitchNumber();
		 			_delay_ms(300);
		 			if (switch_press!=0)
		 			{
		 					 LCD_vidGotoxy(1+i,2);
		 					 _delay_ms(2);
		 					LCD_vidWriteData(2);///////
		 					 num3 = switch_press-1;
		 					 i++;
		 			}
		 	}
			 if(i==3)
			 {
                password = num1 *100 + num2 * 10 + num3 ;
                if (password == 111)
                {
                	 ServoSetAngle(90);

  					LCD_vidWriteCmd(lcd_Clear);//clear
  					LCD_vidWriteString("correct");
                	 i=4;
                }
                else
                {
               	    LCD_vidGotoxy(1,1);
 					LCD_vidWriteCmd(lcd_Clear);//clear
        			LCD_vidWriteString("incorrect");
                	 LCD_vidGotoxy(1,2);
                	 LCD_vidWriteString("try again");
                	_delay_ms(1000);
 					LCD_vidWriteCmd(lcd_Clear);//clear

 					LCD_vidGotoxy(1,1);
 					LCD_vidWriteString("Enter password");
                	  i=0 ;
                }
			 }
	}
}

