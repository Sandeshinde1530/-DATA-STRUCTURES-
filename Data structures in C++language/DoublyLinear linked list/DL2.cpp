// Completed this code in 22.10 minutes;
#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyLL
{
    public:
        int iCount;
        PNODE head;

        DoublyLL()
        {
            head = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn =  new NODE;
            newn->data = no;
            newn->prev = NULL;
            newn->next = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                head->prev = newn;
                newn->next = head;
                head = newn;
            }
            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn =  new NODE;
            newn->data = no;
            newn->prev = NULL;
            newn->next = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                temp = head;
                while(temp ->next != NULL)
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
                return;
            }
            else if(head->next == NULL)
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
            PNODE temp = NULL;
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
            while(temp != NULL)
                {
                    cout<<"| "<<temp->data<<" |->";
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
            if(iPos < 0 || iPos > iCount + 1)
            {
                cout<<"Invalid Positon \n";
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

                newn =  new NODE;
                newn->data = no;
                newn->prev = NULL;
                newn->next = NULL;

                for(int i  = 1 ; i< iPos -1 ; i++)
                {
                    temp = temp ->next;
                }
                newn->next = temp->next;
                temp->next->prev = newn;

                newn->prev = temp;
                temp->next = newn;
            }
            iCount++;            
        }

        void DeleteAtPos(int iPos)
        {
            if(iPos < 1 || iPos > iCount)
            {
                cout<<"Invalid Positon \n";
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
                
                for(int i  = 1 ; i< iPos -1 ; i++)
                {
                    temp = temp ->next;
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
    DoublyLL dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"NO. of node are : "<<iRet<<endl;
    
    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"NO. of node are : "<<iRet<<endl;
    
    dobj.InsertAtPos(75 , 4);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"NO. of node are : "<<iRet<<endl;
    
    dobj.DeleteAtPos(4);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"NO. of node are : "<<iRet<<endl;
    
    dobj.DeleteFirst();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"NO. of node are : "<<iRet<<endl;
    
    dobj.DeleteLast();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"NO. of node are : "<<iRet<<endl;


    return 0;
}