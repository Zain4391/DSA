#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node()
    {
        next = NULL;
    }

    Node(int n)
    {
        data = n;
        next = NULL;
    }
};

class Linkedlist
{
    public:
    Node *head;

    Linkedlist()
    {
        head = NULL;
    }

    void Insert(int n)
    {
        Node *newNode = new Node(n);

        if(head == NULL)
        {
            head = newNode;
            return;
        }
        else
        {
            Node *temp=head;

            while(temp->next!=NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void remove(int data)
    {
        if(head == NULL)
        {
            cerr<<"List empty\n";
            return;
        }

        if(head->data == data)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        else
        {
            Node *current = head;
            Node *prev = NULL;

            while(current!=NULL)
            {
                if(current->data == data)
                {
                    prev->next = current->next;
                    delete current;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }

        cerr<<"Element not found\n";
    }

    void show(Node *ref)
    {
        while(ref!=NULL)
        {
            cout<<ref->data<<" ";
            ref = ref->next;
        }

        cout<<endl;
    }
};

int main()
{
    Linkedlist mylist;
    mylist.Insert(3);
    mylist.Insert(2);
    mylist.Insert(11);
    mylist.Insert(9);

    mylist.show(mylist.head);

    mylist.remove(11);
    mylist.show(mylist.head);

    return 0;
}