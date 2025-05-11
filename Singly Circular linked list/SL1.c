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
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = NULL;

    newn->data = no;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        temp = *head;
        while(temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
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
        head = head->next;
        iCount++;
    }
    return iCount;
}

void DeleteFirst(PPNODE head )
{
    PNODE temp = NULL;
    if(*head == NULL)
    {
        return;
    }
    else if((*head)->next == NULL)
    {
        free((*head));
        *head = NULL;
    }
    else
    {
        temp = *head;
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
        free((*head));
        *head = NULL;
    }
    else
    {
        temp = *head;
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

    InsertFirst(&first ,51);
    InsertFirst(&first ,21);
    InsertFirst(&first ,11);

    Display(first);
    int iRet = Count(first);
    printf("NO. of values are : %d\n",iRet);
    
    InsertLast(&first,101);
    InsertLast(&first,111);
    InsertLast(&first,121);
    Display(first);
     iRet = Count(first);
    printf("NO. of values are : %d\n",iRet);

    DeleteFirst(&first);
    Display(first);
    iRet = Count(first);
    printf("NO. of values are : %d\n",iRet);
    
    DeleteLast(&first);
    Display(first);
    iRet = Count(first);
    printf("NO. of values are : %d\n",iRet);

    return 0;
}