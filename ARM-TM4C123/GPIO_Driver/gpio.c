#include "gpio.h"

void (*callbackTable[6][8])();

void GPIO_setClkSource(volatile uint32_t portAddress){
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
}

void GPIO_initPin(volatile uint32_t portAddress, Pin pin, PinMode mode, PinDir dir){
	GPIO_setClkSource(portAddress);
	Memory(portAddress, GPIO_LCK) = UNLOCK;
	Memory(portAddress, GPIO_CR)  |= pin;	
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
	}else if(dir==PERIPHERAL){
		Memory(portAddress, GPIO_AFSEL) |= (pin);
	}
}

uint8_t GPIO_readPin(volatile uint32_t portAddress,Pin pin){
	return Memory(portAddress, PORT_OFFSET) & pin;
}

void GPIO_writePin(volatile uint32_t portAddress, Pin pin, uint8_t value){
	Memory(portAddress, (pin<<2)) = value;
}

void GPIO_initPort(volatile uint32_t portAddress, PinDir dir){
	GPIO_setClkSource(portAddress);
	Memory(portAddress, GPIO_LCK) 	= UNLOCK;
	Memory(portAddress, GPIO_CR) 	= 0xFF;
	Memory(portAddress, GPIO_DEN) 	= 0xFF;
	Memory(portAddress, GPIO_AMSEL)	= 0x00;
	Memory(portAddress, GPIO_AFSEL) 	= 0x00;
	Memory(portAddress, GPIO_PCTL) 	= 0x00;
	Memory(portAddress, GPIO_DIR) 	= dir;
}

uint8_t GPIO_readPort(volatile uint32_t portAddress){
	return Memory(portAddress, PORT_OFFSET);
}

void GPIO_writePort(volatile uint32_t portAddress, uint8_t value){
	Memory(portAddress, PORT_OFFSET) = value;
}


void GPIO_initInterrupt(volatile uint32_t portAddress, Pin pin, InterruptEvent ev, void (*callback)()){
	GPIO_setClkSource(portAddress);
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
		case PORTA:	(*NVIC_EN0) |= (1 << 0); callbackTable[0][Log(pin)] = callback; break;
		case PORTB: (*NVIC_EN0) |= (1 << 1); callbackTable[1][Log(pin)] = callback; break;
		case PORTC:	(*NVIC_EN0) |= (1 << 2); callbackTable[2][Log(pin)] = callback; break;
		case PORTD:	(*NVIC_EN0) |= (1 << 3); callbackTable[3][Log(pin)] = callback; break;
		case PORTE:	(*NVIC_EN0) |= (1 << 4);	callbackTable[4][Log(pin)] = callback; break;
		case PORTF: (*NVIC_EN0) |= (1 << 30); callbackTable[5][Log(pin)] = callback; break;
	}
}

void GPIO_interruptHandler(volatile uint32_t portAddress){
	uint8_t portNumber;
	switch(portAddress){
		case PORTA: portNumber = 0; break;
		case PORTB: portNumber = 1; break;
		case PORTC: portNumber = 2; break;
		case PORTD: portNumber = 3; break;
		case PORTE: portNumber = 4; break;
		case PORTF: portNumber = 5; break;
	}
	if(Memory(portAddress,GPIO_MIS) == PIN0){
		Memory(portAddress,GPIO_ICR) |= PIN0;
		callbackTable[portNumber][0]();
	}
	else if(Memory(portAddress,GPIO_MIS) == PIN1){
		Memory(portAddress,GPIO_ICR) |= PIN1;
		callbackTable[portNumber][1]();
	}
	else if(Memory(portAddress,GPIO_MIS) == PIN2){
		Memory(portAddress,GPIO_ICR) |= PIN2;
		callbackTable[portNumber][2]();
	}
	else if(Memory(portAddress,GPIO_MIS) == PIN3){
		Memory(portAddress,GPIO_ICR) |= PIN3;
		callbackTable[portNumber][3]();
	}
	else if(Memory(portAddress,GPIO_MIS) == PIN4){
		Memory(portAddress,GPIO_ICR) |= PIN4;
		callbackTable[portNumber][4]();
	}
	else if(Memory(portAddress,GPIO_MIS) == PIN5){
		Memory(portAddress,GPIO_ICR) |= PIN5;
		callbackTable[portNumber][5]();
	}
	else if(Memory(portAddress,GPIO_MIS) == PIN6){
		Memory(portAddress,GPIO_ICR) |= PIN6;
		callbackTable[portNumber][6]();
	}
	else if(Memory(portAddress,GPIO_MIS) == PIN7){
		Memory(portAddress,GPIO_ICR) |= PIN7;
		callbackTable[portNumber][7]();
	}
}

void GPIOA_Handler(){
	GPIO_interruptHandler(PORTA);
}

void GPIOB_Handler(){
	GPIO_interruptHandler(PORTB);
}

void GPIOC_Handler(){
	GPIO_interruptHandler(PORTC);
}

void GPIOD_Handler(){
	GPIO_interruptHandler(PORTD);
}

void GPIOE_Handler(){
	GPIO_interruptHandler(PORTE);
}

void GPIOF_Handler(){
	GPIO_interruptHandler(PORTF);
}

void GPIO_setPullup(volatile uint32_t portAddress, Pin pin){
	Memory(portAddress, GPIO_PUR) |= pin;
}

void GPIO_setPulldown(volatile uint32_t portAddress, Pin pin){
	Memory(portAddress, GPIO_PDR) |= pin;
}


void GPIO_setPCTL(volatile uint32_t portAddress, Pin pin, uint8_t function){
	Memory(portAddress, GPIO_PCTL) &= ~(0x0f << (pin << 2));
	Memory(portAddress, GPIO_PCTL) |= (function << (pin << 2));
}

void GPIO_setOpenDrain(volatile uint32_t portAddress, Pin pin){
	Memory(portAddress, GPIO_ODR) |= pin;
}

void GPIO_set_drive2m(volatile uint32_t portAddress, Pin pin){
	Memory(portAddress, GPIO_DRV2M) |= pin;
}
void GPIO_set_drive4m(volatile uint32_t portAddress, Pin pin){
	Memory(portAddress, GPIO_DRV4M) |= pin;
}
void GPIO_set_drive8m(volatile uint32_t portAddress, Pin pin){
	Memory(portAddress, GPIO_DRV8M) |= pin;
}

void GPIO_set_register(volatile uint32_t portAddress, Pin pin, RegistersOffset registerName){
	Memory(portAddress, registerName) |= pin;
}
void GPIO_clear_register(volatile uint32_t portAddress, Pin pin, RegistersOffset registerName){
	Memory(portAddress, registerName) &= ~(pin);
}

