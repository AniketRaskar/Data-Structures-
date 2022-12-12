//Doubly linear linked list

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;  // //*

};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE head,int no)
{
    PNODE newn = NULL;
    newn = ((PNODE)malloc(sizeof(NODE)));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;  //*

    if(*head ==NULL)  //LL is empty
    {
        *head = newn;
    }
    else  //LL contains at least one node
    {
        newn -> next = *head;
        (*head) -> prev = newn;// or   newn -> next -> prev = newn;
        *head = newn;
    }
    /*
    //it is also valid and better for above code:
    if(*head != NULL)
    {
        newn -> next = *head;
        (*head) -> prev =newn;
    }
    *head = newn;
    */
}

void InsertLast(PPNODE head,int no)
{
     PNODE newn = NULL;
    newn = ((PNODE)malloc(sizeof(NODE)));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;  //*
    PNODE temp = NULL;

    if(*head == NULL)  //LL is empty
    {
        *head = newn;
    }
    else  //LL contains at least one node
    {
    temp = *head;  
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newn;
    newn -> prev = temp;  //*  or (temp -> next -> prev =temp;)
    }
}
void Display(PNODE head)
{
    printf("Data from linked list is:\n");
    while(head != NULL)
    {
        printf("| %d | <=>",head -> data);
        head = head -> next;
    }
    printf("NULL \n");
}
int Count(PNODE head)
{
    int iCnt=0;
    while(head != NULL)
    {
        iCnt++;
        head = head -> next;
    }
    return iCnt;
}
void InsertAtPos(PPNODE head,int no,int pos)
{
    int size=0;
    size = Count(*head);
    PNODE temp = NULL;
    PNODE newn = NULL;
    int iCnt =0;

    if((pos < 1) || (pos >(size+1)))
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(head,no);
    }
    else if(pos == (size+1))
    {
        InsertLast(head,no);
    }
    else
    {
        temp = *head;
    newn = ((PNODE)malloc(sizeof(NODE)));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;  //*
   
   for(iCnt =1;iCnt<(pos-1);iCnt++)
   {
       temp = temp -> next;
   }
   newn -> next = temp -> next;
   temp -> next ->prev = newn; //*
   temp -> next = newn;
   newn -> prev = temp;  //*
    }
}

void DeleteFirst(PPNODE head)
{
    if(*head ==NULL)  //LL is empty
    {
        return;
    }
    else if((*head) -> next ==NULL)  //Single node
    {
        free(*head);
        *head = NULL;
    }
    else //more than one node
    {
        *head =(*head) -> next; //*
        free((*head) ->prev);  //*
        (*head) -> prev = NULL;  //*
    }
}
void DeleteLast(PPNODE head)
{
    PNODE temp =NULL;
if(*head =NULL)  //LL is empty
    {
        return;
    }
    else if((*head) -> next =NULL)  //Single node
    {
        free(*head);
        *head = NULL;
    }
    else //more than one node
    {
        temp = *head;
       while(temp -> next -> next !=NULL)
       {
           temp = temp -> next;
       } 
       free(temp -> next);
       temp -> next = NULL;
    }
    /*
    while loop varities

    while(temp!=NULL)
    {
        temp = temp -> next;
    }(here temp NULL)
    or
    while(temp -> next !=NULL)
    {
        temp = temp -> next;
    }(here temp = 400)
    or
    while(temp -> next ->next !=NUll)
    {
        temp = temp -> next;
    }(here temp = 300)
    */
}

void DeleteAtPos(PPNODE head,int pos)
{
    int size=0;
    size = Count(*head);
    PNODE temp = NULL;
    
    int iCnt =0;

    if((pos < 1) || (pos >(size)))
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(head);
    }
    else if(pos == (size))
    {
        DeleteLast(head);
    }
    else
    {
        temp = *head;
   
   for(iCnt =1;iCnt<(pos-1);iCnt++)
    {
       temp = temp -> next;
    }
    temp -> next = temp -> next -> next;
    free(temp -> next ->prev);
    temp -> next -> prev = temp;
   
    }

}



int main()
{
    PNODE first = NULL;
    int ret=0;

    InsertFirst(&first,21);
    InsertFirst(&first,11);

    InsertLast(&first,51);
    InsertLast(&first,101);

    Display(first);
    ret = Count(first);

    printf("Number of nodes are: %d\n",ret);

    InsertAtPos(&first,75,3);
    Display(first);

    DeleteAtPos(&first,3);
    Display(first);

    DeleteFirst(&first);
    DeleteLast(&first);

    Display(first);
    ret = Count(first);

    printf("Number of nodes are: %d\n",ret);
    return 0;

    

}