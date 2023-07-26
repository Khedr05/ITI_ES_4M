
#include <stdio.h>

void main(void)
{
   int userInput = 0;

   printf("\n\n");   
   printf("Enter The Answer 3 * 4 = : ");
   scanf("%d",&userInput);

   while(userInput != 12)
   {
      printf("Not Correct Please Try Again : ");
      scanf("%d",&userInput);
   }
      printf("Thank You");
   printf("\n\n");
}