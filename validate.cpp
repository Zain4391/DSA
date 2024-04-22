#include <iostream>
#include <climits>

class TreeNode 
{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isValidBST(TreeNode* root,int min = INT_MIN, int max = INT_MAX) 
{
    if(root == NULL)
    {
        return true;
    }

    if(root->data < min || root->data > max)
    {
        return false;
    }

    bool leftside = isValidBST(root->left,min,root->data);
    bool rightside = isValidBST(root->right,root->data,max);

    return leftside && rightside;
}

int maxDepth(TreeNode* root) 
{
    if(root == NULL)
    {
        return 0;
    }

    return std::max(maxDepth(root->left),maxDepth(root->right)) + 1;
}

int main() 
{
    // Create a sample binary tree
    // You can customize this tree with your own values

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // Check if the tree is a valid BST
    if (isValidBST(root)) {
        std::cout << "The tree is a valid BST." << std::endl;
    } else {
        std::cout << "The tree is not a valid BST." << std::endl;
    }

    std::cout<<"Max Depth : "<<maxDepth(root)<<std::endl;

    return 0;
}
