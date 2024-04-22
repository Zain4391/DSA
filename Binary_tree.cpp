#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node *left,*right;

    Node()
    {
        data=0;
        left=right=NULL;
    }

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class BinaryTree
{
    public:
    Node *root;

    BinaryTree(){ root = NULL;}

    Node* make_root(Node *obj)
    {
        root = obj;
        return root;
    }

    void Insert(Node *&root_ptr,int val)
    {
        Node *newNode = new Node (val);

        if(root_ptr == NULL)
        {
            root_ptr = newNode;
            return;
        }

        queue<Node*> nodes; 
        nodes.push(root_ptr);

        while(!nodes.empty())
        {
            Node *curr = nodes.front();
            nodes.pop();

            if(curr->left==NULL)
            {
                curr->left = newNode;
                return;
            }
            else
            {
                nodes.push(curr->left);
            }

            if(curr->right==NULL)
            {
                curr->right = newNode;
                return;
            }
            else
            {
                nodes.push(curr->right);
            }
        }
    }

    void Inorder(Node*root_ptr)
    {
        if(root_ptr!=NULL)
        {
            Inorder(root_ptr->left);
            cout<<root_ptr->data<<" ";
            Inorder(root_ptr->right);
        }
    }

    void delete_node(Node *&root_ptr, int key)
   {
    if (root_ptr == NULL)
    {
        return;
    }

    if (root_ptr->left != NULL)
    {
        delete_node(root_ptr->left, key);
    }

    if (root_ptr->right != NULL)
    {
        delete_node(root_ptr->right, key);
    }

    if (root_ptr->data == key)
    {
        if (root_ptr->left == NULL && root_ptr->right == NULL)
        {
            delete root_ptr;
            root_ptr = NULL;
        }
        else if (root_ptr->left == NULL)
        {
            Node *temp = root_ptr;
            root_ptr = root_ptr->right;
            delete temp;
        }
        else if (root_ptr->right == NULL)
        {
            Node *temp = root_ptr;
            root_ptr = root_ptr->left;
            delete temp;
        }

        else
        {
            Node *temp = inorder_successor(root_ptr->right);
            root_ptr->data = temp->data;
            delete_node(root_ptr->right, temp->data);
        }
    }
}

Node *inorder_successor(Node *ptr)
{
    if(ptr==NULL)
    {
        return NULL;
    }

    while(ptr->left!=NULL)
    {
        ptr = ptr->left;
    }

    return ptr;
}

    void preorder(Node*root_ptr)
    {
        if(root_ptr!=NULL)
        {
            cout<<root_ptr->data<<" ";
            preorder(root_ptr->left);
            preorder(root_ptr->right);
        }
    }

    void postorder(Node*root_ptr)
    {
        if(root_ptr!=NULL)
        {
            postorder(root_ptr->left);
            postorder(root_ptr->right);
            cout<<root_ptr->data<<" ";
        }
    }

    int tree_height(Node *ptr,int height)
    {
        if(ptr==NULL)
        {
            return height;
        }

        int left = tree_height(ptr->left,height);
        int right = tree_height(ptr->right,height);

        return 1 + max(left,right);
    }

    int check_BST(Node *root_ptr, int &count, int min_val, int max_val) 
    {
    if (root_ptr == NULL) 
    {
        return 1; 
    }

    if (root_ptr->data < min_val || root_ptr->data > max_val) 
    {
        return 0; // This subtree is not a BST.
    }

    int left = check_BST(root_ptr->left, count, min_val, root_ptr->data - 1);
    int right = check_BST(root_ptr->right, count, root_ptr->data + 1, max_val);

    if (left && right) 
    {
        count++;
    }

    return count;
    }

};

int main()
{
    //Node *tree_root = new Node (6);
    BinaryTree tree;
    tree.make_root(new Node (50));
    tree.Insert(tree.root,25);
    tree.Insert(tree.root,7);
    tree.Insert(tree.root,2);
    tree.Insert(tree.root,38);
    int count = 1;
    cout<<tree.check_BST(tree.root,count,INT_MIN,INT_MAX)<<endl;
    tree.Inorder(tree.root);
    cout<<"\ntree height: "<<tree.tree_height(tree.root,0)<<endl;
    cout<<endl;
    tree.delete_node(tree.root,6);
    tree.Inorder(tree.root);
    return 0;
}