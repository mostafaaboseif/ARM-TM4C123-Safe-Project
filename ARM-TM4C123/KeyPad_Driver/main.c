#include "stdint.h"
#include "gpio.h"
#include "C:\Keil_v5\EE319Kware\inc\tm4c123gh6pm.h"
#include "I2C.h"
#include "KeyPad.h"
#include "lcd.h"

int main()
{
	LCD_init();
	Keypad_init();
	delayMs(500);
	LCD_writeCommand(0x80	);
	delayMs(500);
	LCD_writeCommand(0x0F);
		 
	while(1){
		
		delayMs(500);

		char key;
			

		key = keypad_getkey();
	   	if(key != 'x'){
					LCD_writeChar(key);
				delayMs(100); 
				}
		
				else{
					LCD_writeChar('1');
					
		delayMs(500);
		}
	}
}
