#include "i2c_eeprom.h"

I2C i2c_connected;

void I2C_EEPROM_init(volatile I2C i2c, uint8_t address){
	i2c_connected = i2c;
	I2C_initMaster(i2c);
	I2C_setSlaveAddress(i2c, 0x50);
}

void I2C_EEPROM_writeChar(uint8_t ch, uint16_t address){
	I2C_writeByte(i2c_connected, address >> 8, I2C_START_BIT | I2C_RUN);	// MSB of address
	I2C_writeByte(i2c_connected, address & 0xFF, I2C_RUN);	// LSB of address
	I2C_writeByte(i2c_connected, ch, I2C_RUN | I2C_STOP_BIT);		
	for(long i = 0; i < 40000; i++);					// delay between transactions
}

void I2C_EEPROM_writeString(uint8_t *ch, uint16_t address){
	I2C_writeByte(i2c_connected, address >> 8, I2C_START_BIT | I2C_RUN);	// MSB of address
	I2C_writeByte(i2c_connected, address & 0xFF, I2C_RUN);	// LSB of address
	while(*ch != '\0'){
		I2C_writeByte(i2c_connected, *ch, I2C_RUN);
		ch++;
	}
		I2C_writeByte(i2c_connected, '\0', I2C_STOP_BIT | I2C_RUN);
	for(long i = 0; i < 40000; i++);					// delay between transactions
}

uint8_t I2C_EEPROM_readChar(uint16_t address){
	I2C_writeByte(i2c_connected, address >> 8 ,I2C_START_BIT | I2C_RUN);	// send slave addrr and start bit	and start address	
	I2C_writeByte(i2c_connected, address & 0xFF, I2C_RUN);
	uint8_t output = I2C_readByte(i2c_connected, I2C_START_BIT | I2C_RUN | I2C_STOP_BIT);
	for(long i = 0; i < 40000; i++);					// delay between transactions
	return output;
}

uint8_t I2C_EEPROM_readString(uint8_t *str, uint8_t max_nob, uint16_t address){
	I2C_writeByte(i2c_connected, address >> 8 ,I2C_START_BIT | I2C_RUN);	// send slave addrr and start bit	and MSB of address	
	I2C_writeByte(i2c_connected, address & 0xFF, I2C_RUN);								// send LSB of addr
	uint8_t count = 0;
	for(; count < max_nob; count++){
		uint8_t chr = I2C_readByte(I2C1, I2C_RUN | I2C_START_BIT);
		if(chr == '\0') return count;
		str[count] = chr;
	}
	return count;
}
