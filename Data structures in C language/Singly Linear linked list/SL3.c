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
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
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
            temp = (temp)->next;
        }
        temp->next  = newn;        
    }
    
}

void DeleteFirst(PPNODE head)
{
    PNODE temp = NULL;

    if(*head == NULL)
    {
        return;
    }
    else if((*head)->next ==NULL)
    {
        free(*head);
    }
    else
    {
        temp = *head;
        *head = temp ->next;
        free(temp);
    }

}

void DeleteLast(PPNODE head)
{
    PNODE temp = NULL;

    if(*head == NULL)
    {
        return;
    }
    else if((*head)->next ==NULL)
    {
        free(*head);
    }
    else
    {
        temp = *head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next =NULL;
        
    }



}

void Display(PNODE head )
{
    while(head != NULL)
    {
        printf("| %d |->",head->data);
        head = head->next;
    }
    printf("| NULL |\n");
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
    int Counter = Count(*head);

    if(iPos < 1 || iPos >Counter+1 )
    {
        printf("Invalid position \n");
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(head , no);
    }
    else if(iPos == Counter+1)
    {
        InsertLast(head,no);
    }
    else
    {
        PNODE newn = NULL;
        PNODE temp = *head;

        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        int i = 0;
        for(i = 1 ; i<iPos-1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

    }

}

void DeleteAtPos(PPNODE head, int iPos)
{
     int Counter = Count(*head);

    if(iPos < 1 || iPos >Counter )
    {
        printf("Invalid position \n");
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

        int i = 0;
        for(i = 1 ; i<iPos-1;i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target ->next;
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
    printf("NO of nodes :%d\n",iRet);
    
    InsertLast(&first ,101);
    InsertLast(&first ,111);
    InsertLast(&first ,121);
    Display(first);
    iRet = Count(first);
    printf("NO of nodes :%d\n",iRet);
    
    // DeleteFirst(&first);
    // Display(first);
    // iRet = Count(first);
    // printf("NO of nodes :%d\n",iRet);

    // DeleteLast(&first);
    //  Display(first);
    // iRet = Count(first);
    // printf("NO of nodes :%d\n",iRet);.

    InsertAtPos(&first ,75,4);
    Display(first);
    iRet = Count(first);
    printf("NO of nodes :%d\n",iRet);
    
    DeleteAtPos(&first,4);
    Display(first);
    iRet = Count(first);
    printf("NO of nodes :%d\n",iRet);
    

    return 0;
}