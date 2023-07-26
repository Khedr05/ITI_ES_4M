
#include <stdio.h>

void main(void)
{
   int gradeInput = 0;

   printf("\n\n");   
   printf("Please Enter Number : ");
   scanf("%d",&gradeInput);

   if((gradeInput >= 0) && (gradeInput < 50))
   {
      printf("Your Rating Is Failed");  
   }
   else if((gradeInput >= 50) && (gradeInput < 65))
   {
     printf("Your Rating Is Normal");  
   }
   else if((gradeInput >= 65) && (gradeInput < 75))
   {
     printf("Your Rating Is Good");  
   }
   else if((gradeInput >= 75) && (gradeInput < 85))
   {
     printf("Your Rating Is Very Good");  
   }
   else if((gradeInput >= 85) && (gradeInput <= 100))
   {
     printf("Your Rating Is Excellent");  
   }
   else
   {
      /* Do Nothing */
   }
   printf("\n\n");
}