#include<iostream>
using namespace std;

template < class T>
struct node
{
    T data;
    struct node<T> *prev;
    struct node<T> *next;
};
template<class T>
class DoublyLL
{
    public:
    int iCount;
    struct node<T> *head;

    DoublyLL();
    void InsertFirst( T no);
    void InsertLast( T no);
    void DeleteFirst( );
    void DeleteLast( );
    void Display();
    int Count();
    void InsertAtPos(T no ,int iPos);
    void DeleteAtPos(int iPos);
};

template < class T>
 DoublyLL<T> :: DoublyLL()
 {
    iCount = 0 ; 
    head = NULL;
 }

template < class T>
void DoublyLL<T> :: InsertFirst( T no)
{
    struct node<T>* newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(head == NULL)
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

template < class T>
void DoublyLL<T> :: InsertLast( T no)
{
    struct node<T>* temp = NULL;
    struct node<T>* newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;

        while(temp ->next != NULL)
        {
            temp = temp->next;
        }
        newn->prev = temp;
        temp->next = newn;
    }
    iCount++;
}

template < class T>
void DoublyLL<T> :: DeleteFirst( )
{
    if(head == NULL)
    {
        return ;
    }
    else if(head ->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
       head = head->next;
       delete head->prev;
       head->prev = NULL;
    }
    iCount--;
}

template < class T>
void DoublyLL<T> :: DeleteLast( )
{
     if(head == NULL)
    {
        return ;
    }
    else if(head ->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
       struct node<T> *temp = head;

       while(temp->next->next != NULL)
       {
            temp = temp->next;
       }
       delete temp->next;
       temp->next = NULL;
    }
    iCount--;
}

template < class T>
void DoublyLL<T> :: Display()
{
    cout<<"NULL<=>";
    struct node<T> * temp = head;
    struct node<T> * temp2 = head;
    
    while(temp != NULL)
    {
        if(temp->next == NULL)
        {
            temp2 = temp;
        }
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    
    cout<<"NULL"<<endl;
    
    cout<<"REVERSED :::::::::::::::NULL<=>";
    
    while(temp2 != NULL)
    {
        cout<<"| "<<temp2->data<<" |<=>";
        temp2 = temp2->prev;
    }    
    cout<<"NULL"<<endl;
    cout<<endl;
    cout<<endl;
}

template < class T>
int DoublyLL<T>:: Count()
{
    return iCount;
}

template < class T>
void DoublyLL<T> :: InsertAtPos(T no , int iPos)
{
    if(iPos < 1 || iPos > iCount + 1)
    {
        cout<<"Invalid Position"<<endl;
        return;
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
        struct node<T> * temp = head;
        struct node<T> * newn = NULL;
        newn = new node<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int i = 1 ; i< iPos - 1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        newn->prev = temp;
        temp->next = newn;
    }
    iCount++;
}

template < class T>
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position"<<endl;
        return;
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
        struct node<T> * temp = head;
        struct node<T> * target = NULL;

        for(int i = 1 ; i< iPos - 1 ; i++)
        {
            temp = temp->next;
        }
        target =  temp->next;
        temp->next = target ->next;
        target->next->prev = temp;

        delete target;
    }
    iCount--;
}

int main()
{
    DoublyLL<char> dobj;
    int iRet = 0;

    dobj.InsertFirst('A');
    dobj.InsertFirst('A');
    dobj.InsertFirst('A');
    iRet = dobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    dobj.Display();

    dobj.InsertLast('B');
    dobj.InsertLast('B');
    dobj.InsertLast('B');
    iRet = dobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    dobj.Display();
    
    dobj.InsertAtPos('C' , 4);
    iRet = dobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    dobj.Display();
    
    dobj.DeleteAtPos(4);
    iRet = dobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    dobj.Display();
    
    dobj.DeleteFirst();
    iRet = dobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    dobj.Display();

    dobj.DeleteLast();
    iRet = dobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    dobj.Display();

    return 0;
}