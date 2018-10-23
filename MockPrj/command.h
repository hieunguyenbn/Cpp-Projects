#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "common.h"
#include "change.h"
#include "linklist.h"
#include "file.h"
#include "monitor.h"

int commandCDFolder(FILE *pFile, char *folder);//command access in folder
void comandLS(FILE * pFile);
uint32 commandVIfile(FILE *pFile,char *command);
void RunCommand(FILE * pFile);

#endif