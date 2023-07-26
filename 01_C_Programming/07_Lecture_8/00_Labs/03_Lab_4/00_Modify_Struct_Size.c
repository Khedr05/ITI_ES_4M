
/*
uint16_t = 2byte  for padding wil take all 4 byte
uint32_t = 4 byte
uint16_t = 2byte for padding wil take all 4 byte
uint16_t = 4 byte
Total Will Be 16 Byte
*/

/* 
Modifying The Size I Will Put The Bigger Size At First Then The Smaller
It Will Be Like This :
uint32_t = 4 byte
uint32_t = 4 byte
uint16_t = 2byte  & uint16_t = 2byte Sum Of Them 4Byte
Then Total Will Be 12 Byte 
*/

#include "stdio.h"
typedef unsigned short int uint16_t;
typedef unsigned long int  uint32_t;
typedef struct
{
	uint16_t  x;
	uint32_t  y;
	uint16_t  z;
	uint32_t  k;
}myStruct;

typedef struct 
{
   	
	uint32_t  y;
	uint32_t  k; 
    uint16_t  x;
    uint16_t  z;
}myStructModifyed;

void main(void)
{

    printf("\n\n");
	printf("Size Of Sturct Before Modify Is : %d \n", sizeof(myStruct));
    printf("Size Of Sturct After Modify Is  : %d \n", sizeof(myStructModifyed));
    printf("\n\n");
}