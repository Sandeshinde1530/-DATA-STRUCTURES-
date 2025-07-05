//30.48 specificd
// 34.50 total GENERIC
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
class GBST
{
    public:
    T data;
    struct node<T> *head;

    GBST();
    void Insert(T no);
    bool Search(T no);
    void Inorder(struct node<T>  *temp);
    void Preorder(struct node<T>  *temp);
    void Postorder(struct node<T>  *temp);
    int TotalNodes(struct node<T> *temp);
    int ParentNodes(struct node<T> *temp);
    int LeafNodes(struct node<T> *temp);
    void DisplayInorder();
    void DisplayPreorder();
    void DisplayPostorder();
    int CountTotalNodes();
    int CountParentNodes();
    int CountLeafNodes();

};

template <class T>
GBST<T> :: GBST()
{
    head = NULL;
}

template <class T>
void GBST<T>::  Insert(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->lchild  = NULL;
    newn->rchild  = NULL;

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
                if( temp ->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)
            {
                if( temp ->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else if(no == temp->data)
            {
                cout<<"Unable to insert value is duplicate\n";
                delete newn;
                break;
            }
        }
    }
}

template <class T>
bool GBST<T>::  Search(T no)
{
    bool bFlag = false;
    struct node<T> *temp = head;

    while(temp != NULL)
    {
        if(no  == temp->data)
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
void GBST<T>::  Inorder(struct node<T>  *temp)
{
    if(temp != NULL)
    {
        Inorder(temp->lchild);
        cout<<temp->data<<endl;
        Inorder(temp->rchild);
    }

}

template <class T>
void GBST<T>::  Preorder(struct node<T>  *temp)
{
     if(temp != NULL)
    {
        cout<<temp->data<<endl;
        Preorder(temp->lchild);
        Preorder(temp->rchild);
    }
}

template <class T>
void GBST<T>::  Postorder(struct node<T>  *temp)
{
    if(temp != NULL)
    {
        Postorder(temp->lchild);
        Postorder(temp->rchild);
        cout<<temp->data<<endl;
    }
}

template <class T>
int  GBST<T>:: TotalNodes(struct node<T> *temp)
{
    static int iCount = 0;

    if( temp != NULL)
    {
        iCount++;
        TotalNodes(temp->lchild);
        TotalNodes(temp->rchild);
    }
    return iCount;
}

template <class T>
int  GBST<T>:: ParentNodes(struct node<T> *temp)
{
    static int iCount = 0;

    if( temp != NULL)
    {
        if(temp->lchild  != NULL || temp->rchild != NULL)
        {iCount++;}
        ParentNodes(temp->lchild);
        ParentNodes(temp->rchild);
    }
    return iCount;
}

template <class T>
int  GBST<T>:: LeafNodes(struct node<T> *temp)
{
    static int iCount = 0;

    if( temp != NULL)
    {
        if(temp->lchild  == NULL && temp->rchild == NULL)
        {iCount++;}
        LeafNodes(temp->lchild);
        LeafNodes(temp->rchild);
    }
    return iCount;
}

template <class T>
void GBST<T>::  DisplayInorder()
{
    cout<<"Displaying Inorder\n";
    Inorder(head);
}

template <class T>
void GBST<T>::  DisplayPreorder()
{
     cout<<"Displaying Preorder\n";
    Preorder(head);
}

template <class T>
void GBST<T>::  DisplayPostorder()
{
    cout<<"Displaying Postorder\n";
    Postorder(head);
}

template <class T>
int  GBST<T>:: CountTotalNodes()
{
    return TotalNodes(head);
}

template <class T>
int  GBST<T>:: CountParentNodes()
{
    return ParentNodes(head);
}

template <class T>
int  GBST<T>:: CountLeafNodes()
{
    return LeafNodes(head);
}


int main()
{
    GBST <float>bobj;
    bool bRet = false;
    int iRet = 0;

    bobj.Insert(51.1231f);
    bobj.Insert(11.1231f);
    bobj.Insert(101.1231f);
    bobj.Insert(21.1231f);
    bobj.Insert(75.1231f);
    bobj.Insert(45.1231f);
    bobj.DisplayInorder();
    bobj.DisplayPreorder();
    bobj.DisplayPostorder();
    iRet = bobj.CountTotalNodes();
    cout<<"total Nodes are:"<<iRet<<endl;
    iRet = bobj.CountParentNodes();
    cout<<"Parent Nodes are:"<<iRet<<endl;
    iRet = bobj.CountLeafNodes();
    cout<<"Leaf Nodes are:"<<iRet<<endl;

    bRet = bobj.Search(51.1231);
    if(bRet == true)
    {   
        cout<<"Found\n";

    }
    else
    {
        cout<< "NOt FOund\n";
    } 
    bRet = bobj.Search(511.1231);
    if(bRet == true)
    {   
        cout<<"Found\n";

    }
    else
    {
        cout<< "NOt FOund\n";
    } 

    bRet = bobj.Search(21.1231);
    if(bRet == true)
    {   
        cout<<"Found\n";

    }
    else
    {
        cout<< "NOt FOund\n";
    } 
    
    return 0;
}