
#include <stdio.h>

void main(void)
{
   int hoursInput = 0;

   printf("\n\n");	
   printf("Please Enter Your Working Hours : ");
   scanf("%d",&hoursInput);

   if(hoursInput >= 40)
   {
      printf("Your Salary Is %d",hoursInput * 50);  
   }
   else
   {
     printf("Your Salary Is %d",(((hoursInput * 50) *90) / 100));  
   }
   printf("\n\n");
}