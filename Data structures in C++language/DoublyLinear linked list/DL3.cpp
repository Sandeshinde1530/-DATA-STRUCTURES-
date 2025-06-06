// completed in 24.30 mins
#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} NODE , *PNODE , **PPNODE;

class DoublyLL
{
    public:
        int iCount;
        PNODE head;

        DoublyLL()
        {
            iCount = 0;
            head = NULL;
        }


        void InsertFirst(int no)
        {
            PNODE newn = NULL;
            newn = (PNODE)malloc(sizeof(NODE));
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                newn->next = head;
                head->prev = newn;
                head = newn;
            }
            
            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            newn = (PNODE)malloc(sizeof(NODE));
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                PNODE temp = head;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newn;
                newn->prev = temp;
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
                free(head);
                head = NULL;
            }
            else
            {
                head = head->next;
                free(head->prev);
                head->prev = NULL;
            }

            iCount--;
        }

        void DeleteLast()
        {
            if(head == NULL)
            {
                return;
            }
            else if(head->next == NULL)
            {
                free(head);
                head = NULL;
            }
            else
            {
                PNODE temp = head;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                free(temp->next);
                temp->next = NULL;
            }

            iCount--;
        }

        void Display()
        {
            PNODE temp = head;

            while(temp != NULL)
            {
                cout<<" | "<<temp->data<<" |<=>";
                temp = temp->next;
            }
            cout<<"\n";
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
                 PNODE newn = NULL;
                newn = (PNODE)malloc(sizeof(NODE));
                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                PNODE temp = head;

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
                cout<<"invalid Position\n";
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

                free(target);
            }
            iCount--;
        }

};

int main()
{
    DoublyLL dobj;
    int iRet = 0;

    dobj.InsertFirst(30);
    dobj.InsertFirst(20);
    dobj.InsertFirst(10);
    dobj.Display();
    iRet =dobj.Count();
    cout<<"NO. of nodes are:"<<iRet<<endl;

    dobj.InsertLast(40);
    dobj.InsertLast(50);
    dobj.InsertLast(60);
    dobj.Display();
    iRet =dobj.Count();
    cout<<"NO. of nodes are:"<<iRet<<endl;
    
    dobj.InsertAtPos(45 , 5);
    dobj.Display();
    iRet =dobj.Count();
    cout<<"NO. of nodes are:"<<iRet<<endl;
    
    dobj.DeleteAtPos(5);
    dobj.Display();
    iRet =dobj.Count();
    cout<<"NO. of nodes are:"<<iRet<<endl;
    
    dobj.DeleteFirst();
    dobj.Display();
    iRet =dobj.Count();
    cout<<"NO. of nodes are:"<<iRet<<endl;    
    
    dobj.DeleteLast();
    dobj.Display();
    iRet =dobj.Count();
    cout<<"NO. of nodes are:"<<iRet<<endl;

    return 0;
}

