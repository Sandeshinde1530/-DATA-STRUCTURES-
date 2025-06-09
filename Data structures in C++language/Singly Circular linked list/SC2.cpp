//23.46
#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE , *PNODE , **PPNODE;

class SinglyCircular
{
    public:
        int iCount;
        PNODE head;
        PNODE tail;

        SinglyCircular()
        {
            head = NULL;
            tail = NULL;
            iCount = 0;
        }


        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;
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

        void InsertLast(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;
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

        void DeleteFirst()
        {
            if(head == NULL && tail == NULL)
            {
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
                delete tail->next;
            }
            tail->next = head;
            iCount--;
        }

        void DeleteLast()
        {
            if(head == NULL && tail == NULL)
            {
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
                PNODE temp = head;

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

        void Display()
        {
            PNODE temp = head;

            do
            {
                cout<<"| "<<temp->data<<" |->";
                temp = temp->next;
            }while(temp != tail->next);
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
                cout<<"invalid Positon\n";
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

                for(int i = 1 ; i< iPos - 1;i++)
                {
                    temp = temp->next;
                }
                newn->next = temp->next;
                temp->next = newn;
            }
            tail->next = head;
            iCount++;
        }
        
        void DeleteAtPos( int iPos)
        {
             if(iPos < 1 || iPos > iCount)
            {
                cout<<"invalid Positon\n";
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

                for(int i = 1 ; i< iPos - 1;i++)
                {
                    temp = temp->next;
                }
               target = temp->next;
               temp->next = target->next;
               delete target;
            }
            tail->next = head;
            iCount--;
        }

};

int main()
{
    SinglyCircular scobj;
    int iRet = 0;

    scobj.InsertFirst(30);
    scobj.InsertFirst(20);
    scobj.InsertFirst(10);
    scobj.Display();
    iRet = scobj.Count();
    cout<<"NO of NOdes Are :"<<iRet<<endl;
    
    scobj.InsertLast(40);
    scobj.InsertLast(50);
    scobj.InsertLast(60);
    scobj.Display();
    iRet = scobj.Count();
    cout<<"NO of NOdes Are :"<<iRet<<endl;
    
    scobj.InsertAtPos(35  , 4);
    scobj.Display();
    iRet = scobj.Count();
    cout<<"NO of NOdes Are :"<<iRet<<endl;
    
    scobj.DeleteAtPos(3);
    scobj.Display();
    iRet = scobj.Count();
    cout<<"NO of NOdes Are :"<<iRet<<endl;
    
    scobj.DeleteFirst();
    scobj.Display();
    iRet = scobj.Count();
    cout<<"NO of NOdes Are :"<<iRet<<endl;
    scobj.DeleteLast();
    scobj.Display();
    iRet = scobj.Count();
    cout<<"NO of NOdes Are :"<<iRet<<endl;



    return 0 ;
}
