
#include <stdio.h>

void main(void)
{
   int idInput = 0;

   printf("\n\n");   
   
   printf("Please Enter Your Id : ");
   scanf("%d",&idInput);
   
   switch(idInput)
   {
      case 1234:
      {
         printf("Welcome Ahmed");
         break; 
      }
      case 5678:
      {
         printf("Welcome Youssef");
         break; 
      } 
      case 1145:
      {
         printf("Welcome Mina");
         break; 
      }
      default :
      {
         printf("Wrong Id");
         break;
      }     
   }

   printf("\n\n");
}