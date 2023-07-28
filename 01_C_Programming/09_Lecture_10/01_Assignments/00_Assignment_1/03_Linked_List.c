
#include "02_Linked_List.h"

void LINKEDLIST_vCreateList(ST_linkedList_t *ptrLinkedListInstance , uint32_t u32CopyData)
{
    if(ptrLinkedListInstance != PTR_NULL)
    {
        ST_linkedListNode_t *node = (ST_linkedListNode_t *)malloc(sizeof(ST_linkedListNode_t));
        node->ptrOfNextNode = PTR_NULL;
        node->u32DataValue = u32CopyData;
        ptrLinkedListInstance->ptrHeadOfList = node;
        ptrLinkedListInstance->ptrTailOfList = PTR_NULL;
    }
    else
    {
        /* Do Nothing */
    }
}

void LINKEDLIST_vAddNodeInFirst(ST_linkedList_t *ptrLinkedListInstance , uint32_t u32CopyData)
{
    if( ptrLinkedListInstance != PTR_NULL )
    {
        if((ptrLinkedListInstance->ptrHeadOfList == PTR_NULL))
        {
            LINKEDLIST_vCreateList(ptrLinkedListInstance , u32CopyData);
        }
        else
        {
            ST_linkedListNode_t *node = (ST_linkedListNode_t *)malloc(sizeof(ST_linkedListNode_t));
            node->u32DataValue = u32CopyData;
            node->ptrOfNextNode = ptrLinkedListInstance->ptrHeadOfList;
            ptrLinkedListInstance->ptrHeadOfList = node;
        }
    }
    else
    {
        /* Do Nothing */
    }
}


void LINKEDLIST_vAddNodeInLast(ST_linkedList_t *ptrLinkedListInstance , uint32_t u32CopyData)
{
    if( ptrLinkedListInstance != PTR_NULL )
    {
        if((ptrLinkedListInstance->ptrHeadOfList == PTR_NULL))
        {
            LINKEDLIST_vCreateList(ptrLinkedListInstance , u32CopyData);
        }
        else
        {
            ST_linkedListNode_t *tailOfList = ptrLinkedListInstance->ptrHeadOfList; 
            ST_linkedListNode_t *node = (ST_linkedListNode_t *)malloc(sizeof(ST_linkedListNode_t));
            while(tailOfList->ptrOfNextNode != PTR_NULL)
            {
                tailOfList = tailOfList->ptrOfNextNode;
            }
            tailOfList->ptrOfNextNode = node;
            node->u32DataValue = u32CopyData;
            node->ptrOfNextNode = PTR_NULL;
        }
    }
    else
    {
        /* Do Nothing */
    }    
}


void LINKEDLIST_vDisplayList(ST_linkedList_t *ptrLinkedListInstance)
{
    uint8_t u8FoundedFlag = 0;
    printf("\n---------------------------------------------------\n");
    if(ptrLinkedListInstance != PTR_NULL)
    {
        uint8_t u8NodeIndex = 0;
        ST_linkedListNode_t *ptrOfPrint = ptrLinkedListInstance->ptrHeadOfList;
        while(ptrOfPrint != PTR_NULL)
        {
            printf("Data In Node Of Index %d Is : %d \n",u8NodeIndex,ptrOfPrint->u32DataValue);
            u8NodeIndex++;
            ptrOfPrint = (ptrOfPrint->ptrOfNextNode);
            u8FoundedFlag = 1;
        }
        if(u8FoundedFlag == 0)
        {
            printf("List Is Empty \n");
        }
    }
    else
    {
        /* Do Nothing */
    }
    printf("\n---------------------------------------------------\n");
}

void LINKEDLIST_vSearchByValue(ST_linkedList_t *ptrLinkedListInstance , uint32_t u32CopyData)
{
    if(ptrLinkedListInstance != PTR_NULL)
    {
        uint8_t u8NodeIndex = 0;
        uint8_t u8FoundedFlag = 0;
        ST_linkedListNode_t *ptrOfSearch = ptrLinkedListInstance->ptrHeadOfList;
        while(ptrOfSearch != PTR_NULL)
        {
            if(ptrOfSearch->u32DataValue == u32CopyData)
            {
                printf("Data %d Founded In Index : %d \n",ptrOfSearch->u32DataValue,u8NodeIndex);
                u8FoundedFlag = 1;
                break;
            }
            else
            {
                /* Do Nothing */
            }
            u8NodeIndex++;
            ptrOfSearch = (ptrOfSearch->ptrOfNextNode);
        }
        if(u8FoundedFlag == 0)
        {
            printf("Data %d Not Found \n",u32CopyData);
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }    
}

void LINKEDLIST_vSearchByIndex(ST_linkedList_t *ptrLinkedListInstance , uint8_t u8CopyIndex)
{
    if(ptrLinkedListInstance != PTR_NULL)
    {
        uint8_t u8NodeIndex = 0;
        uint8_t u8FoundedFlag = 0;
        ST_linkedListNode_t *ptrOfSearch = ptrLinkedListInstance->ptrHeadOfList;
        while(ptrOfSearch != PTR_NULL)
        {
            if( u8NodeIndex == u8CopyIndex)
            {
                printf("Data Founded In Index %d Is : %d \n",u8NodeIndex , ptrOfSearch->u32DataValue);
                u8FoundedFlag = 1;
                break;
            }
            else
            {
                /* Do Nothing */
            }
            u8NodeIndex++;
            ptrOfSearch = (ptrOfSearch->ptrOfNextNode);
        }
        if(u8FoundedFlag == 0)
        {
            printf("Index %d Not Found \n",u8CopyIndex);
        }
        else
        {
            /*Do Nothing*/
        }
    }
    else
    {
        /* Do Nothing */
    } 
}


void LINKEDLIST_vDeleteByValue(ST_linkedList_t *ptrLinkedListInstance , uint32_t u32CopyData)
{
    uint8_t totalDeleted = 0;
    ST_linkedListNode_t *prev, *cur;
    ST_linkedListNode_t *head = ptrLinkedListInstance->ptrHeadOfList;

    while (head != PTR_NULL && (head->u32DataValue) == u32CopyData)
    {
        prev = head;
        head = (head->ptrOfNextNode);
        free(prev);
        totalDeleted++;
    }

    prev = PTR_NULL;
    cur  = head;
    while (cur != PTR_NULL)
    {
        if (cur->u32DataValue == u32CopyData)
        {
            if (prev != PTR_NULL) 
            {
                prev->ptrOfNextNode = cur->ptrOfNextNode;
            }
            free(cur);
            cur = prev->ptrOfNextNode;
            totalDeleted++;
        } 
        else
        {
            prev = cur;
            cur = cur->ptrOfNextNode;
        }        
    } 
    printf("%d Nodes Deleted Contain Data %d \n",totalDeleted,u32CopyData);
}


