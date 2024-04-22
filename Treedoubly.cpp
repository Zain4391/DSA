#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *parent;
		Node *left,*right;
		
	Node ()
	{
	   parent=NULL;
	   left=NULL;
	   right=NULL;	
	}
	
	Node (int x)
	{
	   data=x;
	   parent=NULL;
	   left=NULL;
	   right=NULL;	
	}	
};

class BinaryTree
{
	public:
		Node *root;
		
		Node* make_root(Node *obj)
		{
			root=obj;
			return root;
		}
		
		void insert(Node *&root_ptr,int val)
		{
			Node *newNode=new Node (val);
			if(root_ptr==NULL)
			{
				root_ptr= newNode;
			}
			
			else
			{
				if(root_ptr->data > val)
				{
					if(root_ptr->left == NULL)
					{
						root_ptr->left= newNode;
						root_ptr->left->parent=newNode;
					}
					else
					{
						insert(root_ptr->left,val);
					}
				}
				
				if(root_ptr->data <= val)
				{
					if(root_ptr->right == NULL)
					{
						root_ptr->right=newNode;
						root_ptr->right->parent=newNode;
					}
					else
					{
						insert(root_ptr->right,val);
					}
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
        else
        {
            if(root_ptr->left!=NULL)
            {
                return Treeheight(root_ptr->left,height+1);
            }

            if(root_ptr->right!=NULL)
            {
                return Treeheight(root_ptr->right,height+1);
            }
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
            }
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
        
};

int main()
{
	BinaryTree tree;
    Node *tree_parent = new Node (5);
	tree.make_root(tree_parent);
	tree.insert(tree.root,8);
	tree.insert(tree.root,9);
	tree.insert(tree.root,3);
	tree.insert(tree.root,4);
	tree.insert(tree.root,11);
	
	tree.traversal(tree.root);
    cout<<endl;
	tree.pre_order(tree.root);
	cout<<endl;
	tree.post_order(tree.root);
	cout<<endl;
    cout<<"The tree height: ";
    cout<<tree.Treeheight(tree.root,0);
	cout<<endl;

	bool isThere = tree.Search(tree.root,3);
    if(isThere)
    {
        cout<<"Value found\n";
    }    
    else
    {
        cout<<"Not Found!\n";
    }

	cout<<"Tree after deletion: ";
	tree.delete_node(tree.root,5);
	tree.traversal(tree.root);
	
    cout<<"\nSum of Nodes: ";
    cout<<tree.Node_sum(tree.root,0);
    cout<<"\nNumbe rof nodes: ";
    cout<<tree.Count_Nodes(tree.root,0);
	return 0;
}