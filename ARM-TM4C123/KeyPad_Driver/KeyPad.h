#include "stdio.h"
#include "C:\Keil_v5\EE319Kware\inc\tm4c123gh6pm.h"
#include "gpio.h"
#include "lcd.h"

#define keypad_column  GPIOC
#define Keypad_row     GPIOE

//void delayMs(int n);
//void delayUs(int n);

void Keypad_init(void);
char keypad_getkey(void);