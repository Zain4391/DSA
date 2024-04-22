#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int data;
    Node *next_ptr;
    Node *prev_ptr;

    Node()
    {
        next_ptr=NULL;
        prev_ptr=NULL;
    }

    Node(int value)
    {
        data=value;
        next_ptr=NULL;
        prev_ptr=NULL;
    }
};

class DoublyLinkedList
{
    public:
    Node* head,*tail;

    DoublyLinkedList()
    {
        head=NULL;
        tail=NULL;   
    }

    void insert(int value) //inserts at the end
    {
        Node *newNode = new Node (value);

        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next_ptr=newNode;
            newNode->prev_ptr=tail;
            tail=newNode;
        }
    }

    void insertAt(int pos,int value)
    {
        Node *newNode = new Node (value);
        Node *temp=head;
        if(pos==0)
        {
            newNode->next_ptr=head;
            if(head!=NULL)
            {
                head->prev_ptr=newNode;
            }
            head=newNode;

            if(tail==NULL)
            {
                tail=newNode;
            }
        }

        else
        {
        //traversing the list to go to the previous element
        for(int i=0;i<pos-1;i++)
        {
            if(temp!=NULL)
            {
                temp=temp->next_ptr;
            }
        }

        //reached end of list
        if(temp==NULL)
        {
            cout<<"Index out of bounds."<<endl;
            delete newNode;
            return;
        }

        //newNode's previous ptr will point to the previous element and the next pointer of the new element will point to the next element
        newNode->prev_ptr=temp;
        newNode->next_ptr=temp->next_ptr;

        //check if it's not the end of the list then the element after new one, it's prev ptr will point to the new element
        if(temp->next_ptr!=NULL)
        {
            temp->next_ptr->prev_ptr=newNode;
        }
        else
        {
            tail=newNode;// if nothing then insert at the end
        }

        temp->next_ptr=newNode; // next pointer of prev element points to the new node
    }

    }

         void deleteNode(int val) 
      {
        Node* current = head;
        while (current != NULL)
        {
            if (current->data == val) 
            {
                if (current == head) 
                {
                    head = current->next_ptr;
                    if (head != NULL) 
                    {
                        head->prev_ptr = nullptr;
                    }
                } 
                else if (current == tail) 
                {
                    tail = current->prev_ptr;
                    tail->next_ptr = nullptr;
                } 
                else 
                {
                    current->prev_ptr->next_ptr = current->next_ptr;
                    current->next_ptr->prev_ptr = current->prev_ptr;
                }
                delete current;
                return;
            }
            current = current->next_ptr;
        }

        cout <<" Value not found in the list." <<endl;
    }

void Deletebypos(int pos)
{
    if (head == NULL)
    {
        cout << "\nEmpty list" << endl;
        return;
    }
    
    if (pos == 0)
    {
        Node* temp = head;
        head = head->next_ptr;
        if (head != NULL)
        {
            head->prev_ptr = NULL;
        }
        delete temp;
        return;
    }

    Node* current = head;
    int currentPos = 1;

    while (current != NULL && currentPos < pos)
    {
        current = current->next_ptr;
        currentPos++;
    }

    if (current == nullptr)
    {
        cout << "Position " << pos << " not found in the list." << endl;
        return;
    }

    Node* prevNode = current->prev_ptr;
    Node* nextNode = current->next_ptr;

    if (prevNode != NULL)
    {
        prevNode->next_ptr = nextNode;
    }

    if (nextNode != NULL)
    {
        nextNode->prev_ptr = prevNode;
    }
    delete current;
}

    void print_forward()
    {
        Node *temp=head;

        while(temp!=NULL)
        {
            cout<<"Element: "<<temp->data<<" ";
            temp=temp->next_ptr;
        }
    }

    void print_backwards()
    {
        Node *temp=tail;

        while(temp!=NULL)
        {
            cout<<"Element: "<<temp->data<<" ";
            temp=temp->prev_ptr;
        }
    }

    void reverse_list()
     {
        Node *current=head;
        Node *prev=NULL,*next=NULL;
        while ( current != NULL )
        {
            next=current->next_ptr;
            current->next_ptr=prev;
            prev=current;
            current=next;
        }

        head=prev;
     }

    void sort()
    {
        Node *current=head;
        Node *temp2=current;

        for(current=head;current!=NULL;current=current->next_ptr)
        {
            for(temp2=current;temp2!=NULL;temp2=temp2->next_ptr)
            {
                if(current->data > temp2->data)
                {
                    swap(current->data,temp2->data);
                }
            }
        }
    }

    int listlength()
    {
        Node *current=head;
        int list_length=0;

        while(current!=NULL)
        {
            current=current->next_ptr;
            ++list_length;
        }

        return list_length;
    }

};


int main()
{
    DoublyLinkedList numbers;
    numbers.insert(1);
    numbers.insert(20);
    numbers.insert(23);
    cout<<endl;
    numbers.print_forward();
    cout<<endl;
    numbers.insertAt(2,11);
    numbers.insertAt(0,2);
    numbers.print_forward();
    cout<<endl;
    //numbers.sort();
    //cout<<endl;
    //cout<<"Sorted List: "<<endl;
    //numbers.print_forward();
    //cout<<endl;
    //cout<<numbers.listlength()<<endl;
    //cout<<endl;
    //numbers.reverse_list();
    //cout<<endl;
    //numbers.print_forward();
    numbers.Deletebypos(3);
    cout<<endl;
    numbers.print_forward();
    numbers.deleteNode(2);
    cout<<endl;
    numbers.print_forward();
    return 0;
}