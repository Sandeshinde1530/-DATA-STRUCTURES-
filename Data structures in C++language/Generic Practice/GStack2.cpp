//specific 12.09
// total with generic  15.7 Mins
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node<T> *next;
};


template <class T>
class GStack2
{
    public:
    struct node<T> *head;
    int iCount ;

    GStack2();
    void push(T no);
    T pop();
    void Display();
    int Count();
};


template <class T>
GStack2<T> :: GStack2 ()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void GStack2<T> :: push(T no)
{
    struct node<T>  *newn = NULL;
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
T  GStack2<T> :: pop()
{
    int no = 0;

    if(head ==NULL)
    {
        cout<<"LIst is empty\n";
        return no;
    }
    else if(head ->next == NULL)
    {
        no = head->data;
        delete head;
        head  = NULL;
    }
    else
    {
        no = head->data;
        struct node<T> *temp = head;
        head= temp->next;
        delete temp;
    }
    iCount--;
    return no;
}


template <class T>
void GStack2<T> :: Display()
{
    if(head == NULL)
    {
        cout<<"List is empty \n";
        return;
    }

    struct node<T> *temp = head;

    cout<<"Our Stack is :\n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |\n";
        temp =temp->next;
    }

    cout<<endl;
    cout<<endl;
}

template <class T>
int GStack2<T> :: Count()
{
    return iCount;
}

int main()
{
    GStack2<float> sobj;
    int iRet = 0;

    sobj.push(50.23265f);
    sobj.push(40.23265f);
    sobj.push(30.23265f);
    sobj.push(20.23265f);
    sobj.push(10.23265f); 
    iRet  = sobj.Count();
    cout<<"count is : "<<iRet<<endl;
    sobj.Display();
    
    iRet = sobj.pop();
    cout<<"Popped element is : "<<iRet<<endl;
    iRet  = sobj.Count();
    cout<<"count is : "<<iRet<<endl;
    sobj.Display();
    
    iRet = sobj.pop();
    cout<<"Popped element is : "<<iRet<<endl;
    iRet  = sobj.Count();
    cout<<"count is : "<<iRet<<endl;
    sobj.Display();
    
    iRet = sobj.pop();
    cout<<"Popped element is : "<<iRet<<endl;
    iRet  = sobj.Count();
    cout<<"count is : "<<iRet<<endl;
    sobj.Display();

    return 0;
}