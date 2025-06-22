// specific 15.01 MIns
// specific 20.16 MIns
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node<T> *next;
};


template <class T>
class GQueue
{
    public:
        int iCount;
        struct node<T>*head;

        GQueue();
        void enqueue(T no);
        T dequeue();
        void Display();
        int Count();
};

template <class T>
GQueue<T> :: GQueue()
{
    iCount = 0;
    head = NULL;
}  

template <class T>
void GQueue<T> :: enqueue(T no)
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
        struct node<T> *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
T GQueue<T> :: dequeue()
{
    T no = 0;
    if(head == NULL)
    {
        return no;
    }
    else if(head->next ==NULL)
    {
        no = head->data;
        delete head;
        head = NULL;
    }
    else
    {
        no = head->data;
        struct node<T>* temp = head;

        head = temp->next;
        delete temp;
    }
    iCount--;
    return no;
}

template <class T>
void GQueue<T> :: Display()
{
    struct node<T>*temp = head;

    while(temp != NULL)
    {
         cout<<"| "<<temp->data<<" |"<<endl;
         temp = temp->next;
    }
    cout<<endl;
    cout<<endl;   
}

template <class T>
int GQueue<T> :: Count()
{
    return iCount;
}


int main()
{
    GQueue<float> qobj;
    float iRet = 0.0f;

    qobj.enqueue(11.033f);
    qobj.enqueue(21.033f);
    qobj.enqueue(51.033f);
    qobj.enqueue(101.033f);
    qobj.enqueue(111.033f);
    qobj.enqueue(121.033f);
    iRet = qobj.Count();
    cout<<"Count is:"<<iRet<<endl;
    qobj.Display();
    
    iRet  = qobj.dequeue();
    cout<<"Removed Element is:"<<iRet<<endl;
    iRet = qobj.Count();
    cout<<"Count is:"<<iRet<<endl;
    qobj.Display();
    
    iRet  = qobj.dequeue();
    cout<<"Removed Element is:"<<iRet<<endl;
    iRet = qobj.Count();
    cout<<"Count is:"<<iRet<<endl;
    qobj.Display();
   
    iRet  = qobj.dequeue();
    cout<<"Removed Element is:"<<iRet<<endl;
    iRet = qobj.Count();
    cout<<"Count is:"<<iRet<<endl;
    qobj.Display();


    return  0;
}
