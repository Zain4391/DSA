#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int data;
    Node *next;

    Node()
    {
        next=NULL;
    }

    Node(int x)
    {
        this->data=x;
        next=NULL;
    }
};

class Stack
{
    int size;
    public:
    Node* tos_ptr; //top of stack pointer

    Stack()
    {
        tos_ptr=NULL;
        size = 0;
    }

    void push(int val)
    {
        Node *newNode = new Node (val);
        if(tos_ptr==NULL)
        {
            tos_ptr=newNode;
            size++;
        }
        else
        {
            newNode->next=tos_ptr;
            tos_ptr=newNode;
            size++;
        }

        for(Node *i=tos_ptr;i!=NULL;i=i->next)
        {
            for(Node *j=i->next;j!=NULL;j=j->next)
            {
                if(j->data < i->data)
                {
                    swap(j->data,i->data);
                }
            }
        }
    }

    void pop()
    {
        if(tos_ptr==NULL)
        {
            cerr<<"Stack empty."<<endl;
            return;
        }
        else
        {
            Node *temp=tos_ptr;
            tos_ptr=tos_ptr->next;
            delete temp;
            size--;
        }
    }

    int peek()
    {
        if(tos_ptr==NULL)
        {
            cout<<"Stack empty"<<endl;
            return -1;
        }
        return tos_ptr->data;
    }

    void display()
    {
        Node *current=tos_ptr;

        while(current!=NULL)
        {
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getmin()
    {
        if(size == 0)
        {
            return -1;
        }
        else
        {
            return tos_ptr->data;
        }
    }

};

int main()
{
    Stack numbers;
    //numbers.pop(); //error: stack is already empty, so cannot be deleted!
    numbers.push(11);
    numbers.push(3);
    numbers.push(5);
    numbers.push(9);
    numbers.push(10);
    numbers.display();
    cout<<numbers.peek()<<endl;
    cout<<"Min element : "<<numbers.getmin()<<endl;
    return 0;
}