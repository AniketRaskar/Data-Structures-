// Singly linear linked list

/*
    Insertfirst
    Insertlast
    InsertAtPosition

    DeleteFirst
    DeleteLast
    DeleteAtPosition

    Display
    Count
*/

#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node * next;

};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

/*
1-Allocate memory for node
2-initialise the node
3-cheak wheather ll is empty
4-if ll is empty the new node is the first node
5- if ll contains atleast one node in it then stire the addres of previous first  node in the next pointer of new node
*/
void InsertFirst(PPNODE Head,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(*Head == NULL)  //If ll is empty
    {
        *Head = newn;
    }
    else  //If ll contains atleast one node
    {
        newn -> next = *Head;
        *Head = newn;
    }
}

int main()
{
    PNODE First = NULL;

    InsertFirst(&First,101);
    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);

    return 0;
}

/*
1-use only dyanamic memory allocation
2-don't write any techinical syntax in main
3-don't use any global variables
4- be careful while manipulating the first pointer
5-pass the first pointer directly of the function is not going to modify the linked list(Display,Count)
6-pass the address of first pointer if the function is going to modify the linked list (InsertFisrt,InsertLast,InsetAtPos,DeleteFist,DeleteLast,DeketeAtpos)
*/