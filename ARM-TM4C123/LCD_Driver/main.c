#include "stdint.h"
#include "lcd.h"
int main(){

	LCD_init();
	 //LCD_command(1); /* clear display */
	delayMs(500);

	LCD_command(0x80);
	delayMs(500);

	LCD_data('S');
	delayMs(500);
	LCD_data('W');
	delayMs(500);
	LCD_data('I');
	delayMs(500);
	LCD_data('L');
	delayMs(500);
	LCD_data('A');
	delayMs(500);
		 
	LCD_data('M');
	delayMs(500);
}
