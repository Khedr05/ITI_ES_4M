
#include<stdio.h>

int main()
{
   int hieght;
   int space;
   printf("Please Enter The Hieght Of The Pyramid : \n");
   scanf("%d",&hieght);
   for(int i = 1; i<=hieght;i++)
   {
      for (space = hieght; space >= i;space--) 
      {
         printf("  ");
      }
      for(int j = 1;j <= (2*i-1);j++)
      {
         printf("* ");
      }
      printf("\n");
   }  
}