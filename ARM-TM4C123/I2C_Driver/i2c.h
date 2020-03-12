#ifndef _I2C_DRIVER_H
#define _I2C_DRIVER_H

#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "gpio.h"

typedef enum I2C {
	I2C0		=		0x40020000,
  I2C1 		=		0x40021000,
  I2C2		=		0x40022000,
  I2C3 		=		0x40023000,	
} I2C;

#define WRITE				0
#define READ				1

typedef enum I2COffset{
	 I2C_MSA  = 0x000,
	 I2C_MCS  = 0x004,
	 I2C_MDR  = 0x008,
	 I2C_MTPR = 0x00C,
	 I2C_MIMR = 0x010,
	 I2C_MRIS = 0x014,
	 I2C_MICR = 0x01C,
	 I2C_MCR  =  0x020
} I2COffset;

#define SYSCTL_PRI2C   ((volatile uint32_t*)0x400FEA20)
#define SYSCTL_RCGCI2C ((volatile uint32_t*)0x400FE620)
	
#define Memory(X,Y)			(*((volatile uint32_t*)(((volatile uint32_t)X)+((volatile uint32_t)Y))))

void I2C_initMaster(I2C i2cAddress, uint8_t mode);

void I2C_setSlaveAddress(uint8_t address);

void I2C_writeByte(uint8_t data , uint8_t conditions);
void I2C_receiveString(int nb ,char* data);
char I2C_readByte(int conditions);
void I2C_writeTransaction(char* data);

void I2C_switchToWrite();
void I2C_switchToRead();

void I2C_initSlave(int address);
void I2C_setCallBackFn(void (*function)(char));

#endif