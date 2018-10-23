//#include "common.h"
#include "hal.h"
#include "linklist.h"
#include "file.h"
#include "change.h"
#include "command.h"
listNode *listFirst = NULL;
listNode *listPoint;
listNode *listEnd =  NULL;
uint16 nodeFinishRootDirector = 0;//finish cluster root director
uint16 nodeRootDirector;
structChange table[]={
	{"LS", LS}, {"CD", CD}, {"vi",VI}, {"ls", LS}, {"cd", CD}, {"VI",VI}, {"write", WRITE}, {"WRITE", WRITE}  
};

root_Entries* checkMemmory()
{
	root_Entries * m1;
	m1 = (root_Entries*)malloc(sizeof(root_Entries));
	return m1;
}
int main ()
{
  FILE * pFile ;
  fat32 *infoDisk =	(fat32 *)malloc(sizeof(fat32));
  fat12_16		*infoDisk12_16;
  root_Entries *rootEntry = (root_Entries*)malloc(sizeof(root_Entries));
  listNode *listnode = NULL;
  char bufTest[255];
  pFile=fopen ("floppy.img","a+");	//open file img
	memset(infoDisk,'\0', sizeof(fat32));
	if (pFile==NULL){ 
		perror ("Error opening file");
		return 0;
	}
	else{
			fread(infoDisk, sizeof(fat32), 1, pFile);  	
	}
	InputLinkList(0, 0,"\0",0);
	if(!strncmp((char*)infoDisk->BS_FilSysType,FAT32,strlen(FAT32))){ //check fype of fat is opened
		fseek(pFile, 0xC00, SEEK_SET);	//jump to 0xC00
		fread(infoDisk, sizeof(fat32), 1, pFile);	
		infoDisk->BS_FilSysType[5] = '\0';
		printf("OEM:%s\n",infoDisk->BS_OEMName);	 
		printf("file type:%s\n",infoDisk->BS_FilSysType);
		nodeRootDirector = infoDisk->BPB_NumFATs * infoDisk->BPB_FATSz32 + infoDisk->BPB_RsvdSecCnt;
		
	}
	else{
		infoDisk12_16 = (fat12_16*)infoDisk;
		infoDisk12_16->BS_FilSysType[5] = '\0';
		printf("OEM:%s\n",infoDisk12_16->BS_OEMName);	 
		printf("file type:%s\n",infoDisk12_16->BS_FilSysType);
		nodeRootDirector = infoDisk12_16->BPB_NumFATs * infoDisk12_16->BPB_FATSz16 + 1;
	}
	nodeFinishRootDirector = nodeRootDirector + (infoDisk->BPB_RootEntCnt *32)/512 - 2;
	comandLS(pFile);	//runcomamd
  fclose (pFile);	//close file
  getch();
  return 0;
}
