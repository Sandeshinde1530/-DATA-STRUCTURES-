#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

class Gbst
{
    public:
    int iCount;
    struct node *head;

    Gbst();
    void Insert(int no);
    bool Search(int no);
    void Inorder(struct node *head);
    void Preorder(struct node *head);
    void Postorder(struct node *head);
    void DisplayInorder();
    void DisplayPreorder();
    void DisplayPostorder();
    int CountNodes(struct node *head);
    int CountParentNodes(struct node *head);
    int CountLeafNodes(struct node *head);
    int CountTotalNodes();
    int CountTotalParentNodes();
    int CountTotalLeafNodes();
};

Gbst :: Gbst()
{
    head = NULL;
    iCount = 0;
}
void Gbst :: Insert(int no)
{
    struct node *newn = NULL;

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
                cout<<"Unable to insert as value is duplicate\n";
                free(newn);
                break;
            }

        }
    }

}

bool Gbst :: Search(int no)
{
    bool bFlag = false;
    struct node *temp = head;

    while(temp != NULL)
    {
        if(no == temp->data)
        {
            bFlag = true;
            break;
        }
        else if(no < temp->data)
        {
            temp = temp->lchild;
        }
        else if(no > temp->data)
        {
            temp = temp->rchild;
        }
    }
    return bFlag;
}

void Gbst :: Inorder(struct node *head)
{
    if(head != NULL)
    {
        Inorder(head->lchild);
        cout<<head->data<<endl;
        Inorder(head->rchild);
    }
}

void Gbst :: Preorder(struct node *head)
{
    if(head != NULL)
    {
        cout<<head->data<<endl;
        Preorder(head->lchild);
        Preorder(head->rchild);
    }
}

void Gbst :: Postorder(struct node *head)
{
    if(head != NULL)
    {
        Postorder(head->lchild);
        Postorder(head->rchild);
        cout<<head->data<<endl;
    }
}

void Gbst :: DisplayInorder(){Inorder(head);}

void Gbst :: DisplayPreorder(){Preorder(head);}

void Gbst :: DisplayPostorder(){ Postorder(head);}

int Gbst :: CountTotalNodes(){return CountNodes(head);}

int Gbst :: CountTotalParentNodes(){return CountParentNodes(head);}

int Gbst :: CountTotalLeafNodes(){ return CountLeafNodes(head);}


int Gbst :: CountNodes(struct node *head)
{
    static int iCount = 0;

    if(head != NULL)
    {   
        iCount++;
        CountNodes(head-> lchild);
        CountNodes(head-> rchild);
    }
    return iCount;
}

int Gbst :: CountParentNodes(struct node *head)
{
      static int iCount = 0;

    if(head != NULL)
    {   
        if( head ->rchild  != NULL || head->lchild != NULL)
        {
            iCount++;
        }
        CountParentNodes(head-> lchild);
        CountParentNodes(head-> rchild);
    }
    return iCount;
}

int Gbst :: CountLeafNodes(struct node *head)
{
     static int iCount = 0;

    if(head != NULL)
    {   
        if( head ->rchild  == NULL && head->lchild == NULL)
        {
            iCount++;
        }
        CountLeafNodes(head-> lchild);
        CountLeafNodes(head-> rchild);
    }
    return iCount;
}


int main()
{
    Gbst bobj;
    int iRet = 0;
    bool bRet = false;

    bobj.Insert(51);
    bobj.Insert(81);
    bobj.Insert(91);
    bobj.Insert(61);
    bobj.Insert(21);
    bobj.Insert(11);
    cout<<"Inorder Traversal"<<endl;
    bobj.DisplayInorder();
    cout<<"Preorder vTraversal"<<endl;
    bobj.DisplayPreorder();
    cout<<"Post Traversal"<<endl;
    bobj.DisplayPostorder();

    iRet = bobj.CountTotalNodes();
    cout<<"Total Nodes are:"<<iRet<<endl;
    iRet = bobj.CountTotalParentNodes();
    cout<<" Total Parent Nodes are:"<<iRet<<endl;
    iRet = bobj.CountTotalLeafNodes();
    cout<<" Total Leaf Nodes are:"<<iRet<<endl;

    bRet = bobj.Search(51);
    if(bRet == true)
    {cout<<"Element Found\n";}
    else
    {cout<<"Element Not Found\n";}

    bRet = bobj.Search(25);
    if(bRet == true)
    {cout<<"Element Found\n";}
    else
    {cout<<"Element Not Found\n";}

    bRet = bobj.Search(61);
    if(bRet == true)
    {cout<<"Element Found\n";}
    else
    {cout<<"Element Not Found\n";}


    return 0;
}

