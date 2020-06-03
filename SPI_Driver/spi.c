#include "spi.h"

void SPI_initMaster(uint8_t spi){
	switch(spi){
		case SPI2:
			SYSCTL_RCGCGPIO_R = (1 << 1);
			SYSCTL_RCGCSSI_R = (1 << 2);
			
			Memory(PORTB, GPIO_AFSEL) |= (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
			Memory(PORTB, GPIO_PCTL)  |= (2 << 16) | (2 << 20) | (2 << 24) | (2 << 28);
			Memory(PORTB, GPIO_DEN)   |= (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
			SSI2_CR1_R &= ~(1 << 1); 						// SSI is disapled
	
			SSI2_CR1_R = 0;  										// SSI is Master Check Datasheet
			SSI2_CC_R = 0;											// Baud rate is same as system clock
			SSI2_CPSR_R = 80;										// Prescaler: should be even number
			SSI2_CR0_R = (0x7 << 0) | (1 << 7); // 0x7  for 8 bit transaction. 1 << 7 sck is active low
			
			SSI2_CR1_R |= (1 << 1);							// SSI is Enabled
			break;
	}
}

uint8_t SPI_writeRead(uint8_t spi, uint8_t data){
	switch(spi){
		case SPI2:
			SSI2_DR_R = data; 								// data required to be set
			while(!(SSI2_SR_R & (1 << 0)));		// polling until data is sent
			
			while(!(SSI2_SR_R & (1 << 2)));		// polling until received data is read
			return SSI2_DR_R;									// return recieved data
	}
	return 0;
}
