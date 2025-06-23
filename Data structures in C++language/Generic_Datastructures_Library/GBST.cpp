#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node<T> *lchild;
    struct node<T> *rchild;
};

template <class T>
class Gbst
{
    public:
    int iCount;
    struct node<T> *head;

    Gbst();
    void Insert(T no);
    bool Search(T no);
    void Inorder(struct node<T> *head);
    void Preorder(struct node<T> *head);
    void Postorder(struct node<T> *head);
    void DisplayInorder();
    void DisplayPreorder();
    void DisplayPostorder();
    int CountNodes(struct node<T> *head);
    int CountParentNodes(struct node<T> *head);
    int CountLeafNodes(struct node<T> *head);
    int CountTotalNodes();
    int CountTotalParentNodes();
    int CountTotalLeafNodes();
};


template <class T>
Gbst<T> :: Gbst()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void Gbst<T>  :: Insert(T no)
{
    struct node<T> *newn = NULL;

    newn = new node<T> ;
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        struct node<T> *temp = head;
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
                delete newn;
                break;
            }

        }
    }

}

template <class T>
bool Gbst<T>  :: Search(T no)
{
    bool bFlag = false;
    struct node<T> *temp = head;

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

template <class T>
void Gbst<T>  :: Inorder(struct node<T> *head)
{
    if(head != NULL)
    {
        Inorder(head->lchild);
        cout<<head->data<<endl;
        Inorder(head->rchild);
    }
}

template <class T>
void Gbst<T>  :: Preorder(struct node<T> *head)
{
    if(head != NULL)
    {
        cout<<head->data<<endl;
        Preorder(head->lchild);
        Preorder(head->rchild);
    }
}

template <class T>
void Gbst<T>  :: Postorder(struct node<T> *head)
{
    if(head != NULL)
    {
        Postorder(head->lchild);
        Postorder(head->rchild);
        cout<<head->data<<endl;
    }
}

template <class T>
void Gbst<T>  :: DisplayInorder(){Inorder(head);}

template <class T>
void Gbst<T>  :: DisplayPreorder(){Preorder(head);}

template <class T>
void Gbst<T>  :: DisplayPostorder(){ Postorder(head);}

template <class T>
int Gbst<T>  :: CountTotalNodes(){return CountNodes(head);}

template <class T>
int Gbst<T>  :: CountTotalParentNodes(){return CountParentNodes(head);}

template <class T>
int Gbst<T>  :: CountTotalLeafNodes(){ return CountLeafNodes(head);}


template <class T>
int Gbst<T>  :: CountNodes(struct node<T> *head)
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

template <class T>
int Gbst<T>  :: CountParentNodes(struct node<T> *head)
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

template <class T>
int Gbst<T>  :: CountLeafNodes(struct node<T> *head)
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
    Gbst<float>bobj;
    float iRet = 0;
    bool bRet = false;

    bobj.Insert(511.234);
    bobj.Insert(811.234);
    bobj.Insert(911.234);
    bobj.Insert(611.234);
    bobj.Insert(211.234);
    bobj.Insert(111.234);
    cout<<"Inorder Traversal"<<endl;
    bobj.DisplayInorder();
    cout<<"Preorder Traversal"<<endl;
    bobj.DisplayPreorder();
    cout<<"Post Traversal"<<endl;
    bobj.DisplayPostorder();

    iRet = bobj.CountTotalNodes();
    cout<<"Total Nodes are:"<<iRet<<endl;
    iRet = bobj.CountTotalParentNodes();
    cout<<" Total Parent Nodes are:"<<iRet<<endl;
    iRet = bobj.CountTotalLeafNodes();
    cout<<" Total Leaf Nodes are:"<<iRet<<endl;

    bRet = bobj.Search(511.234);
    if(bRet == true)
    {cout<<"Element Found\n";}
    else
    {cout<<"Element Not Found\n";}

    bRet = bobj.Search(251.234);
    if(bRet == true)
    {cout<<"Element Found\n";}
    else
    {cout<<"Element Not Found\n";}

    bRet = bobj.Search(611.234);
    if(bRet == true)
    {cout<<"Element Found\n";}
    else
    {cout<<"Element Not Found\n";}


    return 0;
}

