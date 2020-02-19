#ifndef LCD_H
#define LCD_H
#include "lcd.h"

void delayMs(int n)
{
 int i, j;
 for(i = 0 ; i < n; i++)
 for(j = 0; j < 3180; j++)
 {} /* do nothing for 1 ms */
}
/* delay n microseconds (16 MHz CPU clock) */
void delayUs(int n)
{
 int i, j;
 for(i = 0 ; i < n; i++)
 for(j = 0; j < 3; j++)
 {} /* do nothing for 1 us */
}

void LCD_command(unsigned char command){
		GPIOA->DATA = 0;
		GPIOB->DATA = command;
		//3shan ne3mel 7war l high wel low hanconfigure pin 7
		GPIOA->DATA= 0x80;
		delayMs(0);
		GPIOA->DATA= 0;
		delayUs(0);
		GPIOA->DATA = 0;
		if (command < 4)
		delayUs(2); /* command 1 and 2 needs up to 1.64ms */
		else
		delayUs(40);
}
void LCD_data(unsigned char data){
		GPIOA->DATA =0x20;
		GPIOB->DATA = data;
			//3shan ne3mel 7war l high wel low hanconfigure pin 7
		GPIOA->DATA = 0xA0;
		delayUs(0);
		GPIOA->DATA = 0;
		delayUs(40);

}
void LCD_init(void){
	SYSCTL->RCGCGPIO |= 0x03;		 
	GPIOA->DIR = 0xE0;
	GPIOA->DEN = 0xE0;
	GPIOA->AFSEL = 0;
	GPIOA->AMSEL =0;

	GPIOB->DIR = 0xFF;
	GPIOB->DEN = 0xFF;
	GPIOB->AFSEL = 0;
	GPIOB->AMSEL = 0;

		
	delayMs(20); 
	LCD_command(0x30);
	delayMs(5);
	LCD_command(0x30);
	delayUs(100);
	LCD_command(0x30);
	LCD_command(0x38); 
	LCD_command(0x06); 
	LCD_command(0x01); 
	LCD_command(0x0F); 
}
#endif
