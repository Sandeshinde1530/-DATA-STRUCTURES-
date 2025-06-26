// 20.56 Mins
#include<iostream>

using namespace std;

struct node 
{
    int data;
    struct node  *prev;
    struct node  *next;
};

class DoublyCircular
{
    public :
        struct node* head;
        struct node* tail;
        int iCount;

        DoublyCircular();
        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no , int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        void Display();
        int Count();
};

DoublyCircular :: DoublyCircular ()
{
    head = NULL;
    tail = NULL;
    iCount = 0;
}

void DoublyCircular ::  InsertFirst(int no)
{
        struct node *newn = NULL;
        newn = new node;

        newn->data = no;
        newn->prev = NULL;
        newn->next = NULL;

        if(head == NULL && tail == NULL)
        {
            head = newn;
            tail = newn;
        }
        else
        {
            newn->next = head;
            head->prev = newn;
            head = newn;
        }
        head->prev = tail;
        tail->next = head;
        iCount++;
}

void DoublyCircular ::  InsertLast(int no)
{
        struct node *newn = NULL;
        newn = new node;

        newn->data = no;
        newn->prev = NULL;
        newn->next = NULL;

        if(head == NULL && tail == NULL)
        {
            head = newn;
            tail = newn;
        }
        else
        {
            newn->prev = tail;
            tail->next = newn;
            tail = newn;
        }
        head->prev = tail;
        tail->next = head;
        iCount++;
}

void DoublyCircular ::  InsertAtPos(int no , int iPos)
{
    if(iPos < 1 || iPos > iCount + 1)
    {
        cout<<"Invalid Position\n";
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
        newn->prev = NULL;
        newn->next = NULL;

        for(int i = 1 ; i<iPos - 1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        newn->prev = temp;
        temp->next = newn;
    }
         head->prev = tail;
        tail->next = head;
        iCount++;
}

void DoublyCircular ::  DeleteFirst()
{
    if(head == NULL && tail == NULL)
    {
        cout<<"List is empty";
        return;
    }
    else if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        delete head->prev;
    }
    tail->next = head;
    head->prev = tail;
    iCount--;
}

void DoublyCircular ::  DeleteLast()
{
    if(head == NULL && tail == NULL)
    {
        cout<<"List is empty";
        return;
    }
    else if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
    }
    tail->next = head;
    head->prev = tail; 
    iCount--;
}

void DoublyCircular ::  DeleteAtPos(int iPos)
{
    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position\n";
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

        for(int i = 1 ; i<iPos - 1 ; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        target ->next->prev = temp;
        delete target;
    }
        head->prev = tail;
        tail->next = head;
        iCount--;
}

void DoublyCircular ::  Display()
{
    if(head == NULL)
    {
        cout<<"List is empty\n";
    }

    struct node *temp = head;
    cout<<"Display the elements FORWARD:\n";
    
    do
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    } while (temp != tail->next);
    cout<<endl;
    
    temp = tail;
    cout<<"Display the elements REVERSED:\n";
    
    do
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->prev;
    } while (temp != head->prev);
    cout<<endl;
    cout<<endl;
}

int  DoublyCircular ::  Count()
{
    return iCount;
}

int main()
{
    DoublyCircular dobj;
    int iRet = 0;

    dobj.InsertFirst(30);
    dobj.InsertFirst(20);
    dobj.InsertFirst(10);
    iRet = dobj.Count();
    cout<<"Count is : "<<iRet<<endl;
    dobj.Display();

    dobj.InsertLast(40);
    dobj.InsertLast(50);
    dobj.InsertLast(60);
    iRet = dobj.Count();
    cout<<"Count is : "<<iRet<<endl;
    dobj.Display();

    dobj.InsertAtPos(35 , 4);
    iRet = dobj.Count();
    cout<<"Count is : "<<iRet<<endl;
    dobj.Display();

    dobj.DeleteAtPos(4);
    iRet = dobj.Count();
    cout<<"Count is : "<<iRet<<endl;
    dobj.Display();
    
    dobj.DeleteFirst();
    iRet = dobj.Count();
    cout<<"Count is : "<<iRet<<endl;
    dobj.Display();
    
    dobj.DeleteLast();
    iRet = dobj.Count();
    cout<<"Count is : "<<iRet<<endl;
    dobj.Display();

    return 0;
}