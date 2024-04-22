#include <iostream>
using namespace std;
class Node 
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data=value;
        next=NULL;
    }
    
};

class LinkedList 
{
public:
    Node* head;

    LinkedList()
    {
        head=NULL;
    }

    void insert(int value) 
    {
        Node* newNode = new Node(value);
        if (!head) 
        {
            head = newNode;
        } 
        else 
        {
            Node* current = head;
            while (current->next) 
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() 
    {
        Node* current = head;
        while (current) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << std::endl;
    }
};

Node* partition(Node* start, Node* end) 
{
    int pivot = end->data;
    Node* i = start;
    
    for (Node* j = start; j != end; j = j->next) 
    {
        if (j->data < pivot) 
        {
            swap(i->data, j->data);
            i = i->next;
        }
    }
    swap(i->data, end->data);

    return i;
}

void quick_sort(Node* start, Node* end) 
{
    if (end != NULL && start != end && start != end->next) 
    {
        Node* pivot = partition(start, end);
        Node *temp=start;
        if(pivot!=start)
        {
         while(temp->next!=pivot)
         {
            temp=temp->next;
         }
         quick_sort(start,temp);  // Sort the left partition
        }
        quick_sort(pivot->next, end);    // Sort the right partition
    }
}

int main() 
{
    LinkedList list;
    int arr[] = {8,2,1,7,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; ++i) 
    {
        list.insert(arr[i]);
    }

    cout << "Original Linked List: ";
    list.display();

    // Sorting
    Node* end = list.head;
    while (end->next) 
    {
        end = end->next;
    }
    quick_sort(list.head, end);

    cout << "Sorted Linked List: ";
    list.display();

    return 0;
}
