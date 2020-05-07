/*
 * LCD_priv.h
 *
 *  Created on: Jan 15, 2019
 *      Author: kariman
 */

#ifndef HAL_HLCD_LCD_PRIV_H_
#define HAL_HLCD_LCD_PRIV_H_



#define lcd_Clear           1   //0b00000001                   // replace all characters with ASCII 'space'
#define lcd_DisplayOn       15  //0b00001111                 // display on, cursor off, don't blink character
#define lcd_SetCursor       128  //0b10000000                // set cursor position
#define lcd_FunctionSet8bit  56 // 0x38                     // 8-bit data, 2-line display, 5 x 7 font
#define lcd_EntryMode       6//0x06                    // shift cursor from left to right on read/write
#define lcd_FunctionReset   48//0x30                   // reset the LCD
#define lcd_DisplayOff      8 //0x08                  // turn display off

#define lcd_FunctionSet4bit_1     51 //0x33
#define lcd_FunctionSet4bit_2   50 // 0x32
#define lcd_FunctionSet4bit_3   40 //0x28             // 4-bit data, 2-line display, 5 x 7 font




#endif /* HAL_HLCD_LCD_PRIV_H_ */
