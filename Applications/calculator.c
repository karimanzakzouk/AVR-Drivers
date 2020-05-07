/*
 * calc.c
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
#include"../MCAL/MDIO/DIO_int.h"
#include"../MCAL/MDIO/DIO_priv.h"

//CALC ( KEYPAD + lcd )

void main (void)
{
	 u8 switch_press=0, i=0, result=0 ,num1=0 ,num2=0 ,op=0;

	   KPD_Init();
	   LCD_vidInit();
	   LCD_vidWriteExtraChar();

	 while(1)
	{
		 	if(i==0)
		 	{
		 		switch_press= kPD_Get_SwitchNumber();
		 			_delay_ms(300);
		 			if (switch_press!=0)
		 			{
		 				if((switch_press-1)==10)//clear
		 				{
		 					LCD_vidWriteCmd(lcd_Clear);
		 					_delay_ms(2);
		 					i=0;
		 				}
		 				else
		 				{
		 					 LCD_vidGotoxy(1+i,1);
		 					_delay_ms(2);
		 					//LCD_vidWriteData((switch_press-1)+'0');
		 					 	 LCD_vidPrintNum(switch_press-1);
		 					 num1 = switch_press-1;
		 					 i++;
		 				}
		 			}
		 	}

		 	if(i==1)
		 	{
		 		switch_press= kPD_Get_SwitchNumber();
		 			_delay_ms(300);
		 			if (switch_press!=0)
		 			{
		 				if((switch_press-1)==10)
		 				{
		 					LCD_vidWriteCmd(lcd_Clear);//clear
		 					_delay_ms(2);
		 					i=0;
		 				}
		 				else
		 				{
		 					 LCD_vidGotoxy(1+i,1);
		 					_delay_ms(2);
		 					if((switch_press-1)==12)
		 					{
		 						LCD_vidWriteData(0);
		 					}
		 					else if((switch_press-1)==13)
		 					{
		 						LCD_vidWriteData(1);
		 					}
		 					else if((switch_press-1)==14)
		 					{
		 						LCD_vidWriteData(2);
		 					}
		 					else if((switch_press-1)==15)
		 					{
		 						LCD_vidWriteData(3);
		 					}
		 					else{}

		 					op = switch_press-1;
		 					   i++;
		 				}
		 			}
		 	}
		 	if(i==2)
		 	{
		 		switch_press=  kPD_Get_SwitchNumber();
		 			_delay_ms(300);
		 			if (switch_press!=0)
		 			{
		 				if((switch_press-1)==10)
		 				{
		 					LCD_vidWriteCmd(lcd_Clear);
		 					_delay_ms(2);
		 					i=0;
		 				}
		 				else
		 				{
		 					 LCD_vidGotoxy(1+i,1);
		 					 _delay_ms(2);
		 					// LCD_vidWriteData((switch_press-1)+'0');
		 					 LCD_vidPrintNum(switch_press-1);
		 					 num2 = switch_press-1;
		 					 i++;
		 				}
		 			}
		 	}
		 if(i>2)
		 {
		 		switch(op)
		 		{
		 		case 12 : //  +
		 			result = num1 +num2 ;
		 			LCD_vidWriteData('=');
		 			LCD_vidPrintNum(result);
		 	    	i=0;
		 			break;
		 		case 13 : //  -
		 			result = num1 - num2 ;
		 			LCD_vidWriteData('=');
		 			LCD_vidPrintNum(result);
		 	    	i=0;
		 			break;
		 		case 14 : //  *
		 			result = num1 * num2 ;
		 			LCD_vidWriteData('=');
		 			LCD_vidPrintNum(result);
		 	    	i=0;
		 			break;
		 		case 15 : //  /
		 			if(num2==0)
		 			{
		 				LCD_vidWriteData('e');
		 				LCD_vidWriteData('r');
		 				LCD_vidWriteData('r');
		 				LCD_vidWriteData('o');
		 				LCD_vidWriteData('r');
		 				_delay_ms(2000);
		 				LCD_vidWriteCmd(lcd_Clear); //clear
		 				_delay_ms(2);
		 				i=0;
		 			}
		 			else
		 			{
		 				result = num1 / num2 ;
		 				LCD_vidWriteData('=');
		 				LCD_vidPrintNum(result);
		 				i=0;
		 			}

		 			break;
		 		default :
		 			break;
		 		}
		 }
		 switch_press=  kPD_Get_SwitchNumber();
		 	_delay_ms(300);
		 	if (switch_press!=0)
		 	{
		 		if((switch_press-1)==10) //clear
		 		{
		 			LCD_vidWriteCmd(lcd_Clear);
		 			_delay_ms(2);
		 			i=0;
		 		}
		 	}
	}
}

