// speecific in 20.55 Mins
// Continued
// conversion to generic 34.54
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node<T> *next;
};

template <class T>
class SinglyLL
{
    public:
    int iCount;
    struct node<T>* head;

    SinglyLL();
    void InsertFirst(T no)    ;
    void InsertLast(T no);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void InsertAtPos(T no , int iPos);
    void DeleteAtPos(int iPos);

};

template <class T>
SinglyLL<T> :: SinglyLL()
    {
        iCount = 0 ; 
        head = NULL;
    }

template <class T>
void  SinglyLL<T> :: InsertFirst(T no)
{
    struct node<T>* newn = NULL;

    newn = new node<T>;
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

template <class T>
void  SinglyLL<T> :: InsertLast(T no)
{
    struct node<T>* newn = NULL;

    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else 
    {
        struct node<T>* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void  SinglyLL<T> :: DeleteFirst()
{
    if(head == NULL)
    {
        return ;
    }
    else if( head->next == NULL)
    {
        delete head;
        head  = NULL;
    }
    else
    {
            struct node<T>* temp = head;
            head = temp->next ;
            delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T> :: DeleteLast()
{
    if(head == NULL)
    {
        return ;
    }
    else if( head->next == NULL)
    {
        delete head;
        head  = NULL;
    }
    else
    {
        struct node<T>* temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T> :: Display()
{
    struct node<T>* temp = head;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

template <class T>
int SinglyLL<T> :: Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T> :: InsertAtPos(T no , int iPos)
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
        struct node<T>* temp = head;
        struct node<T>* newn = NULL;

        newn = new node<T>;
        newn->data = no;
        newn->next = NULL;

        for(int i = 0 ; i< iPos - 1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T> :: DeleteAtPos(int iPos)
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
        struct node<T>* temp = head;
        struct node<T>* target = NULL;

        for(int i = 0 ; i< iPos - 1 ; i++)
        {
            temp = temp->next;
        }
        target = temp->next;

        temp->next = target->next;
        delete target;            
    }
    iCount--;
}

int main()
{
    SinglyLL<int>sobj;
    int iRet =  0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);
    iRet = sobj.Count();
    cout<<"Count is : "<< iRet << endl;
    sobj.Display();
    
    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);
    iRet = sobj.Count();
    cout<<"Count is : "<< iRet << endl;
    sobj.Display();


    sobj.InsertAtPos(75 , 4);
    iRet = sobj.Count();
    cout<<"Count is : "<< iRet << endl;
    sobj.Display();
    
    sobj.DeleteAtPos( 4);
    iRet = sobj.Count();
    cout<<"Count is : "<< iRet << endl;
    sobj.Display();
    
    sobj.DeleteFirst();
    iRet = sobj.Count();
    cout<<"Count is : "<< iRet << endl;
    sobj.Display();
    
    sobj.DeleteLast();
    iRet = sobj.Count();
    cout<<"Count is : "<< iRet << endl;
    sobj.Display();

    return 0;
}