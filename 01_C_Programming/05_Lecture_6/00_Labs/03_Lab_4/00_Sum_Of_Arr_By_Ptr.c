
#include <stdio.h>



void main(void)
{
	int arr[5] = {0};
	int sum = 0;
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	int i;

	printf("\n\n");
	printf("Please Enter Five Numbers To Get The Sum \n");

	for(i = 0 ; i < arrSize ; i++)
	{
		printf("Enter Number %d : ",i);
		scanf("%d",&arr[i]);
	}

	for(i = 0 ; i < arrSize ; i++)
	{
		sum += *arr+i;
	}

	printf("Sumation Of The Array Is : %d",sum);
	printf("\n\n");
}
