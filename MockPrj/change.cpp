#include "change.h"
extern listNode *listFirst ;
extern listNode *listPoint;
extern listNode *listEnd;
extern structChange table[8] ;

#define NKEYS (sizeof(table)/sizeof(structChange))
wchar_t * MergeNameFile(FILE *pFile, char *fileName, char *extensionFileName)
{
	uint32 i, sum = 0;
	char *p;
	char *mergeFileName = (char*)malloc(255);
	wchar_t *mergeFileNameConvert = NULL;// (char*)malloc(255 * sizeof(wchar_t));
	longName *structLongName = (longName*)malloc(sizeof(longName));
	char extenNameBuff[5];
	char checkCh[2] = {(char)0xff, (char)0xff};
	char *pch;
	//uint32	addrFile = 0;//save int of point point to file
	wchar_t wchar_externName[5];
	strncpy((extenNameBuff+1),extensionFileName,3);
	extenNameBuff[4]	= '\0';
	*extenNameBuff		= '.';
	strncpy(mergeFileName,fileName,8);
	mergeFileName[8] = '\0';
	wchar_t checkName[1] = {(wchar_t)0xffff};
	fseek(pFile, -64, SEEK_CUR);
	fread(structLongName, sizeof(longName), 1, pFile);
	//fseek(pFile, addrFile, SEEK_SET);
	if (structLongName->Attribute == 0x0f)
	{
		mergeFileNameConvert = (wchar_t*)malloc(255 * sizeof(wchar_t));
		fseek(pFile, -32, SEEK_CUR);
		memset(mergeFileNameConvert, '\0', 255);
		do{
			
			fread(structLongName, sizeof(longName), 1, pFile);
			structLongName->unicodePart1[5] = '\0';
			structLongName->unicodePart2[6] = '\0';
			structLongName->unicodePart3[2] = '\0';							
			wcscat((wchar_t *)mergeFileNameConvert, (wchar_t *)structLongName->unicodePart1);
			wcscat((wchar_t *)mergeFileNameConvert, (wchar_t *)structLongName->unicodePart2);
			wcscat((wchar_t *)mergeFileNameConvert, (wchar_t *)structLongName->unicodePart3);
		
			if(structLongName->OrdinalField & 0x40){
				wcstok((wchar_t *)mergeFileNameConvert,checkName);
				free(mergeFileName);
				p = (char*)mergeFileNameConvert;
				for (sum = i = 0; i < 11; i++) { 
					sum = (((sum & 1) << 7) | ((sum & 0xfe) >> 1)) + p[i]; 
				}
				return mergeFileNameConvert;
			}else
				fseek(pFile, -64, SEEK_CUR);
		}while(1);
	}else{
		pch = strtok(mergeFileName," ");
		while(pch != NULL)
		{
			pch = strtok(NULL, " ");
		}
		if(extenNameBuff[1] != ' ')
			strcat(mergeFileName, extenNameBuff);
		pch  = mergeFileName;
		while(*pch != NULL){
			*pch =(char) tolower(*pch);
			pch++;
		}
		mergeFileNameConvert = (wchar_t*)malloc(255 * sizeof(wchar_t));
		mbstowcs (mergeFileNameConvert, mergeFileName, 255);
		free(mergeFileName);
		
		return mergeFileNameConvert;
	}
	
		
}



int stringToNum(char **key)// from string chang to number to switch case
{
	int i;
	char *nameFolder = NULL;
	printf("\n>");
	listPoint = listFirst;	//show director present
	while(listPoint != NULL)
	{
		printf("%s/",listPoint->fileName);
		listPoint = listPoint->next;
	}
	fflush(stdin); //delete cache
	memset (*key,'\0',255);	//delete string
	fgets(*key,255,stdin);		//get charater from monitor
	nameFolder = strtok(*key," ");
    for (i=0; i < NKEYS; i++) {
        if (strcmp(table[i].key, *key) == 0){	//compare 
			*key += (strlen(table[i].key)+1);	
            return table[i].val;
		}
    }
    return BADKEY;	// 
}