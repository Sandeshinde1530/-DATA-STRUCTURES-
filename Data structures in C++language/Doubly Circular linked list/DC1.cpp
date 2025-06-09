// completed this code in 27.53 mins
#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}NODE , *PNODE ; 


class DoublyCircular
{
    public:
        int iCount;
        PNODE head;
        PNODE tail;

        DoublyCircular()
        {
            iCount = 0;
            head = NULL;
            tail = NULL;
        }


        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn->data = no;
            newn->prev = NULL;
            newn->next = NULL;

            if(head == NULL && tail == NULL)
            {
                head = newn;
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

            newn = new NODE;
            newn->data = no;
            newn->prev = NULL;
            newn->next = NULL;

            if(head == NULL && tail == NULL)
            {
                head = newn;
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
            if(head == NULL && tail == NULL)
            {
                cout<<"linked list is empty";
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
             if(head == NULL && tail == NULL)
            {
                cout<<"linked list is empty";
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
            PNODE temp =head;

            do
            {
                cout<<"| "<<temp->data<<" |<=>";
                temp = temp->next;
            } while (temp != tail->next);

            cout<<endl;
            
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no , int iPos)
        {
            if(iPos < 1 || iPos > iCount + 1)
            {
                cout<<"invalid Position\n";
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

                newn = new NODE;
                newn->data = no;
                newn->prev = NULL;
                newn->next = NULL;


                for(int i = 1 ; i<iPos - 1 ; i++)
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

        void DeleteAtPos( int iPos)
        {
            if(iPos < 1 || iPos > iCount)
            {
                cout<<"invalid Position\n";
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

                for(int i = 1 ; i<iPos - 1 ; i++)
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
    DoublyCircular dcobj;
    int iRet = 0;

    dcobj.InsertFirst(30);
    dcobj.InsertFirst(20);
    dcobj.InsertFirst(10);
    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"NO of nodes are:"<<iRet<<endl;
    
    dcobj.InsertLast(40);
    dcobj.InsertLast(50);
    dcobj.InsertLast(60);
    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"NO of nodes are:"<<iRet<<endl;
    
    dcobj.InsertAtPos(45 , 5);
    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"NO of nodes are:"<<iRet<<endl;
    
    dcobj.DeleteAtPos(5);
    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"NO of nodes are:"<<iRet<<endl;
    
    dcobj.DeleteFirst();
    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"NO of nodes are:"<<iRet<<endl;
    
    dcobj.DeleteLast();
    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"NO of nodes are:"<<iRet<<endl;

    return 0 ;
}