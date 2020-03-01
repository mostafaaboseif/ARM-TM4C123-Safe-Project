#include "uart.h"

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
  while((Memory(uart, UART_FLAG)&0x0010) != 0);     // wait until RXFE is 0 (reciver is not empty)
  return (uint8_t)Memory(uart, UART_DATA);
}

void UART_sendChar(Uart uart, const char data){
	while((Memory(uart, UART_FLAG)&0x0020) != 0);			// wait until TXFF is 0 (transmitter is not full)
	Memory(uart, UART_DATA) = data;
}


void UART_sendString(Uart uart, const char *data){
	int j=0;
  while(data[j]!='\0'){ 
    UART_sendChar(uart,data[j]);
    j++;			
  }
	UART_sendChar(uart,'\0');
}

void UART_sendByteStream(Uart uart, const uint8_t *data){
	int j = sizeof(*data)/8;
	for(int i = 0; i < j; i++) UART_sendChar(uart,data[i]);
}
	
void UART_attachToBuffer(Uart uart){
	Memory(uart, UART_IFLS) &= 0xFFFFFF00;
	Memory(uart, UART_IM) |= 0x00000010;
}