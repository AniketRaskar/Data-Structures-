//Accept ll and no find frequency of no
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
int Frequency(PNODE head,int no)
{
    int iFreq =0;
    
    while(head != NULL)
    {
        if(head->data == no)
        {
            iFreq++;
        }
        head = head ->next;
    }
    return iFreq;
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
    int iNo = 41;
    iRet = Frequency(first,iNo);
    printf("Frequency is :%d\n",iRet);
    return 0;
}