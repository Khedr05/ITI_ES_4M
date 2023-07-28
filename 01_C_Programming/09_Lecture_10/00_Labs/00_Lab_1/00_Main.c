
#include <stdio.h>
#include <stdlib.h>
#include "01_Std_Types.h"
#include "03_Bubble_Sort.h"

void main(void)
{
   uint8_t *ptrOfBlock;
   uint8_t sizeOfBlock;
   
   printf("\n\n");

   printf("Enter How Many Numbers You Will Enter : ");
   scanf("%d",&sizeOfBlock);

    ptrOfBlock = (uint8_t*) malloc(sizeOfBlock);

   scanArray(ptrOfBlock , sizeOfBlock);
   printf("Array Values Before Sorting \n");
   printArray(ptrOfBlock , sizeOfBlock);

   bubbleSorting(ptrOfBlock , sizeOfBlock);
   printf("Array Values After Sorting \n");
   printArray(ptrOfBlock , sizeOfBlock);

   printf("\n\n");
}