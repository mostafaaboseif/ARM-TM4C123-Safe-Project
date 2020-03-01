
#ifndef _UART_H
#define _UART_H

#include "stdint.h"
#include "gpio.h"
#include "string.h"

#define CLK_SPEED				50000000
#define Memory(X,Y)			(*((volatile uint32_t*)(((uint32_t)X)+((uint32_t)Y))))
#define BAUD_IDIV(B)		(int)(CLK_SPEED/(16*B))
#define BAUD_FDIV(B) 		(int)(((CLK_SPEED/(16*B)) - BAUD_IDIV(B))*64)
#define UART_CLK				((volatile uint32_t *)0x400FE618)
#define RCGC2_REG				((volatile uint32_t *)0x400FE108)	//really don't know why we are using this

typedef enum Uart{
	UART0 			= 0x4000C000,
	UART1 			= 0x4000D000,
	UART2 			= 0x4000E000,
	UART3 			= 0x4000F000,
	UART4 			= 0x40010000,
	UART5			= 0x40011000,
	UART6			= 0x40012000,
	UART7			= 0x40013000,
} Uart;

typedef enum UARTRegistersOffset{
	UART_DATA 			= 0x000,
	UART_RS_EC 			= 0x004,
	UART_FLAG 			= 0x018,
	UART_IBRD 			= 0x024,
	UART_FBRD 			= 0x028,
	UART_LCTL			= 0x02C,
	UART_CTL			= 0x030,
	UART_IFLS			= 0x034,
	UART_IM 			= 0x038,
	UART_RIS			= 0x03C,
	UART_MIS			= 0x040,
	UART_IC			    = 0x044,
	UART_DMACTL			= 0x048,
	UART_PP 			= 0xFC0,
	UART_CC 			= 0xFC8,
} UARTRegistersOffset;

typedef enum UART_BAUDRATE{
	UART_BAUD_300 			  = 300,
	UART_BAUD_1200 			= 1200,
	UART_BAUD_2400 			= 2400,
	UART_BAUD_4800 			= 4800,
	UART_BAUD_9600 			= 9600,
	UART_BAUD_19200 			= 19200,
	UART_BAUD_38400 			= 38400,
	UART_BAUD_57600 			= 57600,
	UART_BAUD_74880 			= 74880,
	UART_BAUD_115200			= 115200,
} UART_BAUDRATE;

void UART_Init(Uart uart, UART_BAUDRATE baudrate);
uint8_t UART_readChar(Uart uart);
void UART_sendChar(Uart uart, const char data);
void UART_sendString(Uart uart, const char *data);
void UART_sendByteStream(Uart uart, const uint8_t *data);
void UART_attachToBuffer(Uart uart);
#endif
