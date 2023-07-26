

#include <stdio.h>

int scalerMultiplcation(int *ptrArr1, int *ptrArr2);

void main (void)
{
	int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
	int arr2[10] = {1,2,3,4,5,6,7,8,9,10};
	int res = 0; 

	res = scalerMultiplcation(arr1, arr2);

	printf("\n\n");
	printf("Scaler Multiplcation : %d",res);
	printf("\n\n");
}

int scalerMultiplcation(int *ptrArr1, int *ptrArr2)
{
	int sum = 0;
	int i;
	
	for(i=0;i<10;i++)
	{
		sum += ptrArr1[i] * ptrArr2[i];
	}
	
	return sum;
}