/*
 * LCD_prog.c
 *
 *  Created on: Jan 5, 2019
 *      Author: kariman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/MACROS.h"
#include "LCD_int.h"
#include "LCD_cfg.h"
#include "LCD_priv.h"


#include<util/delay.h>
#include"../../MCAL/MDIO/DIO_int.h"




void LCD_vidInit(void)
{

   // CONTROL PINS
	 DIO_SetPinDirection ( RS, OUTPUT);   // RS > OUTPUT
	 DIO_SetPinDirection ( RW, OUTPUT);   // RW > OUTPUT
	 DIO_SetPinDirection ( E , OUTPUT);   // E > OUTPUT

	switch(mode)
	{
	case 0:  // 8 bits
		// DATA PINS >>> 8 BITS
		 DIO_SetPinDirection ( D0, OUTPUT);   // RS > OUTPUT
		 DIO_SetPinDirection ( D1, OUTPUT);   // RS > OUTPUT
		 DIO_SetPinDirection ( D2, OUTPUT);   // RS > OUTPUT
		 DIO_SetPinDirection ( D3, OUTPUT);   // RS > OUTPUT
		 DIO_SetPinDirection ( D4, OUTPUT);   // RS > OUTPUT
		 DIO_SetPinDirection ( D5, OUTPUT);   // RS > OUTPUT
		 DIO_SetPinDirection ( D6, OUTPUT);   // RS > OUTPUT
		 DIO_SetPinDirection ( D7, OUTPUT);   // RS > OUTPUT

		LCD_vidWriteCmd(lcd_FunctionSet8bit);
		_delay_ms(1);
		 LCD_vidWriteCmd(lcd_DisplayOn);
		_delay_ms(1);
		 LCD_vidWriteCmd(lcd_Clear);
		_delay_ms(1);
		 LCD_vidWriteCmd(lcd_EntryMode);
		_delay_ms(1);
		break;

	case 1:  // 4 bits
		 DIO_SetPinDirection ( D4, OUTPUT);   // RS > OUTPUT
		 DIO_SetPinDirection ( D5, OUTPUT);   // RS > OUTPUT
		 DIO_SetPinDirection ( D6, OUTPUT);   // RS > OUTPUT
		 DIO_SetPinDirection ( D7, OUTPUT);   // RS > OUTPUT

		LCD_vidWriteCmd(lcd_FunctionSet4bit_1);
		_delay_ms(1);
		LCD_vidWriteCmd(lcd_FunctionSet4bit_2);
		_delay_ms(1);
		LCD_vidWriteCmd(lcd_FunctionSet4bit_3);
		_delay_ms(1);
		 LCD_vidWriteCmd(lcd_DisplayOn);
		_delay_ms(1);
		 LCD_vidWriteCmd(lcd_Clear);
		_delay_ms(1);
		 LCD_vidWriteCmd(lcd_EntryMode);
		_delay_ms(1);
		break;

	default://8 BITS
		// DATA PINS >>> 8 BITS
		 DIO_SetPinDirection ( D0, OUTPUT);   // RS > OUTPUT
		 DIO_SetPinDirection ( D1, OUTPUT);   // RS > OUTPUT
		 DIO_SetPinDirection ( D2, OUTPUT);   // RS > OUTPUT
		 DIO_SetPinDirection ( D3, OUTPUT);   // RS > OUTPUT
		 DIO_SetPinDirection ( D4, OUTPUT);   // RS > OUTPUT
		 DIO_SetPinDirection ( D5, OUTPUT);   // RS > OUTPUT
		 DIO_SetPinDirection ( D6, OUTPUT);   // RS > OUTPUT
		 DIO_SetPinDirection ( D7, OUTPUT);   // RS > OUTPUT

		LCD_vidWriteCmd(lcd_FunctionSet8bit);
		_delay_ms(1);
		 LCD_vidWriteCmd(lcd_DisplayOn);
		_delay_ms(1);
		 LCD_vidWriteCmd(lcd_Clear);
		_delay_ms(1);
		 LCD_vidWriteCmd(lcd_EntryMode);
		_delay_ms(1);
		break;
	}

_delay_ms(1);

}

void LCD_vidWriteCmd(u8 u8cmd)
{
	  DIO_SetPinValue( RS, LOW);        // RS > 0
	  DIO_SetPinValue( RW, LOW);        //  RW> 0
switch(mode)
{
	case 0 :
			 //DIO_SetPortValue(LCD_Data_PORT, u8cmd);

		 DIO_SetPinValue( D0,   (GET_BIT(u8cmd,0))  );
		 DIO_SetPinValue( D1,   (GET_BIT(u8cmd,1))  );
		 DIO_SetPinValue( D2,   (GET_BIT(u8cmd,2))  );
		 DIO_SetPinValue( D3,   (GET_BIT(u8cmd,3))  );
		 DIO_SetPinValue( D4,   (GET_BIT(u8cmd,4))  );
		 DIO_SetPinValue( D5,   (GET_BIT(u8cmd,5))  );
		 DIO_SetPinValue( D6,   (GET_BIT(u8cmd,6))  );
		 DIO_SetPinValue( D7,   (GET_BIT(u8cmd,7))  );

	       DIO_SetPinValue( E, HIGH);        //  E >> 1
			 _delay_ms(1);
			 DIO_SetPinValue( E, LOW);        //  E >> 0
		break;
	case 1 :
		     // DIO_SetPortValue( LCD_Data_PORT , (u8cmd & 0xF0) );

		 DIO_SetPinValue( D4,   (GET_BIT(u8cmd,4))  );
		 DIO_SetPinValue( D5,   (GET_BIT(u8cmd,5))  );
		 DIO_SetPinValue( D6,   (GET_BIT(u8cmd,6))  );
		 DIO_SetPinValue( D7,   (GET_BIT(u8cmd,7))  );

         DIO_SetPinValue( E, HIGH);        //  E >> 1
		 _delay_ms(1);
		 DIO_SetPinValue( E, LOW);        //  E >> 0

		 //DIO_SetPortValue( LCD_Data_PORT , (u8cmd<<4) );

		 DIO_SetPinValue( D4,   (GET_BIT(u8cmd,0)) );
		 DIO_SetPinValue( D5,   (GET_BIT(u8cmd,1)) );
		 DIO_SetPinValue( D6,   (GET_BIT(u8cmd,2)) );
		 DIO_SetPinValue( D7,   (GET_BIT(u8cmd,3)) );

		 DIO_SetPinValue( E, HIGH);        //  E >> 1
	     _delay_ms(1);
		 DIO_SetPinValue( E, LOW);        //  E >> 0
		break;
	default:

		break;
}

}

void LCD_vidWriteData(u8 u8data)
{

	 DIO_SetPinValue(RS, HIGH);        // RS > 1
	 DIO_SetPinValue( RW, LOW);        //  RW> 0

switch(mode)
{
	case 0 : //8
	              // DIO_SetPortValue(LCD_Data_PORT, u8data);

	  	 DIO_SetPinValue( D0,  (  (GET_BIT(u8data ,0))  ) );
	  	 DIO_SetPinValue( D1,  (  (GET_BIT(u8data ,1))  ) );
	  	 DIO_SetPinValue( D2,  (  (GET_BIT(u8data ,2))   ) );
	  	 DIO_SetPinValue( D3,  (  (GET_BIT(u8data ,3))   ) );
	  	 DIO_SetPinValue( D4,  (  (GET_BIT(u8data ,4))  ) );
	  	 DIO_SetPinValue( D5,  (  (GET_BIT(u8data ,5))  ) );
	  	 DIO_SetPinValue( D6,  (  (GET_BIT(u8data ,6))   ) );
	  	 DIO_SetPinValue( D7,  (  (GET_BIT(u8data ,7))   ) );

			DIO_SetPinValue( E, HIGH);        //  E >> 1
	   	   _delay_ms(1);
	   	   DIO_SetPinValue( E, LOW);        //  E >> 0
	       break;
	case 1:// 4

		// DIO_SetPortValue( LCD_Data_PORT , (u8data & 0xF0) );

	  	 DIO_SetPinValue( D4,  (  (GET_BIT(u8data ,4))  ) );
	  	 DIO_SetPinValue( D5,  (  (GET_BIT(u8data ,5))  ) );
	  	 DIO_SetPinValue( D6,  (  (GET_BIT(u8data ,6))   ) );
	  	 DIO_SetPinValue( D7,  (  (GET_BIT(u8data ,7))   ) );

         DIO_SetPinValue( E, HIGH);        //  E >> 1
		 _delay_ms(1);
		 DIO_SetPinValue( E, LOW);        //  E >> 0

		// DIO_SetPortValue( LCD_Data_PORT , (u8data<<4) );

	  	 DIO_SetPinValue( D4,  (  (GET_BIT(u8data ,0))  ) );
	  	 DIO_SetPinValue( D5,  (  (GET_BIT(u8data ,1))  ) );
	  	 DIO_SetPinValue( D6,  (  (GET_BIT(u8data ,2))  ) );
	  	 DIO_SetPinValue( D7,  (  (GET_BIT(u8data ,3))  ) );

		 DIO_SetPinValue( E, HIGH);        //  E >> 1
	     _delay_ms(1);
		 DIO_SetPinValue( E, LOW);        //  E >> 0
		break;
default :
	break;
}


}
void LCD_vidGotoxy(u8 X, u8 Y)
{

	if (X>0 && X<=16)
	{
	    switch(Y)
	    {
		    case 1:
		    	LCD_vidWriteCmd(X+127);
		    break;
		    case 2:
		    	LCD_vidWriteCmd(X+191);
		    break;
		    default:
		    break;
	    }
	}
}
void LCD_vidPrintNum(u32 num)
{
	   u8 arr[8]={0,0,0,0, 0,0,0,0};
	   u8 i;
	   arr[0] =  (num / 1000)   ;
	   arr[1] =  (num % 1000)  / 100 ;
	   arr[2] =  (num % 100)  / 10 ;
	   arr[3] =  (num % 10)  / 1;


		if( (arr[0]==0  ) && (arr[1]!=0 )  )
		{
			for(i=1 ; i<=3 ; i++)
		    {
			    LCD_vidWriteData(arr[i]+ '0');
		    }
		}

		else if( (arr[1]==0 ) && (arr[0]==0 )&& (arr[2]!=0 )  )
	    {
			for(i=2 ; i<=3 ; i++)
		    {
			    LCD_vidWriteData(arr[i]+ '0');
		    }
	    }

		else if( (arr[2]==0 )&& (arr[1]==0 ) && (arr[0]==0 ) && (arr[3]!=0 ))
		{
			LCD_vidWriteData(arr[3]+ '0');
		}

		else if( (arr[3]==0 )&& (arr[2]==0 ) && (arr[1]==0 )&& (arr[0]==0 ) )
		{
			LCD_vidWriteData( 0 + '0');
		}

		else
		{
			for(i=0 ; i<=3 ; i++)
		    {
			    LCD_vidWriteData(arr[i]+ '0');
		    }
		}

}

void LCD_vidWriteString (u8* pu8StringCpy)
{

	u8 i=0;
	for (i=0; pu8StringCpy[i]!=0 ; i++)
	{
		// Write Character on LCD
		LCD_vidWriteData(pu8StringCpy[i]);
		_delay_ms(1);
	}

}


void LCD_vidWriteExtraChar(void)
{
    LCD_vidWriteCmd(0b01000000);    //CGRAM
    _delay_ms(1);
    LCD_vidWriteData(0b00000);  // +
    LCD_vidWriteData(0b00000);
    LCD_vidWriteData(0b00100);
    LCD_vidWriteData(0b01110);
    LCD_vidWriteData(0b00100);
    LCD_vidWriteData(0b00000);
    LCD_vidWriteData(0b00000);
    LCD_vidWriteData(0b00000);

    LCD_vidWriteData(0b00000);  // -
    LCD_vidWriteData(0b00000);
    LCD_vidWriteData(0b00000);
    LCD_vidWriteData(0b01110);
    LCD_vidWriteData(0b00000);
    LCD_vidWriteData(0b00000);
    LCD_vidWriteData(0b00000);
    LCD_vidWriteData(0b00000);

    LCD_vidWriteData(0b00000); // *
    LCD_vidWriteData(0b10001);
    LCD_vidWriteData(0b01010);
    LCD_vidWriteData(0b00100);
	LCD_vidWriteData(0b01010);
	LCD_vidWriteData(0b10001);
	LCD_vidWriteData(0b00000);
	LCD_vidWriteData(0b00000);

    LCD_vidWriteData(0b00000);//    /
    LCD_vidWriteData(0b00001);
    LCD_vidWriteData(0b00010);
    LCD_vidWriteData(0b00100);
    LCD_vidWriteData(0b01000);
    LCD_vidWriteData(0b10000);
    LCD_vidWriteData(0b00000);
    LCD_vidWriteData(0b00000);

}
