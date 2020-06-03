#include "uart.h"

char buffer[UART_BUFFER_SIZE];
volatile uint8_t buffer_index = 0;
volatile Uart uartAttachedToBuffer;

void UART_Init(Uart uart, UART_BAUDRATE baudrate){
  if(uart == UART1){
    GPIO_initPin(PORTC, PIN4, DIGITAL, PERIPHERAL);
    GPIO_initPin(PORTC, PIN5, DIGITAL, PERIPHERAL);
		GPIO_setPCTL(PORTC, PIN4, UART_F);
		GPIO_setPCTL(PORTC, PIN5, UART_F);
		(*UART_CLK) |= (1 << 1);		// activate UART1 
		(*RCGC2_REG) |= (1 << 2);		// activate portc clk ??
  }
  Memory(uart, UART_CTL) &= ~0x00000001;						// Disable UART Module
  Memory(uart, UART_IBRD) = BAUD_IDIV(baudrate);		// writing integer baudrate divisor
	Memory(uart, UART_FBRD) = BAUD_FDIV(baudrate);		// Fractional integer baudrate divisor
	Memory(uart, UART_CC) &= ~0x0000000F; 						// clock source is system clock
	Memory(uart, UART_LCTL) = 0x00000060;  						// 8 bit, no parity bits, one stop, no FIFOs
	Memory(uart, UART_CTL) |= 0x00000001;							// enable UART
}

uint8_t UART_readChar(Uart uart){
  while((Memory(uart, UART_FLAG)&0x0010) != 0);     // wait until RXFE is 0 (reciver is empty)
  return (uint8_t)Memory(uart, UART_DATA);
}

void UART_sendChar(Uart uart, const char data){
	while((Memory(uart, UART_FLAG)&0x0020) != 0);			// wait until TXFF is 0 (transmitter is  full)
	Memory(uart, UART_DATA) = data;
}


void UART_sendString(Uart uart, const char *data){
	uint8_t j = 0;
	while(data[j] != '\0'){
		UART_sendChar(uart,data[j]);
		j++;
	}
	UART_sendChar(uart,'\0');
}

void UART_sendByteStream(Uart uart, const uint8_t *data, const uint8_t size){
	for(int i = 0; i < size; i++) UART_sendChar(uart,data[i]);
}
	
void UART_attachBuffer(Uart uart){
	uartAttachedToBuffer = uart;
	if(uart == UART1) (*NVIC_EN0) |= (1 << 6);			//enable interrupts for UART1
	Memory(uart, UART_IFLS) &= 0xFFFFFF00;
	Memory(uart, UART_IM)   |= 0x00000010;
}

void UART1_Handler(){
	if(uartAttachedToBuffer == UART1) UART_interruptHandler(UART1);
}

void UART_interruptHandler(Uart uart){
	buffer[buffer_index] = UART_readChar(uart);
	buffer_index++;
}

void UART_readString(char *dest){
	strncpy(dest,buffer,buffer_index);
	dest[buffer_index] = '\0';
	buffer_index = 0;
}

uint8_t UART_bufferAvailable(){
	return buffer_index;
}