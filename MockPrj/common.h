#ifndef __COMMON_H__
#define __COMMON_H__

#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
typedef unsigned char		uint8;  /*  8 bits */
typedef unsigned short int	uint16; /* 16 bits */
typedef unsigned long int	uint32; /* 32 bits */

typedef char				int8;   /*  8 bits */
typedef short int	        int16;  /* 16 bits */
typedef int		        	int32;  /* 32 bits */
//#define ROOT_DIRECTOR_BLOCK(x,y) (x*y+1) 
//#define ROOT_DIRECTOR_BLOCK(x, y, z) (x*y + z)
#define HOUR(x)  ((x >> 11)& 0x1f)                   
#define MINUTE(x) ((x >> 5) & 0x3f)
#define SECOND(x) (x & 0x1f)
#define YEAR(x)   ((x >> 9) & 0x7f)
#define MONTH(x)   ((x >> 5) & 0xf)
#define DAY(x)     (x & 0x1f)
#define BADKEY	-1
#define CMD   	0
#define LS		1
#define CD		2
#define VI		3
#define WRITE	4
#define FOLDER	0X10
#define NOT_FIND_INDEX -1

#define BACK_FOLDER 1
#define BACK_ROOT 	2
#define SIZESECTOR	512
#define FAT32	"FAT32"
#define FAT12	"FAT12"
#define FAT16	"FAT16"

#pragma pack(1)
typedef struct {

	uint8		BS_jmpBoot[3];//0x00-3byte Part of the bootstrap program.
	uint8		BS_OEMName[8];//0x03-8byte Optional manufacturer description.
	uint16		BPB_BytsPerSec;//0x0b-2byte Number of bytes per block (almost always 512).
	uint8		BPB_SecPerClus;//0x0d-1byte Number of blocks per allocation unit.
	uint16		BPB_RsvdSecCnt;//0x0e-2byte Number of reserved blocks.
	uint8		BPB_NumFATs;//0x10-1byte Number of File Allocation Tables.
	uint16		BPB_RootEntCnt;//0x11-2byte Number of root directory entries 
	uint16		BPB_TotSec16;//0x13-2byte Total number of blocks in the entire disk.
	uint8		BPB_Media;//0x15-1byte Media Descriptor.
	uint16		BPB_FATSz16;//0x16-2byte The number of blocks occupied by one copy of the File Allocation Table.
	uint16		BPB_SecPerTrk;//0x18-2byte The number of blocks per track
	uint16		BPB_NumHeads;//0x1a-2byte The number of heads
	uint32		BPB_HiddSec;//0x1c-4byte The number of hidden blocks.
	uint32		BPB_TotSec32;//0x20-4byte Total number of blocks in the entire disk 
	uint8		BS_DrvNum;//0x24-2byte Physical drive number.
	uint8		BS_Reserved1;//0x25-1byte  Unused
	uint8		BS_BootSig;//0x26-1byte Extended Boot Record Signature 
	uint32		BS_VolID;//0x27-4byte Volume Serial Number.
	uint8		BS_VolLab[11];//0x2b-11byte Volume Label.
	uint8		BS_FilSysType[8];//0x36-8byte File system identifier
	
} fat12_16;//FatBootSector;


typedef struct {

	uint8		BS_jmpBoot[3];//0x00-3byte Part of the bootstrap program.
	uint8		BS_OEMName[8];//0x03-8byte Optional manufacturer description.
	uint16		BPB_BytsPerSec;//0x0b-2byte Number of bytes per block (almost always 512).
	uint8		BPB_SecPerClus;//0x0d-1byte Number of blocks per allocation unit.
	uint16		BPB_RsvdSecCnt;//0x0e-2byte Number of reserved blocks.
	uint8		BPB_NumFATs;//0x10-1byte Number of File Allocation Tables.
	uint16		BPB_RootEntCnt;//0x11-2byte Number of root directory entries 
	uint16		BPB_TotSec16;//0x13-2byte Total number of blocks in the entire disk.
	uint8		BPB_Media;//0x15-1byte Media Descriptor.
	uint16		BPB_FATSz16;//0x16-2byte The number of blocks occupied by one copy of the File Allocation Table.
	uint16		BPB_SecPerTrk;//0x18-2byte The number of blocks per track
	uint16		BPB_NumHeads;//0x1a-2byte The number of heads
	uint32		BPB_HiddSec;//0x1c-4byte The number of hidden blocks.
	uint32		BPB_TotSec32;//0x20-4byte Total number of blocks in the entire disk 
	uint32		BPB_FATSz32;//0x24 Number of sectors per FAT
	uint16		flag		;//0x28	flags
	uint16		verOfFat32	;//0x2a Version of FAT32 drive, high/low byte = major/minor
	uint32		numclusStartRootDir;//0x2c -Cluster number of the start of the root directory
	uint16		numSectorOfFileSys;//0x30 Sector number of the filesystem information sector, offset from the start of the partition
	uint16		numSectorBootBacup;//0x32 Sector number of the backup boot sector, offset from the start of the partition
	uint8		BS_Reserved1[12];//0x34
	uint8		numPartition;//0x40 Logical drive number of partition
	uint8		unuse	;//0x41 unused
	uint8		signature;//0x42 Signature
	uint32		BS_VolID;//0x43 Serial number of partition
	uint8		BS_VolLab[11];//0x47-11byte Volume Label.
	uint8		BS_FilSysType[8];//0x36-8byte File system identifier

} fat32;


typedef struct{
   uint8 short_FileName[8];//11BYTE
   uint8 extensionFileName[3];
   uint8 fileAttributes;//1BYTE
   uint8 reserved[10];//10BYTE
   uint16 Time;//2BYTE
   uint16 Date;//2BYTE
   uint16 firstCluster;//2BYTE
   uint32 sizeofFile;//4BYTE
} root_Entries;

typedef struct{
	uint8	OrdinalField;
	uint16	unicodePart1[5];
	uint8	Attribute;
	uint8	type;
	uint8	checksum;
	uint16	unicodePart2[6];
	uint16	cluster;
	uint16	unicodePart3[2];
}longName;

typedef struct structChange{
	char* 	key;
	int 	val;
} ;
typedef struct listNode{
	uint16 	clusterPresent;
	uint16	clusterParent;
	uint8	fileName[255];
	listNode *next;
};
#endif