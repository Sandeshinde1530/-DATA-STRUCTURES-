//Specific 21.44Mins
//Gemneric 26.37Mins
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node<T>* next;
};

template <class T>
class SinglyCircular
{
    public :
    int iCount;
    struct node<T>* head; 
    struct node<T>* tail; 

    SinglyCircular();
    void InsertFirst(T no);
    void InsertLast(T no);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void InsertAtPos(T no , int iPos);
    void DeleteAtPos(int iPos);
};

template <class T>  
SinglyCircular<T> :: SinglyCircular()
{
    iCount = 0 ;
    head = NULL;
    tail = NULL;
}

template <class T>  
void SinglyCircular<T> :: InsertFirst(T no)
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

template <class T>  
void SinglyCircular<T> :: InsertLast(T no)
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
        tail->next = newn;
        tail = newn;
    }
    tail->next = head;
    iCount++;
}

template <class T>  
void SinglyCircular<T> :: DeleteFirst()
{
    if(head == NULL && tail == NULL)
    {
        return ;
    }
    else if( head == tail)
    {
        delete head;
        head = NULL;
        tail =  NULL;
    }
    else
    {
        head = head->next;
        delete tail->next;
    }
    tail->next =  head;
    iCount--;
}

template <class T>  
void SinglyCircular<T> :: DeleteLast()
{
    struct node<T> *temp = NULL;
        if(head == NULL && tail == NULL)
    {
        return ;
    }
    else if( head == tail)
    {
        delete head;
        head = NULL;
        tail =  NULL;
    }
    else
    {
        temp = head;

        while(temp->next != tail)
        {
            temp = temp->next;
        }
    delete tail;
    tail = temp;
    }
    tail->next =  head;
    iCount--;
}

template <class T>  
void SinglyCircular<T> :: Display()
{
    struct node<T> *temp = head;

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }while(temp != tail->next);
    cout<<endl;
    cout<<endl;
}

template <class T>  
int  SinglyCircular<T> :: Count()
{
    return iCount;
}

template <class T>  
void SinglyCircular<T> :: InsertAtPos(T no , int iPos)
{
    if(iPos < 1 ||iPos > iCount + 1)
    {
        cout<<"List is empty";
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
        struct node<T>*temp = head;
        struct node<T>*newn = NULL;

        newn = new node<T>;
        newn->data = no;
        newn->next = NULL;

        for(int i = 1 ; i<iPos - 1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    iCount++;
}

template <class T>  
void SinglyCircular<T> :: DeleteAtPos(int iPos)
{
    if(iPos < 1 ||iPos > iCount)
    {
        cout<<"List is empty";
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
        struct node<T>*temp = head;
        struct node<T>*target = NULL;

        for(int i = 1 ; i<iPos - 1 ; i++)
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
    SinglyCircular<char> scobj;
    int iRet = 0 ;

    scobj.InsertFirst('f');
    scobj.InsertFirst('f');
    scobj.InsertFirst('f');
    iRet = scobj.Count();
    cout<<"Countj is :"<<iRet<<endl;
    scobj.Display();

    scobj.InsertLast('f');
    scobj.InsertLast('f');
    scobj.InsertLast('f');
    iRet = scobj.Count();
    cout<<"Countj is :"<<iRet<<endl;
    scobj.Display();
    
    scobj.InsertAtPos('H' , 4);
    iRet = scobj.Count();
    cout<<"Countj is :"<<iRet<<endl;
    scobj.Display();
    
    scobj.DeleteAtPos(4);
    iRet = scobj.Count();
    cout<<"Countj is :"<<iRet<<endl;
    scobj.Display();
    
    scobj.DeleteFirst();
    iRet = scobj.Count();
    cout<<"Countj is :"<<iRet<<endl;
    scobj.Display();
    
    scobj.DeleteLast();
    iRet = scobj.Count();
    cout<<"Countj is :"<<iRet<<endl;
    scobj.Display();

    return 0;
}