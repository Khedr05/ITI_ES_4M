
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "01_Std_Types.h"

typedef struct ST_linkedListNode_t
{
    uint32_t                      u32DataValue    ;
    struct ST_linkedListNode_t   *ptrOfNextNode   ;
}ST_linkedListNode_t;

typedef struct 
{
    struct ST_linkedListNode_t *ptrHeadOfList   ;
    struct ST_linkedListNode_t *ptrTailOfList   ;
}ST_linkedList_t;





void LINKEDLIST_vCreateList(ST_linkedList_t *ptrLinkedListInstance , uint32_t u32CopyData);
void LINKEDLIST_vAddNodeInFirst(ST_linkedList_t *ptrLinkedListInstance , uint32_t u32CopyData);
void LINKEDLIST_vAddNodeInLast(ST_linkedList_t *ptrLinkedListInstance , uint32_t u32CopyData);
void LINKEDLIST_vDisplayList(ST_linkedList_t *ptrLinkedListInstance);
void LINKEDLIST_vSearchByValue(ST_linkedList_t *ptrLinkedListInstance , uint32_t u32CopyData);
void LINKEDLIST_vSearchByIndex(ST_linkedList_t *ptrLinkedListInstance , uint8_t u8CopyIndex);

#endif