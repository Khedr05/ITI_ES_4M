
#include <stdio.h>

void main(void)
{
   int userInput = 0;
   int counter ;

   printf("\n\n");   
   
   printf("Enter The Number To Display Its Multiplication Table : ");
   scanf("%d",&userInput);

   for(counter = 1 ; counter <= 10 ; counter++)
   {
      printf("%d x %d = %d \n",userInput,counter,userInput * counter);
   }
   
   printf("\n\n");
}