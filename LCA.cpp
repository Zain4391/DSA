#include <iostream>

class TreeNode 
{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, int node1, int node2) 
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == node1 || root->data == node2)
    {
        return root;
    }

    TreeNode *leftN = lowestCommonAncestor(root->left,node1,node2);
    TreeNode *rightN =lowestCommonAncestor(root->right,node1,node2);

    TreeNode*current;

    if(leftN != NULL)
    {
        current = leftN;
    }
    else
    {
        current = rightN;
    }

    return current;
}


int main() 
{
    // Create a sample binary search tree
    // You can customize this tree with your own values

    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    // Example: Find the lowest common ancestor of nodes 15 and 25
    TreeNode* lca = lowestCommonAncestor(root, 10, 30);

    // Print the value of the lowest common ancestor
    std::cout << "Lowest Common Ancestor: " << lca->data << std::endl;

    return 0;
}
