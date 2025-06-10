//23.35 MIns
#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *prev ;
    struct node *next ;
}NODE , *PNODE , **PPNODE;

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
                cout<<"LIst is Empty";
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
                cout<<"LIst is Empty";
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
            PNODE temp = head;
            PNODE temp2 = tail;

           cout<<"Elements from the list are:\n";
            do
            {
                cout<<"| "<<temp->data<<" |<=>";
                temp = temp->next;
            } while (temp != tail->next);
            cout<<endl;
            
            cout<<" REVERSED Elements from the list are:\n";
            do
            {
                cout<<"| "<<temp2->data<<" |<=>";
                temp2 = temp2->prev;
            } while (temp2 != head->prev);
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
                cout<<"Invalid Position"<<endl;
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

                for(int i = 1 ; i < iPos - 1 ; i++)
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
                cout<<"Invalid Position"<<endl;
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


                for(int i = 1 ; i < iPos - 1 ; i++)
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

    cout<<"Started";

    dcobj.InsertFirst(300);
    dcobj.InsertFirst(200);
    dcobj.InsertFirst(100);
    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    
    dcobj.InsertLast(400);
    dcobj.InsertLast(500);
    dcobj.InsertLast(600);
    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"COunt is :"<<iRet<<endl;
    
    dcobj.InsertAtPos(450 , 5);
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