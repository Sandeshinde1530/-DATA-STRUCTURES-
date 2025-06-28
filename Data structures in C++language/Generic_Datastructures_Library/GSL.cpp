//specific 21.11 MIns
//total generic 24.32

#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node<T> *next;
};

template<class T>
class GSL
{
    public:
    int iCount;
    struct node<T> *head;
    struct node<T> *tail;

    GSL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no , int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    void Display();
    int Count();
};



template<class T>
GSL<T> ::GSL()
{
    head = NULL;
    tail = NULL;
    iCount = 0;
}

template<class T>
void GSL<T> ::  InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL && tail == NULL)
    {
        head = newn;
        tail = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    tail->next = head;
    iCount++;

}

template<class T>
void GSL<T> ::  InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL && tail ->next == NULL)
    {
        head = newn;
        tail = newn;
    }
    else
    {
        tail->next = newn;
        tail = newn;
    }
    tail->next = head;
    iCount++;
}

template<class T>
void GSL<T> ::  InsertAtPos(T no , int iPos)
{
    if(iPos < 1 || iPos > iCount + 1)
    {
        cout<<"invalid position\n";
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

        for(int i = 1 ; i< iPos - 1 ;i++ )
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;        
    }
}

template<class T>
void GSL<T> ::  DeleteFirst()
{
    if( head == NULL && tail == NULL)
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
        head = head->next;
        delete tail->next;
    }
    tail->next = head;
    iCount--;
}

template<class T>
void GSL<T> ::  DeleteLast()
{
    if( head == NULL && tail == NULL)
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
        struct node<T> *temp = head;
        
        while(temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
    }
    tail->next = head;
    iCount--;
}

template<class T>
void GSL<T> ::  DeleteAtPos(int iPos)
{
    if(iPos < 1 || iPos > iCount)
    {
        cout<<"invalid position\n";
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

        for(int i = 1 ; i< iPos - 1 ;i++ )
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        iCount--;        
    }
}

template<class T>
void GSL<T> ::  Display()
{
    if(head == NULL && tail == NULL)
    {
        cout<<"List is empty\n";
    }
    cout<<"Elements of list are: \n";

    struct node<T> *temp = head;
    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    } while (temp!=head);
    cout<<endl;
    cout<<endl;
}

template<class T>
int GSL<T> :: Count()
{
    return iCount;
}


int main()
{
    GSL<float> sobj;
    int iRet = 0;

    sobj.InsertFirst(51.254f);
    sobj.InsertFirst(21.254f);
    sobj.InsertFirst(11.254f);
    iRet = sobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    sobj.Display();
    
    sobj.InsertLast(101.254f);
    sobj.InsertLast(111.254f);
    sobj.InsertLast(121.254f);
    iRet = sobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    sobj.Display();
    
    sobj.InsertAtPos(75.254f , 4);
    iRet = sobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    sobj.Display();
    
    sobj.DeleteAtPos( 4);
    iRet = sobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    sobj.Display();
    
    sobj.DeleteFirst();
    iRet = sobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    sobj.Display();
    
    sobj.DeleteLast();
    iRet = sobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    sobj.Display();

    return 0;
}