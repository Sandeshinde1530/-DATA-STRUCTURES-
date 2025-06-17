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

};

int main()
{


    return 0;
}
