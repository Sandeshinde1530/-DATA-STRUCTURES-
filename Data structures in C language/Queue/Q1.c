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
    PNODE temp = *head;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

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
    int no= -1;
    if(*head == NULL)
    {
        printf("List is Empty\n");
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
    while(head != NULL)
    {
        printf("| %d |\n",head->data);
        head = head->next;
    }
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

int main()
{
    PNODE first = NULL;
    int iRet = 0;

    enqueue(&first , 11);
    enqueue(&first , 21);
    enqueue(&first , 51);
    Display(first);
    iRet = Count(first);
    printf("Count is : %d\n",iRet);
    
    enqueue(&first , 101);
    enqueue(&first , 111);
    enqueue(&first , 121);
    Display(first);
    iRet = Count(first);
    printf("Count is : %d\n",iRet);
    
    iRet = dequeue(&first);
    printf("Removed Element is : %d\n", iRet);
    Display(first);
    iRet = Count(first);
    printf("Count is : %d\n",iRet);
    
    
    iRet = dequeue(&first);
    printf("Removed Element is : %d\n", iRet);
    Display(first);
    iRet = Count(first);
    printf("Count is : %d\n",iRet);
    
    iRet = dequeue(&first);
    printf("Removed Element is : %d\n", iRet);
    Display(first);
    iRet = Count(first);
    printf("Count is : %d\n",iRet);
    
    iRet = dequeue(&first);
    printf("Removed Element is : %d\n", iRet);
    Display(first);
    iRet = Count(first);
    printf("Count is : %d\n",iRet);

    return 0;
}