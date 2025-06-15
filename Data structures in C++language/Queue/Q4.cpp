//15.12 Mins
#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE , *PNODE , **PPNODE;


class Queue
{
    public:
    int iCount;
    PNODE head;

    Queue()
    {
        iCount = 0;
        head = NULL;
    }

    void enqueue(int no)
    {

        PNODE temp = NULL;
        PNODE newn = NULL;

        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        if(head == NULL)
        {
            head = newn;
        }
        else
        {
            temp = head;
             while(temp->next != NULL)
             {
                temp = temp->next;
             }
             temp->next = newn;
        }
        iCount++;
    }

    int dequeue()
    { 
        int no = 0;
        if(head == NULL)
        {
            cout<<"Queue is empty\n";
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
            PNODE temp = head;
            head = temp->next;
            delete temp;
        }
        iCount--;
        return no;
    }

    int Count()
    {
        return iCount;
    }

    void Display()
    {
        PNODE temp = head;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |"<<endl;
            temp = temp->next;
        }
        cout<<endl;
        cout<<endl;

    }

};
int main()
{
    Queue qobj;
    int iRet = 0;

    qobj.enqueue(10);
    qobj.enqueue(20);
    qobj.enqueue(30);
    qobj.enqueue(40);
    qobj.enqueue(50);

    iRet = qobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    qobj.Display();
    
    iRet = qobj.dequeue();
    cout<<"removed element is :"<<iRet<<endl;
    iRet = qobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    qobj.Display();
    
    iRet = qobj.dequeue();
    cout<<"removed element is :"<<iRet<<endl;
    iRet = qobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    qobj.Display();


    return 0;
}