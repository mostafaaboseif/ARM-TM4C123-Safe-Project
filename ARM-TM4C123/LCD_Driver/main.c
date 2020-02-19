#include "stdint.h"
#include "lcd.h"
int main(){

	LCD_init();
	 //LCD_command(1); /* clear display */
	delayMs(10);
while(1){
	LCD_clearScreen();
	delayMs(50);
	
	LCD_writeInteger(100);
	delayMs(50);
	LCD_writeString("Amgad&Mariam");
	delayMs(50);
}
}