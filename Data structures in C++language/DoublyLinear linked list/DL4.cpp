//20.41 Mins
#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}NODE , *PNODE;

class DoublyLinear
{
    public :
    int iCount;
    PNODE head;

    DoublyLinear()
    {
        iCount = 0;
        head = NULL;
    }

    void InsertFirst(int no)
    {
        PNODE newn = NULL;

        newn = new NODE;
        newn->data = no;
        newn->prev = NULL;
        newn->next  = NULL;

        if(head == NULL)
        {
            head = newn;
        }
        else
        {
            newn->next  = head;
            head->prev  = newn;
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
        newn->prev = NULL;
        newn->next  = NULL;

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
           newn->prev = temp;
           temp->next = newn;
        }
        iCount++;
    }


    void DeleteFirst()
    {
        if(head == NULL)
        {
            printf("List is empty\n");
            return;
        }
        else if(head ->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            head = head->next;
            delete head->prev;
            head->prev = NULL;
        }
        iCount--;
    }

    void DeleteLast()
    {
        PNODE temp = head;
        if(head == NULL)
        {
            printf("List is empty\n");
            return;
        }
        else if(head ->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            temp = head;

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

        cout<<"List is :\n";
        while(temp!= NULL)
        {
            cout<<"| "<<temp->data<<" |<=>";
            temp = temp->next;
        }
        cout<<endl<<endl;

    }

    int Count()
    {
        return iCount;
    }
    
    void InsertAtPos(int no , int iPos)
    {
        if(iPos < 1  || iPos > iCount + 1)
        {
            cout<<"Invalid Position \n";
        }
        else if(iPos  == 1)
        {
            InsertFirst(no);
        }
        else if(iPos  == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            PNODE temp = head;
            PNODE newn = NULL;

            newn = new NODE;
            newn->data = no;
            newn->prev = NULL;
            newn->next  = NULL;

            for(int i = 0 ; i<iPos - 1 ; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next->prev  = newn;

            newn->prev = temp;
            temp->next = newn;

        }
        iCount++;
    }
    
    void DeleteAtPos( int iPos)
    {
        if(iPos < 1  || iPos > iCount)
        {
            cout<<"Invalid Position \n";
        }
        else if(iPos  == 1)
        {
            DeleteFirst();
        }
        else if(iPos  == iCount)
        {
            DeleteLast();
        }
        else
        {
            PNODE temp = head;
            PNODE target = NULL;

           
            for(int i = 0 ; i<iPos - 1 ; i++)
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

    DoublyLinear dobj;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    dobj.Display();

    dobj.InsertLast(101);
    dobj.InsertLast(11);
    dobj.InsertLast(121);
    dobj.Display();
    
    dobj.InsertAtPos(75 , 4);
    dobj.Display();
    
    dobj.DeleteAtPos(4);
    dobj.Display();
    
    dobj.DeleteFirst();
    dobj.Display();
    
    dobj.DeleteLast();
    dobj.Display();
    
    return 0;

}