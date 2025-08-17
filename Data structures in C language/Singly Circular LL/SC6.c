//26.54Mins
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE , *PNODE , **PPNODE;


void InsertFirst(PPNODE head , PPNODE tail, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*head == NULL && *tail == NULL)
    {
        *head = newn;
        *tail = newn;
    }
    else
    {
        newn->next = *head;
        *head = newn;
    }
    (*tail)->next = *head;
}

void InsertLast(PPNODE head , PPNODE tail, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*head == NULL && *tail == NULL)
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

void DeleteFirst(PPNODE head , PPNODE tail)
{
    PNODE temp = *head;

    if(*head == NULL && *tail == NULL)
    {
        printf("List is empty");
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

void DeleteLast(PPNODE head , PPNODE tail)
{
    PNODE temp = *head;

    if(*head == NULL && *tail == NULL)
    {
        printf("List is empty");
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
   do
   {
    printf("| %d |->",head->data);
    head = head->next;
   } while (head != tail->next);
   printf("\n");
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

void InsertAtPos(PPNODE head , PPNODE tail  , int no , int pos)
{
    int count = Count(*head , *tail);

    if(pos < 1 || pos > count + 1)
    {
        printf("Invalid Position : \n");
        return;
    }
    else if(pos == 1)
    {
        InsertFirst(head , tail , no);
    }
    else if(pos == count + 1)
    {
        InsertLast(head , tail , no);
    }
    else
    {
        PNODE newn = NULL;
        PNODE temp = *head;

        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        for(int i = 1 ; i < pos - 1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE head , PPNODE tail  ,int pos)
{
    int count = Count(*head , *tail);

    if(pos < 1 || pos > count)
    {
        printf("Invalid Position : \n");
        return;
    }
    else if(pos == 1)
    {
       DeleteFirst(head , tail );
    }
    else if(pos == count)
    {
       DeleteLast(head , tail );
    }
    else
    {
        PNODE target = NULL;
        PNODE temp = *head;


        for(int i = 1 ; i < pos - 1 ; i++)
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
    PNODE last  = NULL;
    int iRet = 0;

    InsertFirst(&first , &last , 51);
    InsertFirst(&first , &last , 21);
    InsertFirst(&first , &last , 11);
    iRet = Count(first , last);
    printf("Count is : %d\n",iRet);
    Display(first , last);

    InsertLast(&first , &last , 101);
    InsertLast(&first , &last , 111);
    InsertLast(&first , &last , 121);
    iRet = Count(first , last);
    printf("Count is : %d\n",iRet);
    Display(first  , last);
    
    InsertAtPos(&first , &last , 75 , 4);
    iRet = Count(first , last);
    printf("Count is : %d\n",iRet);
    Display(first  , last);
    
    DeleteAtPos(&first , &last ,4);
    iRet = Count(first , last);
    printf("Count is : %d\n",iRet);
    Display(first  , last);
    
    DeleteFirst(&first , &last );
    iRet = Count(first , last);
    printf("Count is : %d\n",iRet);
    Display(first  , last);
    
    DeleteLast(&first , &last );
    iRet = Count(first , last);
    printf("Count is : %d\n",iRet);
    Display(first  , last);
    
    return 0;
}