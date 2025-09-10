//29.54
#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

class SinglyCircular
{
    public:
        struct node *head;
        struct node *tail;
        int iCount;

    SinglyCircular();    
    void InsertFirst(int no);
    void InsertLast(int no);
    void InsertAtPos(int no , int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    void Display();
    int Count();

};

    SinglyCircular ::  SinglyCircular()
    {
        head = NULL;
        tail = NULL;
        iCount = 0;
    }

    void SinglyCircular :: InsertFirst(int no)
    {
        struct node *newn = new node;
        newn->data = no;
        newn->next = NULL;

        if(head == NULL && tail == NULL)
        {
            head = newn;
            tail = newn;
        }
        else
        {
            newn->next = head;
            head = newn;
        }
        tail->next = head;
        iCount++;
    }

    void SinglyCircular :: InsertLast(int no)
    {
        struct node *newn = new node;
        newn->data = no;
        newn->next = NULL;

        if(head == NULL && tail == NULL)
        {
            head = newn;
            tail = newn;
        }
        else
        {
            tail->next = newn;
            tail = newn;
        }
        tail->next = head;
        iCount++;
    }

    void SinglyCircular :: InsertAtPos(int no , int iPos)
    {
        if(iPos < 1 || iPos > iCount + 1)
        {
            cout<<"Invalid Position\n";
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
            struct node *temp = head;
            struct node *newn = NULL;

            newn = new node;
            newn->data = no;
            newn->next = NULL;

            for(int i = 1 ; i < iPos - 1 ; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;
            iCount++;
        }
        tail->next = head;
    }

    void SinglyCircular :: DeleteFirst()
    {
        if(head == NULL && tail == NULL)
        {
            cout<<"List is empty";
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
            head = head ->next;
            delete tail->next;
        }
        tail->next = head;
        iCount--;
    }

    void SinglyCircular :: DeleteLast()
    {
        struct node*temp = head;
        if(head == NULL && tail == NULL)
        {
            cout<<"List is empty";
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
            while(temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
        }
        tail->next = head;
        iCount--;
    }

    void SinglyCircular :: DeleteAtPos(int iPos)
    {
        if(iPos < 1 || iPos > iCount)
        {
            cout<<"Invalid Position\n";
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
            struct node *temp = head;
            struct node *target = NULL;

            for(int i = 1 ; i < iPos - 1 ; i++)
            {
                temp = temp->next;
            }
            target = temp->next;
            temp->next = target->next;
            delete target;
            iCount--;
        }
    }

    void SinglyCircular :: Display()
    {
        struct node *temp = head;

       do
       {
            cout<<"| "<<temp->data<<" |->";
            temp = temp->next;
       } while (temp != tail->next);
       
       cout<<endl;
    }

    int SinglyCircular :: Count()
    {
        return iCount;
    }


int main()
{
    SinglyCircular sobj ;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Count is : "<<iRet<<endl;

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Count is : "<<iRet<<endl;
    
    sobj.InsertAtPos(75,4);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Count is : "<<iRet<<endl;

    sobj.DeleteAtPos(4);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Count is : "<<iRet<<endl;

    sobj.DeleteFirst();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Count is : "<<iRet<<endl;

    sobj.DeleteLast();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Count is : "<<iRet<<endl;


    return 0;
}