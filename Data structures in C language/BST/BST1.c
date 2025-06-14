//30.21 Mins;
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}NODE , *PNODE , **PPNODE;

void Insert(PPNODE head ,  int no)
{
    PNODE newn =NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*head == NULL)
    {
        *head  = newn;
    }
    else
    {PNODE temp = *head;
        while(1)
        {
            if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)
            {
                if(temp->lchild ==NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else if(no == temp->data)
            {
                printf("Unable to Insert As value is duplicate\n");
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
        printf("| %d |\n",head->data);
        Inorder(head->rchild);
    }
}

void Preorder(PNODE head)
{
    if(head != NULL)
    {
        printf("| %d |\n",head->data);
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
        printf("| %d |\n",head->data);
    }
}

int CountNodes(PNODE head)
{
    static int iCount = 0;

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
    static int iCount = 0;

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
    static int iCount = 0;

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

bool Search(PNODE head , int no)
{
    bool bFlag = false;

    while(head != NULL)
    {
        if(head ->data == no)
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
            head  = head->lchild;
        }

    }
    return bFlag;
}



int main()
{
    PNODE first = NULL;
    int iRet = 0;

    Insert(&first , 51);
    Insert(&first , 21);
    Insert(&first , 101);
    Insert(&first , 10);
    Insert(&first , 31);
    Insert(&first , 35);
    Insert(&first , 65);

    printf("Inorder Traversal:\n");
    Inorder(first);

    printf("Preorder Traversal:\n");
    Preorder(first);

    printf("Postorder Traversal:\n");
    Postorder(first);
    
    printf("Counting total nodes:\n");
    iRet = CountNodes(first);
    printf("%d\n",iRet);

    printf("Counting total Parent nodes:\n");
    iRet = CountParentNodes(first);
    printf("%d\n",iRet);

    printf("Counting total Leaf nodes:\n");
    iRet = CountLeafNodes(first);
    printf("%d\n",iRet);

    bool bflag = Search(first , 52);
    if(bflag == true)
    {
        printf("Element is present in the tree\n");
    }
    else
    {
        printf("Element is absent in the tree\n");
    }




    return 0 ;
}