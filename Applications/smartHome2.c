/*
 * smartHome2.c
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
#include"../MCAL/MTIM1/TIM1_int.h"
#include"../MCAL/MTIM1/TIM1_cfg.h"
#include"../MCAL/MTIM1/TIM1_priv.h"
#include"../MCAL/MUART/UART_int.h"
#include"../MCAL/MUART/UART_cfg.h"
#include"../MCAL/MUART/UART_priv.h"
#include"../MCAL/MADC/ADC_int.h"
#include"../MCAL/MADC/ADC_priv.h"

/* MINI SMART HOME >>>> UART+ SERVO , 2 ADC CH + DC + LED */

void main (void)
{
      u8 arr[3]={0,0,0};
      u8 i = 0, angle =0 ,x, y,z , N , S ,TASK = 1, TEST=0;

 	  u32 light_read_val=0, light_actual_val=0;
 	  u32 temp_read_val=0, temp_actual_val=0;
 	  u8  ch = 0;

	   GlobalInt_EN();
   	   ADC_Init();
       TIM1_init();
  	   LCD_vidInit();
       UART_Init();
  	   SERVO_init();

	while(1)
	{
		LCD_vidGotoxy(1,1);
		LCD_vidWriteString (ptr1);

		LCD_vidGotoxy(1,2);
		LCD_vidWriteString (ptr2);

		LCD_vidGotoxy(10,2);
		LCD_vidWriteString (ptr3);

		ServoSetAngle( angle );
		LCD_vidGotoxy(7,1);
		LCD_vidPrintNum(angle);

while( ( (TASK ==1 )  &&  (TEST != 2)  ) || ((UCSRA_Reg &0x80) == 0x00) ) //    || ( UDR_Reg == 0)  )
 {
		switch ( ch)
			{
		                    case 1:
		    							    light_read_val  = ADC_Read( 1);    TEST =2;  TASK =2 ;  break;
		    				case 0:
		    							    temp_read_val  = ADC_Read( 0);  TEST =1;   break;
		    			  default:           break;
			}

		light_actual_val = ( (light_read_val * 5 * 1000) / 256 )  ; //0>5000MV
		temp_actual_val = ( ( (temp_read_val * 5 * 1000) / 256 ) / 100   ); //0>50 C

		LCD_vidGotoxy(6,2);
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
 }


while( (TASK == 2)  )//&& (  UDR_Reg != 0)  ) //  && ((UCSRA_Reg &0x80) != 0x00)
{
	if(i==0)
		{
			 x = UART_GetChar();

			 if(x=='0')
			 {
				 arr[0] =0;
			 }
			 else if(x == '1')
              {
            	  arr[0] =1;
              }
              else if ( x== '2')
              {
            	  arr[0] =2;
              }
              else if ( x== '3')
              {
            	  arr[0] =3;
              }
              else if ( x== '4')
              {
            	  arr[0] =4;
              }
              else if ( x== '5')
              {
            	  arr[0] =5;
              }
              else if ( x== '6')
              {
            	  arr[0] =6;
              }
              else if ( x== '7')
              {
            	  arr[0] =7;
              }
              else if ( x== '8')
              {
            	  arr[0] =8;
              }
              else if ( x== '9')
              {
            	  arr[0] =9;
              }
			 i++;
		}
		else if (i ==1)
		{
			 y =  UART_GetChar() ;

			 if(y=='0')
			 {
				 arr[1] =0;
				 i++;
			 }
			 else if(y == '1')
              {
            	  arr[1] =1;
            	  i++;
              }
              else if ( y== '2')
              {
            	  arr[1] =2;
            	  i++;
              }
              else if ( y== '3')
              {
            	  arr[1] =3;
            	  i++;
              }
              else if ( y== '4')
              {
            	  arr[1] =4;
            	  i++;
              }
              else if ( y== '5')
              {
            	  arr[1] =5;
            	  i++;
              }
              else if ( y== '6')
              {
            	  arr[1] =6;
            	  i++;
              }
              else if ( y== '7')
              {
            	  arr[1] =7;
            	  i++;
              }
              else if ( y== '8')
              {
            	  arr[1] =8;
            	  i++;
              }
              else if ( y== '9')
              {
            	  arr[1] =9;
            	  i++;
              }
              else if ( y== 'G')
              {
            	  N = 1;
            	  i=4;
              }
		}
		else if(i==2)
		{
			 z =  UART_GetChar() ;

			 if(z =='0')
			 {
				 arr[2] = 0;
				 i=3;
			 }
			 else if(z == '1')
              {
            	  arr[2] =1;
            		 i=3;
              }
              else if ( z== '2')
              {
            	  arr[2] =2;
            		 i=3;
              }
              else if ( z== '3')
              {
            	  arr[2] =3;
            		 i=3;
              }
              else if ( z== '4')
              {
            	  arr[2] =4;
            		 i=3;
              }
              else if ( z== '5')
              {
            	  arr[2] =5;
            		 i=3;
              }
              else if ( z== '6')
              {
            	  arr[2] =6;
            		 i=3;
              }
              else if ( z== '7')
              {
            	  arr[2] =7;
            		 i=3;
              }
              else if ( z== '8')
              {
            	  arr[2] =8;
            		 i=3;
              }
              else if ( z== '9')
              {
            	  arr[2] =9;
            		 i=3;
              }
              else if ( z== 'G')
              {
            	  N = 2;
            	  i=4;
              }
		}
		 else if(i==3)
		 {
			 S =  UART_GetChar();
             if ( S== 'G')
             {
           	    N = 3;
             	 i=4;
             }
		 }

			if( (N ==1) && (i==4) )
			{
				   angle =   arr[0]  ;
					 i = 0 ;
			}
			else if( (N ==2) && (i==4) )
			{
				   angle =  ( arr[0] * 10  ) +  arr[1] ;
					 i = 0 ;
			}
			else if( (N ==3)  && (i==4) )
			{
				   angle =  ( arr[0] * 100  ) +  ( arr[1]* 10 ) + arr[2] ;
					 i = 0 ;
			}
			  TASK =1 ; TEST = 0 ;
}
		   _delay_ms(1000);
 		   LCD_vidWriteCmd(lcd_Clear );
	}
}


