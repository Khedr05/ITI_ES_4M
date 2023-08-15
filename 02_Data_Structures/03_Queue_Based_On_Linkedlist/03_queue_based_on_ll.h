

#ifndef QUEUE_BASED_ON_LL_H_
#define QUEUE_BASED_ON_LL_H_

#include "01_Std_Types.h"
#include "04_Linked_List.h"

typedef struct {
  ST_linkedListNode_t queueNode;
} ST_queue_t;

typedef struct {
  ST_linkedList_t queueHead;
} ST_queueHead_t;

void vQueueInit(ST_queueHead_t *ptrQueueInstance, uint32_t u32CopyData);
void vQueuePush(ST_queueHead_t *ptrQueueInstance, uint32_t u32CopyData);
void vQueuePop(ST_queueHead_t *ptrQueueInstance);
uint8_t u8QueueIsEmpty(ST_queueHead_t *ptrQueueInstance);
uint8_t u8QueueIsFull(ST_queueHead_t *ptrQueueInstance);
void vQueueDisplay(ST_queueHead_t *ptrQueueInstance);

#endif