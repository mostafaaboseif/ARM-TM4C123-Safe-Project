#include "KeyPad.h"

char key_pad [4][4] = {{'1','2','3','A'},
											 {'4','5','6','B'},
											 {'7','8','9','C'},
											 {'*','0','#','D'}};

											 
											 
void Keypad_init(void)
{
		
	GPIO_initPort(PORTE,OUTPUT);
	GPIO_initPort(PORTC,INPUT);
	GPIO_initPin(PORTC,PIN4,DIGITAL,INPUT);
	GPIO_initPin(PORTC,PIN5,DIGITAL,INPUT);
	GPIO_initPin(PORTC,PIN6,DIGITAL,INPUT);
	GPIO_initPin(PORTC,PIN7,DIGITAL,INPUT);
	GPIO_setPullup(PORTC,PIN4);
	GPIO_setPullup(PORTC,PIN5);
	GPIO_setPullup(PORTC,PIN6);
	GPIO_setPullup(PORTC,PIN7);
	GPIO_setOpenDrain(PORTC,PIN4);
	GPIO_setOpenDrain(PORTC,PIN5);
	GPIO_setOpenDrain(PORTC,PIN6);
	GPIO_setOpenDrain(PORTC,PIN7);
	
	
	GPIO_initPin(PORTE,PIN1,DIGITAL,OUTPUT);
	GPIO_initPin(PORTE,PIN2,DIGITAL,OUTPUT);
	GPIO_initPin(PORTE,PIN3,DIGITAL,OUTPUT);
	GPIO_initPin(PORTE,PIN4,DIGITAL,OUTPUT);
	GPIO_setPullup(PORTE,PIN1);
	GPIO_setPullup(PORTE,PIN2);
	GPIO_setPullup(PORTE,PIN3);
	GPIO_setPullup(PORTE,PIN4);
	GPIO_setOpenDrain(PORTE,PIN1);
	GPIO_setOpenDrain(PORTE,PIN2);
	GPIO_setOpenDrain(PORTE,PIN3);
	GPIO_setOpenDrain(PORTE,PIN4);
	
}

char keypad_getkey(void){

			
					int  col;
					col= GPIO_readPort(PORTC);
	
					GPIO_writePort(PORTE,0x00);
					
					if(col==0xF0){
							return 'x';
					}
											 
			while(1){
		
				// 1st row has zero
				GPIO_writePort(PORTE,0x1C); 
				delayMs(100); 
				col = GPIO_readPort(PORTC) & 0xF0;
				
				if (col == 0xE0)
				{
					
					return key_pad [0][0];
					delayMs(100);
					break;
				}
				 if (col == 0xD0){
					return key_pad [0][1];
					 delayMs(100);
					break;
					
				}
				if (col == 0xB0){
					return key_pad [0][2];
					delayMs(100);
					break;
					
				}
				if (col == 0x70){
					return key_pad [0][3];
					delayMs(100);
					break;
				}
				
			  // 2nd row has zero
				GPIO_writePort(PORTE,0x1A);
				delayMs(100);  
				col = GPIO_readPort(PORTC) & 0xF0;
				if (col == 0xE0)
				{
					return key_pad [1][0];
					delayMs(100);
					break;
				}
				 if (col == 0xD0){
					return key_pad [1][1];
					 delayMs(100);
					break;
				}
				if (col == 0xB0){
					return key_pad [1][2];
					delayMs(100);
					break;
				}
				 if (col == 0x70){
					return key_pad [1][3];
					 delayMs(100);
					break;
				}
			
				
				// 3rd row has zero
				GPIO_writePort(PORTE,0x16); 
				delayMs(100);   
				col = GPIO_readPort(PORTC)& 0xF0;
				if (col == 0xE0)
				{
					return key_pad [2][0];
					delayMs(100);
					break;
				}
				 if (col == 0xD0){
					return key_pad [2][1];
					 delayMs(100);
					break;
					
				}
				 if (col == 0xB0){
					return key_pad [2][2];
					 delayMs(100);
					break;
					
				}
				 if (col == 0x70){
					return key_pad [2][3];
					 delayMs(100);
 					 break;
					
				}
				 
				// 4th row has zero
				GPIO_writePort(PORTE,0x0E);
				delayMs(100); 
				col = GPIO_readPort(PORTC) & 0xF0;
				
				if (col == 0xE0)
				{
					return key_pad [3][0];
					delayMs(100);
					break;
				}
				 if (col == 0xD0){
					return key_pad [3][1];
					 delayMs(100);
					break;
				}
				 if (col == 0xB0){
					return key_pad [3][2];
					 delayMs(100);
					break;
				}
				 if (col == 0x70){
					return key_pad [3][3];
					 delayMs(100);
					break;
				}
							
	   }
}