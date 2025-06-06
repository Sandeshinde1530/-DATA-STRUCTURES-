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
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next =NULL;

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
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = NULL;

    newn->data = no;
    newn->next =NULL;

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
        temp->next = newn;
    }

}

void Display(PNODE head)
{
    PNODE temp = head;

    while(temp != NULL)
    {
        printf("| %d |->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int Count(PNODE head)
{
    PNODE temp = head;
    int iCount = 0;

    while(temp != NULL)
    {
        temp = temp->next;
        iCount++;
    }
    return iCount;
}

void DeleteFirst(PPNODE head)
{
    PNODE temp = NULL;

    if(*head ==NULL)
    {
        return;
    }
    else if((*head)->next ==NULL)
    {
        free(*head);
        *head=NULL;
    }
    else
    {
        temp = *head;

        *head = temp->next;
        free(temp);
    }    
}

void DeleteLast(PPNODE head)
{
    PNODE temp = NULL;

    if(*head ==NULL)
    {
        return;
    }
    else if((*head)->next ==NULL)
    {
        free(*head);
        *head=NULL;
    }
    else
    {
        temp =*head;
        while(temp->next->next !=NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }    
}



int main()
{
    PNODE first = NULL;
    int iRet = 0;

    InsertFirst(&first,51);
    InsertFirst(&first,21);
    InsertFirst(&first,11);
    Display(first);
    iRet = Count(first);
    printf("No. of nodes are : %d\n",iRet);
    
    InsertLast(&first,101);
    Display(first);
    iRet = Count(first);
    printf("No. of nodes are : %d\n",iRet);
   
    // DeleteFirst(&first);
    // Display(first);
    // iRet = Count(first);
    // printf("No. of nodes are : %d\n",iRet);
    
    // DeleteLast(&first);
    // Display(first);
    // iRet = Count(first);
    // printf("No. of nodes are : %d\n",iRet);

    return 0;
}