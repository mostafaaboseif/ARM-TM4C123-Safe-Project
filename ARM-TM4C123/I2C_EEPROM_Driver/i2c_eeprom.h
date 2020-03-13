#ifndef _EEPROM_I2C_DRIVER_H
#define _EEPROM_I2C_DRIVER_H

#include "stdint.h"
#include "uart.h"
#include "i2c.h"

void I2C_EEPROM_init(volatile I2C i2c, uint8_t address);
void I2C_EEPROM_writeChar(uint8_t ch, uint16_t address);
uint8_t I2C_EEPROM_readChar(uint16_t address);
void I2C_EEPROM_writeString(uint8_t *str, uint16_t address);
uint8_t I2C_EEPROM_readString(uint8_t *str, uint8_t nob, uint16_t address);

#endif

