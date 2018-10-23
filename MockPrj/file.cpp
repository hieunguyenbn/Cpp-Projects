#include "file.h"
extern listNode *listFirst ;
extern listNode *listPoint;
extern listNode *listEnd;
extern uint16 nodeFinishRootDirector;//finish cluster root director
extern uint16 nodeRootDirector;
void ChangeStructFile(FILE * pFile, uint16 index, uint32 sizeFile)
{
	root_Entries *rootEntry = (root_Entries*)malloc(sizeof(root_Entries));
	uint16 nodeParent;
	listPoint = listEnd;
	uint32 nPositionFile = 0;
	char *fileNameMerge;
	nodeParent = listPoint->clusterPresent;
	if(listPoint->clusterPresent != 0)	// if not root director
		fseek(pFile, (nodeFinishRootDirector + listPoint->clusterPresent)*512, SEEK_SET );//jump 
	else
		fseek(pFile, nodeRootDirector *512, SEEK_SET );

	while(1){
		nPositionFile = ftell (pFile);
		fread(rootEntry, sizeof(root_Entries), 1, pFile); //read struct file 32 bit
		if(rootEntry->firstCluster == index){
			rootEntry->sizeofFile = sizeFile;
			fseek(pFile, nPositionFile, SEEK_SET );
			kmc_write_sub_sector(nPositionFile, (uint8*)rootEntry, pFile);
			fflush(pFile);
			break;
		}
	if( *rootEntry->short_FileName == 0)//if file name = 0 return
		return ;
	}
}

uint32 commandWrite(FILE *pFile, char *folder)
{
	uint32 sizeFile = 0;
	uint16 indexOpenFile = 0;
	indexOpenFile = FindIndexFolder(pFile, folder, &sizeFile);
	if(indexOpenFile != NOT_FIND_INDEX){
	}
	else{
		
	}
	return 0;
}
uint16 FindIndexFolder(FILE *pFile, char *folder, uint32 *sizeFile)
{
	root_Entries *rootEntry = (root_Entries*)malloc(sizeof(root_Entries));
	uint16 nodeParent;
	listPoint = listEnd;
	wchar_t *tCheck;
	wchar_t folder2[255];
	uint32	addrFile = 0;//save int of point point to file
	wchar_t *fileNameMerge;
	uint32 nCountSector = 0;
	nodeParent = listPoint->clusterPresent;
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
		mbstowcs (folder2, folder, 255);
 		if( wcscmp(folder2, (wchar_t*)fileNameMerge) == 0) {	//compare with name folder typed 
			if(FOLDER != rootEntry->fileAttributes){
				*sizeFile = rootEntry->sizeofFile;
				return rootEntry->firstCluster;
			}
		}
		if( *rootEntry->short_FileName == 0)//if file name = 0 return
			return NOT_FIND_INDEX;
	}
}

//int GetInfoDisk(FatBootSector *infoDisk, FILE * pFile)
//{
//    pFile=fopen ("floppy.img","r");
//    if (pFile==NULL){ 
//       perror ("Error opening file");
//       return 0;
//    }
//    else{
//         fread(infoDisk, sizeof(FatBootSector), 1, pFile);  
//         printf("OEM:%s\n",infoDisk->BS_OEMName);	 
//         printf("file type:%s\n",infoDisk->BS_FilSysType);
//    }
//    return 1;
//}