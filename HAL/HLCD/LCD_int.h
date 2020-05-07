/*
 * LCD_int.h
 *
 *  Created on: Jan 5, 2019
 *      Author: kariman
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/MDIO/DIO_int.h"
// LCD_DATA_PORT >>>>> PORTC >>>   DO >>D7
#define LCD_Data_PORT   PORT2// 2 >>PORT C

#define D0  PIN16
#define D1  PIN17
#define D2  PIN18
#define D3  PIN19

#define D4   PIN20
#define D5   PIN21
#define D6   PIN22
#define D7   PIN23


//////LCD_Ctrl_PORT  >>>>PORT A
#define RS   PIN5
#define RW   PIN6
#define E    PIN7

void LCD_vidInit( void);
void LCD_vidWriteCmd(u8 cmd);
void LCD_vidWriteData(u8 data);
void LCD_vidGotoxy(u8 x, u8 y);
void LCD_vidPrintNum(u32 num);
void LCD_vidWriteString (u8* pu8StringCpy );
void LCD_vidWriteExtraChar(void);

#endif /* LCD_INT_H_ */
