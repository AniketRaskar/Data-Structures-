//accept ll from user and find middle element of ll if node are odd the exact middle if even ie 4 then 2 or 3
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
int MiddleElement(PNODE head)
{
    PNODE fast = head;
    PNODE slow = head;

    while((fast != NULL) && (fast ->next != NULL))
    {
        fast =fast ->next->next;
        slow=slow->next;
    }
    return slow ->data;
}
int main()
{
    int iRet =0;
    PNODE first = NULL;

    InsertFirst(&first,6);
    InsertFirst(&first,28);
    InsertFirst(&first,496);
    InsertFirst(&first,28);
    InsertFirst(&first,22);
    //InsertFirst(&first,32);

    Display(first);
    iRet = MiddleElement(first);
    printf("Middle element is: %d",iRet);

    return 0;
}