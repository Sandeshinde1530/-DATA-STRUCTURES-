// complete this in 26.19 mins
#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE , *PNODE , **PPNODE;

class SinglyCL
{
    public:
        int iCount;
        PNODE head;
        PNODE tail;

        SinglyCL()
        {
            iCount = 0;
            head = NULL;
            tail = NULL;
        }


        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn  = (PNODE)malloc(sizeof(NODE));
            newn->data = no;
            newn->next = NULL;

            if(head == NULL && tail == NULL)
            {
                head = newn;
                tail = newn;
            }
            else if(head == tail)
            {
                newn->next = tail;
                head = newn;
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

            newn  = (PNODE)malloc(sizeof(NODE));
            newn->data = no;
            newn->next = NULL;

            if(head == NULL && tail == NULL)
            {
                head = newn;
                tail = newn;
            }
            else if(head == tail)
            {
                newn->next = tail;
                head = newn;
            }
            else
            {   
                tail->next = newn;
                tail  = newn;
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
               free(head);
               head = NULL;
               tail = NULL;
            }
            else
            {   
               head = head->next;
               free(tail->next);
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
               free(head);
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
                free(tail);
                tail = temp;
            }
            tail->next = head;
            iCount--;
        }
        
        void Display()
        {
            PNODE temp = head;

            do{
                printf("| %d | ->",temp->data);
                temp = temp->next;
            }while(temp != tail->next);

            printf("\n");
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no , int iPos)
        {
            if(iPos < 1 || iPos > iCount + 1)
            {
                printf("Invalid Position\n");
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
                int i = 0;

                newn = (PNODE)malloc(sizeof(NODE));
                newn->data = no;
                newn->next = NULL;

                for(i = 1 ; i< iPos - 1 ;i++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                temp->next = newn;
            }
            iCount++;
        }

        void DeleteAtPos(int iPos)
        {
            if(iPos < 1 || iPos > iCount)
            {
                printf("Invalid Position\n");
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

                for(i = 1 ; i< iPos - 1 ;i++)
                {
                    temp = temp->next;
                }
                target = temp->next;

                temp->next = target->next;
                free(target);                
            }
            iCount--;
        }
};

int main()
{
    SinglyCL sobj;

    int iRet = 0;

    sobj.InsertFirst(30);
    sobj.InsertFirst(20);
    sobj.InsertFirst(10);
    sobj.Display();
    iRet = sobj.Count();
    printf("COunt is :%d\n",iRet);

    sobj.InsertLast(40);
    sobj.InsertLast(50);
    sobj.InsertLast(60);
    sobj.Display();
    iRet = sobj.Count();
    printf("COunt is :%d\n",iRet);
    
    sobj.InsertAtPos(55 , 6);
    sobj.Display();
    iRet = sobj.Count();
    printf("COunt is :%d\n",iRet);
    
    sobj.DeleteAtPos(6);
    sobj.Display();
    iRet = sobj.Count();
    printf("COunt is :%d\n",iRet);
    
    sobj.DeleteFirst();
    sobj.Display();
    iRet = sobj.Count();
    printf("COunt is :%d\n",iRet);
    
    sobj.DeleteLast();
    sobj.Display();
    iRet = sobj.Count();
    printf("COunt is :%d\n",iRet);

    return 0;
}