#include "stdint.h"
#include "gpio.h"
#include "tm4c123gh6pm.h"
#include "i2c.h"
#include "i2c_eeprom.h"
#include "uart.h"


int main()
{	
	UART_Init(UART1, UART_BAUD_9600);
	UART_sendString(UART1, "Starting \n");
	I2C_EEPROM_init(I2C1, 0x50);
	I2C_EEPROM_writeString("Mohamed\n", 0x0100);
	UART_sendString(UART1, "END \n");
	
	UART_sendString(UART1, "Reading \n");
	char str[8];
	uint8_t readNumber = I2C_EEPROM_readString(str, 8, 0x0100);
	for(int a = 0; a < readNumber; a++){
		UART_sendChar(UART1, str[a]);
	}
	UART_sendString(UART1, "END \n");
}