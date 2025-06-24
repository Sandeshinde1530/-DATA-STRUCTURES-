#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class SinglyCircular
{
    public:
        int iCount;
        struct node *head;
        struct node *tail;

        SinglyCircular();
        void InsertFirst(int no);
        void InsertLast(int no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(int no , int iPos);
        void DeleteAtPos(int iPos);
};

SinglyCircular  :: SinglyCircular()
{
    head = NULL;
    tail = NULL;
    iCount = 0 ;

}

void SinglyCircular  :: InsertFirst(int no)
{
    struct node *newn = NULL;

    newn = new node;
    newn->data = no;
    newn->next = NULL;

    if(head  == NULL && tail == NULL)
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

void SinglyCircular  :: InsertLast(int no)
{
    struct node *newn = NULL;

    newn = new node;
    newn->data = no;
    newn->next = NULL;

    if(head  == NULL && tail == NULL)
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

void SinglyCircular  :: DeleteFirst()
{
    if(head == NULL && tail == NULL)
    {
        printf("List is empty\n");
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

void SinglyCircular  :: DeleteLast()
{
    struct node * temp = NULL;

    if(head == NULL && tail == NULL)
    {
        printf("List is empty\n");
    }
    else if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
       temp = head;

        while(temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail  = temp;
    }
    tail->next = head;
    iCount--;
}

void SinglyCircular :: Display()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    struct node * temp = NULL;
    temp = head;
   do {
        cout << "| " << temp->data << " |->";
        temp = temp->next;
    } while (temp != tail->next);
    cout << "[HEAD]\n\n";
}


int SinglyCircular  :: Count()
{
    return iCount;
}

void SinglyCircular  :: InsertAtPos(int no , int iPos)
{
    if(iPos <1 || iPos >iCount + 1)
    {
        cout<<"Invalid Position\n";
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
        struct node *temp = head;
        struct node *newn = NULL;

        newn = new node;
        newn->data = no;
        newn->next = NULL;

        for(int i = 1 ; i < iPos -1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
        tail->next = head;
    }
}

void SinglyCircular  :: DeleteAtPos(int iPos)
{
    if(iPos <1 || iPos >iCount)
    {
        cout<<"Invalid Position\n";
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
        struct node *temp = head;
        struct node *target = NULL;

        for(int i = 1 ; i < iPos -1 ; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target ->next;
        delete target;
        iCount--;
        tail->next = head;
    }
}


int main()
{

    SinglyCircular sobj;
    int iRet = 0;
    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);
    iRet = sobj.Count();
    cout<<"Count is:"<<iRet<<endl;
    sobj.Display();
    sobj.Display();
    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);
    iRet = sobj.Count();
    cout<<"Count is:"<<iRet<<endl;
    sobj.Display();


    
    sobj.InsertAtPos(75 , 4);
    iRet = sobj.Count();
    cout<<"Count is:"<<iRet<<endl;
    sobj.Display();
    
    sobj.DeleteAtPos(4);
    iRet = sobj.Count();
    cout<<"Count is:"<<iRet<<endl;
    sobj.Display();
    
    sobj.DeleteFirst();
    iRet = sobj.Count();
    cout<<"Count is:"<<iRet<<endl;
    sobj.Display();
    
    sobj.DeleteLast();
    iRet = sobj.Count();
    cout<<"Count is:"<<iRet<<endl;
    sobj.Display();

    return 0;
}