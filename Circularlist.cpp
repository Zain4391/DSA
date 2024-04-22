#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next_ptr;

    Node()
    {
        next_ptr=NULL;
    }

    Node(int value)
    {
        data=value;
        this->next_ptr=NULL;
    }
};

class CircularLinkedList
{
    public:
    Node *head;

    CircularLinkedList()
    {
        head=NULL;
    }

    void insert()
    {
        int val;

        cout<<"Enter the value you would like to enter: "<<endl;
        cin>>val;

        Node *newNode= new Node (val);

        if(head==NULL)
        {
            head=newNode;
            newNode->next_ptr=head;
        }
        else
        {
            Node* temp = head;
            while (temp->next_ptr != head) 
            {
                temp = temp->next_ptr;
            }
            temp->next_ptr = newNode;
            newNode->next_ptr = head;
        }
    }

    void insertAt(int pos)
    {
        if(pos<0)
        {
            cout<<"Invalid position."<<endl;
            return;
        }

        Node *temp=head->next_ptr; //begin from node after head
       
       int val;
       cout<<"Enter value: "<<endl;
       cin>>val;

       Node *newNode = new Node (val);

        int list_length=1; //factor in the statement from line 66
        while(temp!=head)
        {
            temp=temp->next_ptr;
            list_length++;
        }

        if(pos>list_length)
        {
            insert();
            return;
        }

        if(pos==0)
        {
            newNode->next_ptr=head->next_ptr;
            head->next_ptr=newNode;
        }

        else
        {
            
        temp=head;

        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next_ptr;

            if(temp==head)
            {
                cout<<"Invalid position."<<endl;
                return;
            }
        }
        newNode->next_ptr=temp->next_ptr;
        temp->next_ptr=newNode;
        }

    }

    void Display()
    {
        if (head == NULL) 
        {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = head;
        cout<<head->data<<" ";
        temp=temp->next_ptr;
        do 
        {
            cout << temp->data << " ";
            temp = temp->next_ptr;
        } while (temp != head);
        cout <<endl;
    }

    void reverse_list()
    {
        Node *current=head;
        Node *prev,*next;
        prev=NULL;
        next=NULL;

        do
        {
            next=current->next_ptr;
            current->next_ptr=prev;
            prev=current;
            current=next;

        }while(current!=head);

        head->next_ptr=prev;
        head=prev;
    }

    void search_list(int element)
    {
        Node *current=head;
        bool found=false;

        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        else
        {
            do
            {
                if(current->data==element)
                {
                    cout<<"Element Found: "<<current->data<<endl;
                    found=true;
                }
                else
                {
                    current=current->next_ptr;
                }
            } while (current!=head && found != true);

            if(found==false)
            {
                cout<<element<<" not found."<<endl;
                return;
            }
            
        }
    }
};

int main()
{
    int i=0;

    CircularLinkedList numbers;
    for(i=0;i<5;i++)
    {
        numbers.insert();
    }
    numbers.Display();
    numbers.insertAt(0);
    //numbers.insertAt(-1);
    numbers.Display();
    numbers.search_list(5);
    //numbers.reverse_list();
    //numbers.Display();
    return 0;
}
