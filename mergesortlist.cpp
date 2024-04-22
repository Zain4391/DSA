#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

class Linkedlist
{
    public:
    Node* head = NULL;

    Linkedlist()
    {
        head=NULL;
    }

    void insert(int val)
    {
        Node *newNode = new Node (val);

        if(head==NULL)
        {
            head=newNode;
            return;
        }
        else
        {
            Node *current=head;
            while(current->next!=NULL)
            {
                current=current->next;
            }

            current->next=newNode;
        }
    }

    //helper functions for merge sort : middle point of list,merge the list
    Node *find_mid(Node *head)
    {
        Node *slow=head;
        Node *fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next; //when fast reaches the end of list slow will be at the middle
        }

        return slow;
    }

    Node *merge(Node *left,Node *right) //returns the merged list
    {
        Node *result=NULL;

        //2 base cases:

        if(left==NULL)
        {
            return right; //right list exists,left doesnt
        }

        if(right==NULL)
        {
            return left; //left list exists,right doesnt
        }

        if(left->data <= right->data)
        {
            result = left;
            result->next=merge(left->next,right); //creating new list of sorted elements wrt left
        }
        else
        {
            result = right;
            result->next=merge(left,right->next); //creating new list of sorted elements wrt right
        }

        return result;
    }

    void Mergesort() //the function which performs the divide and conquer analogy
    {
        if(head==NULL || head->next==NULL) //list empty or already sorted
        {
            return;
        }

        Node *mid = find_mid(head);
        Node *left=head;
        Node *right=mid->next; //right list
        mid->next=NULL; //left list

        Linkedlist leftlist;
        Linkedlist righlist;
        leftlist.head=left;
        righlist.head=right;

        //recursive call
        leftlist.Mergesort();
        righlist.Mergesort();

        head=merge(leftlist.head,righlist.head); //merging the 2 lists
    }

    void display()
    {
        Node *current=head;

        while(current!=NULL)
        {
            cout<<current->data<<" ";
            current=current->next;
        }

        cout<<endl;
    }
};

int main()
{
    Linkedlist numbers;
    numbers.insert(5);
    numbers.insert(1);
    numbers.insert(15);
    numbers.insert(6);
    numbers.insert(19);

    cout<<"Original list: ";
    numbers.display();

    cout<<"Sorted list: ";
    numbers.Mergesort();
    numbers.display();
    return 0;
}