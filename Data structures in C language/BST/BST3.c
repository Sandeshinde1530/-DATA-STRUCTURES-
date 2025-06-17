#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}NODE , *PNODE , **PPNODE;

void Insert(PPNODE head , int no)
{
    PNODE temp = NULL;
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if( *head == NULL)
    {
        *head = newn;
    }
    else
    {
        temp = *head;

        while(1)
        {
            if(no > temp->data)
            {
                if( temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)
            {
                if( temp->lchild ==NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp-> lchild;
            }
            else if(no == temp->data)
            {
                printf("Unable to insert as value is duplicate\n");
                free(newn);
                break;
            }
        }
        
    }   
}


void Inorder(PNODE head)
{
    if( head != NULL)
    {
        Inorder(head->lchild);
        printf("%d\n" , head->data);
        Inorder(head->rchild);
    }
}

void Preorder(PNODE head)
{
    if( head != NULL)
    {
        printf("%d\n" , head->data);
        Preorder(head->lchild);
        Preorder(head->rchild);
    }
}

void Postorder(PNODE head)
{
    if( head != NULL)
    {
        Postorder(head->lchild);
        Postorder(head->rchild);
        printf("%d\n" , head->data);
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
        else if(no < head ->data)
        {
            head = head->lchild;
        }
        else if(no > head->data)
        {
            head = head->rchild;
        }
    }
    return bFlag;
}

int CountNodes(PNODE head)
{
    static int iCount = 0;

    if( head != NULL)
    {
        iCount++;
        CountNodes(head->lchild);
        CountNodes(head->rchild);
    }
    return iCount;
}

int CountParentNodes(PNODE head)
{
    static int iCount = 0;

    if( head != NULL)
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
    static int iCount = 0;

    if( head != NULL)
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
    int iRet = 0;
    bool bRet = false;
    PNODE first = 0;

    Insert(&first , 51);
    Insert(&first , 21);
    Insert(&first , 101);
    Insert(&first , 61);
    Insert(&first , 41);
    Insert(&first , 25);
    Insert(&first , 64);

    printf("Inorder traversal:\n");
    Inorder(first);
    printf("Preorder traversal:\n");
    Preorder(first);
    printf("Postorder traversal:\n");
    Postorder(first);

    bRet = Search(first , 51);
    if( bRet == true)
    {
        printf("Element is present\n");
    }
    else
    {
        printf("Element is Absent\n");
    }
   
   
    bRet = Search(first , 59);
    if( bRet == true)
    {
        printf("Element is present\n");
    }
    else
    {
        printf("Element is Absent\n");
    }

    iRet = CountNodes(first);
    printf("NO of total NODES : %d\n", iRet);
    iRet = CountParentNodes(first);
    printf("NO of total Parent NODES : %d\n", iRet);
    iRet = CountLeafNodes(first);
    printf("NO of total Leaf NODES : %d\n", iRet);

    return 0 ;
}
