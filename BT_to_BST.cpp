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
    TreeNode *deepestNode(TreeNode *&root_ptr, TreeNode *&deepestNode_ptr)
    {
        queue<TreeNode *> q;
        q.push(root_ptr);

        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            deepestNode_ptr = current;

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }

        return deepestNode_ptr;
    }

    void deleteDeepest(TreeNode *&root_ptr, TreeNode *&deepestNode_ptr)
    {
        queue<TreeNode *> q;
        q.push(root_ptr);

        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();

            if (current->right && current->right == deepestNode_ptr)
            {
                delete deepestNode_ptr;
                current->right = NULL;
                return;
            }
            else if (current->left && current->left == deepestNode_ptr)
            {
                delete deepestNode_ptr;
                current->left = NULL;
                return;
            }

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }

    void inOrderTraversal(TreeNode *&root_ptr,vector<int> &nodes)
    {
        if(root_ptr!=NULL)
        {
            inOrderTraversal(root_ptr->left,nodes);
            nodes.push_back(root_ptr->data);
            inOrderTraversal(root_ptr->right,nodes);
        }
    }

    TreeNode*BST(vector<int> nodes, int start, int end)
    {
        if(start > end)
        {
            return NULL;
        }

        int mid = (start + end) / 2;
        TreeNode *root_ptr = new TreeNode(nodes[mid]);
        root_ptr->left = BST(nodes,start, mid - 1);
        root_ptr->right = BST (nodes, mid+1,end);

        return root_ptr;
    }

    public:
    TreeNode *root;

    void inOrder(TreeNode*root_ptr)
    {
        if(root_ptr!=NULL)
        {
            inOrder(root_ptr->left);
            cout<<root_ptr->data<<" ";
            inOrder(root_ptr->right);
        }
    }

    void deleteNode(TreeNode *&root_ptr, int key)
    {
        if (root_ptr == NULL)
            return;

        if (root_ptr->left == NULL && root_ptr->right == NULL)
        {
            delete root_ptr;
            root_ptr = NULL;
            return;
        }

        TreeNode *keyNode = NULL;
        TreeNode *deepNode = NULL;
        queue<TreeNode *> q;
        q.push(root_ptr);

        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();

            if (current->data == key)
                keyNode = current;

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }

        if (keyNode != NULL)
        {
            deepNode = deepestNode(root_ptr, deepNode);
            keyNode->data = deepNode->data;
            deleteDeepest(root_ptr, deepNode);
        }
    }

    void ConvertToBST()
    {
        vector<int> nodes;
        inOrderTraversal(root,nodes);
        sort(nodes.begin(),nodes.end());
        root = BST(nodes,0, nodes.size() - 1);
    }

    int getrootdata()
    {
        return root->data;
    }
};

int main()
{
    BinaryTree tree;
    tree.root = new TreeNode(1);
    tree.root->left = new TreeNode(2);
    tree.root->right = new TreeNode(3);
    tree.root->left->left = new TreeNode(4);
    tree.root->left->right = new TreeNode(5);
    tree.root->right->left = new TreeNode(7);
    tree.root->right->right = new TreeNode(-1);

    cout << "In-order traversal: ";
    tree.inOrder(tree.root);
    cout << endl;
    tree.ConvertToBST();
    tree.inOrder(tree.root);
    cout<<endl;
    cout<<tree.getrootdata()<<endl;
    return 0;

}
