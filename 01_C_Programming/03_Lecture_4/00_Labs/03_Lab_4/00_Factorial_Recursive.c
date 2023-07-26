
#include <stdio.h>


int factorialRecursive(int number);
void main(void)
{
   int userInput = 0;
   int factorial = 1;
   
   printf("\n\n");   
   printf("Enter Number : ");
   scanf("%d",&userInput);

   factorial = factorialRecursive(userInput);
   printf("Factorial Of %d = %d",userInput,factorial);
   printf("\n\n");
}


int factorialRecursive(int number)
{

   if(number >= 1)
   {
      return number * factorialRecursive(number - 1);
   }
   else
   {
      return 1;
   }

}