#include "stdint.h"
#include "gpio.h"
void SystemInit(){}

int main(){
	gpio_init_pin(PORTF_APB, PIN0, DIGITAL, INPUT);
	gpio_init_pin(PORTF_APB, PIN4, DIGITAL, INPUT);
	gpio_set_pullup(PORTF_APB, PIN4);
	gpio_init_pin(PORTF_APB, PIN1, DIGITAL, OUTPUT);
	gpio_init_port(PORTA_APB, OUTPUT);
	gpio_write_port(PORTA_APB, HIGH);
	while(1){
		if(gpio_read_pin(PORTF_APB, PIN4)){
			gpio_write_pin(PORTF_APB,WPIN1,HIGH);
			
		}else{
			gpio_write_pin(PORTF_APB,WPIN1,LOW);
		}
	}
}
