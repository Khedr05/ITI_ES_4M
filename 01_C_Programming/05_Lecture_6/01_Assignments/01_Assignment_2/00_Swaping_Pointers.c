
#include <stdio.h>



void main (void)
{
	int x = 1;
	int y = 2;
	int z = 3;

	int *p = &x;
	int *q = &y;
	int *r = &z;

	printf("\n\n");
	printf("Value Of x,y,z    : %d,%d,%d\n",x,y,z);
	printf("Value Of p,q,r    : %p,%p,%p\n",p,q,r);
	printf("Value Of *p,*q,*r : %d,%d,%d\n",*p,*q,*r);

	r = &x;  // r = p
	p = &y;  // p = q
	q = &z;  // q = r

	printf("Value Of x,y,z    : %d,%d,%d\n",x,y,z);
	printf("Value Of p,q,r    : %p,%p,%p\n",p,q,r);
	printf("Value Of *p,*q,*r : %d,%d,%d\n",*p,*q,*r);	
	printf("\n\n");
}


