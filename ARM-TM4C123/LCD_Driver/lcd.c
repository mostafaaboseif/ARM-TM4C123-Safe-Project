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
<<<<<<< HEAD
=======

	

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
>>>>>>> 49147ee2a2cbf0606b3bebdfd06e27f65f2a1851
void LCD_init(void){
	GPIO_initPort(PORTA,OUTPUT);
	GPIO_initPin(PORTA,PIN5,DIGITAL,OUTPUT);
	GPIO_initPin(PORTA,PIN6,DIGITAL,OUTPUT);
	GPIO_initPin(PORTA,PIN7,DIGITAL,OUTPUT);
	
	GPIO_initPort(PORTB,OUTPUT);
//	GPIO_initPin(PORTB,PIN0,DIGITAL,OUTPUT);
//	GPIO_initPin(PORTB,PIN1,DIGITAL,OUTPUT);
//	GPIO_initPin(PORTB,PIN2,DIGITAL,OUTPUT);
//	GPIO_initPin(PORTB,PIN3,DIGITAL,OUTPUT);
//	GPIO_initPin(PORTB,PIN4,DIGITAL,OUTPUT);
//	GPIO_initPin(PORTB,PIN5,DIGITAL,OUTPUT);
//	GPIO_initPin(PORTB,PIN6,DIGITAL,OUTPUT);
//	GPIO_initPin(PORTB,PIN7,DIGITAL,OUTPUT);
//	
	delayMs(20); 
	LCD_writeCommand(0x30);
	delayMs(5);
	LCD_writeCommand(0x30);
	delayUs(100);
	LCD_writeCommand(0x30);
	LCD_writeCommand(0x38); 
	LCD_writeCommand(0x06); 
	LCD_writeCommand(0x01); 
	LCD_writeCommand(0x0F); 
}

void LCD_writeCommand(unsigned char command){
			GPIO_writePort(PORTA,0);
			GPIO_writePort(PORTB,command);
			GPIO_writePort(PORTA,0x80);
			delayMs(0);
			GPIO_writePort(PORTA,0);
			delayUs(0);
			GPIO_writePort(PORTA,0);
			if (command < 4)
			delayUs(2); /* command 1 and 2 needs up to 1.64ms */
			else
			delayUs(40);
}
void LCD_writeChar(unsigned char data){
			GPIO_writePort(PORTA,0x20);
			GPIO_writePort(PORTB,data);
			GPIO_writePort(PORTA,0xA0);
			delayUs(0);
			GPIO_writePort(PORTA,0);
			delayUs(40);
}
void LCD_writeString( char *str){
	
		while(*str){
			LCD_writeChar(*str++);
			delayMs(10);
		}
}
void LCD_writeInteger(int number){
	char  str[10] ;
	sprintf((char*)str, "%d", number);
	LCD_writeString(str);
}

void LCD_clearScreen(){
	LCD_writeCommand(0x80);
}
#endif
