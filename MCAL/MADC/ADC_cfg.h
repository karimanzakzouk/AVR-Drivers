/*
 * DIO.h
 *
 *  Created on: Dec 29, 2018
 *      Author: kariman
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_


/*
			Voltage Reference Selections for ADC
			REFS1 REFS0 Voltage Reference Selection
MODE0			0 0 	AREF, Internal Vref turned off
MODE1			0 1 	AVCC with external capacitor at AREF pin
MODE2			1 0 	Reserved
MODE3		    1 1 	SInternal 2.56V Voltage Reference with external capacitor at AREF pin

*/

/*
ADC Prescaler Selections
ADPS2 ADPS1 ADPS0 Division Factor
0 0 0 2
0 0 1 2
0 1 0 4
0 1 1 8
1 0 0 16
1 0 1 32
1 1 0 64
1 1 1 128
*/

/* Write one to ADLAR to left adjust
 * zero to ADLAR to right adjust
 */

#define  ADC_Enable     ADC_En

#define  ADC_AUTOtrigger_Enable     ADC_AUTO_EN

#define  ADC_Interrupt_Enable     ADC_INT_EN

#define ADC_prescaler     ADC_prescaler7


#define ADC_Ref_Volt  VR_MODE1

#define  ADC_adj    ADC_leftAdj


#endif /* ADC_CFG_H_ */

