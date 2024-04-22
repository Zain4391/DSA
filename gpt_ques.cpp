#include<iostream>
#include<algorithm>
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

class LinkedList
{
    public:
    Node* head;

    LinkedList()
    {
        head = NULL;
    }

    void insert(int data)
    {
        Node *newNode = new Node(data);

        if(head == NULL)
        {
            head = newNode;
            return;
        }
        else
        {
            Node *temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    Node*reverse_list(Node *headref)
    {
        Node *current = headref;
        Node *prev = NULL;
        Node *next = NULL;
        // reverse the list in place
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        head = prev;

        return head;
    }

};

void display(Node *headref)
{
    Node *current = headref;
    while(current!=NULL)
    {
         cout<<current->data<<" -> ";
        current=current->next;
    }
    cout<<"NULL";
    cout<<endl;
}

int main()
{
    LinkedList mylist;
    mylist.insert(1);
    mylist.insert(2);
    mylist.insert(3);
    mylist.insert(4);
    mylist.insert(5);

    display(mylist.head);
    mylist.reverse_list(mylist.head);
    display(mylist.head);

    return 0;
    
}