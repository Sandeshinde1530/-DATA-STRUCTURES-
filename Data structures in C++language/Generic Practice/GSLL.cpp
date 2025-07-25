//24.15 Mins For Specific
// complete for generic 26.28
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node<T> *next;
};


template <class T>
class GSLL
{
    public :
        int iCount;
        struct node<T> *head;

    GSLL();
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
GSLL<T> :: GSLL  ()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void GSLL<T> ::  InsertFirst(T no)
{
    struct node<T> *newn = NULL;

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
void GSLL<T> ::  InsertLast(T no)
{
    struct node<T> *newn = NULL;
    struct node<T> *temp = head;

    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
       while(temp->next != NULL)
       {
        temp = temp->next;
       }
       temp->next = newn;
    }
    iCount++;
}

template <class T>
void GSLL<T> ::  InsertAtPos(T no , int iPos)
{
    struct node<T> *newn = NULL;
    struct node<T> *temp = head;

    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;

    if(iPos < 1 || iPos > iCount + 1)
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
       for(int i = 1 ; i < iPos - 1 ; i++)
       {
        temp = temp->next;
       }

       newn->next = temp->next;
       temp->next = newn;
    }
    iCount++;

}

template <class T>
void GSLL<T> ::  DeleteFirst()
{
    struct node<T> *temp = head;

    if(head == NULL)
    {
        cout<<"List is Empty\n";
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        head = temp->next ;
        delete temp;
    }
    iCount--;

}

template <class T>
void GSLL<T> ::  DeleteLast()
{
    struct node<T> *temp = head;

    if(head == NULL)
    {
        cout<<"List is Empty\n";
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
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
void GSLL<T> ::  DeleteAtPos(int iPos)
{
    struct node<T> *target = NULL;
    struct node<T> *temp = head;

    if(iPos < 1 || iPos > iCount)
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
       for(int i = 1 ; i < iPos - 1 ; i++)
       {
        temp = temp->next;
       }
       target = temp->next;
       temp->next = target->next;
       delete target;
    }
    iCount--;
}

template <class T>
void GSLL<T> ::  Display()
{
    struct node<T> *temp = head;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<endl;
}

template <class T>
int GSLL<T> ::  Count()
{
    return iCount;
}


int main()
{
    GSLL<float> sobj;
    int iRet = 0;

    sobj.InsertFirst(51.13f);
    sobj.InsertFirst(21.13f);
    sobj.InsertFirst(11.13f);
    iRet = sobj.Count();
    cout<<"Count is : "<< iRet<<endl;
    sobj.Display();

    sobj.InsertLast(101.132f);
    sobj.InsertLast(111.132f);
    sobj.InsertLast(121.132f);
    iRet = sobj.Count();
    cout<<"Count is : "<< iRet<<endl;
    sobj.Display();   
    
    sobj.InsertAtPos(75.134f , 4);
    iRet = sobj.Count();
    cout<<"Count is : "<< iRet<<endl;
    sobj.Display();  
    
    sobj.DeleteAtPos(4);
    iRet = sobj.Count();
    cout<<"Count is : "<< iRet<<endl;
    sobj.Display();  
    
    sobj.DeleteFirst();
    iRet = sobj.Count();
    cout<<"Count is : "<< iRet<<endl;
    sobj.Display();  
    
    sobj.DeleteLast();
    iRet = sobj.Count();
    cout<<"Count is : "<< iRet<<endl;
    sobj.Display();  

    return 0;
}