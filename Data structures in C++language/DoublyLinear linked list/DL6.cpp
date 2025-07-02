#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

class DoublyLinear
{
    public:
        int iCount;
        struct node *head ;

        DoublyLinear();
        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no , int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        void Display();
        int Count();
};


DoublyLinear ::  DoublyLinear()
{
    iCount = 0;
    head = NULL;    
}

void DoublyLinear :: InsertFirst(int no)
{
    struct node *newn = NULL;
    newn = new node;

    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if( head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
    }
    iCount++;
}

void DoublyLinear :: InsertLast(int no)
{
    struct node *temp = head;
    struct node *newn = NULL;
    newn = new node;

    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if( head == NULL)
    {
        head = newn;
    }
    else
    {
       while(temp -> next != NULL)
       {
        temp->next = newn;
        newn->prev = temp;  
       }
    }  
    iCount++;
}

void DoublyLinear :: InsertAtPos(int no , int iPos)
{
    if(iPos <1 ||  iPos > iCount + 1)
    {
        cout<<"Invalid Syntax\n";
        return ;
    }
    else if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct node *temp = head;
        struct node *newn = NULL;

        newn = new node;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (int i = 1 ; i < iPos - 1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = NULL;
        newn->next = NULL;
    }
    iCount++;    
}

void DoublyLinear :: DeleteFirst()
{
     if(head == NULL)
     {
        return;
     }
     else if(head ->next = NULL)
     {
        delete head;
        head == NULL;
     }
     else
     {
        head = head->next;
        delete head;
        head == NULL;
     }
     iCount;
}

void DoublyLinear :: DeleteLast()
{
    struct node *temp = head;

    if(head == NULL)
     {
        return;
     }
     else if(head ->next = NULL)
     {
        delete head;
        head == NULL;
     }
     else
     {
        while(temp->next->next == NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
     }
     iCount--
}

void DoublyLinear :: DeleteAtPos(int iPos)
{
        if(iPos <1 ||  iPos > iCount + 1)
    {
        cout<<"Invalid Syntax\n";
        return ;
    }
    else if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct node *temp = head;
        struct node *target = NULL;

        for (int i = 1 ; i < iPos - 1 ; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next ;
        target->next->prev =  temp;
        delete  target;

    }
    iCount--;    
}

void DoublyLinear :: Display()
{
        struct node * temp = head;

        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" | <=>";
            temp = temp->next;
        }
}


int Count()
{
    return iCount;
}

int main()
{


    return 0;
}