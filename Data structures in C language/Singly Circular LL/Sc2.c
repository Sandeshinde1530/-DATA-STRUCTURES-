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

void InsertFirst(PPNODE head , PPNODE tail , int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*head == NULL && *tail == NULL )
    {
        *head = newn;
        *tail = newn;
    }
    else if(*head == *tail)
    {
        newn->next = *tail;
        *head = newn;
    }
    else
    {
        newn->next = *head;
        *head = newn;
    }
    (*tail)->next = *head;
}

void InsertLast(PPNODE head , PPNODE tail , int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*head == NULL && *tail == NULL )
    {
        *head = newn;
        *tail = newn;
    }
    else
    {
       (*tail)->next = newn;
       *tail = newn;
    }
    (*tail)->next = *head;
}

void DeleteFirst(PPNODE head , PPNODE tail )
{
    if(*head == NULL && *tail == NULL )
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
       free((*tail)->next);
    }
    (*tail)->next = *head;
}

void DeleteLast(PPNODE head , PPNODE tail )
{
     if(*head == NULL && *tail == NULL )
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
       PNODE temp = *head;

       while(temp->next != *tail)
       {
        temp = temp->next;
       }
       free(*tail);
       *tail = temp;
    }
    (*tail)->next = *head;
    
}

void Display(PNODE head , PNODE tail)
{
    do{
        printf("| %d |->",head->data);
        head = head->next;
    }while(head != tail->next);

    printf("\n");
}

int Count(PNODE head , PNODE tail)
{
    int iCount = 0;
    do{
        iCount++;
        head = head->next;
    }while(head != tail->next);

    return iCount;
}

void InsertAtPos(PPNODE head , PPNODE tail , int no , int iPos)
{
    int iCount =  Count(*head , *tail);

    if(iPos < 1 || iPos > iCount +1)
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

        for(int i = 1 ; i<iPos-1 ;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE head , PPNODE tail , int iPos)
{
    int iCount =  Count(*head , *tail);

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
        
        for(int i = 1 ; i<iPos-1 ;i++)
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
    PNODE last = NULL;
    int iRet = 0;


    InsertFirst(&first , &last , 30);
    InsertFirst(&first , &last , 20);
    InsertFirst(&first , &last , 10);
    Display(first , last);
    iRet = Count(first , last);
    printf("Count is : %d\n",iRet);
    
    InsertLast(&first , &last , 40);
    InsertLast(&first , &last , 50);
    InsertLast(&first , &last , 60);
    Display(first , last);
    iRet = Count(first , last);
    printf("Count is : %d\n",iRet);
    
    InsertAtPos(&first , &last , 55 , 6);
    Display(first , last);
    iRet = Count(first , last);
    printf("Count is : %d\n",iRet);

    DeleteAtPos(&first , &last , 6);
    Display(first , last);
    iRet = Count(first , last);
    printf("Count is : %d\n",iRet);

    
    DeleteFirst(&first , &last);
    Display(first , last);
    iRet = Count(first , last);
    printf("Count is : %d\n",iRet);
   
    DeleteFirst(&first , &last);
    Display(first , last);
    iRet = Count(first , last);
    printf("Count is : %d\n",iRet);
  
    printf("Extraaaaaaaaaaaaaaaa");
    Display(first , last);
    iRet = Count(first , last);
    printf("Count is : %d\n",iRet);
    
    DeleteLast(&first , &last);
    Display(first , last);
    iRet = Count(first , last);
    printf("Count is : %d\n",iRet);
    

    return 0;
}