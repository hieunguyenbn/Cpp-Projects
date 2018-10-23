
#include "hal.h"
extern listNode *listPoint;
extern uint16 nodeFinishRootDirector;//finish cluster root director
extern uint16 nodeRootDirector;
uint32 kmc_read_sector(uint16 index, uint8 **buff, FILE *pFile)	
{ 
	uint32 numberCharacter;
	*buff = (uint8*)malloc(SIZESECTOR);
	fseek(pFile, (nodeFinishRootDirector + index)*SIZESECTOR, SEEK_SET );//jump 
	numberCharacter = fread(*buff, 1, SIZESECTOR, pFile);
	return numberCharacter;
	
}
uint32 kmc_read_multi_sector(uint16 index, uint8 **buff, uint16 num, FILE *pFile)	
{ 
	uint32 numberCharacter;
	*buff = (uint8*)malloc(SIZESECTOR * num);
	fseek(pFile, (nodeFinishRootDirector + index)*SIZESECTOR, SEEK_SET );//jump 
	numberCharacter = fread(*buff, 1, SIZESECTOR * num, pFile);
	return numberCharacter;
	
}

uint32 kmc_write_sector(uint16 index, const uint8 *buff, FILE *pFile)
{
	uint32 numberCharacter;
	fseek(pFile, (nodeFinishRootDirector + index)*SIZESECTOR, SEEK_SET );//jump 
	numberCharacter = fwrite(buff, 1, strlen((char*)buff), pFile);
	fflush (pFile);  
	return numberCharacter;
}

uint32 kmc_write_sub_sector(uint32 nPositionFile, const uint8 *buff, FILE *pFile)
{
	uint32 numberCharacter;
	fseek(pFile, nPositionFile, SEEK_SET );//jump 
	numberCharacter = fwrite(buff, 1, strlen((char*)buff), pFile);
	fflush (pFile);  
	return numberCharacter;
}