#include "gpio.h"

void (*callbackTable[6][8])();

void GPIO_initPin(volatile uint32_t portAddress, Pin pin, PinMode mode, PinDir dir){
	switch(portAddress){
		case PORTA_AHB:
		case PORTA:
			(*SYSCTL_RCGCGPIO) |= 0x01;
			while(!((*SYSCTL_PRGPIO)|= 0x01));
			break;
		
		case PORTB_AHB:
		case PORTB:
			(*SYSCTL_RCGCGPIO) |= 0x02;
			while(!((*SYSCTL_PRGPIO)|= 0x02));
			break;
		
		case PORTC_AHB:
		case PORTC:
			(*SYSCTL_RCGCGPIO) |= 0x04;
			while(!((*SYSCTL_PRGPIO)|= 0x04));
			break;
		
		case PORTD_AHB:
		case PORTD:
			(*SYSCTL_RCGCGPIO) |= 0x08;
			while(!((*SYSCTL_PRGPIO)|= 0x08));
			break;
		
		case PORTE_AHB:
		case PORTE:
			(*SYSCTL_RCGCGPIO) |= 0x10;
			while(!((*SYSCTL_PRGPIO)|= 0x10));
			break;
		
		case PORTF_AHB:
		case PORTF:
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
	}else if(dir==PERIPHERAL)
	{
		Memory(portAddress, GPIO_AFSEL) |= (pin);
	}
	
}


uint8_t GPIO_readPin(volatile uint32_t portAddress,Pin pin){
	return Memory(portAddress, PORT_OFFSET) & pin;
}
void GPIO_writePin(volatile uint32_t portAddress, Pin pin, uint8_t value){
	Memory(portAddress, (pin<<2)) = value;
}

void GPIO_setPullup(volatile uint32_t portAddress, Pin pin){
	Memory(portAddress, GPIO_PUR) |= pin;
}
void GPIO_setPulldown(volatile uint32_t portAddress, Pin pin){
	Memory(portAddress, GPIO_PDR) |= pin;
}


void GPIO_initInterrupt(volatile uint32_t portAddress, Pin pin, InterruptEvent ev, void (*callback)(int)){
	switch(portAddress){
		case PORTA_AHB:
		case PORTA:
			callbackTable[0][Log(pin)] = callback;
			break;
		
		case PORTB_AHB:
		case PORTB:
			callbackTable[1][Log(pin)] = callback;
			break;
		
		case PORTC_AHB:
		case PORTC:
			callbackTable[2][Log(pin)] = callback;
			break;
		
		case PORTD_AHB:
		case PORTD:
			callbackTable[3][Log(pin)] = callback;
			break;
		
		case PORTE_AHB:
		case PORTE:
			callbackTable[4][Log(pin)] = callback;
			break;
		
		case PORTF_AHB:
		case PORTF:
			callbackTable[5][Log(pin)] = callback;
			break;
	}
	Memory(portAddress, GPIO_IS) &= ~(pin);
	if(ev == BOTH){
		Memory(portAddress, GPIO_IBE) |= (pin);
	}else if(ev == FALLING){
		Memory(portAddress, GPIO_IBE) &= ~(pin);
		Memory(portAddress, GPIO_IEV) &= ~(pin);
	}else if(ev == RISING){
		Memory(portAddress, GPIO_IBE) &= ~(pin);
		Memory(portAddress, GPIO_IEV) |= (pin);
	}
	
	Memory(portAddress, GPIO_ICR) |= (pin);
	Memory(portAddress, GPIO_IM)  |= (pin);
	switch(portAddress){
		case PORTA:	NVIC_EN0_R |= (1 << 0); break;
		case PORTB:	NVIC_EN0_R |= (1 << 1); break;
		case PORTC:	NVIC_EN0_R |= (1 << 2); break;
		case PORTD:	NVIC_EN0_R |= (1 << 3); break;
		case PORTE:	NVIC_EN0_R |= (1 << 4);	break;
		case PORTF: NVIC_EN0_R |= (1 << 30);break;
	}
}

void GPIOF_Handler(){
	if(Memory(PORTF,GPIO_MIS) == PIN0){
		Memory(PORTF,GPIO_ICR) |= PIN0;
		callbackTable[5][0]();
	}
	else if(Memory(PORTF,GPIO_MIS) == PIN1){
		Memory(PORTF,GPIO_ICR) |= PIN1;
		callbackTable[5][1]();
	}
	else if(Memory(PORTF,GPIO_MIS) == PIN2){
		Memory(PORTF,GPIO_ICR) |= PIN2;
		callbackTable[5][2]();
	}
	else if(Memory(PORTF,GPIO_MIS) == PIN3){
		Memory(PORTF,GPIO_ICR) |= PIN3;
		callbackTable[5][3]();
	}
	else if(Memory(PORTF,GPIO_MIS) == PIN4){
		Memory(PORTF,GPIO_ICR) |= PIN4;
		callbackTable[5][4]();
	}
	else if(Memory(PORTF,GPIO_MIS) == PIN5){
		Memory(PORTF,GPIO_ICR) |= PIN5;
		callbackTable[5][5]();
	}
	else if(Memory(PORTF,GPIO_MIS) == PIN6){
		Memory(PORTF,GPIO_ICR) |= PIN6;
		callbackTable[5][6]();
	}
	else if(Memory(PORTF,GPIO_MIS) == PIN7){
		Memory(PORTF,GPIO_ICR) |= PIN7;
		callbackTable[5][7]();
	}
}


void GPIO_setPCTL(volatile uint32_t portAddress, Pin pin, uint8_t function){
	Memory(portAddress, GPIO_PCTL) &= ~(0x0f << (pin << 2));
	Memory(portAddress, GPIO_PCTL) |= (function << (pin << 2));
}
void GPIO_setOpenDrain(volatile uint32_t portAddress, Pin pin){
	Memory(portAddress, GPIO_ODR) |= pin;
}











/////////////////////////////////////////////////////////////////////////////////////
void gpio_enable_Interrupts(void){
	__asm__("CPSIE  I \n");
}

void GPIO_initPort(volatile uint32_t portAdress, PinDir dir){
	switch(portAdress){
		case PORTA_AHB:
		case PORTA:
			(*SYSCTL_RCGCGPIO) |= 0x01;
			while(!((*SYSCTL_PRGPIO)|= 0x01));
			break;
		
		case PORTB_AHB:
		case PORTB:
			(*SYSCTL_RCGCGPIO) |= 0x02;
			while(!((*SYSCTL_PRGPIO)|= 0x02));
			break;
		
		case PORTC_AHB:
		case PORTC:
			(*SYSCTL_RCGCGPIO) |= 0x04;
			while(!((*SYSCTL_PRGPIO)|= 0x04));
			break;
		
		case PORTD_AHB:
		case PORTD:
			(*SYSCTL_RCGCGPIO) |= 0x08;
			while(!((*SYSCTL_PRGPIO)|= 0x08));
			break;
		
		case PORTE_AHB:
		case PORTE:
			(*SYSCTL_RCGCGPIO) |= 0x10;
			while(!((*SYSCTL_PRGPIO)|= 0x10));
			break;
		
		case PORTF_AHB:
		case PORTF:
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


uint8_t GPIO_readPort(volatile uint32_t portAddress){
	return Memory(portAddress, PORT_OFFSET);
}
void GPIO_writePort(volatile uint32_t portAddress, uint8_t value){
	Memory(portAddress, PORT_OFFSET) = value;
}
