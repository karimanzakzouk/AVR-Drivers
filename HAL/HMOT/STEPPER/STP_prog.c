
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/MACROS.h"
#include<util/delay.h>
#include"../../../MCAL/MDIO/DIO_int.h"
#include"STP_int.h"
#include"STP_cfg.h"


void STP_vidInit(void)
{

	DIO_SetPinDirection (blue, OUTPUT);
	DIO_SetPinDirection (pink, OUTPUT);
	DIO_SetPinDirection (yellow, OUTPUT);
	DIO_SetPinDirection (orange, OUTPUT);


}

void STP_vidCW(u8 u8speed)
{

	u8 i;
	for( i=0 ; i< 250 ; i++)
	{

		switch(step)
		{
			case 0 :
				// full step

				DIO_SetPinValue(blue,LOW);
				DIO_SetPinValue( pink,HIGH);
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,HIGH);
				 _delay_ms(u8speed);

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,LOW);
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,HIGH);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,HIGH);
				DIO_SetPinValue( yellow,LOW);
				DIO_SetPinValue(orange,HIGH);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,HIGH);
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,LOW);
				_delay_ms(u8speed);

				break;

			case 1 :
				// half step

				DIO_SetPinValue(blue,LOW);
				DIO_SetPinValue( pink,HIGH);
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,LOW);
				 _delay_ms(u8speed);

				DIO_SetPinValue(blue,LOW );
				DIO_SetPinValue( pink,HIGH);
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,HIGH);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,LOW );
				DIO_SetPinValue( pink,LOW);
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,HIGH);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,LOW);
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,HIGH);
				_delay_ms(u8speed);
/////////////////////////////////////////////////////////////
				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,LOW);
				DIO_SetPinValue( yellow,LOW);
				DIO_SetPinValue(orange,HIGH);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,HIGH );
				DIO_SetPinValue( yellow,LOW);
				DIO_SetPinValue(orange,HIGH);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,HIGH );
				DIO_SetPinValue( yellow,LOW);
				DIO_SetPinValue(orange,LOW);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,HIGH );
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,LOW);
				_delay_ms(u8speed);

				break;

			default:
				// full step

					DIO_SetPinValue(blue,LOW);
					DIO_SetPinValue( pink,HIGH);
					DIO_SetPinValue( yellow,HIGH);
					DIO_SetPinValue(orange,HIGH);
					 _delay_ms(u8speed);

					DIO_SetPinValue(blue,HIGH );
					DIO_SetPinValue( pink,LOW);
					DIO_SetPinValue( yellow,HIGH);
					DIO_SetPinValue(orange,HIGH);
					_delay_ms(u8speed);

					DIO_SetPinValue(blue,HIGH );
					DIO_SetPinValue( pink,HIGH);
					DIO_SetPinValue( yellow,LOW);
					DIO_SetPinValue(orange,HIGH);
					_delay_ms(u8speed);

					DIO_SetPinValue(blue,HIGH );
					DIO_SetPinValue( pink,HIGH);
					DIO_SetPinValue( yellow,HIGH);
					DIO_SetPinValue(orange,LOW);
					_delay_ms(u8speed);
				    break;
			}
	}


}


void STP_vidCCW(u8 u8speed)
{

	u8 i;
	for( i=0 ; i< 250 ; i++)
	{

		switch(step)
		{
			case 0 :
				// full step

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,HIGH);
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,LOW);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,HIGH);
				DIO_SetPinValue( yellow,LOW);
				DIO_SetPinValue(orange,HIGH);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,LOW);
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,HIGH);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,LOW);
				DIO_SetPinValue( pink,HIGH);
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,HIGH);
				 _delay_ms(u8speed);

				break;

			case 1 :
                  // half step

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,HIGH );
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,LOW);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,HIGH );
				DIO_SetPinValue( yellow,LOW);
				DIO_SetPinValue(orange,LOW);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,HIGH );
				DIO_SetPinValue( yellow,LOW);
				DIO_SetPinValue(orange,HIGH);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,LOW);
				DIO_SetPinValue( yellow,LOW);
				DIO_SetPinValue(orange,HIGH);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,LOW);
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,HIGH);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,LOW );
				DIO_SetPinValue( pink,LOW);
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,HIGH);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,LOW );
				DIO_SetPinValue( pink,HIGH);
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,HIGH);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,LOW);
				DIO_SetPinValue( pink,HIGH);
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,LOW);
				 _delay_ms(u8speed);

				break;

			default:
				// full step

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,HIGH);
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,LOW);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,HIGH);
				DIO_SetPinValue( yellow,LOW);
				DIO_SetPinValue(orange,HIGH);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,HIGH );
				DIO_SetPinValue( pink,LOW);
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,HIGH);
				_delay_ms(u8speed);

				DIO_SetPinValue(blue,LOW);
				DIO_SetPinValue( pink,HIGH);
				DIO_SetPinValue( yellow,HIGH);
				DIO_SetPinValue(orange,HIGH);
				 _delay_ms(u8speed);

				break;
			}
	}
}
