
#include "03_Bubble_Sort.h"


void swap(uint8_t *ptrOfArr , uint8_t index1 , uint8_t index2)
{
   *(ptrOfArr + index1) = *(ptrOfArr + index1)  ^ *(ptrOfArr + index2) ;
   *(ptrOfArr + index2) = *(ptrOfArr + index1)  ^ *(ptrOfArr + index2) ;
   *(ptrOfArr + index1) = *(ptrOfArr + index1)  ^ *(ptrOfArr + index2) ;
}

void bubbleSorting(uint8_t *ptrOfArr , uint8_t size)
{
   int i;
   int j;
   for(i = 0 ; i < size - 1 ; i++)
   {
      for(j = 0 ; j < size - i - 1 ; j++)
      {
         if(*(ptrOfArr + j ) > *(ptrOfArr + (j + 1)))
         {
            swap(ptrOfArr ,j , j + 1);  
         }
         
      }
   }
}

void scanArray(uint8_t *ptrOfArr , uint8_t size)
{
   int counter;
   for(counter = 0 ; counter < size ; counter++)
   {
      printf("Please Enter Number %d : ",counter);
      scanf("%d",(ptrOfArr + counter));
   }
}

void printArray(uint8_t *ptrOfArr , uint8_t size)
{
   int counter;
   printf("\n");
   for(counter = 0 ; counter < size ; counter++)
   {
      printf("Value Of Index %d = %d \n",counter,*(ptrOfArr + counter));
   }
   printf("\n");
}