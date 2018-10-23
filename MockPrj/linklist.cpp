#include "linklist.h"
extern listNode *listFirst ;
extern listNode *listPoint;
extern listNode *listEnd;
void DeleteLinklist(listNode *list)	//delete link list
{
	listNode * listDelete;
	if(list->next != NULL){
		listPoint = list->next;
		while(listPoint != NULL)
		{
			listDelete = listPoint;		
			listPoint = listPoint->next;
			free(listDelete);
			listDelete = NULL;
							
		}
		listEnd->next = NULL;
	}
}

void InputLinkList(uint16 nodeParent, uint16 nodePresent, char *fileName,int nFinishFileName)
{
	if(listFirst == NULL){
		listFirst = (listNode*)malloc(sizeof(listNode));	//get node first of root director
		listPoint = listFirst;
	}
	else{
		listEnd->next = (listNode*)malloc(sizeof(listNode));	//get node first of root director
		listPoint = listEnd->next;
	}
	listPoint->clusterParent = nodeParent;
	listPoint->clusterPresent = nodePresent;
	strcpy((char*)listPoint->fileName, fileName);
	listPoint->fileName[nFinishFileName] = '\0';
	listPoint->next = NULL;
	listEnd = listPoint;	
}