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
     PNODE newn = NULL;
     PNODE temp = NULL;

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
    else if((*head)->next ==NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        *head = (*head)->next;
        free((*head)->prev);
        (*head)->prev = NULL;
    }

}

void DeleteLast(PPNODE head )
{
    PNODE temp = NULL;

     if(*head == NULL)
    {
        return;
    }
    else if((*head)->next ==NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        temp = *head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }

}

void Display (PNODE head)
{
    printf("\n| NULL |<=>");
    while(head != NULL)
    {
        printf("| %d |<=>",head->data);
        head = head->next;
    }
    printf("| NULL |\n");
}

int  Count (PNODE head)
{
    int iCount = 0;
    while(head != NULL)
    {
        iCount++;
        head = head->next;
    }
    return iCount;
}

void InsertAtPos(PPNODE head , int no ,int iPos)
{
    int Counter = Count(*head);

    if(iPos < 0 || iPos > Counter+1)
    {
        printf("Invalid Position");
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(head , no);
    }
    else if(iPos == Counter+1)
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
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

    }
        
}

void DeleteAtPos(PPNODE head ,int iPos)
{
     int Counter = Count(*head);

    if(iPos < 0 || iPos > Counter)
    {
        printf("Invalid Position");
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst(head);
    }
    else if(iPos == Counter)
    {
        DeleteLast(head);
    }
    else
    {
        PNODE temp = *head;
        PNODE target = NULL;

        for(int i = 1 ; i< iPos -1 ; i++)
        {
            temp = temp->next;
        }
        target = temp->next;

        temp->next = target->next;
        temp->next->prev = temp;

        free(target);
    }
}

int main()
{
    PNODE first = NULL;

    InsertFirst(&first , 3);
    InsertFirst(&first , 2);
    InsertFirst(&first , 1);
    Display(first);
    
    InsertLast(&first , 4);
    InsertLast(&first , 5);
    InsertLast(&first , 6);
    Display(first);
    
    // DeleteFirst(&first);
    // Display(first);

    // DeleteLast(&first);
    // Display(first);

        InsertAtPos(&first , 35 , 4);
        Display(first);
        DeleteAtPos(&first ,4);
        Display(first);

    return 0;
}