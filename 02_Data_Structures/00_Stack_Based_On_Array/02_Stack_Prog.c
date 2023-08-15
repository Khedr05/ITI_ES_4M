
#include "01_Stack_Interface.h"


void vStackInit(ST_stack_t *ptrStackInstance)
{
    if(ptrStackInstance != PTR_NULL)
    {
        ptrStackInstance->ArrStack[STACK_MAX_SIZE] = 0;
        ptrStackInstance->elementsSize = 0;
        ptrStackInstance->StackTop = 0;
    }
    else
    {
        /* Do Nothing */
    }
}
void vStackPush(ST_stack_t *ptrStackInstance , uint8_t u8CopyData)
{
    if(ptrStackInstance != PTR_NULL)
    {
        if(u8StackIsFull(ptrStackInstance))
        {
            printf("Stack Is Full \n");
        }
        else
        {
            ptrStackInstance->ArrStack[ptrStackInstance->StackTop] = u8CopyData;
            ptrStackInstance->StackTop++;
            ptrStackInstance->elementsSize++;
        }
    }
    else
    {
        /* Do Nothing */
    }

}
void vStackPop(ST_stack_t *ptrStackInstance)
{
    if(ptrStackInstance != PTR_NULL)
    {
        if(u8StackIsEmpty(ptrStackInstance))
        {
            printf("Stack Is Empty \n");
        }
        else
        {
            ptrStackInstance->StackTop--;
            ptrStackInstance->elementsSize--;
        }
    }
    else
    {
        /* Do Nothing */
    }
}
uint8_t u8StackIsEmpty(ST_stack_t *ptrStackInstance)
{
    uint8_t ret = FALSE;
    if(ptrStackInstance != PTR_NULL)
    {
       if(ptrStackInstance->elementsSize == 0 )
       {
         ret = TRUE;
       }
       else
       {
         ret = FALSE;
       }
    }
    else
    {
        /* Do Nothing */
    }
    return ret;
}
uint8_t u8StackIsFull(ST_stack_t *ptrStackInstance)
{
    uint8_t ret = FALSE;
    if(ptrStackInstance != PTR_NULL)
    {
       if(ptrStackInstance->elementsSize == (STACK_MAX_SIZE - 1))
       {
         ret = TRUE;
       }
       else
       {
         ret = FALSE;
       }
    }
    else
    {
        /* Do Nothing */
    }
    return ret;
}
void vStackDisplay(ST_stack_t *ptrStackInstance)
{
    if(ptrStackInstance != PTR_NULL)
    {
        if(u8StackIsEmpty(ptrStackInstance))
        {
            printf("Stack Is Empty \n");
        }
        else
        {
            for(uint8_t i = 0 ; i <= (ptrStackInstance->elementsSize - 1) ; i++)
            {
                 printf("Data In Index %d Of The Stack Is : %d \n",i,ptrStackInstance->ArrStack[i]);
            }
            printf("\n");
        }

    }
    else
    {
        /* Do Nothing */
    }
}