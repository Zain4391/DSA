#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node()
    {
        data=0;
        left = NULL;
        right = NULL;
        height = 0;
    }

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVLtree
{
    public:
    Node *root;
    
    AVLtree()
    { 
        root = NULL;
    }

    Node*make_root(Node *obj)
    {
        root=obj;
        return root;
    }

    void insert(Node*&root_ptr,int val)
    {
        if(root_ptr==NULL)
        {
            root_ptr=new Node (val);
            return;
        }
        else
        {
            if(val < root_ptr->data)
            {
                insert(root_ptr->left,val);
            }
            else if(val >= root_ptr->data)
            {
                insert(root_ptr->right,val);
            }
        }

        updateHeight(root_ptr); //updating the height of node

        int bf=balance_factor(root_ptr);

        if(bf > 1 && val < root_ptr->left->data) //left-left case
        {
            Rotate_Right(root_ptr);
        }

        else if(bf < -1 && val >= root_ptr->right->data) //right-right case
        {
            Rotate_Left(root_ptr);
        }

        else if(bf > 1 && val >= root_ptr->left->data) //left-right case
        {
            Rotate_Left(root_ptr->left);
            Rotate_Right(root_ptr);
        }

        else if(bf < -1 && val < root_ptr->right->data) //right-left case
        {
            Rotate_Right(root_ptr->right);
            Rotate_Left(root_ptr);
        }
    }

    void delete_node(Node*& root_ptr, int key) 
    {
    if (root_ptr == NULL) 
    {
        return;
    }

    if (key < root_ptr->data) 
    {
        delete_node(root_ptr->left, key);
    } 
    else if (key > root_ptr->data) 
    {
        delete_node(root_ptr->right, key);
    } 
    else 
    {
        if (root_ptr->left == NULL && root_ptr->right == NULL) 
        { // leaf node
            delete root_ptr;
            root_ptr = NULL;
        } else if (root_ptr->right == NULL) 
        { // only left child
            Node* temp = root_ptr;
            root_ptr = root_ptr->left;
            delete temp;
        } 
        else if (root_ptr->left == NULL) 
        { // only right child
            Node* temp = root_ptr;
            root_ptr = root_ptr->right;
            delete temp;
        } 
        else 
        {
            // two children
            Node* temp = find_in_order_succesor(root_ptr->right);
            root_ptr->data = temp->data;
            delete_node(root_ptr->right, temp->data);
        }
    }

    

    updateHeight(root_ptr); // updating the height of node

    int bf = balance_factor(root_ptr);

    if (bf > 1 && balance_factor(root_ptr->left) >= 0) 
    { // left-left case
        Rotate_Right(root_ptr);
    } 
    else if (bf > 1 && balance_factor(root_ptr->left) < 0) 
    { // left-right case
        Rotate_Left(root_ptr->left);
        Rotate_Right(root_ptr);
    } 
    else if (bf < -1 && balance_factor(root_ptr->right) <= 0) 
    { // right-right case
        Rotate_Left(root_ptr);
    } 
    else if (bf < -1 && balance_factor(root_ptr->right) > 0) 
    { // right-left case
        Rotate_Right(root_ptr->right);
        Rotate_Left(root_ptr);
    }
}

    Node*find_in_order_succesor(Node *ptr)
    {
        while(ptr->left!=NULL)
        {
            ptr=ptr->left;
        }

        return ptr;
    }

    void traversal(Node *root_ptr)
    {
        if(root_ptr!=NULL)
        {
            traversal(root_ptr->left);
            cout<<root_ptr->data<<" ";
            traversal(root_ptr->right);
        }
    }

    int tree_height(Node *root_ptr)
    {
        if(root_ptr==NULL)
        {
            return 0;
        }

        return root_ptr->height;
    }

    int balance_factor(Node*root_ptr)
    {
        if(root_ptr==NULL)
        {
            return 0;
        }

        return tree_height(root_ptr->left)-tree_height(root_ptr->right);
    }
    
    void updateHeight(Node *root_ptr)
    {
        if(root_ptr==NULL)
        {
            return;
        }

        root_ptr->height = 1 + max(tree_height(root_ptr->left),tree_height(root_ptr->right));
    }

    void Rotate_Right(Node *&root_ptr)
    {
        Node *temp=root_ptr->left;
        Node *temp2=temp->right;

        temp->right=root_ptr;
        root_ptr->left=temp2;

        updateHeight(root_ptr);
        updateHeight(temp);

        root_ptr=temp;
    }

    void Rotate_Left(Node *&root_ptr)
    {
        Node *temp=root_ptr->right;
        Node *temp2=temp->left;

        temp->left=root_ptr;
        root_ptr->right=temp2;

        updateHeight(root_ptr);
        updateHeight(temp);

        root_ptr=temp;
    }
};

int main()
{
    AVLtree tree;
    tree.make_root(new Node (6));
    tree.insert(tree.root,5);
    tree.insert(tree.root,4);
    tree.insert(tree.root,12);
    tree.insert(tree.root,33);
    tree.insert(tree.root,1);
    tree.insert(tree.root,51);
    cout<<"Before deleting: ";
    tree.traversal(tree.root);
    cout<<endl;
    cout<<"Height: "<<tree.tree_height(tree.root)<<endl;
    cout<<"Balance factor: "<<tree.balance_factor(tree.root)<<endl;
    cout<<endl<<endl;
    cout<<"After deleting: ";
    tree.delete_node(tree.root,6);
    tree.traversal(tree.root);
    cout<<endl;
    cout<<"Height: "<<tree.tree_height(tree.root)<<endl;
    cout<<"Balance factor: "<<tree.balance_factor(tree.root)<<endl;
    return 0;
}