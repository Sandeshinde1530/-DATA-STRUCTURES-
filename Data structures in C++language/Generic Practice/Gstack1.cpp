//14.16
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class Gstack1
{
    public:
        struct node *head;
        int iCount;

    Gstack1();
    void push(int no);
    int pop();
    void Display();
    int Count();    
};

    Gstack1:: Gstack1()
    {
        head = NULL;
        iCount = 0;

    }

    void Gstack1::  push(int no)
    {
        struct node *newn = NULL;
        newn = new node;
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

    int Gstack1::  pop()
    {
        int no = 0;

        if(head== NULL)
        {
            cout<<"Stack is empty";
        }
        else if(head ->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            struct node* temp = head;
            no = head->data;
            head = temp->next;
            delete temp;
        }

        iCount--;
        return no;
    }

    void Gstack1::  Display()
    {
        struct node *temp = head;
        while(temp != NULL)    
        {
            cout<<"| "<<temp->data<<" |"<<endl;
            temp = temp->next;
        }

    }

    int Gstack1::  Count()
    {
        return iCount;
    }


int main()
{
    Gstack1 gobj;
    int iRet = 0;

    gobj.push(51);
    gobj.push(21);
    gobj.push(11);
    gobj.push(10);
    iRet = gobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    gobj.Display();
    
    iRet =  gobj.pop();
    cout<<"Popped Element  is :"<<iRet<<endl;
    iRet = gobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    gobj.Display();
    iRet =  gobj.pop();
    cout<<"Popped Element  is :"<<iRet<<endl;
    iRet = gobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    gobj.Display();
    iRet =  gobj.pop();
    cout<<"Popped Element  is :"<<iRet<<endl;
    iRet = gobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    gobj.Display();

    return 0;
}

