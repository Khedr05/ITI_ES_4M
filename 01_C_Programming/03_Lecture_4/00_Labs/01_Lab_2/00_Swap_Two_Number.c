
#include<stdio.h>


void swap(int Num1,int Num2);

void main(void)
{

   int userInputNum1 = 0;
   int userInputNum2 = 0;

   printf("\n\n");
   printf("Please Enter Value Of x : ");
   scanf("%d",&userInputNum1);
   printf("Please Enter Value Of y : ");
   scanf("%d",&userInputNum2);

   printf("Please Enter Value Of x Before Swaping : %d \n",userInputNum1);
   printf("Please Enter Value Of y Before Swaping : %d \n",userInputNum2);

   swap(userInputNum1 , userInputNum2);
   printf("\n\n");
}

void swap(int Num1,int Num2)
{
   Num1 = Num1 + Num2;
   Num2 = Num1 - Num2;
   Num1 = Num1 - Num2;

   printf("Please Enter Value Of x After Swaping : %d \n",Num1);
   printf("Please Enter Value Of y After Swaping : %d \n",Num2);
}