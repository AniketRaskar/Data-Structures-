//write the generic code for LL

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class SinglyLL
{
    public:
    struct node<T> *head;
    int Count;

    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(T,int);
    void DeleteAtPos(int);
    void Display();
    int CountNode();
};
template<class T>
SinglyLL<T>::SinglyLL()
{
    head = NULL;
    Count =0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data=no;
    newn->next=NULL;

    if(head==NULL)
    {
        head = newn;
    }
    else
    {
        newn->next=head;
        head=newn;
    }
    Count++;
}
template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data=no;
    newn->next=NULL;

    if(head==NULL)
    {
        head = newn;
    }
    else
    {
        struct node<T> *temp =head;
        while(temp ->next != NULL)
        {
            temp = temp ->next;
        }
        temp ->next = newn;
    }
    Count++;
}
template <class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements from linled list are:"<<endl;
    struct node<T> *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
template <class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}
template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct node<T> *temp = head;
    if(head==NULL)
    {
        return;
    }
    else if(head ->next ==NULL)
    {
        delete temp;
        head=NULL;
    }
    else
    {
        head = head ->next;
        delete temp;
    }
    Count--;
}
template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct node<T> *temp = head;
    if(head==NULL)
    {
        return;
    }
    else if(head ->next ==NULL)
    {
        delete temp;
        head==NULL;
    }
    else
    {
        while(temp ->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp ->next =NULL;
    }
    Count--;
}
template<class T>
void SinglyLL<T>::InsertAtPos(T no,int Pos)
{
    int size = Count;
    if((Pos <1) && (Pos> size+1))
    {
        cout<<"Invalid Position"<<endl;
    }
    else if(Pos ==1)
    {
        InsertFirst(no);
    }
    else if(Pos == size+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> *newn = NULL;
        newn = new node<T>;
        newn->data=no;
        newn->next=NULL;
        struct node<T> *temp = head;
        int iCnt=1;
        while(iCnt<Pos-1)
        {
            temp = temp->next;
            iCnt++;
        }
        newn->next=temp->next;
        temp->next=newn;
        Count++;
    }
}
template<class T>
void SinglyLL<T>::DeleteAtPos(int Pos)
{
   int size = Count;
    if((Pos <1) && (Pos> size))
    {
        cout<<"Invalid Position"<<endl;
    }
    else if(Pos ==1)
    {
        DeleteFirst();
    }
    else if(Pos == size)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp = head;
        struct node<T> *Deleteptr =head;
        int iCnt =1;
        while(iCnt<Pos-1)
        {
            temp = temp->next;
            iCnt++;
        }
        Deleteptr=temp->next;
        temp->next=temp->next->next;
        delete Deleteptr;
        Count--;
    }
}
int main()
{
    SinglyLL<int>obj1;
    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertLast(101);
    obj1.InsertLast(121);
    obj1.InsertLast(151);
    obj1.DeleteFirst();
    obj1.DeleteLast();

    obj1.Display();
    int ret=obj1.CountNode();
    cout<<"NUmber of nodes are:"<<ret<<endl;

    obj1.InsertAtPos(75,4);
    obj1.DeleteAtPos(3);
    obj1.Display();
    ret=obj1.CountNode();
    cout<<"NUmber of nodes are:"<<ret<<endl;
    
    SinglyLL<float>obj2;
    obj2.InsertFirst(12.13);
    obj2.InsertFirst(21.22);
    obj2.InsertLast(101.11);
    obj2.InsertLast(51.51);
    obj2.Display();
    float fret=obj2.CountNode();
    cout<<"NUmber of nodes are:"<<fret<<endl; 

    obj2.InsertAtPos(75,3);
    obj2.DeleteAtPos(3);
    obj2.Display();
    fret=obj2.CountNode();
    cout<<"NUmber of nodes are:"<<fret<<endl;
    return 0;
}