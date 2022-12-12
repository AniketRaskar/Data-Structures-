#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node * lchild;
    struct node * rchild;
}NODE,*PNODE,**PPNODE;

void Insert(PPNODE head,int iNo)
{
    PNODE temp = *head;
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->lchild=NULL;
    newn->rchild=NULL;

    if(*head == NULL) //BST empty
    {
        *head = newn;
    }
    else
    {
        while(1)
        {
          if(iNo > temp->data)  //right
          {
            if(temp->rchild == NULL)
            {
                temp->rchild = newn;
                break;
            }
            temp= temp->rchild;
          }  
          else if(iNo< temp->data)   //left
          {
            if(temp->lchild == NULL)
            {
                temp->lchild = newn;
                break;
            }
            temp= temp->lchild;

          }
          else if(iNo == temp->data)  //duplicate
          {
            free(newn);
            printf("Data is already there in BST");
            break;
          }
        }
    }
}
bool Search(PNODE head,int iNo)
{
    while(head != NULL)
    {
        if(head->data ==iNo)
        {
            break;
        }
        else if(iNo>head->data)
        {
            head = head->rchild;
        }
        else if(iNo<head->data)
        {
            head = head->lchild;
        }
    }
    if(head == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void Inorder(PNODE head)
{
    if(head != NULL)
    {
        Inorder(head->lchild);
        printf("%d \t",head->data);
        Inorder(head->rchild);
    }

}
void PreOrder(PNODE head)
{
    if(head != NULL)
    {
        printf("%d \t",head->data);
        PreOrder(head->lchild);
        PreOrder(head->rchild);
    }

}
void PostOrder(PNODE head)
{
    if(head != NULL)
    {
        PostOrder(head->lchild);
        PostOrder(head->rchild);
        printf("%d \t",head->data);
    }

}
int main()
{
    PNODE first = NULL;

    Insert(&first,11);
    Insert(&first,21);
    Insert(&first,7);

    printf("\nInorder data\n");
    Inorder(first);

    printf("\nPostorder data\n");
    PostOrder(first);

    printf("\nPreorder data\n");
    PreOrder(first);

    bool iRet= Search(first,11);
    if(iRet == true)
    {
        printf("Element is there in the tree\n");
    }
    else
    {
        printf("Element is not there in the tree\n");
    }

    // 7    11  21      L D R  //INORDER
    // 11   7   21      D L R  //PREORDER
    // 7    21  11      L R D  //POSTORDER
    return 0;
}