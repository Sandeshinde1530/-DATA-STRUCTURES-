//13.30 Mins
#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE , *PNODE;

class Stack
{
    public:
        int iCount;
        PNODE head;

        Stack()
        {
            iCount = 0;
            head = NULL;
        }

        void push(int no)
        {
            PNODE newn = NULL;
            
            newn = new NODE;
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

        int pop()
        {
            int no = -1;

            if(head == NULL)
            {
                cout<<"Stack is Empty\n";
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
                no = temp->data;
                head = head->next;

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
            cout<<"Elements of Stack are:\n";
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
    Stack sobj;
    int iRet = 0;

    sobj.push(51);
    sobj.push(21);
    sobj.push(11);
    iRet  = sobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    sobj.Display();
    
    sobj.push(200);
    sobj.push(300);
    sobj.push(400);
    iRet  = sobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    sobj.Display();
    
    iRet = sobj.pop();
    cout<<"Popped element is :"<<iRet<<endl;
    iRet  = sobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    sobj.Display();
    
    iRet = sobj.pop();
    cout<<"Popped element is :"<<iRet<<endl;
    iRet  = sobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    sobj.Display();
    iRet = sobj.pop();
    cout<<"Popped element is :"<<iRet<<endl;
    iRet  = sobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    sobj.Display();
    iRet = sobj.pop();
    cout<<"Popped element is :"<<iRet<<endl;
    iRet  = sobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    sobj.Display();

    return 0;
}