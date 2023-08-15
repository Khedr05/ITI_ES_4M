

#include "03_stack_based_on_ll.h"

void vStackInit(ST_stackHead_t *ptrStackInstance, uint32_t u32CopyData) 
{
  LINKEDLIST_vCreateList(&ptrStackInstance->stackHead, u32CopyData);
}

void vStackPush(ST_stackHead_t *ptrStackInstance, uint32_t u32CopyData) 
{
  LINKEDLIST_vAddNodeInLast(&ptrStackInstance->stackHead, u32CopyData);
}

void vStackPop(ST_stackHead_t *ptrStackInstance) 
{
  uint8_t stackSize = 0;
  uint8_t valueOfLastItem;
  LINKEDLIST_vGetSize(&ptrStackInstance->stackHead, &stackSize);
  LINKEDLIST_vSearchByIndex(&ptrStackInstance->stackHead, (stackSize - 1),&valueOfLastItem);
  LINKEDLIST_vDeleteBydata(&ptrStackInstance->stackHead, valueOfLastItem);
}

uint8_t u8StackIsEmpty(ST_stackHead_t *ptrStackInstance) {
  uint8_t stackSize;
  LINKEDLIST_vGetSize(&ptrStackInstance->stackHead, &stackSize);
  if (stackSize == 0) return TRUE; else return FALSE;
}

uint8_t u8StackContainData(ST_stackHead_t *ptrStackInstance) {
  uint8_t stackSize;
  LINKEDLIST_vGetSize(&ptrStackInstance->stackHead, &stackSize);
  if (stackSize >= 1) return TRUE; else return FALSE;
}

void vStackDisplay(ST_stackHead_t *ptrStackInstance) {
  LINKEDLIST_vDisplayList(&ptrStackInstance->stackHead);
}


