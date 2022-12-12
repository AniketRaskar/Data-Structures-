//16-05-22 new week monday
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE head,int no)
{
    //allocate memory for node dynamically
    //initialise that node
    //cheack wheather ll is empty or not
    //if ll is empty then new node is the first node so update it's address in first pointer through head

    //if ll is not empty then store the address of first node in the next pointer of our new node
    //update the first pointer through head.

    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE)); //newn = (struct node *)malloc(12)

    newn -> data = no;
    newn -> next = NULL;

    if(*head == NULL)  // LL is empty
    {
        *head = newn;
    }
    else  //LL contains atleast one node
    {
        newn -> next= *head;
        *head = newn;
    }
}

void InsertLast(PPNODE head,int no)
{
    //allocate memory for node dynamically
    //initialise that node
    //cheack wheather ll is empty or not
    //if ll is empty then new node is the first node so update it's address in first pointer through head

    //if ll is not empty then travel till last node of LL
    //Store address of new node in the next pointer of last node

    PNODE newn = NULL;
    PNODE temp =NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        //travel till last node
        //store address of new node in the next pointer of last node
        temp = *head;

        while(temp -> next != NULL)
        {
            temp = temp ->next;
        }
        temp -> next = newn;
    }
}

void Display(PNODE head)
{
    printf("Elements from linked are: \n");

    while(head != NULL)
    {
        printf("| %d | -> ",head -> data);
        head =head -> next;
    }
    printf("NULL\n");
}

int Count(PNODE head)
{
    int iCnt =0;
    while(head != NULL)
    {
       iCnt++;
        head =head -> next;
    }
    return iCnt;
}

void DeleteFirst(PPNODE head)
{
    //if linked is empty then return
    //if linked list contains at least one node then store the address of second node in the first pointer through head and delete the first node

    PNODE temp = NULL;

    if(*head == NULL) //LL is empty
    {
        return;
    }
    else  //LL contains at least one node
    {
      temp = *head;
      *head = temp -> next;
      free(temp);
    }
}
void DeleteLast(PPNODE head)
{
    //if LL is empty then return
    // if LL contains one nodw then delete that node and return
    //if LL contains more than one node then travel till second last node and delete the last node

    PNODE temp = NULL;
    if(*head == NULL) //LL is empty
    {
        return;
    }
    else if((*head) -> next == NULL)//LL contains one node
    {
        free(*head);
        *head = NULL;
    }
    else//LL contains more than one node
    {
        temp = *head;
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        free(temp->next);
        temp -> next = NULL;
    }
}
void InsertAtPos(PPNODE head,int no,int pos)
{
    //consider no of nodes are 4
    //If position is invalid then return directly( < 1 or > 5)
    //if position is 1 then call insertFirst
    //if position is N+1 then call Insertlast (position is 5)

    PNODE newn = NULL;
    int iCnt=0;
    PNODE temp = NULL;
    int size =0;
    size = Count(*head);//calling the count function

    if((pos < 1) | (pos > (size+1)))
    {
        printf("Position is invalid\n");
        return;
    }

    else if(pos == 1)
    {
        InsertFirst(head,no);
    }
    else if(pos == (size+1))
    {
        InsertLast(head,no);
    }
    else   //At position
    {
     PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE)); //newn = (struct node *)malloc(12)

    newn -> data = no;
    newn -> next = NULL;

    temp = *head;

    for(iCnt =1; iCnt < (pos-1);iCnt++)
    {
        temp = temp -> next;
    }
    newn -> next = temp -> next;
    temp -> next = newn;
             
    }
}

void DeleteAtPos(PPNODE head,int pos)
{
    //consider no of nodes are 4
    //If position is invalid then return directly( < 1 or > 4)
    //if position is 1 then call DelteFirst
    //if position is N then call DeleteLast (position is 4)
    
    int iCnt=0;
    PNODE temp = NULL;
    PNODE tempDelete = NULL;
    int size =0;
    size = Count(*head);//calling the count function

    if((pos < 1) || (pos > (size)))
    {
        printf("Position is invalid\n");
        return;
    }

    else if(pos == 1)
    {
        DeleteFirst(head);
    }
    else if(pos == (size))
    {
        DeleteLast(head);
    }
    else   //At position
    {
     
    
    temp = *head;

    for(iCnt =1; iCnt < (pos);iCnt++)
    {
        temp = temp -> next;
    }
    tempDelete = temp ->next;
    temp -> next = temp -> next -> next;
    free(tempDelete);
    
             
    }
}
int main()
{
    int iRet=0;
    PNODE first = NULL;

    InsertFirst(&first,101);  //call by address
    InsertFirst(&first,51);
    InsertFirst(&first,21);
    InsertFirst(&first,11);

    InsertAtPos(&first,75,3);
    DeleteAtPos(&first,3);

    Display(first);  //call by value

    iRet = Count(first);
    printf("Number of nodes are: %d\n",iRet);

    InsertFirst(&first,1);

    Display(first);  //call by value

    printf("Number of nodes are: %d\n",iRet);

    InsertLast(&first,111);
    InsertLast(&first,121);

    Display(first);  //call by value
    iRet = Count(first);
    
    printf("Number of nodes are: %d\n",iRet);
    Display(first);  //call by value
    iRet = Count(first);
    
    printf("Number of nodes are: %d\n",iRet);

    DeleteFirst(&first); 
    DeleteFirst(&first); 

    Display(first);  //call by value
    iRet = Count(first);
    
    printf("Number of nodes are: %d\n",iRet);

    DeleteLast(&first);
    DeleteLast(&first);

     Display(first);  //call by value
    iRet = Count(first);
    
    printf("Number of nodes are: %d\n",iRet);


    return 0;
}
