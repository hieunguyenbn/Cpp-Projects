#ifndef __FILE_H__
#define __FILE_H__
#include "common.h"
#include "hal.h"
#include "change.h"
void ChangeStructFile(FILE * pFile, uint16 index, uint32 sizeFile);
uint32 commandWrite(FILE *pFile, char *folder);
uint16 FindIndexFolder(FILE *pFile, char *folder, uint32 *sizeFile);
uint32 commandLSr(FILE *pFile,char *command);
#endif