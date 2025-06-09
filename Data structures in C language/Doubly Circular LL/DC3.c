//27.35 mins
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE , *PNODE , **PPNODE;

void InsertFirst(PPNODE head , PPNODE tail , int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(*head == NULL && *tail == NULL)
    {
        *head = newn;
        *tail = newn;
    }
    else
    {
        newn->next  = *head;
        (*head)->prev = newn;
        *head = newn;
    }
    (*tail)->next = *head;
    (*head)->prev = *tail;

}

void InsertLast(PPNODE head , PPNODE tail , int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(*head == NULL && *tail == NULL)
    {
        *head = newn;
        *tail = newn;
    }
    else
    {
       (*tail)->next = newn;
       newn->prev = *tail;
       *tail = newn;
    }
    (*tail)->next = *head;
    (*head)->prev = *tail;
}

void DeleteFirst(PPNODE head , PPNODE tail)
{
     if(*head == NULL && *tail == NULL)
    {
       return;
    }
    else if(*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *head = (*head)->next;
        free((*head)->prev);
    }
    (*tail)->next = *head;
    (*head)->prev = *tail;
}

void DeleteLast(PPNODE head , PPNODE tail)
{
     if(*head == NULL && *tail == NULL)
    {
       return;
    }
    else if(*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *tail = (*tail)->prev;
        free((*tail)->next);
    }
    (*tail)->next = *head;
    (*head)->prev = *tail;
}

void Display(PNODE head , PNODE tail)
{
    if(head == NULL && tail == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("elements of linked list are :\n");
        do
        {
           printf("| %d |<=>",head->data);
           head = head->next;
        } while (head != tail->next);

        printf("\n");
        printf("\n");
        
        do
        {
            printf("| %d |<=>",tail->data);
            tail = tail->prev;
        }while(tail != head->prev);
        
        printf("\n");
        printf("\n");
    }

}

int Count(PNODE head , PNODE tail)
{
    int iCount = 0;
    do
        {
           iCount++;
           head = head->next;
        } while (head != tail->next);

        return iCount;    
}

void InsertAtPos(PPNODE head , PPNODE tail , int no , int iPos)
{
    int i = 0 , iCount = 0;

    iCount = Count(*head , *tail);

    if(iPos < 1 || iPos > iCount + 1)
    {
        printf("Invalid Position\n");
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(head , tail , no);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(head , tail , no);
    }
    else
    {
        PNODE temp = *head;
        PNODE newn = NULL;
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(i = 1 ; i <iPos - 1 ;i ++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
    
}

void DeleteAtPos(PPNODE head , PPNODE tail , int iPos)
{
    int i = 0 , iCount = 0;

    iCount = Count(*head , *tail);

    if(iPos < 1 || iPos > iCount)
    {
        printf("Invalid Position\n");
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst(head , tail );
    }
    else if(iPos == iCount)
    {
        DeleteLast(head , tail );
    }
    else
    {
        PNODE temp = *head;
        PNODE target = NULL;
       
        for(i = 1 ; i <iPos - 1 ;i ++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;

        free(target);
    }
}


int main()
{

    PNODE first = NULL;
    PNODE last = NULL;
    int iRet = 0;

    InsertFirst(&first , &last , 30);
    InsertFirst(&first , &last , 20);
    InsertFirst(&first , &last , 10);
    Display(first , last);
    iRet = Count(first , last);
    printf("NO of nodes are : %d\n",iRet);

    InsertLast(&first , &last , 40);
    InsertLast(&first , &last , 50);
    InsertLast(&first , &last , 60);
    Display(first , last);
    iRet = Count(first , last);
    printf("NO of nodes are : %d\n",iRet);
    
    InsertAtPos(&first , &last , 45 , 5);
    Display(first , last);
    iRet = Count(first , last);
    printf("NO of nodes are : %d\n",iRet);
    
    DeleteAtPos(&first , &last ,  5);
    Display(first , last);
    iRet = Count(first , last);
    printf("NO of nodes are : %d\n",iRet);
    
    DeleteFirst(&first , &last);
    Display(first , last);
    iRet = Count(first , last);
    printf("NO of nodes are : %d\n",iRet);
    
    DeleteLast(&first , &last);
    Display(first , last);
    iRet = Count(first , last);
    printf("NO of nodes are : %d\n",iRet);


    return 0;
}