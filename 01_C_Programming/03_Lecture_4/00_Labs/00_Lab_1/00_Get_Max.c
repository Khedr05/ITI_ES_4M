
#include<stdio.h>


int max(int Num1,int Num2);

void main(void)
{

   int userInputNum1 = 0;
   int userInputNum2 = 0;
   int maxNumber = 0;

   printf("\n\n");
   printf("Please Enter Value 1 : ");
   scanf("%d",&userInputNum1);
   printf("Please Enter Value 2 : ");
   scanf("%d",&userInputNum2);
   maxNumber = max(userInputNum1 , userInputNum2);
   printf("The Maximum Value Is %d \n",maxNumber);
   printf("\n\n");
}

int max(int Num1,int Num2)
{
   int maxNumber = 0;
   if((Num1>Num2))
   {
      maxNumber = Num1;
   }
   else
   {
      maxNumber = Num2;  
   }
   return maxNumber;
}