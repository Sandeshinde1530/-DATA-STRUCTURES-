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

        void enqueue(int  no)
        {
            PNODE newn = NULL;
            newn =new  NODE;
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

       
        int dequeue()
        {
            int no = 0;
            if(head == NULL)
            {
                cout<<"QUeue is empty\n";
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
                PNODE temp = head;
                 
                while(temp->next->next != NULL)
                {
                    temp  = temp->next;
                }
                no = temp->next->data;
                delete temp->next;
                temp->next = NULL;
            }
            iCount--;
            return no;
        }

        void Display()
        {
            PNODE temp = head;
            
            if(head == NULL)
            {
                cout<<"QUEUE is Empty\n";
                return;
            }
            else
            {
                while (temp != NULL)
                {
                    cout<<"| "<<temp->data<<" |"<<endl;
                    temp = temp->next;
                }
                cout<<endl;
            }            
        }


        int Count()
        {
            return iCount;
        }
};

int main()
{
    Queue qobj;
    int iRet = 0;

    qobj.enqueue(51);
    qobj.enqueue(21);
    qobj.enqueue(11);
    qobj.Display();
    iRet = qobj.Count();
    cout<<"Count is ...:"<<iRet<<endl;
    
    iRet = qobj.dequeue();
    cout<<"removed element is :"<<iRet<<endl;
    qobj.Display();
    iRet = qobj.Count();
    cout<<"Count is :"<<iRet<<endl;

    iRet = qobj.dequeue();
    cout<<"removed element is :"<<iRet<<endl;
    qobj.Display();
    iRet = qobj.Count();
    cout<<"Count is :"<<iRet<<endl;

    iRet = qobj.dequeue();
    cout<<"removed element is :"<<iRet<<endl;
    qobj.Display();
    iRet = qobj.Count();
    cout<<"Count is :"<<iRet<<endl;




    return 0;
}