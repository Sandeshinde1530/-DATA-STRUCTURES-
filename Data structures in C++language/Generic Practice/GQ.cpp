//specific 12.52
// total generic 15.42
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node<T> *next;
};

template <class T>
class GQ
{
    public:
    int iCount;
    struct node<T> *head;

    GQ();
    void enqueue(T no);
    T dequeue();
    void Display();
    int Count();
};

template <class T>
GQ<T> :: GQ()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void GQ<T> :: enqueue(T no)
{
    struct node<T> *newn = NULL;
    struct node<T> *temp = head;

    newn = new node<T>;
    newn->data = no;
    newn->next= NULL;

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
T GQ<T> :: dequeue()
{
    T no ;

    if(head == NULL)
    {
        cout<<"List is empty\n";
        return no;
    }
    else if(head->next == NULL)
    {
        no = head->data;
        delete head;
        head = NULL;
    }
    else
    {
        no = head->data;
        struct node<T> *temp = head;
        head = temp->next;
        delete temp;
    }
    iCount--;
    return no;
}

template <class T>
void GQ<T> :: Display()
{
    if(head ==NULL)
    {
        cout<<"List is empty\n";
        return ;
    }
    struct node<T> *temp = head;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |\n";
        temp = temp->next;
    }
    cout<<endl;
}

template <class T>
int  GQ<T> ::Count()
{
    return iCount;
}

int main()
{
    GQ<float>gobj;
    int iRet = 0;

    gobj.enqueue(11.213f);
    gobj.enqueue(21.213f);
    gobj.enqueue(51.213f);
    iRet = gobj.Count();
    cout<<"Count is :"<< iRet<<endl;
    gobj.Display();

    gobj.enqueue(101.213f);
    gobj.enqueue(111.213f);
    gobj.enqueue(121.213f);
    iRet = gobj.Count();
    cout<<"Count is :"<< iRet<<endl;
    gobj.Display();
    
    gobj.dequeue();
    iRet = gobj.Count();
    cout<<"Count is :"<< iRet<<endl;
    gobj.Display();
    
    gobj.dequeue();
    iRet = gobj.Count();
    cout<<"Count is :"<< iRet<<endl;
    gobj.Display();

    return 0;
}
