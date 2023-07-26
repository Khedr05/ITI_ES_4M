
#include<stdio.h>


/************************  Function Prototype ********************/

void max(int num1,int num2,int num3,int num4);
void min(int num1,int num2,int num3,int num4);


/************************  Main Program ********************/

void main(void)
{
	int userInputNum1 = 0 ;
	int userInputNum2 = 0 ; 
	int userInputNum3 = 0 ;
	int userInputNum4 = 0 ;

	printf("\n\n");
	printf("Enter Number 1 : ");
	scanf("%d",&userInputNum1);
	printf("Enter Number 2 : ");
	scanf("%d",&userInputNum2);
	printf("Enter Number 3 : ");
	scanf("%d",&userInputNum3);
	printf("Enter Number 4 : ");
	scanf("%d",&userInputNum4);

	max(userInputNum1,userInputNum2,userInputNum3,userInputNum4);
	min(userInputNum1,userInputNum2,userInputNum3,userInputNum4);

	printf("\n\n");
}


/************************  Function Implmantation ********************/

void max(int num1,int num2,int num3,int num4)
{
	if((num1>num2) && (num1>num3) && (num1>num4))
	{
		printf("Max Number = %d \n",num1);
	}
	else if((num2>num1) && (num2>num3) && (num2>num3))
	{
		printf("Max Number = %d \n",num2);
	}
	else if((num3>num1) && (num3>num2) && (num3>num3))
	{
		printf("Max Number = %d \n",num3);
	}
	else
	{
		printf("Max Number = %d \n",num3);	
	}
}


void min(int num1,int num2,int num3,int num4)
{
	if((num1<num2) && (num1<num3) && (num1<num4))
	{
		printf("Min Number = %d \n",num1);
	}
	else if((num2<num1) && (num2<num3) && (num2<num4))
	{
		printf("Min Number = %d \n",num2);
	}
	else if((num3<num1) && (num3<num2) && (num3<num4))
	{
		printf("Min Number = %d \n",num3);
	}
	else
	{
		printf("Min Number = %d \n",num4);	
	}
}