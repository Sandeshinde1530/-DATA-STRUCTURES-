//25.19 mins
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}NODE,*PNODE , **PPNODE;

void Insert(PPNODE head , int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*head ==NULL)
    {
        *head = newn;
    }
    else
    {
        PNODE temp = *head;

        while(1)
        {
            if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp-> rchild;
            }
            else if(no< temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else if(no == temp->data)
            {
                printf("Unable to insert as the no is duplicate\n");
                free(newn);
                break;
            }
        }
    }
}

bool Search(PNODE head , int no)
{
    bool bFlag = false;

    while(head != NULL)
    {
        if( no == head->data)
        {
            bFlag = true;
            break;
        }
        else if(no > head->data)
        {
            head = head->rchild;
        }
        else if(no < head->data)
        {
            head = head->lchild;
        }
    }
    return bFlag;
}

void Inorder(PNODE head)
{
    if(head != NULL)
    {
        Inorder(head->lchild);
        printf("%d\n", head->data);
        Inorder(head->rchild);
    }
    
}

void Preorder(PNODE head)
{
     if(head != NULL)
    {
        printf("%d\n", head->data);
        Preorder(head->lchild);
        Preorder(head->rchild);
    }
}

void Postorder(PNODE head)
{
    if(head != NULL)
    {
        Postorder(head->lchild);
        Postorder(head->rchild);
        printf("%d\n", head->data);
    }    
}

int CountNodes(PNODE head)
{
    int static iCount = 0;

    if(head != NULL)
    {
        iCount++;
        CountNodes(head->lchild);
        CountNodes(head->rchild);
    }
        return iCount;
}

int CountParentNodes(PNODE head)
{
    int static iCount = 0;

    if(head != NULL)
    {
        if(head->lchild != NULL || head->rchild != NULL)
        {
            iCount++;
        }
        CountParentNodes(head->lchild);
        CountParentNodes(head->rchild);
    }
        return iCount;
}

int CountLeafNodes(PNODE head)
{
     int static iCount = 0;

    if(head != NULL)
    {
        if(head->lchild == NULL && head->rchild == NULL)
        {
            iCount++;
        }
        CountLeafNodes(head->lchild);
        CountLeafNodes(head->rchild);
    }
    return iCount;
}

int main()
{
    PNODE first = NULL;
    int iRet = 0;
    bool bRet = false;

    Insert(&first , 50);
    Insert(&first , 21);
    Insert(&first , 101);
    Insert(&first , 12);
    Insert(&first , 510);

    printf("Inorder traversal:\n");
    Inorder(first);
    printf("Preorder traversal:\n");
    Preorder(first);
    printf("Postorder traversal:\n");
    Postorder(first);

    bRet =  Search(first , 52);
   if(bRet == true)
   {
    printf("element is preset\n");
    }
    else
    {        
    printf("element is absent\n");
    }
    
    bRet =  Search(first , 510);
   if(bRet == true)
   {
    printf("element is preset\n");
    }
    else
    {        
    printf("element is absent\n");
    }

   iRet =  CountNodes(first);
   printf("Total no of Nodes are:%d\n",iRet);

   iRet =  CountParentNodes(first);
   printf("Total no of Parent Nodes are:%d\n",iRet);

   iRet =  CountLeafNodes(first);
   printf("Total no of leaf Nodes are:%d\n",iRet);

    return 0;
}