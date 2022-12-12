//singly circular ll in cpp

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyCLL
{
    private:   //characteritics
        PNODE head;
        PNODE tail;

    public:    //Behaviours
        SinglyCLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no,int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtpos(int iPos);
        void Display();
        int Count();
};

SinglyCLL :: SinglyCLL()
{
    head = NULL;
    tail = NULL;
}
void SinglyCLL :: InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn -> data = no;
    newn -> next = NULL;

    if((head == NULL) && (tail == NULL))  //If LL is empty
    {
        head = newn;
        tail = newn;
    }
    else  //If LL contains at least one node
    {
        newn -> next = head;
        head = newn;
    }
    tail ->next = head;

}

void SinglyCLL :: InsertLast(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn -> data = no;
    newn -> next = NULL;

    if((head == NULL) && (tail == NULL))  //If LL is empty
    {
        head = newn;
        tail = newn;
    }
    else  //If LL contains at least one node
    {
        tail -> next = newn;
        tail = newn;
    }
    tail ->next = head;
}

void SinglyCLL :: InsertAtPos(int no,int iPos)
{
    int iSize = Count();

    if((iPos <1) || (iPos >(iSize +1)))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == (iSize +1))
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = NULL;

        newn = new NODE;

        newn -> data = no;
        newn -> next = NULL;
        PNODE temp = head;
        int iCnt =0;

        for(iCnt =1;iCnt <(iPos-1);iCnt++)
        {
            temp = temp ->next;
        }
        newn -> next= temp -> next;
        temp -> next = newn;

    }
    

}

void SinglyCLL :: DeleteFirst()
{
    if(head == NULL)  //LL is empty
    {
        return;
    }
    else if(head == tail)  //LL contains single node
    {
        delete head;  //or delete tail
        head =NULL;
        tail == NULL;
    }
    else  //LL contains more node
    {
        head = head -> next;
        delete tail -> next;

        tail -> next = head;
    }
    
}

void SinglyCLL :: DeleteLast()
{
    if(head == NULL && tail == NULL)  //LL is empty
    {
        return;
    }
    else if(head == tail)  //LL contains single node
    {
        delete head;  //or delete tail
        head =NULL;
        tail == NULL;
    }
    else  //LL contains more node
    {
        PNODE temp = NULL;
        temp= head;
        
        while(temp->next != tail)
        {
            temp = temp -> next;
        }
        delete tail;  // or delete(temp ->next)
        tail = temp;
        tail -> next = head;
    }
}

void SinglyCLL :: DeleteAtpos(int iPos)
{
    int iSize = Count();

    if((iPos <1) || (iPos >(iSize )))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == (iSize))
    {
        DeleteLast();
    }
    else
    {
        PNODE temp1 = head;
        int iCnt =0;

        for(iCnt =1;iCnt <(iPos-1);iCnt++)
        {
            temp1 = temp1 ->next;
        }
        PNODE temp2 = temp1 -> next;

        temp1 -> next = temp2 -> next;
        delete temp2;
        

    }
}

void SinglyCLL :: Display()
{
    PNODE temp = head;

    /*while(temp != tail)  //don't use this loop
    {
        cout<<"|"<<temp->data<<"| ->";
        temp = temp -> next;
    }
    cout<<"|"<<temp->data<<"| ->";*/

    if((head == NULL) && (tail == NULL)) //If LL is empty
    {
        return;
    }
    do
    {
        cout<<"|"<<temp->data<<"| ->";
        temp = temp -> next;

    }while(temp != head);  //(temp != tail ->next)
    cout<<endl;
}

int SinglyCLL :: Count()
{
    int iCnt =0;
     PNODE temp = head;
    if((head == NULL) && (tail == NULL))
    {
        return 0;
    }
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != head);
    return iCnt;
}


int main()
{
    SinglyCLL obj;
    int iRet =0;
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.InsertLast(201);

    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of nodes are: "<<iRet<<endl;

    //obj.DeleteFirst();
    //obj.DeleteLast();

    obj.InsertAtPos(75,4);

    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of nodes are: "<<iRet<<endl;

    obj.DeleteAtpos(4);
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of nodes are: "<<iRet<<endl;

    return 0;
}