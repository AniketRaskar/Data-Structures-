//accept ll from user and find 1st occurance
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
int SearchFirstOccurance(PNODE head,int iNo)
{
    int iPos =0;
    while(head != NULL)
    {
        iPos++;
        if(head->data == iNo)
        {
            break;
        }
        head = head -> next;
    }
    if(head == NULL)
    {
        return -1;
    }
    else
    {
        return iPos;
    }
}
int main()
{
    int iRet =0;
    PNODE first = NULL;

    InsertFirst(&first,6);
    InsertFirst(&first,28);
    InsertFirst(&first,496);
    InsertFirst(&first,24);
    InsertFirst(&first,22);

    Display(first);
    iRet = SearchFirstOccurance(first,24);
    if(iRet == -1)
    {
        printf("There is no such element.\n");
    }
    else
    {
        printf("Element is there at positon :%d",iRet);
    }
    return 0;
}