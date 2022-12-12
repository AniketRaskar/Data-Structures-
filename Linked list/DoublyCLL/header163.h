#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyCLL
{
    private:
    PNODE head;
    PNODE tail;

    int CountNode;
    public:
    DoublyCLL();

    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int,int);

    void DeleteFirst();
    void Deletelast();
    void DeleteAtPos(int);

    int Count();
    void Display();
};