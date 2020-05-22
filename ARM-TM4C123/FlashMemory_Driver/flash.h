#ifndef _FLASH_H_
#define _FLASH_H_

#include "stdint.h"

#define FLASH_KEY_1 0xA442
#define FLASH_KEY_2 0x71D5

void FLASH_init(void);
void FLASH_Erase(uint32_t blockCount);
void FLASH_Write(const uint32_t* data, uint32_t wordCount);
void FLASH_Read(uint32_t* data, uint32_t wordCount);



#endif