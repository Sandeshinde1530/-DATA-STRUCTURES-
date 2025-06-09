#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE , *PNODE , **PPNODE;

class Queue
{
    public :
        int iCount;
        PNODE head;

        Queue()
        {
            iCount = 0;
            head = NULL;
        }

        void enqueue(int no)
        {
            PNODE newn = NULL;
            PNODE temp = head;

            newn = new NODE;
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

        int dequeue()
        {
            int no= -1;
            if(head == NULL)
            {
                cout<<"Queue is Empty\n";
                return no;
            }
            else if((head)->next == NULL)
            {
                no = (head)->data;
                delete head;
                head = NULL;        
            }
            else
            {
                no = (head)->data;
                PNODE temp = head;
                head = temp->next;

                delete temp;
            }
            iCount--;
            return no;
        }

        void Display()
        {
            PNODE temp = head;
            while(temp != NULL)
            {
                cout<<"| "<<temp->data<<"|\n";
                temp = temp->next;
            }
        }

        int Count()
        {
            return iCount;
        }

};


int main()
{
    int iRet = 0;
    Queue qobj;

    qobj.enqueue(11);
    qobj.Display();
    iRet = qobj.Count();
    cout<<"count is:"<<iRet<<endl;
    qobj.enqueue(21);
    qobj.Display();
    iRet = qobj.Count();
    cout<<"count is:"<<iRet<<endl;
    qobj.enqueue(51);
    qobj.Display();
    iRet = qobj.Count();
    cout<<"count is:"<<iRet<<endl;
    
    qobj.enqueue(101);
    qobj.enqueue(111);
    qobj.enqueue(121);
    qobj.Display();
    iRet = qobj.Count();
    cout<<"count is:"<<iRet<<endl;
    
    iRet = qobj.dequeue();
    cout<<"Removed Element is :"<<iRet<<endl;
    qobj.Display();
    iRet = qobj.Count();
    cout<<"count is:"<<iRet<<endl;
    
    
    iRet = qobj.dequeue();
    cout<<"Removed Element is :"<<iRet<<endl;
    qobj.Display();
    iRet = qobj.Count();
    cout<<"count is:"<<iRet<<endl;
    
    iRet = qobj.dequeue();
    cout<<"Removed Element is :"<<iRet<<endl;
    qobj.Display();
    iRet = qobj.Count();
    cout<<"count is:"<<iRet<<endl;
    
    iRet = qobj.dequeue();
    cout<<"Removed Element is :"<<iRet<<endl;
    qobj.Display();
    iRet = qobj.Count();
    cout<<"count is:"<<iRet<<endl;

    return 0;
}