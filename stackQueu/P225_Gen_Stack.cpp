//write the generic code for stack

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class Stack
{
    public:
    struct node<T> *head;
    int Count;

    Stack();
    void Push(T);  //InsertFirst()
    void Pop();   //DeleteFirst()
    void Display();
    int CountNode();
};

template<class T>
Stack<T>::Stack()
{
    head = NULL;
    Count =0;
}

template<class T>
void Stack<T>::Push(T no)   //InsertFirst()
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next=head;
    head = newn;
    Count++;
}

template <class T>
void Stack<T>::Pop()   //DeleteFirst
{
    T no;  //int no;
    if(Count==0)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }
    
    no = head->data;
    struct node<T> *temp=head;
    head=head->next;
    delete temp;
    
    Count--;
    cout<<"Removed element is :"<<no<<endl;
}

template <class T>
void Stack<T>::Display()
{
    cout<<"Elements from Stack are:"<<endl;
    struct node<T> *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
template <class T>
int Stack<T>::CountNode()
{
    return Count;
}

int main()
{
    Stack<int> obj1;

    obj1.Push(11);
    obj1.Push(21);
    obj1.Push(51);
    obj1.Push(101);
    obj1.Push(121);
    
    obj1.Display();
    cout<<"Number of elements in a queue :"<<obj1.CountNode()<<endl;

    obj1.Pop();
    obj1.Pop();
    obj1.Pop();
   
    obj1.Display();
    cout<<"Number of elements in a stack :"<<obj1.CountNode()<<endl;

    obj1.Pop();
    obj1.Pop();
 
 
    Stack <char>obj2;
    
    obj2.Push('A');
    obj2.Push('B');
    obj2.Push('C');
    obj2.Push('D');

    obj2.Display();

    obj2.Pop();
    obj2.Pop();

    obj2.Display();

    obj2.Push('Z');
    obj2.Pop();

    return 0;
}