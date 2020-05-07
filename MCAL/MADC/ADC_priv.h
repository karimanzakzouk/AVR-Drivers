/*
 * DIO.h
 *
 *  Created on: Dec 29, 2018
 *      Author: kariman
 */

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_



#define ADMUX_Reg 	*((volatile u8*)0x27) 	// ADC Multiplexer Register
#define ADCSRA_Reg 	*((volatile u8*)0x26) 	// ADC Control And Status Register
#define ADCH_Reg 	*((volatile u8*)0x25) 		// ADC High Register
#define ADCL_Reg 	*((volatile u8*)0x24) 		// ADC Low Register



#define ch0   0
#define ch1   1
#define ch2   2
#define ch3   3
#define ch4   4
#define ch5   5
#define ch6   6
#define ch7   7

#define ADC_En  128
#define ADC_DIS  0

#define ADC_INT_EN  8
#define ADC_INT_DIS  0

#define ADC_AUTO_EN  32
#define ADC_AUTO_DIS  0

#define ADC_leftAdj    32
#define ADC_rightAdj   0

#define VR_MODE0   0
#define VR_MODE1   64
#define VR_MODE2   128
#define VR_MODE3   192

#define  ADC_prescaler0    0
#define  ADC_prescaler1    1
#define  ADC_prescaler2  2
#define  ADC_prescaler3  3
#define  ADC_prescaler4  4
#define  ADC_prescaler5  5
#define  ADC_prescaler6  6
#define  ADC_prescaler7  7


#endif /* ADC_PRIV_H_ */

