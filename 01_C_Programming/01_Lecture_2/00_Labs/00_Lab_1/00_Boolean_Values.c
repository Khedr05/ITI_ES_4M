
#include <stdio.h>

void main(void)
{
   int x = 5;
   int y = 5;
   int z;
   z = (x == y);

   printf("\n\n");
   printf("True Value In Gcc = %d\n",z);
   z = (x != y);
   printf("False Value In Gcc = %d\n",z);
   printf("\n\n");
}


