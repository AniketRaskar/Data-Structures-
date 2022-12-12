//Singly linear linked list

#include <stdio.h>
#include<stdlib.h>

//structure declaration
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

//juna naw           nawin naw
//struct node        NODE
//struct node *      PNODE

int main()
{
    //static memory allocation
    NODE obj;

    //Dyanamic memory allocation
    PNODE ptr = (PNODE)malloc(sizeof(NODE));  //malloc gives memory of 12 bytes with return type void and returns the addrees, accept it in the pointer ptr and make typecast as NODE for void

    obj.data = 11;//Direct assesing operator .
    obj.next = NULL;

    ptr -> data = 11; //Indirect assesing operator ->
    ptr -> next = NULL;
    return 0;
}