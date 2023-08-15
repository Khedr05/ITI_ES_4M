
#include "01_Stack_Interface.h"

ST_stack_t ST_stack ;

void main(void)
{
    printf("\n\n");
    vStackInit(&ST_stack);
    vStackPush(&ST_stack , 1);
    vStackPush(&ST_stack , 2);
    vStackPush(&ST_stack , 3);
    vStackPush(&ST_stack , 4);
    vStackPush(&ST_stack , 5);
    vStackDisplay(&ST_stack);
    printf("\n\n");
    vStackPop(&ST_stack);
    vStackPop(&ST_stack);
    vStackDisplay(&ST_stack);
    printf("\n\n");
    vStackPush(&ST_stack , 10);
    vStackPush(&ST_stack , 11);
    vStackPush(&ST_stack , 12);
    vStackDisplay(&ST_stack);
    printf("\n\n");
    vStackPop(&ST_stack);
    vStackDisplay(&ST_stack);
    vStackPush(&ST_stack , 15);
    vStackDisplay(&ST_stack);
    printf("\n\n");
}