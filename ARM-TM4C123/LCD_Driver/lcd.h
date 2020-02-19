#include "TM4C123GH6PM.h"
#include "gpio.h"
#include "stdio.h"

void delayMs(int n);
void delayUs(int n);
void LCD_init(void);
void LCD_writeCommand(unsigned char command);
void LCD_writeChar(unsigned char data);
void LCD_writeString( char* str);
void LCD_writeInteger(int number);
void LCD_clearScreen();
