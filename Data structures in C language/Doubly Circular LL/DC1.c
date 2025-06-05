// Completed this code in 19.21 mins this was the first practice afte learning
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}NODE , *PNODE , **PPNODE;

void InsertFirst(PPNODE head , PPNODE tail , int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;


    if((*head == NULL) && (*tail == NULL))
    {
        *head = newn;
        *tail = newn;
    }
    else
    {
        newn->next = *head;
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


    if((*head == NULL) && (*tail == NULL))
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
    if((*head == NULL) && (*tail == NULL))
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

void DeleteLast(PPNODE head ,  PPNODE tail)
{
     if((*head == NULL) && (*tail == NULL))
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
    if((head == NULL) && (tail == NULL))
    {
        printf("LINKED LISt is empty\n");
        return;
    }

    do{
        printf("| %d |<=>",head->data);
        head = head->next;
    }while(head != tail->next);

    printf("\n");
}

int Count(PNODE head , PNODE tail)
{
    int iCount = 0;
     if((head == NULL) && (tail == NULL))
    {
        return 0;
    }
    
    do{
        iCount++;
        head = head->next;
    }while(head != tail->next);

    return iCount;
}

void InsertAtPos(PPNODE head , PPNODE tail , int no , int iPos)
{
    int i = 0 , iCount = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    iCount = Count(*head , *tail);

    if(iPos < 1 || iPos > iCount + 1)
    {
        printf("INvalid Position\n");
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
        temp = *head;
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->prev = NULL;
        newn->next = NULL;

        for( i  = 1 ; i < iPos-1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        newn->prev = temp;
        temp->next = newn;

    }
}

void DeleteAtPos(PPNODE head , PPNODE tail , int iPos)
{
     int i = 0 , iCount = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    iCount = Count(*head , *tail);

    if(iPos < 1 || iPos > iCount)
    {
        printf("INvalid Position\n");
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst(head , tail);
    }
    else if(iPos == iCount)
    {
        DeleteLast(head , tail);
    }
    else
    {
        temp = *head;
        PNODE target = NULL;

        for( i  = 1 ; i < iPos-1 ; i++)
        {
            temp = temp->next;
        }
        target = temp->next;

        temp->next  = target->next;
        target->next->prev = temp;

        free(target);
    }
}

int main()
{
    PNODE first = NULL;
    PNODE last = NULL;
    int iRet = 0;

    Display(first , last);
    iRet = Count(first , last );
    printf("COunt is : %d\n",iRet);
    
    InsertFirst(&first , &last , 51);
    InsertFirst(&first , &last , 21);
    InsertFirst(&first , &last , 11);
    Display(first , last);
    iRet = Count(first , last );
    printf("COunt is : %d\n",iRet);
    
    InsertLast(&first , &last , 101);
    InsertLast(&first , &last , 111);
    InsertLast(&first , &last , 121);
    Display(first , last);
    iRet = Count(first , last );
    printf("COunt is : %d\n",iRet);
    
    
    InsertAtPos(&first , &last , 75 , 4);
    Display(first , last);
    iRet = Count(first , last );
    printf("COunt is : %d\n",iRet);
    
    DeleteAtPos(&first , &last ,4);
    Display(first , last);
    iRet = Count(first , last );
    printf("COunt is : %d\n",iRet);
    
    DeleteFirst(&first , &last);
    Display(first , last);
    iRet = Count(first , last );
    printf("COunt is : %d\n",iRet);
    
    DeleteLast(&first , &last);
    Display(first , last);
    iRet = Count(first , last );
    printf("COunt is : %d\n",iRet);

    return 0;
}