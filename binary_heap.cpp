#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

class Node
{
    public:
    int data;
    Node *left,*right;

    Node()
    {
        data = 0;
        left = right = NULL;
    }

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Heap
{
    private:
    int n;
    void deleteDeepest(Node* root, Node* deepest) 
    {
        queue<Node*> q;
        q.push(root);

        Node* temp;

        // Do level order traversal to find the deepest node
        while (!q.empty()) 
        {
            temp = q.front();
            q.pop();

            if (temp == deepest) 
            {
                temp = nullptr;
                delete deepest;
                return;
            }

            if (temp->left!=NULL) 
            {
                if (temp->left == deepest) 
                {
                    temp->left = nullptr;
                    delete deepest;
                    return;
                } 
                else 
                {
                    q.push(temp->left);
                }
            }

            if (temp->right!=NULL) 
            {
                if (temp->right == deepest) 
                {
                    temp->right = nullptr;
                    delete deepest;
                    return;
                } 
                else 
                {
                    q.push(temp->right);
                }
            }
        }
    }

     
    public:
    Node *root;

    Heap()
    {
        root=NULL;
        n=0;
    }

    Node*make_root(Node *obj)
    {
        root = obj;
        n++;
        return root;
    }

    void insert(Node *&root_ptr,int val)
    {
        Node *newNode = new Node (val);

        if(root_ptr==NULL)
        {
            root_ptr = newNode;
            n++;
        }
        else
        {
            queue<Node*> q;
            q.push(root_ptr);
        
            Node *current = NULL;

            while(!q.empty())
            {
                current = q.front();
                q.pop();

                if(current->left == NULL)
                {
                    current->left=newNode;
                    n++;
                }
                else if(current->right==NULL)
                {
                    current->right=newNode;
                    n++;
                }
                else if(current->left!=NULL)
                {
                    q.push(current->left);
                }
                else
                {
                    q.push(current->right);
                }

                if(current->data > newNode->data)
                {
                    heapifymin(root_ptr);
                }
            }

            heapifymin(current);
        }
    }

    void heapifymin(Node *root_ptr)
    {
        if(root_ptr==NULL)
        {
            return;
        }

        Node *smallest = root_ptr;
        Node *left = root_ptr->left;
        Node *right = root_ptr->right;

        //finding the smallest node among the two childern

        if(left!=NULL && left->data < smallest->data)
        {
            smallest = left;
        }
        if(right!=NULL && right->data < smallest->data)
        {
            smallest = right;
        }

        if(smallest!=root_ptr)
        {
            swap(root_ptr->data , smallest->data);
            heapifymin(smallest);
        }
    }

    void Display(Node *root_ptr)
    {
        queue<Node*>q;
        q.push(root_ptr);
        Node *current = NULL;

        while(!q.empty())
        {
            current=q.front();
            q.pop();
            
            cout<<current->data<<" ";
            if(current->left != NULL)
            {
                q.push(current->left);
            }
            if(current->right != NULL)
            {
                q.push(current->right);
            }
        }
    }

    void inOrder(Node *root_ptr)
    {
        if(root_ptr!=NULL)
        {
            inOrder(root_ptr->left);
            cout<<root_ptr->data<<" ";
            inOrder(root_ptr->right);
        }
    }

    bool isMin(Node*root_ptr)
    {
        if(root_ptr==NULL)
        {
            return true;
        }

        if (root_ptr->left != NULL && root_ptr->data > root_ptr->left->data)
        {
            return false;
        }

        if (root_ptr->right != NULL && root_ptr->data > root_ptr->right->data)
        {
            return false;
        }

        bool left = isMin(root_ptr->left);
        bool right = isMin(root_ptr->right);

        return left && right;
    }

    int Count_Nodes(Node*root_ptr)
    {
        if(root_ptr==NULL)
        {
            return 0;
        }

        return 1+Count_Nodes(root_ptr->left)+Count_Nodes(root_ptr->right);
    }

    bool isComplete(Node *root_ptr,int index,int nodes)
    {
        if(root_ptr==NULL)
        {
            return true;
        }

        if(index>=nodes)
        {
            return false;
        }

        bool left = isComplete(root_ptr->left , 2*index+1,nodes); //going to left childern
        bool right = isComplete(root_ptr->right , 2*index+2,nodes); //going to right childern

        return left && right;
    }

    int getmin()
    {
        return root->data;
    }

    void deleteValue(int value) 
    {
        if (root == nullptr) 
        {
            cout << "Heap is empty. Cannot delete." << std::endl;
            return;
        }

        Node* keyNode = nullptr;
        Node* lastNode = nullptr;

        queue<Node*> q;
        q.push(root);

        // Do level order traversal to find the node to be deleted
        while (!q.empty()) 
        {
            lastNode = q.front();
            q.pop();

            if (lastNode->data == value) 
            {
                keyNode = lastNode;
            }

            if (lastNode->left!=NULL) 
            {
                q.push(lastNode->left);
            }

            if (lastNode->right!=NULL) 
            {
                q.push(lastNode->right);
            }
        }

        if (keyNode != nullptr) 
        {
            keyNode->data = lastNode->data;
            deleteDeepest(root, lastNode);
            heapifymin(root);
            n--;
        } 
        else 
        {
            cout << value << " not found in the heap." << endl;
        }
    }

    int extract()
    {
        if (root == nullptr)
        {
            cerr << "Error: Heap is empty." << endl;
            return -1; 
        }
        int temp = root->data;
        deleteValue(root->data);
        heapifymin(root);
        n--;
        return temp;
    }


    int getsize()
    {
        return n;
    }

};


int main()
{
    Heap h;
    h.make_root(new Node (7)); //min heap parent node will be less than it's left and right childern
    h.insert(h.root,9);
    h.insert(h.root,8);
    h.insert(h.root,10);
    h.insert(h.root,11);
    h.Display(h.root);
    cout<<endl;
    if(h.isMin(h.root))
    {
        cout<<"TRUE\n";
    }
    else
    {
        cout<<"FALSE\n";
    }

    if(h.isComplete(h.root,0,h.Count_Nodes(h.root)))
    {
        cout<<"TRUE\n";
    }
    else
    {
        cout<<"FALSE\n";
    }
    cout<<endl;
    cout<<"Min Data: "<<h.getmin()<<endl;

    /*cout<<"Heap after deleting 7 : ";
    h.deleteValue(7);
    h.Display(h.root);*/

    if(h.isComplete(h.root,0,h.Count_Nodes(h.root)))
    {
        cout<<"\nTRUE\n";
    }
    else
    {
        cout<<"\nFALSE\n";
    }


    cout<<"Size of heap:"<<h.getsize()<<endl;

    if(h.isComplete(h.root,0,h.Count_Nodes(h.root)))
    {
        cout<<"\nTRUE\n";
    }
    else
    {
        cout<<"\nFALSE\n";
    }
    return 0;
}