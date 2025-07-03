//19.34 MIns
//22.35
#include<iostream>

using namespace std;

template<class T>
struct node
{
    T data;
    struct node<T> *next;
};


template<class T>
class GSL1
{
    public:
        struct node<T> *head;
        int iCount;

        GSL1();
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
GSL1<T> :: GSL1()
{
    head = NULL;
    iCount = 0;
}

template<class T>
void GSL1<T> :: InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;

    if(head ==NULL)
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

template<class T>
void GSL1<T> :: InsertLast(T no)
{
    struct node<T> *temp = head;
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;

    if(head ==NULL)
    {
        head = newn;
    }
    else
    {
        while(temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template<class T>
void GSL1<T> :: InsertAtPos(T no , int iPos)
{
    if(iPos < 1 || iPos > iCount + 1)
    {
        cout<<"Invalid Position\n";
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

        for(int i = 1 ; i < iPos -1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    iCount++;
    
}

template<class T>
void GSL1<T> :: DeleteFirst()
{
    if(head == NULL) 
    {
        cout<<"List is empty\n";
        return;
    }
    else if(head ->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        struct node<T> *temp = head;
        head = temp->next;
        delete temp;
    }
    iCount--;
}

template<class T>
void GSL1<T> :: DeleteLast()
{
    if(head == NULL) 
    {
        cout<<"List is empty\n";
        return;
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

template<class T>
void GSL1<T> :: DeleteAtPos(int iPos)
{
    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position\n";
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

        for(int i = 1 ; i < iPos -1 ; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next  = target ->next;
        delete target;
    }
    iCount--;
}

template<class T>
void GSL1<T> :: Display()
{
    if( head == NULL)
    {
        cout<<"List is empty\n";
        return;
    }

    struct node<T> *temp = head;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template<class T>
int GSL1<T> :: Count()
{
    return iCount;
}


int main()
{
    GSL1<float>gobj;
    int iRet = 0;

    gobj.InsertFirst(51.1234f);
    gobj.InsertFirst(21.1234f);
    gobj.InsertFirst(11.1234f);
    iRet = gobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    gobj.Display();

    gobj.InsertLast(101.1234f);
    gobj.InsertLast(111.1234f);
    gobj.InsertLast(121.1234f);
    iRet = gobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    gobj.Display();

    gobj.InsertAtPos(75.1234f , 4);
    iRet = gobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    gobj.Display();

    gobj.DeleteAtPos(4);
    iRet = gobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    gobj.Display();

    gobj.DeleteFirst();
    iRet = gobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    gobj.Display();

    gobj.DeleteLast();
    iRet = gobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    gobj.Display();



    return 0;
}