//i have Completed this Singly linear linked list code int just 26.30 mins
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
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
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        PNODE temp = *head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
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
        PNODE temp = *head;
        *head = temp->next;
        free(temp);
    }

}

void DeleteLast(PPNODE head )
{
    PNODE temp = NULL;

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
        temp = *head;
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
    while(head != NULL)
    {
        printf("| %d |->",head->data);
        head = head->next;
    }
    printf("NULL\n");

}

int  Count(PNODE head )
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
    int iCounter = Count(*head);

    if(iPos < 0 || iPos > iCounter+1)
    {
        printf("Invalid position\n");
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(head , no);
    }
    else if(iPos == iCounter +1)
    {
        InsertLast(head , no);
    }
    else
    {
        PNODE newn = NULL;
        PNODE temp = *head;

        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        for(int i = 1; i<iPos-1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    
}

void DeleteAtPos(PPNODE head, int iPos)
{
    int iCounter = Count(*head);

    if(iPos < 0 || iPos > iCounter)
    {
        printf("Invalid position\n");
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst(head );
    }
    else if(iPos == iCounter)
    {
        DeleteLast(head);
    }
    else
    {
      PNODE temp = *head;
      PNODE target = NULL;

        for(int i = 1; i< iPos-1 ;i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
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
   
    DeleteAtPos(&first, 4);
    Display(first);

    return 0;
}