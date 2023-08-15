

#ifndef STACK_BASED_ON_LL_H_
#define STACK_BASED_ON_LL_H_

#include "01_Std_Types.h"
#include "04_Linked_List.h"

typedef struct {
  ST_linkedListNode_t stackNode;
} ST_stack_t;

typedef struct {
  ST_linkedList_t stackHead;
} ST_stackHead_t;

void vStackInit(ST_stackHead_t *ptrStackInstance, uint32_t u32CopyData);
void vStackPush(ST_stackHead_t *ptrStackInstance, uint32_t u32CopyData);
void vStackPop(ST_stackHead_t *ptrStackInstance);
uint8_t u8StackIsEmpty(ST_stackHead_t *ptrStackInstance);
uint8_t u8StackContainData(ST_stackHead_t *ptrStackInstance);
void vStackDisplay(ST_stackHead_t *ptrStackInstance);

#endif