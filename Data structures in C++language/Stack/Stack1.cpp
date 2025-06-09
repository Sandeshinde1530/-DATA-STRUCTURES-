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

            newn = (PNODE)malloc(sizeof(NODE));
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

        int  pop()
        {
            int No = -1;
            if(head== NULL)
            {
                cout<<"Linked List is Empty\n";
                return No;
            }
            else if(head->next == NULL)
            {
                No = head->data;
                delete head;
                head = NULL;
            }
            else
            {
                No = head->data;
                PNODE temp = head;
                
                head = temp->next;
                delete temp;
            }
            iCount--;
            return No;
        }

        void Display()
        {   
            PNODE temp = head;
            if(temp== NULL)
            {
                cout<<"Linked List is Empty\n";
            }
            else
            {
                while( temp != NULL)
                {
                    cout<<"| "<<temp->data<<" |"<<endl;
                    temp = temp->next;
                }
            }

        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    Stack sobj;
    int iRet = 0;

    sobj.push(60);
    sobj.push(50);
    sobj.push(40);
    iRet = sobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    sobj.Display();
    
    sobj.push(30);
    sobj.push(20);
    sobj.push(10);
    iRet = sobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    sobj.Display();
    
    iRet = sobj.pop();
    cout<<"Poped element is :"<<iRet<<endl;
    iRet = sobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    sobj.Display();
    
    iRet = sobj.pop();
    cout<<"Poped element is :"<<iRet<<endl;
    iRet = sobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    sobj.Display();
    
    
    iRet = sobj.pop();
    cout<<"Poped element is :"<<iRet<<endl;
    iRet = sobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    sobj.Display();
    
    
    
    return 0 ;
}