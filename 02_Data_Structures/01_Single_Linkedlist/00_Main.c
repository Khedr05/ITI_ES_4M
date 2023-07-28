
#include <stdio.h>
#include "02_Linked_List.h"

#define START_CASE      50

ST_linkedList_t list;
void main(void)
{
    uint8_t lU8ExitFlag = 0;
    uint8_t lU8UserChoice = START_CASE;
    printf("Hello To Your Database System \n");
    while(1)
    {
      
        if(lU8ExitFlag == 1) break;
        switch (lU8UserChoice)
        {
            case START_CASE :
            {
                printf("\n---------------------------------------------------\n");
                printf("0 - Add New Node In First Of The List \n");
                printf("1 - Add New Node In Last Of The List \n");
                printf("2 - Display The List \n");
                printf("3 - Search By Value In The List \n");
                printf("4 - Search By Index In The List \n");
                printf("5 - Delete By Value In The List \n");
                printf("6 - Add Node By Index In The List \n");
                printf("7 - Exit \n");
                printf("Enter Your Choice : ");
                scanf("%d",&lU8UserChoice);
                printf("\n---------------------------------------------------\n");
                break;
            }
            case 0 :
            {
                uint8_t lU8DataInput;
                printf("Enter The Value Of Data : ");
                scanf("%d",&lU8DataInput);
                LINKEDLIST_vAddNodeInFirst(&list,lU8DataInput);
                lU8UserChoice = START_CASE;
                break;
            }
            case 1 :
            {
                uint8_t lU8DataInput;
                printf("Enter The Value Of Data : ");
                scanf("%d",&lU8DataInput);
                LINKEDLIST_vAddNodeInLast(&list,lU8DataInput);
                lU8UserChoice = START_CASE;
                break;
            }
            case 2 :
            {
                LINKEDLIST_vDisplayList(&list);
                lU8UserChoice = START_CASE;
                break;
            }
            case 3 :
            {
                uint8_t lU8DataInput;
                printf("Enter The Value Of Data To Search : ");
                scanf("%d",&lU8DataInput);
                LINKEDLIST_vSearchByValue(&list,lU8DataInput);
                lU8UserChoice = START_CASE;
                break;
            }
            case 4 :
            {
                uint8_t lU8DataInput;
                printf("Enter The Index To Search : ");
                scanf("%d",&lU8DataInput);
                LINKEDLIST_vSearchByIndex(&list,lU8DataInput);
                lU8UserChoice = START_CASE;
                break;
            }
            case 5 :
            {
                uint8_t lU8DataInput;
                printf("Enter The Value Of Data To Delete : ");
                scanf("%d",&lU8DataInput);
                LINKEDLIST_vDeleteByValue(&list,lU8DataInput);
                lU8UserChoice = START_CASE;
                break;
            }   
            case 6 :
            {
                uint32_t lU32DataInput;
                uint8_t lu8IndexInput;
                printf("Enter The Value Of Index : ");
                scanf("%d",&lu8IndexInput);
                printf("Enter The Value Of Data : ");
                scanf("%d",&lU32DataInput);
                LINKEDLIST_vAddNodeInIndex(&list,lU32DataInput,lu8IndexInput);
                lU8UserChoice = START_CASE;
                break;
            }                   
            case 7 :
            {
                printf("Thanks Goodbye \n");
                lU8ExitFlag = 1;
                lU8UserChoice = START_CASE;
                break;
            }                                    
            default :
            {
                printf("Invalid Choice Please Try Agian \n");
                lU8UserChoice = START_CASE;                
                break;
            }
        }
    }
}