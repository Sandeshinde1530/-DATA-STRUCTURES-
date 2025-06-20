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
        PNODE head;
        int iCount;

        DoublyLL()
        {
            head = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn->data = no;
            newn->prev= NULL;
            newn->next= NULL;
            
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

            newn = new NODE;
            newn->data = no;
            newn->prev= NULL;
            newn->next= NULL;
            
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
        
        void InsertAtPos(int no , int iPos)
        {
            if(iPos < 1 || iPos > iCount + 1)
            {
                cout<<"Invalid POsition\n";
                return;
            }
            else if(iPos == 1)
            {
                InsertFirst(no);
            }
            else if(iPos == iCount +1)
            {
                InsertLast(no);
            }
            else
            {
                PNODE newn = NULL;
                PNODE temp = head;

                newn = new NODE;
                newn->data = no;
                newn->prev = NULL;
                newn->next = NULL;

                int i = 0;
                for(i = 1 ; i<iPos-1 ; i++)
                {
                    temp = temp->next;
                }
                newn->next = temp->next;
                temp->next->prev = newn;

                temp->next = newn;
                newn->prev = temp;
            }
            iCount++;

        }
        
        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(head == NULL)
            {
                return;
            }
            else if(head->next == NULL)
            {
                delete head;
                head= NULL;
            }
            else
            {
                temp = head;

                head = temp->next;
                head->prev = NULL;
                delete temp;
            }
            iCount--;
        }
        
        void DeleteLast()
        {
            PNODE temp = head;

            if(head == NULL)
            {
                return;
            }
            else if(head ->next == NULL)
            {
                delete(head);
                head= NULL;
            }
            else
            {
                temp = head;

                while(temp ->next->next != NULL)
                {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = NULL;
            }
            iCount--;
        }

        void DeleteAtPos(int iPos)
        {
             if(iPos < 1 || iPos > iCount)
            {
                cout<<"Invalid POsition\n";
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
               
                int i = 0;
                for(i = 1 ; i<iPos-1 ; i++)
                {
                    temp = temp->next;
                }
                target = temp->next;

                temp->next = target->next;
                temp->next->prev = temp;
                delete target;
                
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
            cout<<"NULL\n";
        }

        int Count()
        {
            return iCount;
        }

};

int main()
{
    DoublyLL dobj;
    int iRet = 0;

    dobj.InsertFirst(3);
    dobj.InsertFirst(2);
    dobj.InsertFirst(1);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"NO. of nodes are :"<<iRet<<"\n";
    
    dobj.InsertLast(4);
    dobj.InsertLast(5);
    dobj.InsertLast(6);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"NO. of nodes are :"<<iRet<<"\n";
    
    // dobj.DeleteFirst();
    // dobj.Display();
    
    // dobj.DeleteLast();
    // dobj.Display();
    
    dobj.InsertAtPos(35 , 4);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"NO. of nodes are :"<<iRet<<"\n";
    
    dobj.DeleteAtPos(4);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"NO. of nodes are :"<<iRet<<"\n";

    return 0;
}
