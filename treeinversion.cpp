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

void invertTree(TreeNode* root) 
{
    if(root == NULL)
    {
        return;
    }

    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);
}

void inorderTraversal(TreeNode* root) 
{
    if(root != NULL)
    {
        inorderTraversal(root->left);
        std::cout<<root->data<<" ";
        inorderTraversal(root->right);
    }
}

bool isMirror(TreeNode *root1,TreeNode *root2)
{
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if(root1->data != root2->data)
    {
        return false;
    }

    bool ls = isMirror(root1->left,root2->left);
    bool rs = isMirror(root1->right,root2->right);

    return ls && rs;
}

int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

        
    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(7);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(3);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(9);
    
    std::cout<<"Tree before inversion: ";
    inorderTraversal(root);

    /*invertTree(root);
    std::cout<<"\n\nTree after inversion: ";
    inorderTraversal(root);*/

    if(isMirror(root,root2))
    {
       std:: cout<<"\nTree1 and Tree2 are mirrors.\n";
    }
    else
    {
        std::cout<<"Not mirrors.\n";
    }

    return 0;

}