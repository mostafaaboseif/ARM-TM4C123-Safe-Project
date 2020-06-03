#include "flash.h"
#include "tm4c123gh6pm.h"

// The TM4C123 has 256 KiB of Flash memory located from addresses 0 to 0x0003FFFF

#define FLASH_BASE_ADDR			((volatile uint32_t*)0x00020000)

static uint16_t	flashKey_ = 0;

void FLASH_init(void)
{
	if (FLASH_BOOTCFG_R & 0x10) {
		flashKey_ =	FLASH_KEY_1;
	}
	else {
		flashKey_ = FLASH_KEY_2;
	} 
	
}


void FLASH_Erase(uint32_t blockCount)
{
	if (flashKey_ == 0) {
		return;
	}
	
	for (uint32_t i = 0; i < blockCount; i++) {
	
		FLASH_FMA_R &= 0xFFFC0000;
		
		FLASH_FMA_R |= ((uint32_t)FLASH_BASE_ADDR) + (i*1024);
		
		FLASH_FMC_R = (flashKey_ << 16) | 0x02; 

		while (FLASH_FMC_R & 0x2);
	
	}
}


void FLASH_Write(const uint32_t* data, uint32_t wordCount)
{
	if (flashKey_ == 0) {
		return;
	}
	
	uint32_t blockCount = ((wordCount * sizeof(uint32_t)) / 1024) + 1;
	FLASH_Erase(blockCount);
	
	for (uint32_t i = 0; i < wordCount; i++) {
		FLASH_FMD_R = data[i];
		
		FLASH_FMA_R &= 0xFFFC0000;  
		FLASH_FMA_R |= (uint32_t)FLASH_BASE_ADDR + (i * sizeof(uint32_t));
		
		FLASH_FMC_R = (flashKey_ << 16) | 0x01; 

		// Poll the WRITE bit until it is cleared.
		while (FLASH_FMC_R & 0x1);
			
	}
}



void FLASH_Read(uint32_t* data, uint32_t wordCount)
{
	for (uint32_t i = 0; i < wordCount; i++) {
		data[i] = FLASH_BASE_ADDR[i];
	}

}

