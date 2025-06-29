#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};


class BST2
{   
    public:
        int iCount;
        struct node * head;

    BST2();
    void Insert(int no);
    bool Search(int no);
    void Inorder(struct node *head);
    void Preorder(struct node *head);
    void Postorder(struct node *head);
    int CountNodes(struct node *head);
    int CountParentNodes(struct node *head);
    int CountLeafNodes(struct node *head);
    void DisplayInorder();
    void DisplayPreorder();
    void DisplayPostorder();
    int CountTotalNodes();
    int CountTotalParentNodes();
    int CountTotalLeafNodes();
};


BST2:: BST2()
{
    head = NULL;
}

void BST2 :: Insert(int no)
{
    
    struct node *newn = NULL;
    struct node *temp = head;

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
        struct node *temp = head;
        while(1)
        {
            if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    cout<<"Inserted\n";
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    cout<<"Inserted\n";
                    break;
                }
                temp = temp->lchild;
            }
            else if( no == temp->data)
            {
                cout<<"Unable to insert as value is duplicate\n";
                break;
            }
        }
    }

    
}

bool BST2 :: Search(int no)
{
    struct node *temp = head;
    bool bFlag = false;

    while(temp != NULL)
    {
        if( no == temp ->data)
        {
            bFlag = true;
            break;
        }
        else if(no < head->data)
        {
            temp = temp->lchild;
        }
        else if(no > head->data)
        {
            temp = temp->rchild;
        }        
    }
    return bFlag;
}

void BST2 :: Inorder(struct node *temp)
{
    if(temp != NULL)
    {
        Inorder(temp->lchild);
        cout<<temp->data<<endl;
        Inorder(temp->rchild);
    }
}

void BST2 :: Preorder(struct node *temp)
{
    if(temp != NULL)
    {
        cout<<temp->data<<endl;
        Preorder(temp->lchild);
        Preorder(temp->rchild);
    }
}

void BST2 :: Postorder(struct node *temp)
{
    if(temp != NULL)
    {
        Postorder(temp->lchild);
        Postorder(temp->rchild);
        cout<<temp->data<<endl;
    }
    
}

int BST2 :: CountNodes(struct node *temp)
{
    static int iCount = 0;

    if( temp != NULL)
    {
        iCount++;
        CountNodes(temp->lchild);
        CountNodes(temp->rchild);
    }
    return iCount;
}

int BST2 :: CountParentNodes(struct node *temp)
{
    static int iCount = 0;

    if( temp != NULL)
    {
        if(temp->lchild != NULL || temp ->rchild != NULL)
        {
            iCount++;
        }
        CountParentNodes(temp->lchild);
        CountParentNodes(temp->rchild);
    }
    return iCount;
}

int BST2 :: CountLeafNodes(struct node *temp)
{
        static int iCount = 0;

    if( temp != NULL)
    {
        if(temp->lchild == NULL && temp ->rchild == NULL)
        {
            iCount++;
        }
        CountLeafNodes(temp->lchild);
        CountLeafNodes(temp->rchild);
    }
    return iCount;
}

void BST2 :: DisplayInorder()
{
    cout<<"Displaying Inorder\n";
    Inorder(head);
}

void BST2 :: DisplayPreorder()
{
    cout<<"Displaying Preorder\n";
    Preorder(head);
}

void BST2 :: DisplayPostorder()
{
    cout<<"Displaying Postorder\n";
    Postorder(head);
}

int BST2 :: CountTotalNodes()
{
    return CountNodes(head);
}

int BST2 :: CountTotalParentNodes()
{
    return CountParentNodes(head);
}

int BST2 :: CountTotalLeafNodes()
{
    return CountLeafNodes(head);
}


int main()
{
    BST2 bobj;
    int iRet = 0;
    bool bRet = false;

    bobj.Insert(51);
    bobj.Insert(21);
    bobj.Insert(101);
    bobj.Insert(151);
    bobj.Insert(26);
    bobj.Insert(45);
    bobj.Insert(11);
    bobj.DisplayInorder();
    bobj.DisplayPreorder();
    bobj.DisplayPostorder();
    iRet = bobj.CountTotalNodes();
    cout<<"total Node are: "<<iRet<<endl;
    iRet = bobj.CountTotalParentNodes();
    cout<<"total Parent Node are: "<<iRet<<endl;
    iRet = bobj.CountTotalLeafNodes();
    cout<<"total Leaf Node are: "<<iRet<<endl;

    bRet = bobj.Search(51);
    if(bRet == true)
    {
        cout<<"Found element\n";
    }
    else
    {
        cout<<"Not Found\n";
    }
    bRet = bobj.Search(515);
    if(bRet == true)
    {
        cout<<"Found element\n";
    }
    else
    {
        cout<<"Not Found\n";
    }
    bRet = bobj.Search(11);
    if(bRet == true)
    {
        cout<<"Found element\n";
    }
    else
    {
        cout<<"Not Found\n";
    }

    return 0;
}