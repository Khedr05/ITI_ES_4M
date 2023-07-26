
#include<stdio.h>

void main(void)
{

   int userInputArr[10] = {0};
   int counter;

   printf("\n\n");
   for(counter = 0 ; counter < 10 ; counter++)
   {
      printf("Please Enter Number %d : ",counter);
      scanf("%d",&userInputArr[counter]);
   }
   printf("\n");
   printf("The Values In Reversed Order \n");
   printf("\n");
   for(counter = 9 ; counter >= 0 ; counter --)
   {
      printf("Value In Index %d = %d \n",counter,userInputArr[counter]);
   }
   
   printf("\n\n");
}
