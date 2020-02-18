#include "gpio.h"

void gpio_init_port(volatile uint32_t portAdress, PinDir dir){
	switch(portAdress){
		case PORTA_AHB:
		case PORTA_APB:
			(*SYSCTL_RCGCGPIO) |= 0x01;
			while(!((*SYSCTL_PRGPIO)|= 0x01));
			break;
		
		case PORTB_AHB:
		case PORTB_APB:
			(*SYSCTL_RCGCGPIO) |= 0x02;
			while(!((*SYSCTL_PRGPIO)|= 0x02));
			break;
		
		case PORTC_AHB:
		case PORTC_APB:
			(*SYSCTL_RCGCGPIO) |= 0x04;
			while(!((*SYSCTL_PRGPIO)|= 0x04));
			break;
		
		case PORTD_AHB:
		case PORTD_APB:
			(*SYSCTL_RCGCGPIO) |= 0x08;
			while(!((*SYSCTL_PRGPIO)|= 0x08));
			break;
		
		case PORTE_AHB:
		case PORTE_APB:
			(*SYSCTL_RCGCGPIO) |= 0x10;
			while(!((*SYSCTL_PRGPIO)|= 0x10));
			break;
		
		case PORTF_AHB:
		case PORTF_APB:
			(*SYSCTL_RCGCGPIO) |= 0x20;
			while(!((*SYSCTL_PRGPIO)|= 0x20));
			break;
	}
	Memory(portAdress, GPIO_LCK) 		= UNLOCK;
	Memory(portAdress, GPIO_CR) 		= 0xFF;
	Memory(portAdress, GPIO_DEN) 		= 0xFF;
	Memory(portAdress, GPIO_AMSEL)	= 0x00;
	Memory(portAdress, GPIO_AFSEL) 	= 0x00;
	Memory(portAdress, GPIO_PCTL) 	= 0x00;
	Memory(portAdress, GPIO_DIR) 		= dir;
}


void gpio_init_pin(volatile uint32_t portAddress, Pin pin, PinMode mode, PinDir dir){
	switch(portAddress){
		case PORTA_AHB:
		case PORTA_APB:
			(*SYSCTL_RCGCGPIO) |= 0x01;
			while(!((*SYSCTL_PRGPIO)|= 0x01));
			break;
		
		case PORTB_AHB:
		case PORTB_APB:
			(*SYSCTL_RCGCGPIO) |= 0x02;
			while(!((*SYSCTL_PRGPIO)|= 0x02));
			break;
		
		case PORTC_AHB:
		case PORTC_APB:
			(*SYSCTL_RCGCGPIO) |= 0x04;
			while(!((*SYSCTL_PRGPIO)|= 0x04));
			break;
		
		case PORTD_AHB:
		case PORTD_APB:
			(*SYSCTL_RCGCGPIO) |= 0x08;
			while(!((*SYSCTL_PRGPIO)|= 0x08));
			break;
		
		case PORTE_AHB:
		case PORTE_APB:
			(*SYSCTL_RCGCGPIO) |= 0x10;
			while(!((*SYSCTL_PRGPIO)|= 0x10));
			break;
		
		case PORTF_AHB:
		case PORTF_APB:
			(*SYSCTL_RCGCGPIO) |= 0x20;
			while(!((*SYSCTL_PRGPIO)|= 0x20));
			break;
	}
	
	Memory(portAddress, GPIO_LCK) = UNLOCK;
	Memory(portAddress, GPIO_CR)  |= pin;
	//Memory(portAddress, GPIO_PDR)  |= pin;
	
	if(mode == DIGITAL){
		Memory(portAddress, GPIO_DEN) |= pin;
	}else{
		Memory(portAddress, GPIO_AMSEL) |= pin;
	}
	
	if(dir == OUTPUT){
		Memory(portAddress, GPIO_DIR) |= pin;
		Memory(portAddress, GPIO_AFSEL) &= ~(pin);
	}else if(dir == INPUT){
		Memory(portAddress, GPIO_DIR) &= ~(pin);
		Memory(portAddress, GPIO_AFSEL) &= ~(pin);
	}else{
		Memory(portAddress, GPIO_AFSEL) |= (pin);
	}
	
}


void gpio_set_pullup(volatile uint32_t portAddress, Pin pin){
	Memory(portAddress, GPIO_PUR) |= pin;
}
void gpio_set_pulldown(volatile uint32_t portAddress, Pin pin){
	Memory(portAddress, GPIO_PDR) |= pin;
}
void gpio_set_drive2m(volatile uint32_t portAddress, Pin pin){
	Memory(portAddress, GPIO_DRV2M) |= pin;
}
void gpio_set_drive4m(volatile uint32_t portAddress, Pin pin){
	Memory(portAddress, GPIO_DRV4M) |= pin;
}
void gpio_set_drive8m(volatile uint32_t portAddress, Pin pin){
	Memory(portAddress, GPIO_DRV8M) |= pin;
}


void gpio_set_register(volatile uint32_t portAddress, Pin pin, RegistersOffset registerName){
	Memory(portAddress, registerName) |= pin;
}
void gpio_clear_register(volatile uint32_t portAddress, Pin pin, RegistersOffset registerName){
	Memory(portAddress, registerName) &= ~(pin);
}


uint8_t gpio_read_port(volatile uint32_t portAddress){
	return Memory(portAddress, PORT_OFFSET);
}
void gpio_write_port(volatile uint32_t portAddress, uint8_t value){
	Memory(portAddress, PORT_OFFSET) = value;
}


uint8_t gpio_read_pin(volatile uint32_t portAddress,Pin pin){
	return Memory(portAddress, PORT_OFFSET) & pin;
}
void gpio_write_pin(volatile uint32_t portAddress, PinOffset pin, uint8_t value){
	Memory(portAddress, pin) = value;
}
