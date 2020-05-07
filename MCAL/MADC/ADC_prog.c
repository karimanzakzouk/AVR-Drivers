
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/MACROS.h"
#include "ADC_int.h"
#include "ADC_cfg.h"
#include "ADC_priv.h"

#include "../MINT/INT_int.h"
#include "../MINT/INT_cfg.h"
#include "../MINT/INT_priv.h"



ISR(ADC_vect)
{
	//ADC_callback();
}

////// WITH INT

void ADC_Init (void)
{

	ADCSRA_Reg =  ADC_Enable + ADC_AUTOtrigger_Enable + ADC_Interrupt_Enable + ADC_prescaler;	


	ADMUX_Reg = ADC_Ref_Volt + ADC_adj ;	

}


u16 ADC_Read (u8 u8channel)
{
	// ADC Channel Selection
	u8channel &= 0x07;
	ADMUX_Reg &= 0xE0;
	ADMUX_Reg |= u8channel;

	// Start  Conversion
	SET_BIT(ADCSRA_Reg,6);

	return ADCH_Reg;
}

// POLING
//while((ADCSRA&0X10)== 0X00);
//while(!(ADCSRA_Reg));

//ADC Flag Clear
//SET_BIT(ADCSRA_Reg,4);
