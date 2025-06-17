//21.35 Mins
#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}NODE , *PNODE , **PPNODE;

class DC6
{
    public:
    int iCount;
    PNODE head;
    PNODE tail;

    DC6()
    {
        iCount = 0;
        head = NULL;
        tail = NULL;
    }

    void InsertFirst(int no)
    {
        PNODE newn = NULL;

        newn = (PNODE)malloc(sizeof(NODE));
        newn->data= no;
        newn->prev = NULL;
        newn->next = NULL;

        if( head == NULL && tail  == NULL)
        {
            head  = newn;
            tail = newn;
        }
        else
        {
            newn->next = head;
            head->prev = newn;
            head = newn;
        }
        head->prev = tail;
        tail->next = head;      
        iCount++;  
    }
    
    void InsertLast(int no)
    {
        PNODE newn = NULL;

        newn = (PNODE)malloc(sizeof(NODE));
        newn->data= no;
        newn->prev = NULL;
        newn->next = NULL;

        if( head == NULL && tail  == NULL)
        {
            head  = newn;
            tail = newn;
        }
        else
        {
           newn->prev = tail;
           tail->next = newn;
           tail = newn;
        }
        head->prev = tail;
        tail->next = head;   
        iCount++;
    }

    void DeleteFirst()
    {
        if(head == NULL && tail ==NULL)
        {
            cout<<"List is empty\n";
            return;
        }
        else if(head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            delete head->prev;
        }
        head->prev = tail;
        tail->next = head;
        iCount--;
    }

    void DeleteLast()
    {
        if(head == NULL && tail ==NULL)
        {
            cout<<"List is empty\n";
            return;
        }
        else if(head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
        }
        head->prev = tail;
        tail->next = head;
        iCount--;
    }
    void Display()
    {
        cout<<"list is:\n";
        
        PNODE temp = head;
        do
        {
            cout<<"| "<<temp->data<<" |<=>";
            temp = temp->next;
        }while(temp != tail->next);

        cout<<endl;
        cout<<endl;
        
        cout<<"REVERSED list is:\n";
        temp = tail;
        do
        {
            cout<<"| "<<temp->data<<" |<=>";
            temp = temp->prev;
        }while(temp != head->prev);
        cout<<endl;
        cout<<endl;

    }

    int Count()
    {
        return iCount;
    }

    void InsertAtPos(int no , int iPos)
    {
        if(iPos < 1 ||iPos > iCount + 1)
        {
            cout<<"Invalid positon\n";
            return;
        }
        else if(iPos == 1)
        {
            InsertFirst(no);
        }
        else if(iPos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            PNODE temp = head;
            PNODE newn = NULL;

            newn = (PNODE)malloc(sizeof(NODE));
            newn->data = no;
            newn->prev = NULL;
            newn->next = NULL;

            for(int i = 1 ; i<iPos-1 ; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next->prev = newn;

            temp->next = newn;
            newn ->prev = temp;
        }
        iCount++;

    }
    
    void DeleteAtPos( int iPos)
    {
        if(iPos < 1 ||iPos > iCount)
        {
            cout<<"Invalid positon\n";
            return;
        }
        else if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == iCount)
        {
            DeleteLast();
        }
        else
        {
            PNODE temp = head;
            PNODE target = NULL;

            for(int i = 1 ; i<iPos-1 ; i++)
            {
                temp = temp->next;
            }
            target = temp->next;

            temp->next = target->next;
            target->next->prev = temp;
            delete target;
        }
        iCount--;
    }
};

int main()
{

    DC6 dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    
    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    
    dobj.InsertAtPos(75, 4);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Count is :"<<iRet<<endl;
   
    dobj.DeleteAtPos(3);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    
    dobj.DeleteFirst();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Count is :"<<iRet<<endl;
    
    dobj.DeleteLast();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Count is :"<<iRet<<endl;

    return 0;
}