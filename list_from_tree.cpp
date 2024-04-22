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

class ListNode
{
    public:
    int data;
    ListNode *next,*prev;

    ListNode()
    {
        next = prev = NULL;
    }

    ListNode(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

class BinaryTree
{
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
};

class DoublyLinkedList
{
    public:
    ListNode *head, *tail;

    DoublyLinkedList()
    {
        head = tail = NULL;
    }

    void insert(int val)
    {
        ListNode *newNode = new ListNode(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void print()
    {
        ListNode *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout <<endl;
    }

    void BuildList(TreeNode *&root_ptr)
    {
        if(root_ptr == NULL)
        {
            return;
        }

        BuildList(root_ptr->left);
        insert(root_ptr->data);
        BuildList(root_ptr->right);
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

    DoublyLinkedList dll;
    dll.BuildList(tree.root);

    cout << "Doubly Linked List: ";
    dll.print();

    return 0;
}
