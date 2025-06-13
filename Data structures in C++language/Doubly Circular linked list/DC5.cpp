//24.42 mIns
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
            iCount = 0;
            head = NULL;
            tail = NULL;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn  = new NODE;
            newn->data = no;
            newn->prev = NULL;
            newn->next = NULL;

            if(head == NULL && tail  == NULL)
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
            tail->next = head;
            head->prev = tail;
            iCount++;
        }
       
        void InsertLast(int no)
        {
            PNODE newn = NULL;

            newn  = new NODE;
            newn->data = no;
            newn->prev = NULL;
            newn->next = NULL;

            if(head == NULL && tail  == NULL)
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
            tail->next = head;
            head->prev = tail;
            iCount++;
        }

        void DeleteFirst()
        {
            if(head == NULL && tail == NULL)
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
            tail->next = head;
            head->prev = tail;
            iCount--;
            
        }

        void DeleteLast()
        {
            if(head == NULL && tail == NULL)
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
            tail->next = head;
            head->prev = tail;
            iCount--;
        }

        void Display()
        {
            PNODE temp = head;
            PNODE temp2 = tail;

            cout<<"Elements of LIst are:\n";

           do
            {
                cout<<"| "<<temp->data<<" |<=>";
                temp = temp->next;
            } while(temp != tail->next);
            cout<<"\n\n";
           
            cout<<"REVERSED Elements of LIst are:\n";

            do
            {
                cout<<"| "<<temp2->data<<" |<=>";
                temp2 = temp2->prev;
            }while(temp2 != head->prev);
            cout<<"\n\n";
        }
       
        int Count()
        {
        return iCount;
        }

        void InsertAtPos(int no ,  int iPos)
        {
            if(iPos < 1 || iPos > iCount + 1)
            {
                cout<<"Invalid Position\n";
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
                newn->next = NULL;
                newn->prev = NULL;

                for(int i = 1 ; i< iPos - 1 ; i++)
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

        void DeleteAtPos(int iPos)
        {
            if(iPos < 1 || iPos > iCount)
            {
                cout<<"Invalid Position\n";
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

                for(int i = 1 ; i< iPos - 1 ; i++)
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

    dcobj.InsertFirst(51);
    dcobj.InsertFirst(21);
    dcobj.InsertFirst(11);
    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"COunt is :"<<iRet<<endl;

    dcobj.InsertLast(101);
    dcobj.InsertLast(111);
    dcobj.InsertLast(121);
    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    
    dcobj.InsertAtPos(75 ,4);
    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    
    dcobj.DeleteAtPos(4);
    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    
    dcobj.DeleteFirst();
    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    
    dcobj.DeleteLast();
    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"COunt is :"<<iRet<<endl;


    return 0;
}