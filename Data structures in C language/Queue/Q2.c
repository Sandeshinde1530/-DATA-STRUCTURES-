//13.55 Mins
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE , *PNODE , **PPNODE;

void enqueue(PPNODE head , int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    PNODE temp = *head;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
       while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newn; 
    }
    
}

int dequeue(PPNODE head)
{
    PNODE temp = *head;
    int No = 0;
    
    if(*head == NULL)
    {
        printf("Queue is empty\n");
        return No;
    }
    else if((*head)->next == NULL)
    {
        No = (*head)->data;
        free(*head);
        *head = NULL;
    }
    else
    {
         No = temp->data;
        *head = temp->next;
        free(temp);
    }   

    return No;
}

int Count(PNODE head)
{
    int iCount = 0 ; 
    while(head != NULL)
    {
        iCount++;
        head = head->next;
    }
    return iCount;
}

void Display(PNODE head)
{
    while(head != NULL)
    {
        printf("| %d |\n",head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    PNODE first = NULL;
    int iRet = 0;
    
    enqueue(&first , 51);
    enqueue(&first , 21);
    enqueue(&first , 11);
    enqueue(&first , 1);
    iRet = Count(first);
    printf("Count is : %d\n",iRet);
    Display(first);
   
    iRet = dequeue(&first );
    printf("removed element  is : %d\n",iRet);
    iRet = Count(first);
    printf("Count is : %d\n",iRet);
    Display(first);
    
   
    iRet = dequeue(&first );
    printf("removed element  is : %d\n",iRet);
    iRet = Count(first);
    printf("Count is : %d\n",iRet);
    Display(first);
    return 0;
}