#include<iostream>

using namespace std;


template <class T>
struct node
{
    T data;
    struct node<T> *prev;
    struct node<T> *next;
};


template <class T>
class DoublyLinear
{
    public:
        int iCount;
        struct node<T> *head ;

        DoublyLinear();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no , int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        void Display();
        int Count();
};


template <class T>
DoublyLinear<T> ::  DoublyLinear()
{
    iCount = 0;
    head = NULL;    
}

template <class T>
void DoublyLinear<T> :: InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

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

template <class T>
void DoublyLinear<T> :: InsertLast(T no)
{
    struct node<T> *temp = head;
    struct node<T> *newn = NULL;
    newn = new node<T>;

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
            temp = temp->next;
        }   
        temp->next = newn;
        newn->prev = temp;  
    }  
    iCount++;
}

template <class T>
void DoublyLinear<T> :: InsertAtPos(T no , int iPos)
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
        struct node<T> *temp = head;
        struct node<T> *newn = NULL;

        newn = new node<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (int i = 1 ; i < iPos - 1 ; i++)
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

template <class T>
void DoublyLinear<T> :: DeleteFirst()
{
     if(head == NULL)
     {
        return;
     }
     else if(head ->next == NULL)
     {
        delete head;
        head == NULL;
     }
     else
     {
        head = head->next;
        delete head->prev;
        head->prev =  NULL;
     }
     iCount--;
}

template <class T>
void DoublyLinear<T> :: DeleteLast()
{
    struct node<T> *temp = head;

    if(head == NULL)
     {
        return;
     }
     else if(head ->next ==  NULL)
     {
        delete head;
        head == NULL;
     }
     else
     {
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
void DoublyLinear<T> :: DeleteAtPos(int iPos)
{
        if(iPos <1 ||  iPos > iCount)
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
        struct node<T> *temp = head;
        struct node<T> *target = NULL;

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

template <class T>
void DoublyLinear<T> :: Display()
{
        struct node<T> * temp = head;

        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" | <=>";
            temp = temp->next;
        }
        cout<<endl;
}


template <class T>
int DoublyLinear<T> :: Count()
{
    return iCount;
}

int main()
{
    DoublyLinear <float>dobj;
    int iRet = 0;

    dobj.InsertFirst(51.054f);
    dobj.InsertFirst(21.054f);
    dobj.InsertFirst(11.054f);
    iRet = dobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    dobj.Display();

    dobj.InsertLast(101.054f);
    dobj.InsertLast(111.054f);
    dobj.InsertLast(121.054f);
    iRet = dobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    dobj.Display();

    dobj.InsertAtPos(75.054f , 4);
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


    return 0;
}