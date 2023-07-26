#include<stdio.h>

int main()
{
	int num1,num2,num3,num4,num5,num6,num7,num8,num9,num10,val;

	printf("\n\n");
	printf("Enter Number 1 : ");
	scanf("%d",&num1);
	printf("Enter Number 2 : ");
	scanf("%d",&num2);
    printf("Enter Number 3 : ");
	scanf("%d",&num3);
	printf("Enter Number 4: ");
	scanf("%d",&num4);
	printf("Enter Number 5 : ");
	scanf("%d",&num5);
	printf("Enter Number 6 : ");
	scanf("%d",&num6);	
	printf("Enter Number 7 : ");
	scanf("%d",&num7);
	printf("Enter Number 8 : ");
	scanf("%d",&num8);
	printf("Enter Number 9 : ");
	scanf("%d",&num9);
	printf("Enter Number 10 : ");
	scanf("%d",&num10);						

	printf("Enter Number To Search\n");
	scanf("%d",&val);

	(val == num1)? printf("Value Is Exist At Element Number 1"):(val == num2)? printf("Value Is Exist At Element Number 2"):
	(val == num3)? printf("Value Is Exist At Element Number 3"):(val == num4)? printf("Value Is Exist At Element Number 4"):
	(val == num5)? printf("Value Is Exist At Element Number 5"):(val == num6)? printf("Value Is Exist At Element Number 6"):
	(val == num7)? printf("Value Is Exist At Element Number 7"):(val == num8)? printf("Value Is Exist At Element Number 8"):
	(val == num9)? printf("Value Is Exist At Element Number 9"):(val == num10)? printf("Value Is Exist At Element Number 10"):
	printf("Value Is Not Exist At Any Element");
	printf("\n\n");

}