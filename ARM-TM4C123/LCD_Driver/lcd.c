#ifndef LCD_H
#define LCD_H
#include "lcd.h"

#define CLEAR 										0x01
#define RETURN_CURSOR 						0x02
#define INCREMENT_CURSOR 					0x06
#define BLINK_CURSOR 							0x0F
#define CURSOR_BEGIN_FIRST_LINE		0x80
#define CURSOR_BEGIN_SECOND_LINE	0xC0



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
void LCD_init(void){
	
	GPIO_initPort(PORTA,OUTPUT);
	GPIO_initPin(PORTA,PIN5,DIGITAL,OUTPUT);
	GPIO_initPin(PORTA,PIN6,DIGITAL,OUTPUT);
	GPIO_initPin(PORTA,PIN7,DIGITAL,OUTPUT);
	
	//Writing data on PORTB PB0~PB7
	GPIO_initPort(PORTB,OUTPUT);

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
			GPIO_writePort(PORTA,CURSOR_BEGIN_FIRST_LINE);
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
			GPIO_writePort(PORTA,RETURN_CURSOR);
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
	LCD_writeCommand(CLEAR);
}

void LCD_RowCol(uint32_t row, uint32_t col)
{

  if( row == 0)
  {
    char command = 0x80;
   while (col <=  0x0F )
    {
      LCD_command(command + col);
      break;
    }
	}
		if( row == 1)
  {
    char command = 0xC0;
   while (col <=  0x0F )
    {
      LCD_command(command + col);
      break;
    }
		
  }
}	

#endif
