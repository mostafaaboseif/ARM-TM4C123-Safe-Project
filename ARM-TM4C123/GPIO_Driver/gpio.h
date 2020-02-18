#ifndef _GPIO_DRIVER_H
#define _GPIO_DRIVER_H

#include <stdint.h>

#define PORTA_APB				0x40004000
#define PORTA_AHB				0x40058000
#define PORTB_APB				0x40005000
#define PORTB_AHB				0x40059000
#define PORTC_APB				0x40006000
#define PORTC_AHB				0x4005A000
#define PORTD_APB				0x40007000
#define PORTD_AHB				0x4005B000
#define PORTE_APB				0x40024000
#define PORTE_AHB				0x4005C000
#define PORTF_APB				0x40025000
#define PORTF_AHB				0x4005D000
	
#define SYSCTL_PRGPIO   ((volatile uint32_t*)0x400FEA08)
#define SYSCTL_RCGCGPIO ((volatile uint32_t*)0x400FE608)
	
#define UNLOCK					0x4C4F434B
#define PORT_OFFSET			0x3FC
#define HIGH						0xFF
#define LOW							0x00

#define Memory(X,Y)			(*((volatile uint32_t*)(((volatile uint32_t)X)+((volatile uint32_t)Y))))

typedef enum RegistersOffset{
	GPIO_DIR 			= 0x400,
	GPIO_AFSEL		=	0x420,
	GPIO_DRV2M		=	0x500,
	GPIO_DRV4M		=	0x504,
	GPIO_DRV8M		=	0x508,
	GPIO_ODR			= 0x50C,
	GPIO_PUR			=	0x510,
	GPIO_PDR			=	0x514,
	GPIO_SLR 			=	0x518,
	GPIO_DEN			=	0x51C,
	GPIO_LCK			=	0x520,
	GPIO_CR				=	0x524,
	GPIO_AMSEL		=	0x528,
	GPIO_PCTL			=	0x52C
} RegistersOffset;

typedef enum Pin{
	PIN0					=	0x01,
	PIN1					=	0x02,
	PIN2					=	0x04,
	PIN3					=	0x08,
	PIN4					=	0x10,
	PIN5					=	0x20,
	PIN6					=	0x40,
	PIN7					=	0x80,
} Pin;

typedef enum PinOffset{
	WPIN0					= 0x004,
	WPIN1					= 0x008,
	WPIN2					= 0x010,
	WPIN3					= 0x020,
	WPIN4					= 0x040,
	WPIN5					= 0x080,
	WPIN6					= 0x100,
	WPIN7					= 0x200,
} PinOffset;

typedef enum PinMode{
	DIGITAL,
	ANALOG ,
} PinMode;

typedef enum PinDir{
	INPUT			 = 0x00,
	OUTPUT		 = 0xFF,
	PERIPHERAL,
} PinDir;

void 		gpio_init_port(volatile uint32_t portAddress, PinDir dir);
void 		gpio_init_pin(volatile uint32_t portAddress, Pin pin, PinMode mode, PinDir dir);

void 		gpio_set_pullup(volatile uint32_t portAddress, Pin pin);
void 		gpio_set_pulldown(volatile uint32_t portAddress, Pin pin);

uint8_t gpio_read_pin(volatile uint32_t portAddress,Pin pin);
void 		gpio_write_pin(volatile uint32_t portAddress, PinOffset pin, uint8_t value);

void 		gpio_set_register(volatile uint32_t portAddress, Pin pin, RegistersOffset registerName);
void 		gpio_clear_register(volatile uint32_t portAddress, Pin pin, RegistersOffset registerName);

uint8_t gpio_read_port(volatile uint32_t portAddress);
void    gpio_write_port(volatile uint32_t portAddress, uint8_t value);

void 		gpio_set_drive2m(volatile uint32_t portAddress, Pin pin);
void 		gpio_set_drive4m(volatile uint32_t portAddress, Pin pin);
void 		gpio_set_drive8m(volatile uint32_t portAddress, Pin pin);

#endif
