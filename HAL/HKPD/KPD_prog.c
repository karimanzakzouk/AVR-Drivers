/*
 * KPD_prog.c
 *
 *  Created on: Jan 10, 2019
 *      Author: kariman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/MACROS.h"
#include<util/delay.h>
#include"../../MCAL/MDIO/DIO_int.h"
#include"../../MCAL/MDIO/DIO_priv.h"
#include"KPD_int.h"

#include"../HLCD/LCD_int.h"
#include"../HLCD/LCD_cfg.h"
#include"../HLCD/LCD_priv.h"


void KPD_Init(void)
{
	DIO_SetPinDirection(KPD_COL1,OUTPUT)	;
	DIO_SetPinDirection(KPD_COL2,OUTPUT)	;
	DIO_SetPinDirection(KPD_COL3,OUTPUT)	;
	DIO_SetPinDirection(KPD_COL4,OUTPUT)	;

	DIO_SetPinDirection(KPD_ROW1,INPUT)	;
	DIO_SetPinDirection(KPD_ROW2,INPUT)	;
	DIO_SetPinDirection(KPD_ROW3,INPUT)	;
	DIO_SetPinDirection(KPD_ROW4,INPUT)	;

	//////////pull up
	DIO_SetPinValue ( KPD_ROW1  ,HIGH);
	DIO_SetPinValue ( KPD_ROW2  ,HIGH);
	DIO_SetPinValue ( KPD_ROW3  ,HIGH);
	DIO_SetPinValue ( KPD_ROW4  ,HIGH);
}

u8 kPD_Get_SwitchNumber(void)
{
	u8 colum_number=0,row_number=0;
	u8 switch_number = 0;
	u8 getter=1;

	for(colum_number=0;colum_number<=3;colum_number++)
	{
		DIO_SetPinValue ( KPD_COL1  ,HIGH);
		DIO_SetPinValue ( KPD_COL2  ,HIGH);
		DIO_SetPinValue ( KPD_COL3  ,HIGH);
		DIO_SetPinValue ( KPD_COL4  ,HIGH);

		if(colum_number == 0)
		{
			DIO_SetPinValue ( KPD_COL1  ,LOW);
		}
		else if(colum_number == 1)
		{
			DIO_SetPinValue ( KPD_COL2  ,LOW);
		}
		else if(colum_number == 2)
		{
			DIO_SetPinValue ( KPD_COL3  ,LOW);
		}
		else if(colum_number == 3)
		{
			DIO_SetPinValue ( KPD_COL4  ,LOW);
		}
		else{}


			 for(row_number=0;row_number<=3;row_number++)
			 {

					if(row_number == 0)
					{
						   getter =  DIO_GetPinValue(KPD_ROW1 );
					}
					else if(row_number == 1)
					{
						   getter =  DIO_GetPinValue(KPD_ROW2 );
					}
					else if(row_number == 2)
					{
						   getter =  DIO_GetPinValue(KPD_ROW3 );
					}
					else if(row_number == 3)
					{
						   getter =  DIO_GetPinValue(KPD_ROW4 );
					}
					else{}


					if (getter == 0)
					{

						if(row_number == 0)
						{
							while(  (DIO_GetPinValue(KPD_ROW1) )  == 0  );
						}
						else if(row_number == 1)
						{
							while(  (DIO_GetPinValue(KPD_ROW2) )  == 0  );
						}
						else if(row_number == 2)
						{
							while(  (DIO_GetPinValue(KPD_ROW3) )  == 0  );
						}
						else if(row_number == 3)
						{
							while(  (DIO_GetPinValue(KPD_ROW4) )  == 0  );
						}
						else{}

						switch_number= ( row_number * 4) + colum_number + 1 ;

						// Delay to avoid bouncing
						_delay_ms(10);
					}

			 }
	}

	return switch_number ;
}
