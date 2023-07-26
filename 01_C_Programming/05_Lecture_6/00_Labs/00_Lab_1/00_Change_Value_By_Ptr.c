
#include "stdio.h"


void main(void)
{
	int x = 10;
	int *ptrOfX = &x;

	printf("\n\n");
	printf("X Before Change Is : %d \n",x);

	*ptrOfX = 20;

	printf("X After Change Is : %d \n",x);
	printf("\n\n");
}