#include <iostream>

class TreeNode 
{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) 
    {
        data = val;
        left = right = NULL;
    }
};

void inorderTraversal(TreeNode* root) 
{
    if(root != NULL)
    {
        inorderTraversal(root->left);
        std::cout<<root->data<<" ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(TreeNode* root) 
{
    if(root != NULL)
    {
        std::cout<<root->data<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode* root) 
{
    if(root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        std::cout<<root->data<<" ";
    }
}

int main() 
{
    // Create a sample binary tree
    // You can customize this tree with your own values

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Print traversals
    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Preorder Traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    postorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
