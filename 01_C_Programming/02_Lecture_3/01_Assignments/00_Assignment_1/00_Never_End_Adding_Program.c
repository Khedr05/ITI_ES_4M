#include<stdio.h>

int main()
{
	int UserInputNum1 = 0 ; 
	int UserInputNum2 = 0 ;
	int sum = 0 ;
	while(1)
	{
		printf("Please Enter First Number\n");
		scanf("%d",&UserInputNum1);
		printf("Please Enter Second Number\n");
		scanf("%d",&UserInputNum2);

		sum = UserInputNum1 + UserInputNum2;

		printf("The Result Is %d \n",sum);
	}
		
}