#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE head , int no)
{
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        (*head)->prev = newn;
        newn->next = *head;
        *head = newn;
    }
}

void InsertLast(PPNODE head , int no)
{
    PNODE temp = NULL;
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        temp = *head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        newn->prev = temp;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE head )
{
    if(*head == NULL)
    {
        return;
    }
    else if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        *head = (*head)->next;
        free((*head) ->prev);
        (*head)->prev = NULL;
    }

}

void DeleteLast(PPNODE head )
{
    if(*head == NULL)
    {
        return;
    }
    else if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        PNODE temp = *head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void Display(PNODE head )
{
    printf("| NULL |<=>");
    while(head != NULL)
    {
        printf("| %d |<=>",head->data);
        head = head ->next;
    }
    printf("NULL\n");

}

int Count(PNODE head )
{
    int iCount = 0;
    while(head != NULL)
    {
        iCount++;
        head = head ->next;
    }
    return iCount;
}

void InsertAtPos(PPNODE head , int no , int iPos)
{
    int iCount = Count(*head);

    if(iPos < 1 || iPos > iCount + 1)
    {
        printf("Invalid Position\n");
        return;
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
        newn->prev = NULL;
        newn->next = NULL;

        for(int i = 1 ; i<iPos-1 ;i++ )
        {
            temp = temp->next;
        }
        newn->prev = temp;
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
    }
    
}

void DeleteAtPos(PPNODE head , int iPos)
{
     int iCount = Count(*head);

    if(iPos < 1 || iPos > iCount)
    {
        printf("Invalid Position\n");
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst(head);
    }
    else if(iPos == iCount)
    {
        DeleteLast(head);
    }
    else
    {
        PNODE temp = *head;
        PNODE target = NULL;
        

        for(int i = 1 ; i<iPos-1 ;i++ )
        {
            temp = temp->next;
        }
        target = temp->next ;
        temp->next = target->next;
        free(target);

    }
}

int main()
{
    PNODE first = NULL;
    int iRet = 0;

    InsertFirst(&first , 30);
    InsertFirst(&first , 20);
    InsertFirst(&first , 10);
    Display(first);
    iRet = Count(first);
    printf("COunt is : %d\n",iRet);

    InsertLast(&first , 40);
    InsertLast(&first , 50);
    InsertLast(&first , 60);
    Display(first);
    iRet = Count(first);
    printf("COunt is : %d\n",iRet);
    
    InsertAtPos(&first , 55 , 6);
    Display(first);
    iRet = Count(first);
    printf("COunt is : %d\n",iRet);

    DeleteAtPos(&first , 6);
    Display(first);
    iRet = Count(first);
    printf("COunt is : %d\n",iRet);
    
    DeleteFirst(&first);
    Display(first);
    iRet = Count(first);
    printf("COunt is : %d\n",iRet);
    
    DeleteLast(&first);
    Display(first);
    iRet = Count(first);
    printf("COunt is : %d\n",iRet);

    return 0;
}