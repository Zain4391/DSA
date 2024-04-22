#include<iostream>
using namespace std;

class Stack
{
    int top;
    int size;
    int capacity;
    int *arr;

    public:
    // constructor to initialize the stack object
    Stack()
    {
        top = -1;
        size = 0;
        capacity = 0;
        arr = NULL;
    }

    Stack(int c)
    {
        capacity = c;
        arr = new int[capacity];
        top = -1;
        size = 0;
    }

    bool isFull()
    {
        if(top == capacity-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int x)
    {
        if(isFull()==true)
        {
            cerr<<"Stack overflow"<<endl;
        }
        else
        {
            arr[++top]=x;
            size++;
        }
    }

    int pop()
    {
        if(isEmpty()==true)
        {
            cerr<<"Stack empty"<<endl;
            return -1;
        }
        else
        {
            return arr[top--];
            size--;
        }
    }

    int peek(int pos)
    {
        if(top - pos + 1 < 0)
        {
            cerr<<"Invalid position."<<endl;
            return -1;
        }
        
        return arr[top - pos + 1];
    }

    void Display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }

        cout<<endl;
    }
};

class Node
{
    public:
    int data;
    Node* next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class stack
{
    private:
    Node *tos;
    int size;

    public:
    stack()
    {
        tos = NULL;
        size=0;
    }

    bool isEmpty()
    {
        if(tos==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int x)
    {
        Node* newNode = new Node(x);
        if(tos == NULL)
        {
            tos = newNode;
            size++;
        }
        else
        {
            newNode->next = tos;
            tos = newNode;
            size++;
        }
    }

    int pop()
    {
        if(tos == NULL)
        {
            cerr<<"Stack Empty."<<endl;
            return -1;
        }

        int value = tos->data;
        Node *temp = tos;
        tos = tos->next;
        delete temp;
        size--;
        return value;
    }

    int top()
    {
        if(tos == NULL)
        {
            cerr<<"Stack Empty."<<endl;
            return -1;
        }

        return tos->data;
    }

    int peek(int pos)
    {
        if(tos==NULL)
        {
            cerr<<"Stack Empty."<<endl;
            return -1;
        }

        Node *current = tos;

        for(int i=1;i<=pos;i++)
        {
            current=current->next;
        }

        return current->data;
    }

    void Display()
    {
        Node *curr = tos;
        while(curr!=NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }

        cout<<endl;
    }

};

int main()
{
    //array stack
    Stack myStack(5);
    
    for(int i=1;i<5;i++)
    {
        myStack.push(i);
    }

    myStack.Display();
    cout<<"Value at index 2: "<<myStack.peek(2)<<endl;
    cout<<"Popped Value: "<<myStack.pop()<<endl;

    //Linked List stack:
    stack LLstack;
    LLstack.push(7);
    LLstack.push(3);
    LLstack.push(9);
    LLstack.push(4);
    LLstack.Display();
    cout<<"Value at position 2: "<<LLstack.peek(2)<<endl;
    cout<<"Popped value: "<<LLstack.pop()<<endl;
    return 0;
}