//find the sum of data from the ll
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
    while(head->next != NULL)
    {
        printf("| %d |->",head->data);
        head = head->next;
    }
    printf("|NULL|");
}
int main()
{
    PNODE first = NULL;

    InsertFirst(&first,101);
    InsertFirst(&first,51);
    InsertFirst(&first,41);
    InsertFirst(&first,21);
    InsertFirst(&first,11);

    Display(first);
    return 0;
}