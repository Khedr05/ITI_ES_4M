
#include "stdio.h"


void calcSumAndSubtract(int *num1 , int *num2 , int *returnOfSum , int *returnOfSub);

void main(void)
{
	int userInputNum1 = 0;
	int userInputNum2 = 0;
	int resOfSum = 0;
	int resOfSub = 0;

	printf("\n\n");

	printf("Please Enter Value 1 : ");
	scanf("%d",&userInputNum1);

	printf("Please Enter Value 2 : ");
	scanf("%d",&userInputNum2);

	calcSumAndSubtract(&userInputNum1 , &userInputNum2 , &resOfSum , &resOfSub);

	printf("The Result Of Summation Is : %d \n",resOfSum);
	printf("The Result Of Subtraction Is : %d \n",resOfSub);
	printf("\n\n");
}

void calcSumAndSubtract(int *num1 , int *num2 , int *returnOfSum , int *returnOfSub)
{	
   int sum = 0;
   int sub = 0;
   sum = *num1 + *num2 ;
   sub = *num1 - *num2 ;

   *returnOfSum = sum;
   *returnOfSub = sub;
}