
#include <stdio.h>

void main(void)
{
   int userInput = 0;

   printf("\n\n");   
   printf("Please Enter Number : ");
   scanf("%d",&userInput);

   if(userInput % 2 == 0)
   {
      printf("Number Is Even");  
   }
   else
   {
     printf("Number Is Odd");  
   }
   printf("\n\n");
}