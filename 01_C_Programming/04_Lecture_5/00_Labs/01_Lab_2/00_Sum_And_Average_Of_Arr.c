
#include<stdio.h>

void main(void)
{

   int userInputArr[10] = {0};
   int counter;
   int sum = 0;
   float average;

   printf("\n\n");
   for(counter = 0 ; counter < 10 ; counter++)
   {
      printf("Please Enter Number %d : ",counter);
      scanf("%d",&userInputArr[counter]);
   }

   for(counter = 0 ; counter < 10 ; counter++)
   {
       sum += userInputArr[counter];
   }
   average = sum / (float)(sizeof(userInputArr) / sizeof(userInputArr[0]));
   
   printf("\n");
   printf("Sum Of Array Elements = %d \n",sum);
   printf("Average Of Array Elements = %0.2f \n",average);
   printf("\n\n");
}
