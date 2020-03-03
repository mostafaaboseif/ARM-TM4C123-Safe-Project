#ifndef _GPIO_DRIVER_H
#define _GPIO_DRIVER_H

#include <stdint.h>
#include "../External_Libraries/tm4c123gh6pm.h"
#include <math.h>

#define PORTA 0x40004000
#define PORTA_AHB 0x40058000
#define PORTB 0x40005000
#define PORTB_AHB 0x40059000
#define PORTC 0x40006000
#define PORTC_AHB 0x4005A000
#define PORTD 0x40007000
#define PORTD_AHB 0x4005B000
#define PORTE 0x40024000
#define PORTE_AHB 0x4005C000
#define PORTF 0x40025000
#define PORTF_AHB 0x4005D000

#define SYSCTL_PRGPIO ((volatile uint32_t *)0x400FEA08)
#define SYSCTL_RCGCGPIO ((volatile uint32_t *)0x400FE608)
#define NVIC_EN0 ((volatile uint32_t *)0xE000E100)
#define RCGC2_REG ((volatile uint32_t *)0x400FE108) // really don't know why we are using this

#define UNLOCK 0x4C4F434B
#define PORT_OFFSET 0x3FC
#define HIGH 0xFF
#define LOW 0x00

#define Memory(X, Y) (*((volatile uint32_t *)(((uint32_t)X) + ((uint32_t)Y))))
#define Log(X) (int)log2(X)

#define I2C_F 0x03
#define UART_F 0x02

typedef enum GPIORegistersOffset
{
	GPIO_DIR = 0x400,
	GPIO_IS = 0x404,
	GPIO_IBE = 0x408,
	GPIO_IEV = 0x40C,
	GPIO_IM = 0x410,
	GPIO_RIS = 0x414,
	GPIO_MIS = 0x418,
	GPIO_ICR = 0x41C,
	GPIO_AFSEL = 0x420,
	GPIO_DRV2M = 0x500,
	GPIO_DRV4M = 0x504,
	GPIO_DRV8M = 0x508,
	GPIO_ODR = 0x50C,
	GPIO_PUR = 0x510,
	GPIO_PDR = 0x514,
	GPIO_SLR = 0x518,
	GPIO_DEN = 0x51C,
	GPIO_LCK = 0x520,
	GPIO_CR = 0x524,
	GPIO_AMSEL = 0x528,
	GPIO_PCTL = 0x52C
} GPIORegistersOffset;

typedef enum Pin
{
	PIN0 = 0x001,
	PIN1 = 0x002,
	PIN2 = 0x004,
	PIN3 = 0x008,
	PIN4 = 0x010,
	PIN5 = 0x020,
	PIN6 = 0x040,
	PIN7 = 0x080,
} Pin;

typedef enum PinMode
{
	DIGITAL,
	ANALOG,
} PinMode;

typedef enum PinDir
{
	INPUT = 0x00,
	OUTPUT = 0xFF,
	PERIPHERAL,
} PinDir;

typedef enum InterruptEvent
{
	RISING,
	FALLING,
	BOTH,
} InterruptEvent;

void GPIO_setClkSource(volatile uint32_t portAddress);

void GPIO_initPin(volatile uint32_t portAddress, Pin pin, PinMode mode, PinDir dir);
uint8_t GPIO_readPin(volatile uint32_t portAddress, Pin pin);
void GPIO_writePin(volatile uint32_t portAddress, Pin pin, uint8_t value);

void GPIO_initPort(volatile uint32_t portAddress, PinDir dir);
uint8_t GPIO_readPort(volatile uint32_t portAddress);
void GPIO_writePort(volatile uint32_t portAddress, uint8_t value);

void GPIO_initInterrupt(volatile uint32_t portAddress, Pin pin, InterruptEvent ev, void (*callback)());
void GPIO_interruptHandler(volatile uint32_t portAddress);

void GPIO_setPullup(volatile uint32_t portAddress, Pin pin);
void GPIO_setPulldown(volatile uint32_t portAddress, Pin pin);
void GPIO_setPCTL(volatile uint32_t portAddress, Pin pin, uint8_t function);
void GPIO_setOpenDrain(volatile uint32_t portAddress, Pin pin);
void GPIO_set_drive2m(volatile uint32_t portAddress, Pin pin);
void GPIO_set_drive4m(volatile uint32_t portAddress, Pin pin);
void GPIO_set_drive8m(volatile uint32_t portAddress, Pin pin);
void GPIO_set_register(volatile uint32_t portAddress, Pin pin, GPIORegistersOffset registerName);
void GPIO_clear_register(volatile uint32_t portAddress, Pin pin, GPIORegistersOffset registerName);

#endif
