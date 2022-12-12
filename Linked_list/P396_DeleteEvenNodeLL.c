//accept ll from chk and delete the even nodes from it 
#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}NODE,*PNODE,**PPNODE;
/*
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;*/

void InsertFirst(PPNODE head,int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next = NULL;

    if(*head != NULL)
    {
        newn->next= *head;
    }
    *head =newn;
}
void Display(PNODE head)
{
    printf("Linked is as follow:\n");
    while(head != NULL)
    {
        printf("| %d |->",head->data);
        head = head->next;
    }
    printf("|NULL| \n");
}

void DeleteEven(PPNODE Head)
{
    PNODE tempHead = *Head;
    PNODE Previous = NULL;
    PNODE temp = NULL;

    if(*Head == NULL)   // LL is empty
    {
        return;
    }
    // 10       20      31      41      50

    while(tempHead != NULL)            
    {
        if(tempHead->data % 2 == 0)
        {
            if(tempHead->next != NULL)
            {
                tempHead->data = tempHead->next->data;
                temp = tempHead->next;
                tempHead ->next = temp->next;
                free(temp);
            }
            else
            {
                if(tempHead->next == NULL)
                {
                    free(tempHead);
                    Previous->next = NULL;
                }
            }
        }
        else
        {
            Previous = tempHead;
            tempHead = tempHead->next;
        }
    }
}

int main()
{
    PNODE first = NULL;
    int iRet =0;

    InsertFirst(&first,50);
    InsertFirst(&first,40);
    InsertFirst(&first,30);
    InsertFirst(&first,20);
    InsertFirst(&first,10);


    return 0;
}