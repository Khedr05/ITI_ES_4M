
#include <stdio.h>

int linearSearching(int arr[] , int size , int value);
void scanArray(int arr[] , int size);

void main(void)
{
   int arr[10] = {0};
   int arrSize = sizeof(arr) / sizeof(arr[0]);
   int numberToSearch = 0;
   int isExistCounter = 0;
   printf("\n\n");

   scanArray(arr , arrSize);
   printf("Enter The Value To Search : ");
   scanf("%d",&numberToSearch);
   printf("\n");
   isExistCounter = linearSearching(arr , arrSize , numberToSearch);

   if(isExistCounter == 0)
   {
      printf("Value Not Exist");
   }
   else if(isExistCounter > 0)
   {
      printf("Value Exists %d Times",isExistCounter);
   }


   printf("\n\n");
}


int linearSearching(int arr[] , int size , int value)
{
   int i;
   int NumberOfExist = 0;
   for(i = 0;i < size ; i++)
   {
      if(arr[i] == value)
      {
         NumberOfExist++;
      }
   }
   return NumberOfExist;
}

void scanArray(int arr[] , int size)
{
   int counter;
   for(counter = 0 ; counter < size ; counter++)
   {
      printf("Please Enter Number %d : ",counter);
      scanf("%d",&arr[counter]);
   }
   printf("\n");
}

