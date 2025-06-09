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

int pop(PPNODE head )
{
    int no = -1;

    if(*head == NULL)
    {
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
        PNODE temp = *head;
        no = temp->data;

        *head = temp->next;
        free(temp);
    }

    return no;
}

void Display(PNODE head)
{
    printf("Elements is Stack\n");
    while(head != NULL)
    {
        printf("| %d |\n",head->data);
        head = head->next;
    }
    printf("\n");
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

    push(&first , 60);
    push(&first , 50);
    push(&first , 40);
    Display(first);
    iRet = Count(first);
    printf(" NO. of elements are :%d\n\n\n" , iRet);
    
    push(&first , 30);
    push(&first , 20);
    push(&first , 10);
    Display(first);
    iRet = Count(first);
    printf(" NO. of elements are :%d\n\n\n" , iRet);
    
    
    iRet = pop(&first);
    Display(first);
    printf("Poped element is : %d\n",iRet);
    iRet = Count(first);
    printf(" NO. of elements are :%d\n\n\n" , iRet);
    
    
    iRet = pop(&first);
    Display(first);
    printf("Poped element is : %d\n",iRet);
    iRet = Count(first);
    printf(" NO. of elements are :%d\n\n\n" , iRet);
    
    iRet = pop(&first);
    Display(first);
    printf("Poped element is : %d\n",iRet);
    iRet = Count(first);
    printf(" NO. of elements are :%d\n\n\n" , iRet);


    return 0;
}