//1043 MIns

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
            newn->next =head;
            head = newn;
        }
        iCount++;
    }

    int pop()
    {
        int no = 0;

        if(head == NULL)
        {
            cout<<"Stack is Empty\n";
            return no;
        }
        else if(head ->next ==NULL)
        {
            no = head->data;
            delete head;
            head = NULL;
        }
        else
        {
            no = head->data;
            PNODE temp = head;
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
        if(head ==NULL)
        {
            cout<<"stack is empty\n";
            return;
        }

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
    sobj.Display();
    iRet = sobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    
    iRet = sobj.pop();
    cout<<"Popped element is :"<<iRet<<endl;
    sobj.Display();
    iRet = sobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    
    iRet = sobj.pop();
    cout<<"Popped element is :"<<iRet<<endl;
    sobj.Display();
    iRet = sobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    
    iRet = sobj.pop();
    cout<<"Popped element is :"<<iRet<<endl;
    sobj.Display();
    iRet = sobj.Count();
    cout<<"COunt is :"<<iRet<<endl;

    return  0;
}