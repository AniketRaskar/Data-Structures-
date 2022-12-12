//accept ll from user and return the addition of digits
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
void SumDigits(PNODE head)
{
    int SumDigit=0;
    while(head != NULL)
    {
        int iNo = head->data;
        while(iNo!= 0)
        {
            int iDigit= iNo%10;
            SumDigit = SumDigit+iDigit;
            iNo= iNo/10;
        }
        printf("%d : %d \n",head->data,SumDigit);
        SumDigit=0;
        head= head ->next;
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
    SumDigits(first);
    return 0;
}