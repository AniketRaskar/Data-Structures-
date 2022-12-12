//accept ll from chk wheather it contains loop in it 
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
bool CheakLoop(PNODE head)
{
    PNODE fast = head;
    PNODE slow = head;
    bool flag = false;

    while((fast != NULL) && (fast ->next != NULL))
    {
        slow = slow->next;
        fast = fast ->next->next;

        if(fast == slow)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
int main()
{
    PNODE first = NULL;
    int iRet =0;
    bool bRet = false;

    PNODE Third = NULL;
    PNODE last = NULL;

    InsertFirst(&first,50);
    InsertFirst(&first,40);
    InsertFirst(&first,30);
    InsertFirst(&first,20);
    InsertFirst(&first,10);

    Third = first;  //100
    last = first;   //100

    Third = Third->next->next;  //300
    last = last ->next->next->next->next;  //500

    last ->next =Third;

    bRet = CheakLoop(first);
    if(bRet == true)
    {
        printf("There is loop in linkedlist");
    }
    else
    {
        printf("There is not loop in LL");
    }

    return 0;
}