#include <stdio.h>
#include "command.h"
extern listNode *listFirst ;
extern listNode *listPoint;
extern listNode *listEnd;
extern uint16 nodeFinishRootDirector;//finish cluster root director
extern uint16 nodeRootDirector;
void comandLS(FILE * pFile)	//show director on monitor
{
	root_Entries *rootEntry = (root_Entries*)malloc(sizeof(root_Entries));
	listPoint = listEnd;
	wchar_t *fileNameMerge;
	uint32 nCountSector = 0;
	if(listPoint->clusterPresent != 0){		//if not root director
		fseek(pFile, (nodeFinishRootDirector + listPoint->clusterPresent)*SIZESECTOR, SEEK_SET );
		nCountSector = (nodeFinishRootDirector + listPoint->clusterPresent)*SIZESECTOR;
	}
	else{
		fseek(pFile, (nodeRootDirector )*SIZESECTOR, SEEK_SET );
		nCountSector =  (nodeRootDirector )*SIZESECTOR;	//caculator position of file
	}
	while(1){
			memset(rootEntry, 0, sizeof(root_Entries));
			fread(rootEntry, sizeof(root_Entries), 1, pFile);	//read struct file 32 bit
			nCountSector += 32;	//increase position of file
			if( *rootEntry->short_FileName == 0)	//check file name = 0 exit loop
			    break;
			if( rootEntry->fileAttributes & 0x0E ) //check attributes 
				continue;
			fileNameMerge = MergeNameFile(pFile, (char*)rootEntry->short_FileName,(char*)rootEntry->extensionFileName);	//process file name
			fseek(pFile, nCountSector, SEEK_SET);	//jump position of point file
			printf("%2d:%2d:%2d", HOUR(rootEntry->Time), MINUTE(rootEntry->Time),
			                       SECOND(rootEntry->Time));	//printf time
			printf("\t%2d/%2d/%2d\t", DAY(rootEntry->Date),  MONTH(rootEntry->Date),
			                   YEAR(rootEntry->Date)+ 1980);	//printf date
			wprintf(L"%-25s\n", (wchar_t *)fileNameMerge);//printf name file
			if(fileNameMerge != NULL){	//free memmory
				free(fileNameMerge);
				fileNameMerge = NULL;
			}
		}
	/* if(rootEntry != NULL){
		free(rootEntry);
		rootEntry = NULL;
	}*/
}



int commandCDFolder(FILE *pFile, char *folder)//command access in folder
{
	uint32	addrFile = 0;//save int of point point to file
	root_Entries *rootEntry = NULL;// (root_Entries*)malloc(sizeof(root_Entries));
	uint16 nodeParent;
	static wchar_t folder2[255];
	uint32 nCountSector = 0;
	listPoint = listEnd;
	wchar_t *fileNameMerge;
	nodeParent = listPoint->clusterPresent;
	rootEntry = (root_Entries*)malloc(sizeof(root_Entries));
	if(listPoint->clusterPresent != 0){	// if not root director
		fseek(pFile, (nodeFinishRootDirector + listPoint->clusterPresent)*512, SEEK_SET );//jump 
		nCountSector = (nodeFinishRootDirector + listPoint->clusterPresent)*SIZESECTOR;
	}
	else{
		fseek(pFile, nodeRootDirector *512, SEEK_SET );
		nCountSector =  (nodeRootDirector )*SIZESECTOR;
	}

	while(1){
		fread(rootEntry, sizeof(root_Entries), 1, pFile); //read struct file 32 bit
		nCountSector += 32;
		fileNameMerge = MergeNameFile(pFile, (char*)rootEntry->short_FileName,(char*)rootEntry->extensionFileName);
		fseek(pFile, nCountSector, SEEK_SET);
		mbstowcs (folder2, folder, 255);	//convert from char to unicode
		if(wcscmp(folder2, (wchar_t*)fileNameMerge) == 0) {	//compare with name folder typed 
			if(FOLDER == rootEntry->fileAttributes){	//if it is folder
				listPoint = listFirst;	//point to first of link list
				while(listPoint != NULL)
				{
					if(listPoint->clusterPresent == rootEntry->firstCluster){	// if cluster existed in link list
						listEnd = listPoint; 
						 DeleteLinklist(listEnd);	//delete link list from position listEnd
						/* if(rootEntry != NULL){
							free(rootEntry);
							rootEntry = NULL;
						}*/
						return 1;
					}
					listPoint = listPoint->next;	//next link list
				}	
				InputLinkList(nodeParent, rootEntry->firstCluster, folder, strlen(folder));	//put in link list
				if(fileNameMerge != NULL){
					free(fileNameMerge);
					fileNameMerge = NULL;
				}
				/*if(rootEntry != NULL){
					free(rootEntry);
					rootEntry = NULL;
				}*/
				return 1;
			}
			else{
				if(fileNameMerge != NULL){
					free(fileNameMerge);
					fileNameMerge = NULL;
				}
				/*if(rootEntry != NULL){
					free(rootEntry);
					rootEntry = NULL;
				}
				return 0;*/
			}
		}
		if( fileNameMerge !=  NULL){
			free(fileNameMerge);
			fileNameMerge = NULL;
		}
		if( *rootEntry->short_FileName == 0){//if file name = 0 return
			if(rootEntry != NULL){
					free(rootEntry);
					rootEntry = NULL;
			}
		    return 0;
		}
	}

}
uint32 commandVIfile(FILE *pFile,char *command){	//printf file on screen
	uint16 indexOpenFile = 0;
	uint8 *buff = NULL;
	char *buffTotal = NULL;
	uint32 nNumCharacReceiv = 0;
	char *buff2 = (char*)malloc(255);
	uint32 sizeFile;
	indexOpenFile = FindIndexFolder(pFile, command, &sizeFile);	//get index of file 
	// read file and save buffer
	if(sizeFile <= SIZESECTOR)
		nNumCharacReceiv = kmc_read_sector(indexOpenFile, &buff, pFile);
	else
		nNumCharacReceiv = kmc_read_multi_sector(indexOpenFile, &buff, sizeFile/SIZESECTOR + 1, pFile);
	showMonitor((char*)buff, nNumCharacReceiv);//show monitor
	fflush(stdin); //delete cache
	fgets(buff2, 255, stdin);		//get charater from monitor
	buffTotal = (char*)malloc(strlen((char*)buff) + strlen(buff2) + 1);
	strcpy((char*)buffTotal, (char*)buff);
	strcat((char*)buffTotal, buff2);
	nNumCharacReceiv = kmc_write_sector(indexOpenFile, (uint8*)buffTotal, pFile);
	ChangeStructFile(pFile, indexOpenFile, strlen(buffTotal));
	//if(buff != NULL)
		//free(buff);
	if(buff2 != NULL){
		free(buff2);
		buff2 = NULL;
	}
	return 0;
}

void RunCommand(FILE * pFile)	//funtion runcommand
{
	char *command = (char*)malloc(255);
	while(1){
		switch( stringToNum(&command)){
			case LS:		//list file
				comandLS(pFile);
				break;
			case CD:	//enter in folder
				if(*command == '\0'){	//if command only have CD delete link list
					listEnd = listFirst;
					DeleteLinklist(listFirst);		
				}
				else if(commandCDFolder(pFile, command) == 0)	//	
					printf("path wrong\n");
					break;
			case VI:		//show file on monitor
				commandVIfile(pFile, command);
				break;
			default:	//comamdn not exist
				printf("command wrong,Please type again\n");
				break;
		}
	}			
}