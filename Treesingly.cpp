#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left,*right;

    Node()
    {
        left=NULL;
        right=NULL;
    }

    Node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};

class BinaryTree
{
    public:

    Node *root;

    BinaryTree()
    {
        root=NULL;
    }

    Node *make_root(int x)
    {
        Node *newNode = new Node (x);
        root=newNode;

        return root;
    }

    void insert(Node *&root_ptr,int val)
    {
        Node *newNode = new Node (val);

        if(root_ptr==NULL)
        {
            root_ptr=new Node (val);
        }
        else
        {
            if(root_ptr->data > val)
            {
                insert(root_ptr->left,val); //log(n) complexity , need to traverse uptil we find the required position
            }
            else if(root_ptr->data < val)
            {
                insert(root_ptr->right,val); //log(n) complexity , need to traverse uptil we find the required position
            }
        }
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

    void pre_order(Node *root_ptr)
	{
		if(root_ptr!=NULL)
		{
			cout<<root_ptr->data<<" ";
			pre_order(root_ptr->left);
			pre_order(root_ptr->right);
		}
	}

		void post_order(Node *root_ptr)
		{
			if(root_ptr!=NULL)
			{
				post_order(root_ptr->left);
				post_order(root_ptr->right);
				cout<<root_ptr->data<<" ";
			}
		}

    int Treeheight(Node *root_ptr,int height)
    {
        if(root_ptr==NULL)
        {
            return height;
        }
            if(root_ptr->left!=NULL)
            {
                return Treeheight(root_ptr->left,height+1);
            }

            if(root_ptr->right!=NULL)
            {
                return Treeheight(root_ptr->right,height+1);
            }

        return height;
    }

    bool Search(Node *root_ptr,int val)
    {
        if(root_ptr==NULL)
        {
            return false;
        }

        if(root_ptr->data==val)
        {
            return true;
        }

        if(root_ptr->left!=NULL)
        {
            if(Search(root_ptr->left,val))
            {
                return true;
            }
        }

        if(root_ptr->right!=NULL)
        {
            if(Search(root_ptr->right,val))
            {
                return true;
            }
        }

        return false;
    }

    void delete_node( Node *&root_ptr,int key)
    {
        if(root_ptr==NULL)
        {
            return;
        }

        if(key < root_ptr->data)
        {
            delete_node(root_ptr->left,key);
        }
        else if(key > root_ptr->data)
        {
            delete_node(root_ptr->right,key);
        }
        else
        {
            if(root_ptr->left==NULL && root_ptr->right==NULL) //leaf node
            {
                delete root_ptr;
                root_ptr=NULL;
            }
            else if(root_ptr->right==NULL) //only left child
            {
                Node* temp = root_ptr;
                root_ptr=root_ptr->left;
                delete temp;
            }
            else if(root_ptr->left==NULL) //only right child
            {
                Node *temp=root_ptr;
                root_ptr=root_ptr->right;
                delete temp;
            } //for a parent with 2 child nodes
            else
            {
                Node *temp=find_in_order_succesor(root_ptr->right);
                root_ptr->data = temp->data;
                delete_node(root_ptr->right,temp->data);
            }
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

    int Node_sum(Node *root_ptr,int sum)
    {
        if(root_ptr==NULL)
        {
            return sum;
        }

        sum=sum+root_ptr->data;

        if(root_ptr->left!=NULL)
        {
            sum = Node_sum(root_ptr->left,sum);
        }
        if(root_ptr->right!=NULL)
        {
            sum = Node_sum(root_ptr->right,sum);
        }

        return sum;
    }

    int Count_Nodes(Node *root_ptr,int count)
    {
        if(root_ptr==NULL)
        {
            return count;
        }

        count=count+1;

        if(root_ptr->left!=NULL)
        {
            return Count_Nodes(root_ptr->left,count+1);
        }
        if(root_ptr->right!=NULL)
        {
            return Count_Nodes(root_ptr->right,count+1);
        }

        return count;
    }

    Node* Swap(Node *root_ptr)
    {
        if(root_ptr==NULL)
        {
            return root_ptr;
        }

        Node *temp=root_ptr->left;
        root_ptr->left = root_ptr->right;
        root_ptr->right=temp;

        Swap(root_ptr->left);
        Swap(root_ptr->right);

        return root_ptr;
    }

    int count_leaves(Node *root_ptr)
    {
        if(root_ptr==NULL)
        {
            return 0;
        }

        if (root_ptr->left == NULL && root_ptr->right == NULL)
        {
           return 1;
        }
        else
        {
          int left = count_leaves(root_ptr->left);
          int right = count_leaves(root_ptr->right);
          return left+right;
        }
    }

    int Max_Node(Node *root_ptr)
    {
        if(root_ptr->right==NULL)
        {
            return root_ptr->data;
        }

        //will traverse the right side for max value

        return Max_Node(root_ptr->right);
    }

    int Min_Node(Node *root_ptr)
    {
        if(root_ptr->left==NULL)
        {
            return root_ptr->data;
        }

        //will traverse the left side for min value

        return Min_Node(root_ptr->left);
    }

    Node* Tree_from_pre(Node *&root_ptr,int *arr,int &index,int N,int min,int max)
    {
        if(index == N || arr[index] < min || arr[index] > max) //base case
        {
            return NULL;
        }

        root_ptr = new Node(arr[index]);
        index++;
        //2 recursive calls one for each side of the tree
        root_ptr->left = Tree_from_pre(root_ptr->left,arr,index,N,min,root_ptr->data);
        root_ptr->right = Tree_from_pre(root_ptr->right,arr,index,N,root_ptr->data,max);

        return root_ptr;
    }

    Node* Tree_from_post(Node*& root_ptr, int* arr, int& index, int N, int min, int max) 
    {
       if (index < 0 || arr[index] < min || arr[index] > max) 
       {
        return NULL; // Base case
       }

      root_ptr = new Node(arr[index]);
      index--;

      // Create the right subtree first (post-order)
      root_ptr->right = Tree_from_post(root_ptr->right, arr, index, N, root_ptr->data, max);
      root_ptr->left = Tree_from_post(root_ptr->left, arr, index, N, min, root_ptr->data);

     return root_ptr;
   }

   Node*Tree_from_In(Node*&root_ptr,int *arr,int left,int right,int min,int max)
   {
     int mid = (left + right)/2;

     if(left > right || arr[mid] < min || arr[mid] > max)
     {
        return NULL; //base case
     }

     root_ptr = new Node(arr[mid]);
     
     //2 recursive calls one for each side of the tree
     
    root_ptr->left = Tree_from_In(root_ptr->left,arr,left,mid-1,min,root_ptr->data);
    root_ptr->right = Tree_from_In(root_ptr->right,arr,mid+1,right,root_ptr->data,max);

    return root_ptr;
   }
   
};

//combinig trees
class Combine
{
    BinaryTree left_tree;
    BinaryTree right_tree;

    Node *entry;

    void traversal(Node *root_ptr)
    {
        if(root_ptr!=NULL)
        {
            traversal(root_ptr->left);
            cout<<root_ptr->data<<" ";
            traversal(root_ptr->right);
        }
    }

    public:
    Combine(const BinaryTree &tree1,const BinaryTree &tree2,int x)
    {
        entry = new Node (x);
        entry->left = tree1.root;
        entry->right = tree2.root;
    }

    Combine(const Combine &tree1,const Combine &tree2,int x)
    {
        entry = new Node (x);
        entry->left = tree1.entry;
        entry->right = tree2.entry;
    }

    void inorder()
    {
        traversal(entry);
    }


};

int main()
{
    BinaryTree tree;
    tree.make_root(5);
    tree.insert(tree.root, 4);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 11);
    tree.insert(tree.root, 9);
    tree.insert(tree.root,6);
    tree.traversal(tree.root);

    cout<<endl;
    cout<<"The tree height: ";
    cout<<tree.Treeheight(tree.root,0)<<endl;

    bool isThere = tree.Search(tree.root,3);
    if(isThere)
    {
        cout<<"Value found\n";
    }    
    else
    {
        cout<<"Not Found!\n";
    }
    cout<<tree.count_leaves(tree.root)<<endl;
    cout<<"Tree after deletion: ";
    tree.delete_node(tree.root,11);
    tree.traversal(tree.root);
    cout<<"\nSum of Nodes: ";
    cout<<tree.Node_sum(tree.root,0);
    cout<<"\nNumbe of nodes: ";
    cout<<tree.Count_Nodes(tree.root,0)<<endl;
    cout<<tree.Max_Node(tree.root)<<endl;
    cout<<tree.Min_Node(tree.root)<<endl;

    BinaryTree tree2;
    cout<<"Tree from pre-order: ";
    int preorder[] = {8,5,1,7,10,12};
    int N = sizeof(preorder)/sizeof(preorder[0]);
    int index = 0;
    tree2.root = tree2.Tree_from_pre(tree2.root,preorder,index,N,INT_MIN,INT_MAX);
    tree2.pre_order(tree2.root);
    cout<<endl;

    int postorder[] = {1, 4, 3, 6, 8, 7, 5};
    cout<<"Tree from post-order: ";
    int N2 = sizeof(postorder)/sizeof(postorder[0]);
    int index2 = N2-1;
    BinaryTree tree3;
    tree3.root = tree3.Tree_from_post(tree3.root,postorder,index2,N2,INT_MIN,INT_MAX);
    tree3.post_order(tree3.root);
    cout<<endl;

    BinaryTree tree4;
    int inorder[] = {5, 3, 7, 8, 10, 12, 15};
    cout<<"Tree from In-order: ";
    int N3 = sizeof(inorder)/sizeof(inorder[0]);
    int index3=N3-1;
    tree4.root = tree4.Tree_from_In(tree4.root,inorder,0,index3,INT_MIN,INT_MAX);
    tree4.traversal(tree4.root);
    cout<<endl;

    Combine first_combine(tree,tree2,4);
    Combine second_combine(tree3,tree4,6);
    Combine final_combine(first_combine,second_combine,8);
    cout<<"All trees combined to one Binary Forest:\n";
    final_combine.inorder();
    cout << endl;
    return 0;
}