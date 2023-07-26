
#include <stdio.h>

void main(void)
{
   int userInput = 0;
   int sum = 0;
   int counter = 0;
   float average = 0.0;


   printf("\n\n"); 

   printf("Enter The 10 Numbers \n");
   for(counter = 1; counter <= 10 ; counter++)
   {
      printf("Enter Number %d : ",counter);
      scanf("%d",&userInput);

      sum += userInput;
      average = sum / (float)counter;
   }
   printf("The Sum Of 10 No Is : %d \n",sum);
   printf("The Avg Of 10 No Is : %0.2f \n",average);

   printf("\n\n");
}