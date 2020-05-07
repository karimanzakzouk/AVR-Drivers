/*
 * DIO.h
 *
 *  Created on: Dec 29, 2018
 *      Author: kariman
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_



extern void ADC_Init (void); 

extern u16 ADC_Read (u8 u8channel);





/* call back function */

void ADC_callback(void);

void ADC_func_setter(void(*ADC_Callback)(void));




#endif /* ADC_INT_H_ */

