#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "gpio.h"
void SystemInit(){}

int main(){
	gpio_init_pin(PORTF_APB, PIN0, DIGITAL, INPUT);
	gpio_init_pin(PORTF_APB, PIN4, DIGITAL, INPUT);
	gpio_set_pullup(PORTF_APB, PIN4);
	gpio_init_pin(PORTF_APB, PIN1, DIGITAL, OUTPUT);
	while(1){
		if(gpio_read_pin(PORTF_APB, PIN4)){
			gpio_write_pin(PORTF_APB,WPIN1,0x02);
		}else{
			gpio_write_pin(PORTF_APB,WPIN1,0x00);
		}
	}
}
