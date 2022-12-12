//accept ll from user and display addition of factor of each no
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
void  DisplayAddiFact(PNODE head)
{
    int iNo =0,iSum=0;
    while(head != NULL)
    {
        
        for(int i=1,iSum=0,iNo=head->data;i<=(iNo/2);i++)
        {
            if(iNo%i==0)
            {
                iSum = iSum+i;
            }
        }
        printf("%d : %d\n",head->data,iSum);
        //iSum =0; //better in for loop
        head= head->next;
        
    }
}
int main()
{
    int iRet =0;
    PNODE first = NULL;

    InsertFirst(&first,101);
    InsertFirst(&first,50);
    InsertFirst(&first,48);
    InsertFirst(&first,25);
    InsertFirst(&first,11);

    Display(first);
    DisplayAddiFact(first);
    return 0;
}