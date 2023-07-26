#include <stdio.h>

int main()
{
   int num1 = 0 ;
   int num2 = 0 ;
   int num3 = 0 ;
   
   printf("Enter Number 1:");
   scanf("%d",&num1);
   printf("Enter Number 2:");
   scanf("%d",&num2);
   printf("Enter Number 3:");
   scanf("%d",&num3);

   (num1 > num2 && num1 > num3)? 
   printf("Max Number Is %d",num1):
   (num2 > num1 && num2 > num3)? 
   printf("Max Number Is %d",num2):
   printf("Max Number Is %d",num3);

   
}