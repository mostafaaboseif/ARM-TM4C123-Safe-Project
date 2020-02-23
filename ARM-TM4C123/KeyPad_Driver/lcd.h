#include "stdio.h"
#include "gpio.h"
#include "C:\Keil_v5\EE319Kware\inc\tm4c123gh6pm.h"


#define CLEAR 				0x01
#define RETURN_CURSOR 			0x02
#define SHIFT_CURSOR_RIGHT 		0x06
#define SHIFT_CURSOR_LEFT		0x04
#define DISPLAY_OFF_CURSOR_OFF          0x08
#define DISPLAY_BLINK_CURSOR_ON	        0x0F
#define FUNC_SET_8BIT_1LINE             0x30
#define FUNC_SET_8BIT_2LINE             0x38
#define CURSOR_BEGIN_FIRST_LINE		0x80
#define CURSOR_BEGIN_SECOND_LINE	0xC0

void delayMs(int n);
void delayUs(int n);
void LCD_init(void);
void LCD_writeCommand(unsigned char command);
void LCD_writeChar(unsigned char data);
void LCD_writeString( char* str);
void LCD_writeInteger(int number);
void LCD_clearScreen();
void LCD_RowCol(uint32_t row, uint32_t col);
