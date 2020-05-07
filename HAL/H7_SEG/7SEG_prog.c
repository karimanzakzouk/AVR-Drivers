/*
 *  Created on: Jan 5, 2019
 *      Author: kariman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/MACROS.h"
#include<util/delay.h>
#include"../../MCAL/MDIO/DIO_int.h"
#include "7SEG_cfg.h"
#include "7SEG_int.h"
#include "7SEG_priv.h"


void _7SEG_vidInit(void)
{
		 DIO_SetPinDirection ( _7SEG_A, OUTPUT);  
		 DIO_SetPinDirection ( _7SEG_B, OUTPUT);
		 DIO_SetPinDirection ( _7SEG_C, OUTPUT);
		 DIO_SetPinDirection ( _7SEG_D, OUTPUT);
		 DIO_SetPinDirection (_7SEG_E, OUTPUT);
		 DIO_SetPinDirection (_7SEG_F, OUTPUT);
		 DIO_SetPinDirection ( _7SEG_G, OUTPUT);
}

void _7_SEG_vidWriteNum(u8 u8num)
{
//active low
	  u8 arr[10]={0b1000000, 0b1111001, 0b0100100, 0b0110000,0b0011001, 0b0010010, 0b0000010, 0b1111000, 0b0000000, 0b0010000};
if(Active_mode ==0)
{
	DIO_SetPinValue(_7SEG_A , GET_BIT(arr[u8num] , 0) );
	DIO_SetPinValue(_7SEG_B , GET_BIT(arr[u8num] , 1) );
	DIO_SetPinValue(_7SEG_C , GET_BIT(arr[u8num] , 2) );
	DIO_SetPinValue(_7SEG_D , GET_BIT(arr[u8num] , 3) );
	DIO_SetPinValue(_7SEG_E , GET_BIT(arr[u8num] , 4) );
	DIO_SetPinValue(_7SEG_F , GET_BIT(arr[u8num] , 5) );
	DIO_SetPinValue(_7SEG_G , GET_BIT(arr[u8num] , 6) );
}

else if(Active_mode ==1)
{
	DIO_SetPinValue(_7SEG_A ,~ ( GET_BIT(arr[u8num] ,  0) ) );
	DIO_SetPinValue(_7SEG_B ,~  ( GET_BIT(arr[u8num] , 1) ) );
	DIO_SetPinValue(_7SEG_C ,~ ( GET_BIT(arr[u8num] ,  2) ) );
	DIO_SetPinValue(_7SEG_D ,~ ( GET_BIT(arr[u8num] ,  3) ) );
	DIO_SetPinValue(_7SEG_E ,~  ( GET_BIT(arr[u8num] , 4) ) );
	DIO_SetPinValue(_7SEG_F ,~  ( GET_BIT(arr[u8num] , 5) ) );
	DIO_SetPinValue(_7SEG_G ,~( GET_BIT(arr[u8num] ,   6)  ) );

}


}




