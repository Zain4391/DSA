#include<iostream>
#include<queue>
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode *left,*right;

    TreeNode()
    {
        left = right = NULL;
    }

    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
};

//Helper Func
int countRoutesStartingFromNode(TreeNode *node, int K, int currentSum = 0) 
{
    if (node == NULL) 
    {
        return 0;
    }

    currentSum += node->val;

    int count = 0;
    if (currentSum == K) 
    {
        count = 1;
    }

    count += countRoutesStartingFromNode(node->left, K, currentSum);
    count += countRoutesStartingFromNode(node->right, K, currentSum);

    return count;
}


int counttillK(TreeNode *root,int K)
{
    if(root == NULL)
    {
        return 0;
    }

    queue<TreeNode*> q;
    q.push(root);
    int count = 0;

    while(!q.empty())
    {
        TreeNode * current = q.front();
        q.pop();

        count+=countRoutesStartingFromNode(current , K);

        if(current->left!=NULL)
        {
            q.push(current->left);
        }
        if(current->right!=NULL)
        {
            q.push(current->right);
        }
    }

    return count;
}

int main() 
{
    // Example usage:
    // Construct a binary tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    int k = 8;
    int result = counttillK(root, k);

    cout << "Number of routes with sum " << k << ": " << result << endl;

    return 0;
}