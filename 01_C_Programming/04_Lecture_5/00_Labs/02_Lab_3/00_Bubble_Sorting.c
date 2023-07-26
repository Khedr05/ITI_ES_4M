
#include <stdio.h>

void bubbleSorting(int arr[] , int size);
void scanArray(int arr[] , int size);
void printArray(int arr[] , int size);
void swap(int arr[] , int index1 , int index2);

void main(void)
{
   int arr[10] = {0};
   int arrSize = sizeof(arr) / sizeof(arr[0]);
   printf("\n\n");

   scanArray(arr , arrSize);
   printf("Array Values Before Sorting \n");
   printArray(arr , arrSize);

   bubbleSorting(arr , arrSize);
   printf("Array Values After Sorting \n");
   printArray(arr , arrSize);



   printf("\n\n");
}

void swap(int arr[] , int index1 , int index2)
{
   arr[index1] = arr[index1] ^ arr[index2];
   arr[index2] = arr[index1] ^ arr[index2];
   arr[index1] = arr[index1] ^ arr[index2];
}

void bubbleSorting(int arr[] , int size)
{
   int i;
   int j;
   for(i = 0 ; i < size - 1 ; i++)
   {
      for(j = 0 ; j < size - i - 1 ; j++)
      {
         if(arr[j] > arr[j + 1])
         {
            swap(arr ,j , j + 1);  
         }
         
      }
   }
}

void scanArray(int arr[] , int size)
{
   int counter;
   for(counter = 0 ; counter < size ; counter++)
   {
      printf("Please Enter Number %d : ",counter);
      scanf("%d",&arr[counter]);
   }
}

void printArray(int arr[] , int size)
{
   int counter;
   printf("\n");
   for(counter = 0 ; counter < size ; counter++)
   {
      printf("Value Of Index %d = %d \n",counter,arr[counter]);
   }
   printf("\n");
}