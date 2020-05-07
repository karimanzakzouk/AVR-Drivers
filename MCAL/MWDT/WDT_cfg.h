/*
 *  Created on: Jan 31, 2019
 *      Author: kariman
 */

#ifndef   MCAL_MWDT_WDT_CFG_H_
#define  MCAL_MWDT_WDT_CFG_H_

#include "../MWDT/WDT_priv.h"
/*
Watchdog Timer Prescale Select
WDP2 WDP1 WDP0
Number of WDT
Oscillator Cycles
Typical Time-out
at VCC = 3.0V
Typical Time-out
at VCC = 5.0V

0 0 0 16K (16,384) 17.1 ms 16.3 ms
0 0 1 32K (32,768) 34.3 ms 32.5 ms
0 1 0 64K (65,536) 68.5 ms 65 ms
0 1 1 128K (131,072) 0.14 s 0.13 s
1 0 0 256K (262,144) 0.27 s 0.26 s
1 0 1 512K (524,288) 0.55 s 0.52 s
1 1 0 1,024K (1,048,576) 1.1 s 1.0 s
1 1 1 2,048K (2,097,152) 2.2 s 2.1 s
*/
#define WDT_prescaler    WDT_prescaler7


#endif /* MCAL_MTIM1_TIM1_CFG_H_ */
