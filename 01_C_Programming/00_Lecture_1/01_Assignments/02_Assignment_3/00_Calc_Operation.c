

#include <stdio.h>

void main(void)
{
   int userInputNum1 = 0 ;
   int userInputNum2 = 0 ;

   printf("\n\n");

   printf("Please Enter Number a : ");
   scanf("%d",&userInputNum1);
   printf("Please Enter Number b : ");
   scanf("%d",&userInputNum2);

   printf("a +  b = %d \n",userInputNum1 + userInputNum2);
   printf("a -  b = %d \n",userInputNum1 - userInputNum2);
   printf("a &  b = %d \n",userInputNum1 & userInputNum2);
   printf("a |  b = %d \n",userInputNum1 | userInputNum2);
   printf("a ^  b = %d \n",userInputNum1 ^ userInputNum2);

   printf("\n\n");
}