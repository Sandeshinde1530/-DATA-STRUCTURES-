// COmpleted this while code only in ({["19.14"]}) mins
// only in  single compilations

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;


class SinglyLL
{
    public:
    int iCount;
    PNODE head;

    SinglyLL()
    {
        iCount = 0;
        head = NULL;
    }

    void InsertFirst(int no)
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
   
    void InsertLast(int no)
    {
        PNODE temp = NULL;
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
            temp = head;
            
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        iCount++;  
    }
   
    void DeleteFirst()
    {
        if(head == NULL)
        {
            return;
        }
        else if(head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            PNODE temp = head;
            head = temp ->next;
            delete temp;
        }
        iCount--;
    }
    
    void DeleteLast()
    {
        if(head == NULL)
        {
            return;
        }
        else if(head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            PNODE temp = head;
            
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
        iCount--;
    }

    void Display()
    {
        PNODE temp = head;

        while(temp != NULL)
        {
            cout<<"|  "<<temp->data<<" |->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    int Count()
    {
        return iCount;
    }

    void InsertAtPos(int no , int iPos)
    {
        if(iPos < 1 || iPos > iCount + 1)
        {
            cout<<"Invali POsition\n";
            return;
        }
        else if(iPos == 1)
        {
            InsertFirst(no);
        }
        else if(iPos ==  iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            PNODE temp = head;
            PNODE newn = NULL;

            newn =new NODE;
            newn->data = no;
            newn->next = NULL;

            for(int i = 1 ; i< iPos-1 ; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;
        }
        iCount++;
    }

    void DeleteAtPos( int iPos)
    {
        if(iPos < 1 || iPos > iCount)
        {
            cout<<"Invali POsition\n";
            return;
        }
        else if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos ==  iCount)
        {
            DeleteLast();
        }
        else
        {
            PNODE temp = head;
            PNODE target = NULL;
          
            for(int i = 1 ; i< iPos-1 ; i++)
            {
                temp = temp->next;
            }
            target = temp->next ;
            temp->next = target->next;
            delete target;
        }
        iCount--;
    }
};

int main()
{

    SinglyLL sobj ;
    int iRet = 0;

    sobj.InsertFirst(300);
    sobj.InsertFirst(200);
    sobj.InsertFirst(100);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"NODEs are :"<< iRet<<endl;

    sobj.InsertLast(400);
    sobj.InsertLast(500);
    sobj.InsertLast(600);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"NODEs are :"<< iRet<<endl;
    
    sobj.InsertAtPos(450 , 5);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"NODEs are :"<< iRet<<endl;
    
    sobj.DeleteAtPos(4);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"NODEs are :"<< iRet<<endl;
    
    sobj.DeleteFirst();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"NODEs are :"<< iRet<<endl;
    
    sobj.DeleteLast();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"NODEs are :"<< iRet<<endl;
    

    return 0;
}