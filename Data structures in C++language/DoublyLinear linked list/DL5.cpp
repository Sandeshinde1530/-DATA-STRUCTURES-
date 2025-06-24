//23.32 Mins
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
    struct node *head;
    int iCount;

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

DoublyLinear ::DoublyLinear()
{
    head = NULL;
    iCount = 0;
}

void DoublyLinear :: InsertFirst(int no)
{
    struct node *newn = NULL;
    newn = new node;
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(head == NULL)
    {
        head  = newn;
    }
    else
    {
        head->prev = newn;
        newn->next = head;
        head = newn;
    }
    iCount++;
}

void DoublyLinear :: InsertLast(int no)
{
    struct node *temp = NULL;
    struct node *newn = NULL;
    newn = new node;
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(head == NULL)
    {
        head  = newn;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

void DoublyLinear :: InsertAtPos(int no , int iPos)
{
    if(iPos < 1 ||  iPos > iCount + 1)
    {
        cout<<"Invalid Position\n";
        return;
    }
    else if( iPos == 1)
    {
        InsertFirst(no);
    }
    else if( iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct node *temp = head;
        struct node *newn = NULL;
        newn = new node;
        newn->data = no;
        newn->prev = NULL;
        newn->next = NULL; 

        for(int i=1 ; i< iPos - 1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        newn->prev = temp;
        temp->next = newn;
        
        iCount++;
    }

}

void DoublyLinear :: DeleteFirst()
{
    if(head == NULL)
    {
        cout<<"List is empty\n";
    }
    else if(head ->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        head = head ->next;
        delete head->prev ;
        head->prev = NULL;
    }
    iCount--;

}

void DoublyLinear :: DeleteLast()
{
    if(head == NULL)
    {
        cout<<"List is empty\n";
    }
    else if(head ->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        struct node *temp = head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

void DoublyLinear :: DeleteAtPos(int iPos)
{
    if(iPos < 1 ||  iPos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }
    else if( iPos == 1)
    {
        DeleteFirst();
    }
    else if( iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct node *temp = head;
        struct node *target = NULL;

        for(int i=1 ; i< iPos - 1 ; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;

        delete target;

        iCount--;
    }
}

void DoublyLinear :: Display()
{
    if(head == NULL)
    {
        cout<<"List is empty\n";
        return;
    }

    struct node * temp = head;
    struct node * temp2 = NULL;

    cout<<"NULL";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";

        if(temp ->next == NULL)
        {
            temp2 = temp;
        }
        temp = temp->next;
    }
    cout<<"NULL\n";

    cout<<"NULL";
    while(temp2 != NULL)
    {
        cout<<"| "<<temp2->data<<" |<=>";

        temp2 = temp2->prev;
    }
    cout<<"NULL\n";

    cout<<"//////////////////////////////////////////////////////////////////////////////////////\n";

}

int DoublyLinear:: Count()
{
    return iCount;
}


int main()
{
    DoublyLinear dobj;
    int iRet = 0;

    dobj.Display();
    dobj.InsertFirst(30);
    dobj.InsertFirst(20);
    dobj.InsertFirst(10);
    iRet = dobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    dobj.Display();

    dobj.InsertLast(40);
    dobj.InsertLast(50);
    dobj.InsertLast(60);
    iRet = dobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    dobj.Display();
    
    dobj.InsertAtPos(35 , 4);
    iRet = dobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    dobj.Display();
    
    dobj.DeleteAtPos(4);
    iRet = dobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    dobj.Display();
    
    dobj.DeleteFirst();
    iRet = dobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    dobj.Display();
    
    dobj.DeleteLast();
    iRet = dobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    dobj.Display();

    return 0 ;
}