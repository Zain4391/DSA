#include<iostream>
#include<queue>
using namespace std;

//D-queue for messages (will behave like a stack)
class Node
{
    public:
    string data;
    Node* next;
    Node *prev;

    Node()
    {
        data = " ";
        next = NULL;
        prev = NULL;
    }

    Node(string x)
    {
        data = x;
        next = prev = NULL;
    }

};

class Buffer
{
    private:
    int size;
    int tob;
    string *buff;
    
    public:
    Buffer()
    {
        tob=-1;
        buff=NULL;
    }

    Buffer(int x)
    {
        size = x;
        tob = -1;
        buff = new string[size];
    }

    void push(string x)
    {
        if(size == -1)
        {
            cout<<"Buffer FULL\n";
        }
        else
        {
            tob++;
            buff[tob]=x;
        }
    }

    void pop()
    {
        if(tob==-1)
        {
            cout<<"Buffer EMPTY\n";
        }
        else
        {
            tob--; //delete element from the top of buffer
        }
    }

    string top()
    {
        if(tob==-1)
        {
            return "NULL";
        }
        else
        {
            return buff[tob];
        }
    }

    void set_size(int x)
    {
        size = x;
        tob = -1;
        buff = new string[size];
    }

    int get_size()
    {
        return size;
    }

};

class editor
{
    public:
    Node *front,*rear;
    Buffer *buffer;

    editor()
    {
        front = rear = NULL;
        buffer = new Buffer(); //creating a new instance of the buffer class
    }

    void set_buffer_size(int n)
    {
        buffer->set_size(n);
    }

    void push(string x)
    {
        Node *newNode = new Node (x);

        if(front == NULL)
        {
            front  = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void Undo()
    {
        // we will delete from the rear of our queue.

        if(front == NULL)
        {
            return;
        }
        
        Node *temp = rear;
        buffer->push(temp->data);
        rear  = rear->prev;
        delete temp;
        rear->next = NULL;
    }

    void Redo()
    {
        string temp = buffer->top();
        buffer->pop();
        push(temp);
    }

    void display()
    {
        Node *temp = front;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

};

class UserNode
{
    public:
    string name;
    UserNode *next;

    UserNode()
    {
        name =" ";
        next=NULL;
    }

    UserNode(string n)
    {
        name = n;
        next = NULL;
    }
};

class User
{
    public:
    UserNode *tos;

    User()
    {
        tos=NULL;
    }

    User(string n)
    {
        push(n);
    }

    void push(string n)
    {
        UserNode *newuser = new UserNode(n);
    
        if(tos==NULL)
        {
            tos = newuser;
        }
        else
        {
            newuser->next = tos;
            tos = newuser;
        }
    }

    void showUsers()
    {
        UserNode *temp=tos;

        while(temp!=NULL)
        {
            cout<<temp->name<<" ";
            temp=temp->next;
        }

        cout<<endl;
    }
};


int main()
{
    editor doc;
    Buffer bff(100);
    doc.set_buffer_size(bff.get_size());
    doc.push("This is User1.");
    doc.push("This is User2.");
    doc.push("This is User3.");
    User u("User1.");
    u.push("User2.");
    u.push("User3.");
    doc.display();
    cout<<endl;
    doc.Undo();
    doc.display();
    cout<<endl;
    doc.Redo();
    doc.display();
    cout<<endl;
    u.showUsers();
    return 0;
}

