//20.57 Mins
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
    PNODE newn= NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*head == NULL)
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
                if(temp->rchild ==NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)
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
                printf("Unable to insert value is duplicate\n");
                free(newn);
                break;
            }
        }
    }
}

void Inorder(PNODE head)
{
    if(head != NULL)
    {
        Inorder(head->lchild);
        printf("%d\n",head->data);
        Inorder(head->rchild);
    }
}

void Preorder(PNODE head)
{
    if(head != NULL)
    {
        printf("%d\n",head->data);
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
        printf("%d\n",head->data);
    }
}

bool Search(PNODE head , int no)
{
    bool bFlag = false;
    while(head != NULL)
    {
        if(no  ==  head->data)
        {
            bFlag  = true;
            break;
        }
        else if(no< head->data)
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
    static int iCount = 0 ; 
    if(head!= NULL)
    {
        iCount++;
        CountNodes(head->lchild);
        CountNodes(head->rchild);
    }
    return iCount;
}

int CountParentNodes(PNODE head)
{
    static int iCount = 0 ; 
    if(head!= NULL)
    {
        if( head -> lchild != NULL || head->rchild != NULL)
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
    static int iCount = 0 ; 
    if(head!= NULL)
    {
        if( head -> lchild == NULL && head->rchild == NULL)
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
    bool bRet = 0;

    Insert(&first , 51);
    Insert(&first , 21);
    Insert(&first , 101);
    Insert(&first , 11);
    Insert(&first , 30);
    Insert(&first , 71);
    Insert(&first , 171);

    printf("Inorder Traversal \n");
    Inorder(first);
    printf("Preorder Traversal \n");
    Preorder(first);
    printf("Postorder Traversal \n");
    Postorder(first);

    iRet = CountNodes(first);
    printf("Total no. of Nodes are:%d\n",iRet);
    iRet = CountParentNodes(first);
    printf("Total no. of Parent Nodes are:%d\n",iRet);
    iRet = CountLeafNodes(first);
    printf("Total no. of Leaf Nodes are:%d\n",iRet);
    
    bRet = Search(first , 51);
    if(bRet == true)
    {
        printf("Element is present\n");
    }
    else
    {
        printf("Element is Absent\n");
    }

    bRet = Search(first , 755);
    if(bRet == true)
    {
        printf("Element is present\n");
    }
    else
    {
        printf("Element is Absent\n");
    }

    bRet = Search(first , 71);
    if(bRet == true)
    {
        printf("Element is present\n");
    }
    else
    {
        printf("Element is Absent\n");
    }


    return 0;
}