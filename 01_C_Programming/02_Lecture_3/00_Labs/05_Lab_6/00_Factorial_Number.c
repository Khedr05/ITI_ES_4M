
#include <stdio.h>

void main(void)
{
   int userInput = 0;
   int factorial = 1;
   printf("\n\n");   
   
   printf("Enter An Integer : ");
   scanf("%d",&userInput);
   
   if(userInput < 0)
   {
      printf("No Factorial For Negative Number");
   }
   else
   {
      while(userInput != 0)
      {
         factorial *=userInput;
         userInput--;
      }
      printf("Factorial = %d",factorial);
   }


   printf("\n\n");
}