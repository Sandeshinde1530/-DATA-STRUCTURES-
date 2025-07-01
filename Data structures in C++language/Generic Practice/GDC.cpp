//22.18 specific
// total generic 25.45
#include<iostream>
using namespace std;

template <class T >
struct node
{
    T data;
    struct node<T> *prev;
    struct node<T> *next;    
};


template <class T >
class DoublyCircular
{
    public:
    int iCount;
    struct node<T> *head;
    struct node<T> *tail;

    DoublyCircular();
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no , int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    void Display();
    int Count();
};

template <class T >
DoublyCircular<T> :: DoublyCircular()
{
    head = NULL;
    tail = NULL;
    iCount = 0;
}

template <class T >
void DoublyCircular<T>:: InsertFirst(T no)
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

template <class T >
void DoublyCircular<T>:: InsertLast(T no)
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
        tail->next = newn;
        newn->prev = tail;
        tail = newn;
    }
    tail->next = head;
    head->prev = tail;
    iCount++;
}

template <class T >
void DoublyCircular<T>:: InsertAtPos(T no , int iPos)
{
    if( iPos < 1 || iPos > iCount + 1)
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
        struct node<T> *temp = head;
        struct node<T> *newn = NULL;
        newn = new node<T>;
        newn->data = no;
        newn->prev = NULL;
        newn->next = NULL;

        for(int i = 1 ; i <iPos - 1 ; i++)
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

template <class T >
void DoublyCircular<T>:: DeleteFirst()
{
    if(head == NULL && tail == NULL)
    {
       cout<<"list is empty\n";
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

template <class T >
void DoublyCircular<T>:: DeleteLast()
{
    if(head == NULL && tail == NULL)
    {
       cout<<"List is empty\n";
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

template <class T >
void DoublyCircular<T>:: DeleteAtPos(int iPos)
{
    if( iPos < 1 || iPos > iCount)
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
        struct node<T> *temp = head;
        struct node<T> *target = NULL;

        for(int i = 1 ; i <iPos - 1 ; i++)
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

template <class T >
void DoublyCircular<T>:: Display()
{
    if(head == NULL && tail == NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    struct node<T> *temp = head;
    cout<<"Elements of List Sequentially:\n";

    do
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    } while (temp != head);
    cout<<endl;

   temp = tail;
    cout<<"Elements of List Sequentially:\n";

    do
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->prev;
    } while (temp != tail);
    cout<<endl;
    cout<<endl;
}

template <class T >
int DoublyCircular<T>:: Count()
{
    return iCount;
}


int main()
{
    DoublyCircular <float>dobj;
    int iRet = 0;

    dobj.InsertFirst(30.3265f);
    dobj.InsertFirst(20.3265f);
    dobj.InsertFirst(10.3265f);
    iRet = dobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    dobj.Display();

    dobj.InsertLast(40.3265f);
    dobj.InsertLast(50.3265f);
    dobj.InsertLast(60.3265f);
    iRet = dobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    dobj.Display();

    dobj.InsertAtPos(35.3265f , 4);
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