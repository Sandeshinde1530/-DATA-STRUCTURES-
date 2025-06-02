//complete code in 31.21 minutes
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data ;
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
        newn->next = *head;
        (*head)->prev = newn;
        *head = newn;
    }
    
}

void InsertLast(PPNODE head , int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = NULL;
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

void DeleteFirst(PPNODE head)
{
    PNODE temp = NULL;

    if(*head == NULL)
    {
        return;
    }
    else if((*head) -> next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        *head =( *head)->next;
        free((*head)->prev);       

    }    
}

void DeleteLast(PPNODE head)
{
    PNODE temp = NULL;

    if(*head == NULL)
    {
        return;
    }
    else if((*head) -> next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        temp = *head;
        while( temp->next->next != NULL)
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
    printf("NULL\n");
}

int Count(PNODE head)
{
    int iCount = 0;
    while(head != NULL)
    {
        iCount++;
        head = head->next;
    }
    return iCount;
}

void InsertAtPos(PPNODE head , int no , int iPos)
{
    int iCount = Count(*head);

    if(iPos < 0 || iPos > iCount+1)
    {
        printf("Invalid position\n");
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
        PNODE newn = NULL;
        PNODE temp = *head;

        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->prev = NULL;
        newn->next = NULL;


        for(int i = 1 ; i< iPos -1 ; i++)
        {
            temp = temp -> next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }
    
}

void DeleteAtPos(PPNODE head , int iPos)
{
    int iCount = Count(*head);

    if(iPos < 0 || iPos > iCount)
    {
        printf("Invalid position\n");
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

        for(int i = 1 ; i< iPos -1 ; i++)
        {
            temp = temp -> next;
        }
        target = temp->next;
        temp->next = target ->next;
        temp->next->prev = temp;
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
    printf("No . nodes are : %d\n",iRet);
    
    InsertLast(&first , 101);
    InsertLast(&first , 111);
    InsertLast(&first , 121);
    Display(first);
    iRet = Count(first);
    printf("No . nodes are : %d\n",iRet);
    
    
    InsertAtPos(&first , 75 , 4);
    Display(first);
    iRet = Count(first);
    printf("No . nodes are : %d\n",iRet);
    
    DeleteAtPos(&first , 4);
    Display(first);
    iRet = Count(first);
    printf("No . nodes are : %d\n",iRet);
    
    DeleteFirst(&first);
    Display(first);
    iRet = Count(first);
    printf("No . nodes are : %d\n",iRet);
    
    DeleteLast(&first);
    Display(first);
    iRet = Count(first);
    printf("No . nodes are : %d\n",iRet);
    return 0;
}