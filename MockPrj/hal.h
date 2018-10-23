#ifndef __HAL_H__
#define __HAL_H__

#include "common.h"
uint32 kmc_read_sector(uint16 index, uint8 **buff, FILE *pFile)	;
uint32 kmc_read_multi_sector(uint16 index, uint8 **buff, uint16 num, FILE *pFile);
uint32 kmc_write_sector(uint16 index, const uint8 *buff, FILE *pFile);
uint32 kmc_write_sub_sector(uint32, const uint8 *buff, FILE *pFile);
#endif