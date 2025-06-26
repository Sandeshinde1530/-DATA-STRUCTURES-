// 18.56 MIns
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class SinglyLinear
{
    public:
    struct node *head;
    int iCount;

    SinglyLinear();
    void InsertFirst(int no);
    void InsertLast(int no);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void InsertAtPos(int no , int iPos);
    void DeleteAtPos(int iPos);
};

SinglyLinear :: SinglyLinear()
{
    iCount = 0;
    head = NULL;
}

void SinglyLinear ::  InsertFirst(int no)
{
    struct node *newn = NULL;
        newn = new node;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    iCount++;
}

void SinglyLinear ::  InsertLast(int no)
{
    struct node *temp = NULL;
    struct node *newn = NULL;
    newn = new node;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

void SinglyLinear ::  DeleteFirst()
{

    if(head == NULL)
    {
        cout<<"List is Empty\n";
    }
    else if(head ->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        head = temp->next;
        delete temp;
    }
    iCount--;
}

void SinglyLinear ::  DeleteLast()
{
    
    if(head == NULL)
    {
        cout<<"List is Empty\n";
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

void SinglyLinear ::  Display()
{
    if(head ==NULL)
    {
        cout<<"List is empty\n";
    }

    struct node *temp= head;

    cout<<"Displaying elements:\n";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int  SinglyLinear :: Count()
{
    return iCount;
}

void SinglyLinear ::  InsertAtPos(int no , int iPos)
{
    if(iPos < 1 || iPos > iCount + 1)
    {
        cout<<"Invalid Position"<<endl;
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

        for(int i = 1 ; i<iPos - 1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

void SinglyLinear ::  DeleteAtPos(int iPos)
{
    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position"<<endl;
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

        iCount--;
    }
}


int main()
{
    SinglyLinear sobj;
    int iRet = 0;

    sobj.InsertFirst(30);
    sobj.InsertFirst(20);
    sobj.InsertFirst(10);
    iRet = sobj.Count();
    cout<<"Count is :"<< iRet<<endl;
    sobj.Display();

    sobj.InsertLast(40);
    sobj.InsertLast(50);
    sobj.InsertLast(60);
    iRet = sobj.Count();
    cout<<"Count is :"<< iRet<<endl;
    sobj.Display();
    
    sobj.InsertAtPos(35 , 4);
    iRet = sobj.Count();
    cout<<"Count is :"<< iRet<<endl;
    sobj.Display();
    
    sobj.DeleteAtPos(4);
    iRet = sobj.Count();
    cout<<"Count is :"<< iRet<<endl;
    sobj.Display();
    
    sobj.DeleteFirst();
    iRet = sobj.Count();
    cout<<"Count is :"<< iRet<<endl;
    sobj.Display();
    sobj.DeleteLast();
    iRet = sobj.Count();
    cout<<"Count is :"<< iRet<<endl;
    sobj.Display();


    return 0;
}