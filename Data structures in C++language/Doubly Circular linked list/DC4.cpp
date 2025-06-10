//24.56 mins
#include<iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}NODE , *PNODE , **PPNODE;

class DoublyCircular
{
    public :
        int iCount;
        PNODE head;
        PNODE tail;

        DoublyCircular()
        {
            iCount = 0 ;
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
                tail->next = newn;
                newn->prev = tail;
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
                cout<<"List is empty\n";
                return;
            }
            else if( head == tail)
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
                cout<<"List is empty\n";
                return;
            }
            else if( head == tail)
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
            PNODE temp = head;
            
            cout<<"ELEMENTS OF liST ARE"<<endl;
            do
            {
                cout<<"| "<<temp->data<<" |<=>";
                temp = temp->next;
            } while (temp != tail->next);
            cout<<endl;
        }
        
        void DisplayRev()
        {
            PNODE temp = tail;
            cout<<" REVERSED ELEMENTS OF liST ARE"<<endl;
            do
            {
                cout<<"| "<<temp->data<<" |<=>";
                temp = temp->prev;
            } while (temp != head->prev);
            cout<<endl;
        }

        int Count ()
        {
            return iCount;
        }

        void InsertAtPos(int no , int iPos)
        {
            if(iPos < 1 && iPos > iCount + 1)
            {
                cout<<"Invalid Position\n";
                return ;
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
                newn->data = no ;
                newn->prev = NULL;
                newn->next = NULL;

                for(int i = 1 ; i< iPos - 1 ;i++ )
                {
                    temp = temp->next;
                }
                newn->next = temp->next;
                temp->next->prev = newn;

                newn->prev = temp;
                temp->next = newn;
            }
            iCount++;
        }
        
        void DeleteAtPos( int iPos)
        {
             if(iPos < 1 && iPos > iCount)
            {
                cout<<"Invalid Position\n";
                return ;
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

                for(int i = 1 ; i< iPos - 1 ;i++ )
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

    dcobj.InsertFirst(13);
    dcobj.InsertFirst(12);
    dcobj.InsertFirst(11);
    dcobj.Display();
    dcobj.DisplayRev();
    iRet = dcobj.Count();
    cout<<"Count is :"<<iRet<<endl<<"////////////////////////////////////////////////////////////////////////////////"<<endl;
    
    dcobj.InsertLast(14);
    dcobj.InsertLast(15);
    dcobj.InsertLast(16);
    dcobj.Display();
    dcobj.DisplayRev();
    iRet = dcobj.Count();
    cout<<"Count is :"<<iRet<<endl<<"////////////////////////////////////////////////////////////////////////////////"<<endl;
    
    dcobj.InsertAtPos(5 , 5);
    dcobj.Display();
    dcobj.DisplayRev();
    iRet = dcobj.Count();
    cout<<"Count is :"<<iRet<<endl<<"////////////////////////////////////////////////////////////////////////////////"<<endl;
    
    dcobj.DeleteAtPos(5);
    dcobj.Display();
    dcobj.DisplayRev();
    iRet = dcobj.Count();
    cout<<"Count is :"<<iRet<<endl<<"////////////////////////////////////////////////////////////////////////////////"<<endl;
    
    dcobj.DeleteFirst();
    dcobj.Display();
    dcobj.DisplayRev();
    iRet = dcobj.Count();
    cout<<"Count is :"<<iRet<<endl<<"////////////////////////////////////////////////////////////////////////////////"<<endl;
    
    dcobj.DeleteLast();
    dcobj.Display();
    dcobj.DisplayRev();
    iRet = dcobj.Count();
    cout<<"Count is :"<<iRet<<endl<<"////////////////////////////////////////////////////////////////////////////////"<<endl;

    return 0;
}