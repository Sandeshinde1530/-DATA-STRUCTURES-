//12.6 Min
#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE , *PNODE;

class Queue
{
    public:
        PNODE head;
        int iCount;

        Queue()
        {
            head = NULL;
            iCount = 0;
        }

        void enqueue(int no)
        {
            PNODE newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                PNODE temp = head;

                while(temp->next != NULL)
                {
                    temp  = temp->next;
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
                cout<<"Queue is Empty\n";
            }
            else if(head ->next == NULL)
            {
                no = head->data;
                delete head;
                head = NULL;
            }
            else
            {
                PNODE temp = head;
                no = temp ->data;
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

            while(temp!= NULL)
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

    qobj.enqueue(12);
    qobj.enqueue(13);
    qobj.enqueue(14);
    iRet = qobj.Count();
    cout<<"count is :"<<iRet<<endl;
    qobj.Display();
    
    qobj.enqueue(15);
    qobj.enqueue(16);
    qobj.enqueue(17);
    iRet = qobj.Count();
    cout<<"count is :"<<iRet<<endl;
    qobj.Display();
    
    iRet = qobj.dequeue();
    cout<<"removed element is :"<<iRet<<endl;
    iRet = qobj.Count();
    cout<<"count is :"<<iRet<<endl;
    qobj.Display();
    iRet = qobj.dequeue();
    cout<<"removed element is :"<<iRet<<endl;
    iRet = qobj.Count();
    cout<<"count is :"<<iRet<<endl;
    qobj.Display();
    iRet = qobj.dequeue();
    cout<<"removed element is :"<<iRet<<endl;
    iRet = qobj.Count();
    cout<<"count is :"<<iRet<<endl;
    qobj.Display();


    return 0 ;
}