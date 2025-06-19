#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}NODE , *PNODE , **PPNODE;

class BST
{
    public:
        int iCount;
        PNODE head;

        BST()
        {
            iCount = 0;
            head = NULL;
        }

        void Insert(int no)
        {
            PNODE newn = NULL;
            newn = new NODE;
            newn->data = no;
            newn->lchild = NULL;
            newn->rchild = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                PNODE temp = head;
                while(1)
                {
                    if( no > temp->data)
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
                    else if(no ==  temp->data)
                    {
                        cout<<"Unable to Insert As value is Duplicate\n";
                        delete newn;
                        break;
                    }
                }
            }

        }

        void Inorder(PNODE temp)
        {
            if(temp != NULL)
            {
                Inorder(temp->lchild);
                cout<<temp->data<<endl;
                Inorder(temp->rchild);
            }
        }
       
        void Preorder(PNODE temp)
        {
            if(temp != NULL)
            {
                cout<<temp->data<<endl;
                Preorder(temp->lchild);
                Preorder(temp->rchild);
            }
        }
        
        void Postorder(PNODE temp)
        {
            if(temp != NULL)
            {
                Postorder(temp->lchild);
                Postorder(temp->rchild);
                cout<<temp->data<<endl;
            }
        }

        int CountNodes(PNODE temp)
        {
            static int iCount = 0 ;

            if(temp != NULL)
            {
                iCount++;
                CountNodes(temp->lchild);
                CountNodes(temp->rchild);
            }
            return iCount;
        }

        int CountParentNodes(PNODE temp)
        {
            static int iCount = 0 ;

            if(temp != NULL)
            {
                if(temp->rchild != NULL || temp->lchild != NULL)
                {
                    iCount++;
                }
                CountParentNodes(temp->lchild);
                CountParentNodes(temp->rchild);
            }
            return iCount;
        }

        int CountLeafNodes(PNODE temp)
        {
            static int iCount = 0 ;

            if(temp != NULL)
            {
                if(temp->rchild == NULL && temp->lchild == NULL)
                {
                    iCount++;
                }
                CountLeafNodes(temp->lchild);
                CountLeafNodes(temp->rchild);
            }
            return iCount;
        }

        void DisplayInorder()
        {
            cout<<"Displaying Inorder Traversal\n";
            Inorder(head);
        }
        void DisplayPreorder()
        {
             cout<<"Displaying Preorder Traversal\n";
             Preorder(head);
        }

        void DisplayPostorder()
        {
             cout<<"Displaying PostOrder Traversal\n";
            Postorder(head);
        }

        int TotalNodes(){ return CountNodes(head);}
        int TotalParentNodes(){ return CountParentNodes(head);}
        int TotalLeafNodes(){ return CountLeafNodes(head);}

};

int main()
{
    BST bobj;

    bobj.Insert(51);
    bobj.Insert(21);
    bobj.Insert(101);
    bobj.Insert(31);
    bobj.Insert(45);
    bobj.Insert(151);
    bobj.Insert(71);

    bobj.DisplayInorder();
    bobj.DisplayPreorder();
    bobj.DisplayPostorder();

    cout<<"Total Nodes in the tree are:"<<bobj.TotalNodes()<<endl;
    cout<<"Total Parent Nodes in the tree are:"<<bobj.TotalParentNodes()<<endl;
    cout<<"Total Leaf Nodes in the tree are:"<<bobj.TotalLeafNodes()<<endl;

    return 0;
}
