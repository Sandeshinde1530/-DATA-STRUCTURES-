#include<iostream>
#include<stdbool.h>

template <class T>
struct node
{
    T data;
    struct node<T> *lchild;
    struct node<T> *rchild;
};

template <class T>
class BST
{
    public :
    struct node<T> *head;

    BST();
    void Insert(T no);
    bool Search(T no);
    void Inorder(struct node<T> *temp);
    void Preorder(struct node<T> *temp);
    void Postorder(struct node<T> *temp);
    int CountTotalNodes(struct node<T> *temp);
    int CountLeafNodes(struct node<T> *temp);
    int CountParentNodes(struct node<T> *temp);
    void DisplayInorder();
    void DisplayPreorder();
    void DisplayPostorder();
    int DisplayCountTotalNodes();
    int DisplayCountLeafNodes();
    int DisplayCountParentNodes();
};


template <class T>
BST<T> :: BST()
{
    head = NULL;
}

template <class T>
void BST<T> ::  Insert(T no)
{
    struct node<T> *newn = NULL;
    struct node<T> *temp = NULL;
    
    newn = new node<T>;
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

template <class T>
bool BST<T> ::  Search(T no)
{
    struct node<T> *temp =  head;
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

template <class T>
void BST<T> ::  Inorder(struct node<T> *temp)
{
    if(temp != NULL)
    {
        Inorder(temp->lchild);
        printf("%d\n",temp->data);
        Inorder(temp->rchild);
    }
}

template <class T>
void BST<T> ::  Preorder(struct node<T> *temp)
{
    if(temp != NULL)
    {
        printf("%d\n",temp->data);
        Preorder(temp->lchild);
        Preorder(temp->rchild);
    }
}

template <class T>
void BST<T> ::  Postorder(struct node<T> *temp)
{
    if(temp != NULL)
    {
        Postorder(temp->lchild);
        Postorder(temp->rchild);
        printf("%d\n",temp->data);
    }
}

template <class T>
int BST<T> ::  CountTotalNodes(struct node<T> *temp)
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

template <class T>
int BST<T> ::  CountParentNodes(struct node<T> *temp)
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

template <class T>
int BST<T> ::  CountLeafNodes(struct node<T> *temp)
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


template <class T>
void BST<T> ::  DisplayInorder()
{
    printf("Inorder:\n");
     Inorder(head);
     return;
}

template <class T>
void BST<T> ::  DisplayPreorder()
{
    printf("Preorder:\n");
     Preorder(head);
     return;
}

template <class T>
void BST<T> ::  DisplayPostorder()
{
     printf("Postorder:\n");
     Postorder(head);
     return;
}

template <class T>
int BST<T> ::  DisplayCountTotalNodes()
{
    return CountTotalNodes(head);
}

template <class T>
int BST<T> ::  DisplayCountLeafNodes()
{
        return CountLeafNodes(head);
}

template <class T>
int BST<T> ::  DisplayCountParentNodes()
{
        return CountParentNodes(head);
}

int main()
{
    BST<double>bobj;
    int iRet = 0;
    bool bRet = 0;

    bobj.Insert(51.12);
    bobj.Insert(24.12);
    bobj.Insert(101.12);
    bobj.Insert(30.12);
    bobj.Insert(90.12);

    bobj.DisplayInorder();
    bobj.DisplayPreorder();
    bobj.DisplayPostorder();

    iRet = bobj.DisplayCountTotalNodes();
    printf("totalNodes : %d\n",iRet);

    iRet = bobj.DisplayCountLeafNodes();
    printf("LeafNodes : %d\n",iRet);

    iRet = bobj.DisplayCountParentNodes();
    printf("ParentNodes : %d\n",iRet);

    bRet = bobj.Search(51.12);
    if(bRet == true)
        printf("Found\n");
    else
        printf("Not Found\n");

    bRet = bobj.Search(11.12);
    if(bRet == true)
        printf("Found\n");
    else
        printf("Not Found\n");

        bRet = bobj.Search(30.12);
    if(bRet == true)
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}