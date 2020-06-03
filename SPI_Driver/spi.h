#ifndef SPI_H
#define SPI_H

#include "stdint.h"
#include "gpio.h"
#include "tm4c123gh6pm.h"

#define SYSCTL_PRI2C   ((volatile uint32_t*)0x400FEA20)
#define SYSCTL_RCGCI2C ((volatile uint32_t*)0x400FE620)

typedef enum{
	SPI0,
	SPI1,
	SPI2,
	SPI3
} SPI;

#endif
