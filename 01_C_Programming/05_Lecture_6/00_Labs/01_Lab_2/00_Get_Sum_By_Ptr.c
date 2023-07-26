
#include "stdio.h"


int sum(int *num1 , int *num2);

void main(void)
{
	int userInputNum1 = 0;
	int userInputNum2 = 0;
	int resOfSum = 0;

	printf("\n\n");

	printf("Please Enter Value 1 : ");
	scanf("%d",&userInputNum1);

	printf("Please Enter Value 2 : ");
	scanf("%d",&userInputNum2);

	resOfSum = sum(&userInputNum1 , &userInputNum2);

	printf("The Result Is : %d \n",resOfSum);
	printf("\n\n");
}


int sum(int *num1 , int *num2)
{
	return *num1 + *num2;
}