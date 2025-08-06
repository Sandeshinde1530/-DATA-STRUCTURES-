// After long time switched to C
// complete complete code in 32.46 mins
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}NODE , *PNODE , **PPNODE;

int Count(PNODE head)
{
    int iCount = 0;

    while (head != NULL)
    {
        iCount++;
        head = head->next;
    }
    return iCount;
}

void InsertFirst(PPNODE head , int no)
{

    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else 
    {
        newn->next = *head;
        (*head)->prev = newn;
        *head = newn;
    }
    printf("INSertFIrst");
}

void InsertLast(PPNODE head , int no)
{
    
    PNODE temp = *head;
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else 
    {
        while(temp ->next != NULL)
        {
            temp = temp->next;
        }
        newn->prev = temp;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE head)
{
    PNODE temp = *head;
    
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if((*head)->next == NULL)
    {
        free((*head)->next);
    }
    else
    {
        *head = (*head)->next;
        free((*head)->prev);
        (*head)->prev = NULL;
    }

}

void DeleteLast(PPNODE head)
{
    PNODE temp = *head;
    
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if((*head)->next == NULL)
    {
        free((*head)->next);
    }
    else
    {
       while(temp->next->next != NULL)
       {
        temp = temp->next;
       }
       free(temp->next);
       temp->next = NULL;
    }
}

void InsertAtPos(PPNODE head , int no , int iPos)
{
    int iCount = Count(*head);

    if(iPos < 1 || iPos > iCount +1 )
    {
        printf("LIst is empty\n");
    }
    else if(iPos == 1)
    {
        InsertFirst(head , no);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(head , no);
    }
    else
    {
        PNODE temp = *head;
        PNODE newn = NULL;

        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int i = 0 ; i < iPos - 1 ; i++ )
        {
            temp = temp->next;
        };
        newn->next = temp->next;
        temp->next->prev = newn;

        newn->prev = temp;
        temp->next = newn;

    }
}

void DeleteAtPos(PPNODE head , int iPos)
{
 int iCount = Count(*head);

    if(iPos < 1 || iPos > iCount  )
    {
        printf("LIst is empty\n");
    }
    else if(iPos == 1)
    {
        DeleteFirst(head);
    }
    else if(iPos == iCount )
    {
        DeleteLast(head);
    }
    else
    {
        PNODE temp = *head;
        PNODE target = NULL;
        for(int i = 0 ; i < iPos - 1 ; i++ )
        {
            temp = temp->next;
        };
        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;

        free(target);
    }
}

void Display(PNODE head)
{
    PNODE temp = NULL;

    printf("NULL");
    while(head != NULL)
    {
        if(head->next == NULL)
        {
            temp = head;
        }
        printf("| %d |<=>",head->data);
        head = head->next;
    }
    printf("NULL\n");

    printf("REVERSED:\n");
    printf("NULL");
    while(temp != NULL)
    {
        printf("| %d |<=>",temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main()
{
    PNODE first = NULL;
    int iRet = 0;

    InsertFirst(&first , 51);
    InsertFirst(&first , 21);
    InsertFirst(&first , 11);
    iRet = Count(first);
    printf("\nCOunt is : %d\n",iRet);
    Display(first);

    InsertLast(&first , 101);
    InsertLast(&first , 111);
    InsertLast(&first , 121);
    iRet = Count(first);
    printf("\nCOunt is : %d\n",iRet);
    Display(first);

    InsertAtPos(&first , 75 , 4);
    iRet = Count(first);
    printf("\nCOunt is : %d\n",iRet);
    Display(first);

    DeleteAtPos(&first , 4);
    iRet = Count(first);
    printf("\nCOunt is : %d\n",iRet);
    Display(first);

    DeleteFirst(&first);
    iRet = Count(first);
    printf("\nCOunt is : %d\n",iRet);
    Display(first);

    DeleteLast(&first);
    iRet = Count(first);
    printf("\nCOunt is : %d\n",iRet);
    Display(first);

    return 0;

}