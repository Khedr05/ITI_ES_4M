

#include "03_queue_based_on_ll.h"

void vQueueInit(ST_queueHead_t *ptrStackInstance, uint32_t u32CopyData) 
{
  LINKEDLIST_vCreateList(&ptrStackInstance->queueHead, u32CopyData);
}

void vQueuePush(ST_queueHead_t *ptrStackInstance, uint32_t u32CopyData) 
{
  LINKEDLIST_vAddNodeInFirst(&ptrStackInstance->queueHead, u32CopyData);
}

void vQueuePop(ST_queueHead_t *ptrStackInstance) 
{
  uint8_t stackSize = 0;
  uint8_t valueOfLastItem;
  LINKEDLIST_vGetSize(&ptrStackInstance->queueHead, &stackSize);
  LINKEDLIST_vSearchByIndex(&ptrStackInstance->queueHead, (stackSize - 1),&valueOfLastItem);
  LINKEDLIST_vDeleteByData(&ptrStackInstance->queueHead, valueOfLastItem);
}

uint8_t u8QueueIsEmpty(ST_queueHead_t *ptrStackInstance) {
  uint8_t stackSize;
  LINKEDLIST_vGetSize(&ptrStackInstance->queueHead, &stackSize);
  if (stackSize == 0) return TRUE; else return FALSE;
}

uint8_t u8QueueContainData(ST_queueHead_t *ptrStackInstance) {
  uint8_t stackSize;
  LINKEDLIST_vGetSize(&ptrStackInstance->queueHead, &stackSize);
  if (stackSize >= 1) return TRUE; else return FALSE;
}

void vQueueDisplay(ST_queueHead_t *ptrStackInstance) {
  LINKEDLIST_vDisplayList(&ptrStackInstance->queueHead);
}