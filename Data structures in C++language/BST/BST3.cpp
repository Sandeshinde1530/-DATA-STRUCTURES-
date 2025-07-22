#include<iostream>
#include<stdbool.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

class BST
{
    public :
    struct node *head;

    BST();
    void Insert(int no);
    bool Search(int no);
    void Inorder(struct node *temp);
    void Preorder(struct node *temp);
    void Postorder(struct node *temp);
    int CountTotalNodes(struct node *temp);
    int CountLeafNodes(struct node *temp);
    int CountParentNodes(struct node *temp);
    void DisplayInorder();
    void DisplayPreorder();
    void DisplayPostorder();
    int DisplayCountTotalNodes();
    int DisplayCountLeafNodes();
    int DisplayCountParentNodes();
};

BST :: BST()
{
    head = NULL;
}

void BST ::  Insert(int no)
{
    struct node *newn = NULL;
    struct node *temp = NULL;
    
    newn = new node;
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;

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
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else if(no == temp->data)
            {
                printf("Value is duplicate\n");
                delete newn;
                break;
            }
        }
    }
}

bool BST ::  Search(int no)
{
    struct node *temp =  head;
    bool bFlag = false;

while(temp != NULL)
    {
        if(temp->data == no)
        {
            bFlag = true;
            break;
        }
        else if(no > temp->data)
        {
            temp = temp->rchild;
        }
        else if(no < temp->data)
        {
            temp = temp->lchild;
        }
    }
return bFlag;
}

void BST ::  Inorder(struct node *temp)
{
    if(temp != NULL)
    {
        Inorder(temp->lchild);
        printf("%d\n",temp->data);
        Inorder(temp->rchild);
    }
}

void BST ::  Preorder(struct node *temp)
{
    if(temp != NULL)
    {
        printf("%d\n",temp->data);
        Preorder(temp->lchild);
        Preorder(temp->rchild);
    }
}

void BST ::  Postorder(struct node *temp)
{
    if(temp != NULL)
    {
        Postorder(temp->lchild);
        Postorder(temp->rchild);
        printf("%d\n",temp->data);
    }
}

int BST ::  CountTotalNodes(struct node *temp)
{
    static int iCount = 0;

    if(temp != NULL)
    {
        iCount++;
        CountTotalNodes(temp->lchild);
        CountTotalNodes(temp->rchild);
    }
    return iCount;
}

int BST ::  CountParentNodes(struct node *temp)
{
    static int iCount = 0;

    if(temp != NULL)
    {
        if((temp->lchild != NULL) || (temp->rchild != NULL))
        {
            iCount++;
        }
        CountParentNodes(temp->lchild);
        CountParentNodes(temp->rchild);
    }
    return iCount;
}

int BST ::  CountLeafNodes(struct node *temp)
{
    static int iCount = 0;

    if(temp != NULL)
    {
        if((temp->lchild == NULL) && (temp->rchild == NULL))
        {
            iCount++;
        }
        CountLeafNodes(temp->lchild);
        CountLeafNodes(temp->rchild);
    }
    return iCount;
}


void BST ::  DisplayInorder()
{
    printf("Inorder:\n");
     Inorder(head);
     return;
}

void BST ::  DisplayPreorder()
{
    printf("Preorder:\n");
     Preorder(head);
     return;
}

void BST ::  DisplayPostorder()
{
     printf("Postorder:\n");
     Postorder(head);
     return;
}

int BST ::  DisplayCountTotalNodes()
{
    return CountTotalNodes(head);
}

int BST ::  DisplayCountLeafNodes()
{
        return CountLeafNodes(head);
}

int BST ::  DisplayCountParentNodes()
{
        return CountParentNodes(head);
}

int main()
{
    BST bobj;
    int iRet = 0;
    bool bRet = 0;

    bobj.Insert(51);
    bobj.Insert(24);
    bobj.Insert(101);
    bobj.Insert(30);
    bobj.Insert(90);

    bobj.DisplayInorder();
    bobj.DisplayPreorder();
    bobj.DisplayPostorder();

    iRet = bobj.DisplayCountTotalNodes();
    printf("totalNodes : %d\n",iRet);

    iRet = bobj.DisplayCountLeafNodes();
    printf("LeafNodes : %d\n",iRet);

    iRet = bobj.DisplayCountParentNodes();
    printf("ParentNodes : %d\n",iRet);

    bRet = bobj.Search(51);
    if(bRet == true)
        printf("Found\n");
    else
        printf("Not Found\n");

    bRet = bobj.Search(11);
    if(bRet == true)
        printf("Found\n");
    else
        printf("Not Found\n");

        bRet = bobj.Search(30);
    if(bRet == true)
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}