//29.16 mins Specific
//32.01 GENERIC Complete;

#include<iostream>
using namespace std;

template <class T>
struct node 
{
    T data;
    struct node<T> *prev ;
    struct node<T> *next ;
};


template <class T>
class GDC
{
    public :
        struct node<T> *head;
        struct node<T> *tail;
        int iCount;

    GDC();
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
GDC<T> :: GDC()
{
    head = NULL;
    tail = NULL;
    iCount= 0;
}

template <class T>
void GDC<T> ::  InsertFirst(T no)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;
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
    tail->next = head;
    head->prev = tail;
    iCount++;
}

template <class T>
void GDC<T> ::  InsertLast(T no)
{
        struct node<T> *newn = NULL;

    newn = new node<T>;
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
    tail->next = head;
    head->prev = tail;
    iCount++;
}

template <class T>
void GDC<T> ::  InsertAtPos(T no , int iPos)
{
    if(iPos <1 || iPos > iCount + 1)
    {
        cout<<"Invalid Position\n";
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
        struct node<T> *newn = NULL;
        struct node<T> *temp = head;
        
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

        temp->next = newn;
        newn->prev = temp;
        iCount++;
    }
}

template <class T>
void GDC<T> ::  DeleteFirst()
{
    if(head == NULL && tail == NULL)
    {
        cout<<"List is empty\n";
        return ;
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

template <class T>
void GDC<T> ::  DeleteLast()
{
        if(head == NULL && tail == NULL)
    {
        cout<<"List is empty\n";
        return ;
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

template <class T>
void GDC<T> ::  DeleteAtPos(int iPos)
{
     if(iPos <1 || iPos > iCount)
    {
        cout<<"Invalid Position\n";
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
        struct node<T> *target = NULL;
        struct node<T> *temp = head;        

        for(int i = 1 ; i< iPos - 1 ; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
       
        iCount--;
    }
}

template <class T>
void GDC<T> ::  Display()
{
    struct node<T> *temp = head;
    cout<<"Linear : \n";
    do
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    } while (temp != head);
    cout<<endl;
    cout<<endl;
    
    temp = tail;
    cout<<"Reversed : \n";
    do
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->prev;
    } while (temp != tail);
    
    cout<<endl;
    cout<<endl;
}

template <class T>
int GDC<T> :: Count()
{
    return iCount;
}


int main()
{
    GDC<float>dobj;
    int iRet = 0;

    dobj.InsertFirst(51.123);
    dobj.InsertFirst(21.123);
    dobj.InsertFirst(11.123);
    iRet = dobj.Count();
    cout<<"Count is : "<<iRet<<endl;
    dobj.Display();

    dobj.InsertLast(101.135);
    dobj.InsertLast(111.135);
    dobj.InsertLast(121.135);
    iRet = dobj.Count();
    cout<<"Count is : "<<iRet<<endl;
    dobj.Display();
    
    dobj.InsertAtPos(75.156 , 4);
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