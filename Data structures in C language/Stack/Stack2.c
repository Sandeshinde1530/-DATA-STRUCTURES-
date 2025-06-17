//11.54 Mins
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE , *PNODE , **PPNODE;

void push(PPNODE head , int no)
{
    PNODE newn = NULL;
    newn =(PNODE)malloc(sizeof(NODE));
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

int pop(PPNODE head )
{
    int no = 0 ;
    if(*head == NULL)
    {
        printf("Stack is empty\n");
        return no;
    }
    else if((*head)->next == NULL)
    {
        no = (*head)->data;
        free(*head);
        *head = NULL;
    }
    else
    {
         no = (*head)->data;
        PNODE temp = *head;
        *head = temp->next;
        free(temp);
    }
    return no;
}

void Display(PNODE head)
{
    int iCount = 0 ; 

    while(head != NULL)
    {
        printf("| %d |\n",head->data);
        head = head->next;
    }
    printf("\n");
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


int main()
{
    PNODE first = NULL;
    int iRet = 0;

    push(&first , 51);
    push(&first , 21);
    push(&first , 11);
    iRet = Count(first);
    printf("Count is : %d\n",iRet);
    Display(first);
    
    iRet = pop(&first);
    printf("Popped element is : %d\n",iRet);
    iRet = Count(first);
    printf("Count is : %d\n",iRet);
    Display(first);
    iRet = pop(&first);
    printf("Popped element is : %d\n",iRet);
    iRet = Count(first);
    printf("Count is : %d\n",iRet);
    Display(first);
    iRet = pop(&first);
    printf("Popped element is : %d\n",iRet);
    iRet = Count(first);
    printf("Count is : %d\n",iRet);
    Display(first);
    
    
    return 0;
}