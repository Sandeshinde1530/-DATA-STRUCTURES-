#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE , *PNODE , **PPNODE;

void InsertFirst(PPNODE head , int no)
{
    PNODE newn  = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        newn->next = *head;
        *head = newn;
    }
}

void InsertLast(PPNODE head , int no)
{
    PNODE temp  = *head;
    PNODE newn  = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        while(temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next  = newn;
    }
}

void DeleteFirst(PPNODE head)
{
    PNODE temp = *head;

    if(*head == NULL)
    {
        printf("List is empty");
        return ;
    }
    else if((*head)->next == NULL)
    {
        free((*head));
        *head = NULL;
    }
    else
    {
        *head = temp->next;
        free(temp);
    }
}

void DeleteLast(PPNODE head)
{
    PNODE temp = *head;

    if(*head == NULL)
    {
        printf("List is empty");
        return ;
    }
    else if((*head)->next == NULL)
    {
        free((*head));
        *head = NULL;
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

void Display(PNODE head)
{
    while(head != NULL)
    {
        printf("| %d |->",head->data);
        head = head->next;
    }
    printf("\n\n");
}

int Count(PNODE head)
{
    int iCount = 0 ; 
    while(head != NULL)
    {
        iCount++;
        head = head->next;
    }
    return iCount;
}

void InsertAtPos(PPNODE head , int no , int iPos)
{
    int iCount = Count(*head );

    if(iPos < 1 || iPos > iCount + 1)
    {
        printf("Invalid Postion \n");
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

        for(int i = 1 ; i < iPos - 1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}


void DeleteAtPos(PPNODE head , int iPos)
{
    int iCount = Count(*head );

    if(iPos < 1 || iPos > iCount )
    {
        printf("Invalid Postion \n");
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

        for(int i = 1 ; i < iPos - 1 ; i++)
        {
            temp = temp->next;
        }
       target = temp->next;
       temp ->next = target->next;
       free(target);
    }
}

int main()
{
    PNODE first = NULL;
    int iRet = 0;

    InsertFirst(&first , 51);
    InsertFirst(&first , 21);
    InsertFirst(&first , 11);
    Display(first);
    iRet = Count(first);
    printf("The COunt is : %d\n",iRet);

    InsertLast(&first , 101);
    InsertLast(&first , 111);
    InsertLast(&first , 121);
    Display(first);
    iRet = Count(first);
    printf("The COunt is : %d\n",iRet);
    
    InsertAtPos(&first , 75 , 4);
    Display(first);
    iRet = Count(first);
    printf("The COunt is : %d\n",iRet);
    
    DeleteAtPos(&first, 4);
    Display(first);
    iRet = Count(first);
    printf("The COunt is : %d\n",iRet);
    
    DeleteFirst(&first);
    Display(first);
    iRet = Count(first);
    printf("The COunt is : %d\n",iRet);
    
    DeleteLast(&first);
    Display(first);
    iRet = Count(first);
    printf("The COunt is : %d\n",iRet);

    return 0;
}