// specific 22.22 Mins
// Generic  28.53 Mins

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node<T>*prev;
    struct node<T>*next;
};

template <class T>
class GDoublyCircular
{
    public:
    int  iCount;
    struct node<T> *head;
    struct node<T> *tail;

    GDoublyCircular();
    void InsertFirst(T no);
    void InsertLast(T no);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void InsertAtPos(T no , int iPos);
    void DelteAtPos(int iPos);
};

template <class T>
GDoublyCircular<T> :: GDoublyCircular()
{
    iCount = 0 ;
    head = NULL;
    tail = NULL;
}

template <class T>
void GDoublyCircular<T> :: InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

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
void GDoublyCircular<T> :: InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

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
void GDoublyCircular<T> :: DeleteFirst()
{
    if(head == NULL && tail == NULL)
    {
        return ;
    }
    else if( head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        head  = head->next;
        delete head->prev;
    }
    tail->next = head;
    head->prev = tail;
    iCount--;
}

template <class T>
void GDoublyCircular<T> :: DeleteLast()
{
    if(head == NULL && tail == NULL)
    {
        return ;
    }
    else if( head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail = tail ->prev ;
        delete tail->next;
    }
    tail->next = head;
    head->prev = tail;
    iCount--;
}

template <class T>
void GDoublyCircular<T> :: Display()
{
    struct node<T>* temp = head;

    cout<<"ELements of list\n";
    do
    {
        cout<<"| "<<temp->data<<" |";
        temp = temp->next;
    } while (temp != tail->next);
    cout<<endl;
    temp = tail;
    cout<<"REVERSED\n";
    do
    {
        cout<<"| "<<temp->data<<" |";
        temp = temp->prev;
    } while (temp != head->prev);
    cout<<endl;cout<<endl;
}

template <class T>
int  GDoublyCircular<T> :: Count()
{
    return iCount;
}

template <class T>
void GDoublyCircular<T> :: InsertAtPos(T no , int iPos)
{
    if(iPos < 1  || iPos > iCount + 1)
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
        struct node<T>*temp = head;
        struct node<T>*newn = NULL;

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

        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void GDoublyCircular<T> :: DelteAtPos(int iPos)
{
    if(iPos < 1  || iPos > iCount)
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
        struct node<T>*temp = head;
        struct node<T>*target = NULL;

        for(int i = 1 ; i <iPos - 1 ; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        
        delete target;
    }
    iCount--;
}


int main()
{
    GDoublyCircular <float> gdcobj;
    int iRet = 0;

    gdcobj.InsertFirst(51.43f);
    gdcobj.InsertFirst(21.43f);
    gdcobj.InsertFirst(11.43f);
    iRet = gdcobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    gdcobj.Display();

    gdcobj.InsertLast(101.43f);
    gdcobj.InsertLast(111.43f);
    gdcobj.InsertLast(121.43f);
    iRet = gdcobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    gdcobj.Display();
    
    gdcobj.InsertAtPos(75.33f,4);
    iRet = gdcobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    gdcobj.Display();
    
    gdcobj.DelteAtPos(4);
    iRet = gdcobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    gdcobj.Display();
    
    gdcobj.DeleteFirst();
    iRet = gdcobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    gdcobj.Display();
    
    gdcobj.DeleteFirst();
    iRet = gdcobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    gdcobj.Display();

    return 0;
}