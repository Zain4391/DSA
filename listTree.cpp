#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
    int data;
    TreeNode *left,*right;

    TreeNode()
    {
        left=NULL;
        right=NULL;
    }

    TreeNode(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};


class BinaryTree
{
    private :
    TreeNode *head,*tail;

    void list_insert(int data)
    {
        TreeNode *newNode = new TreeNode(data);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            newNode->left = tail;
            tail->right = newNode;
            tail = newNode;
        }
    }
    public:
    TreeNode *root;

    TreeNode*make_root(TreeNode *obj)
    {
        root = obj;
        return root;
    }

    void insert(TreeNode*&root_ptr,int val)
    {
        TreeNode *newNode = new TreeNode(val);

        if(root_ptr == NULL)
        {
            root_ptr = newNode;
            return;
        }

        queue<TreeNode*> q;
        q.push(root_ptr);
        while(!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();

            if(current->left == NULL)
            {
                current->left = newNode;
                return;
            }
            else
            {
                q.push(current->left);
            }
            if(current->right == NULL)
            {
                current->right = newNode;
                return;
            }
            else
            {
                q.push(current->right);
            }
        }
    }

    void inOrder(TreeNode*root_ptr)
    {
        if(root_ptr!=NULL)
        {
            inOrder(root_ptr->left);
            cout<<root_ptr->data<<" ";
            inOrder(root_ptr->right);
        }
    }

    void BuildList(TreeNode *&root_ptr)
    {
        if(root_ptr == NULL)
        {
            return;
        }

        BuildList(root_ptr->left);
        list_insert(root_ptr->data);
        BuildList(root_ptr->right);
    }

    void Display()
    {
        TreeNode *temp = head;

        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->right;
        }

        cout<<endl;
    }
};

int main()
{
    BinaryTree tree;
    tree.make_root(new TreeNode(1));

    tree.insert(tree.root, 2);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 4);
    tree.insert(tree.root, 5);

    cout << "In-order traversal: ";
    tree.inOrder(tree.root);
    cout << endl;
    tree.BuildList(tree.root);
    cout<<"Linked List built from in-Order traversal: ";
    tree.Display();

    return 0;
}