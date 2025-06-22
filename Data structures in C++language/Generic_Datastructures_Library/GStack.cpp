// specific 14.01 mins
// specific 17.24 mins
#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node<T> * next;
};


template<class T>
class GStack
{
    public:
    int iCount;
    struct node<T> * head;

    GStack();
    void push(T no);
    T pop();
    void Display();
    int Count();
};

template<class T>
GStack<T> :: GStack()
{
    head = NULL;
    iCount = 0;
}

template<class T>
void GStack<T> :: push(T no)
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

template<class T>
T GStack<T> ::pop()
{
    T no;

    if(head == NULL)
    {
        cout<<"Stack is empty\n";
        return no;
    }
    else if(head ->next == NULL)
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

template<class T>
void GStack<T> :: Display()
{
    struct node<T> *temp = head;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |\n";
        temp = temp->next;
    }
    cout<<"\n\n";
    
}

template<class T>
int  GStack<T> ::Count()
{
    return iCount;
}


int main()
{
    GStack<float>sobj;
    float iRet = 0;

    sobj.push(60.23f);
    sobj.push(50.23f);
    sobj.push(40.23f);
    sobj.push(30.23f);
    sobj.push(20.23f);
    sobj.push(10.23f);
    iRet = sobj.Count();
    cout<<"Count is:"<<iRet<<endl;
    sobj.Display();
    
    iRet = sobj.pop();
    cout<<"Popped element is:"<<iRet<<endl;
    iRet = sobj.Count();
    cout<<"Count is:"<<iRet<<endl;
    sobj.Display();

    iRet = sobj.pop();
    cout<<"Popped element is:"<<iRet<<endl;
    iRet = sobj.Count();
    cout<<"Count is:"<<iRet<<endl;
    sobj.Display();

    iRet = sobj.pop();
    cout<<"Popped element is:"<<iRet<<endl;
    iRet = sobj.Count();
    cout<<"Count is:"<<iRet<<endl;
    sobj.Display();


    return 0;
}