
#ifndef STACK_INTERFACE_H_
#define STACK_INTERFACE_H_ 

#include <stdio.h>
#include "00_Std_Types.h"

#define STACK_MAX_SIZE      100

typedef struct 
{
    uint8_t ArrStack[STACK_MAX_SIZE];
    uint8_t StackTop;
    uint8_t elementsSize; 
}ST_stack_t;


void vStackInit(ST_stack_t *ptrStackInstance);
void vStackPush(ST_stack_t *ptrStackInstance , uint8_t u8CopyData);
void vStackPop(ST_stack_t *ptrStackInstance);
uint8_t u8StackIsEmpty(ST_stack_t *ptrStackInstance);
uint8_t u8StackIsFull(ST_stack_t *ptrStackInstance);
void vStackDisplay(ST_stack_t *ptrStackInstance);


#endif /*STACK_INTERFACE_H_*/
