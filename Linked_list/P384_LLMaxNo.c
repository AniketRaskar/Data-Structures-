//find the largest no of ll
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
    printf("|NULL|");
}
int Maximum(PNODE head)
{
    int iMax = 0;
    if(head != NULL)
    {
         iMax =head->data;
    }
    while(head != NULL)
    {
        if((head->data)>iMax)
        {
            iMax = head->data;
        }
        head = head ->next;
    }
    return iMax;
}
int main()
{
    int iRet =0;
    PNODE first = NULL;

    InsertFirst(&first,101);
    InsertFirst(&first,51);
    InsertFirst(&first,41);
    InsertFirst(&first,21);
    InsertFirst(&first,11);

    Display(first);
    iRet = Maximum(first);
    printf("Maximum no is :%d\n",iRet);
    return 0;
}