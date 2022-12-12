//accept ll from user and reverse the ll inplace
#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

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
void Reverse(PPNODE head)
{
    PNODE previous = NULL;
    PNODE Current = *head;
    PNODE Next = NULL;

    while(Current != NULL)
    {
        Next = Current ->next;
        Current ->next = previous;
        previous = Current;
        Current = Next;
    }
    *head = previous;
}
int main()
{
    int iRet =0;
    PNODE first = NULL;

    InsertFirst(&first,50);
    InsertFirst(&first,40);
    InsertFirst(&first,30);
    InsertFirst(&first,20);
    InsertFirst(&first,10);

    Display(first);
    
    Reverse(&first);
    Display(first);

    return 0;
}