#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}NODE, *PNODE;

class BST
{
public:
    PNODE head;

    BST()
    {
        head = NULL;
    }

    void Insert(int no)
    {
        PNODE newn = new NODE;
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
                else
                {
                    cout << "Unable to Insert as value is duplicate\n";
                    delete newn;
                    break;
                }
            }
        }
    }

    bool Search(int no)
    {
        PNODE temp = head;

        while(temp != NULL)
        {
            if(no == temp->data)
                return true;
            else if(no > temp->data)
                temp = temp->rchild;
            else
                temp = temp->lchild;
        }
        return false;
    }

    void Inorder(PNODE temp)
    {
        if(temp != NULL)
        {
            Inorder(temp->lchild);
            cout << temp->data << "\n";
            Inorder(temp->rchild);
        }
    }

    void Preorder(PNODE temp)
    {
        if(temp != NULL)
        {
            cout << temp->data << "\n";
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
            cout << temp->data << "\n";
        }
    }

    int CountNodes(PNODE temp)
    {
        if(temp == NULL)
            return 0;
        return 1 + CountNodes(temp->lchild) + CountNodes(temp->rchild);
    }

    int CountParentNodes(PNODE temp)
    {
        if(temp == NULL)
            return 0;
        if(temp->lchild != NULL || temp->rchild != NULL)
            return 1 + CountParentNodes(temp->lchild) + CountParentNodes(temp->rchild);
        else
            return CountParentNodes(temp->lchild) + CountParentNodes(temp->rchild);
    }

    int CountLeafNodes(PNODE temp)
    {
        if(temp == NULL)
            return 0;
        if(temp->lchild == NULL && temp->rchild == NULL)
            return 1;
        else
            return CountLeafNodes(temp->lchild) + CountLeafNodes(temp->rchild);
    }

    // Wrapper methods for external calls
    void DisplayInorder() { Inorder(head); }
    void DisplayPreorder() { Preorder(head); }
    void DisplayPostorder() { Postorder(head); }
    int GetTotalNodes() { return CountNodes(head); }
    int GetParentNodes() { return CountParentNodes(head); }
    int GetLeafNodes() { return CountLeafNodes(head); }
};
