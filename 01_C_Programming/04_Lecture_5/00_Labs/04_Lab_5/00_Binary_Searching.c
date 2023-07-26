
#include "stdio.h"

void bubbleSorting(int arr[] , int size);
void scanArray(int arr[] , int size);
void swap(int arr[] , int index1 , int index2);
int binarySearching(int arr[] , int size , int value);

void main(void)
{
   int arr[10] = {0};
   int arrSize = sizeof(arr) / sizeof(arr[0]);
   int numberIsExist = 0;
   int numberToSearch = 0;
   printf("\n\n");

   scanArray(arr,arrSize);
   printf("Enter Number To Search : ");
   scanf("%d",&numberToSearch);
   numberIsExist = binarySearching(arr,arrSize,numberToSearch);

   if(numberIsExist == 1)
   {
      printf("Value Found \n");
   }
   else
   {
      printf("Value Not Exist \n");
   }

   printf("\n\n");

}







int binarySearching(int arr[] , int size , int value)
{
   int low = 0;
   int high = size-1;
   int mid = 0;
   int isExistFlag = 0;
   bubbleSorting(arr , size);
   while(low <= high)
   {
      mid = low + (high - low) / 2; 

      if(arr[mid] == value)
      {
         isExistFlag = 1;
         break;
      }
      else if(arr[mid] < value)
      {
         low = mid + 1;
      }
      else if(arr[mid] > value)
      {
         high = mid - 1;
      }
      else
      {
         /* Do Nothing */
      }
   }
   return isExistFlag;
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
