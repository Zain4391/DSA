#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;

    Node(int x) 
    { // Use a constructor with a parameter to set the data value.
        data = x;
        next = NULL;
    }
};

class Queue 
{
    public:
    Node* head;
    Node* tail;

    Queue() 
    { // Initialize head and tail to NULL in the constructor.
        head = NULL;
        tail = NULL;
    }

    void push(Node* obj) 
    {
        if (head == NULL) 
        {
            head = obj;
            tail = obj;
        } 
        else 
        {
            tail->next = obj;
            tail = obj;
        }
    }

    void emplace(int x) 
    {
        Node* newNode = new Node(x);

        if (head == NULL) 
        {
            head = newNode;
            tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int size() 
    {
        int size = 0;
        Node* current = head;

        while (current != NULL) 
        {
            size++;
            current = current->next;
        }

        return size;
    }

    bool isempty() 
    {
        return head == NULL; // You can simplify this function.
    }

    void swap(Queue* q1, Queue* q2) 
    {
        if (q1->head != NULL && q2->head != NULL) 
        {
            // Swap heads of the queues
            Node* temp = q1->head;
            q1->head = q2->head;
            q2->head = temp;

            // Swap tails of the queues
            Node* temptail = q1->tail;
            q1->tail = q2->tail;
            q2->tail = temptail;
        }
    }

    void Display() 
    {
        Node* current = head;

        while (current != NULL) 
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void Rotate(Queue *q)
    {
        if(q->head!=NULL && q->tail!=NULL)
        {
            Node* temp = head;
            tail->next = head; 
            head = head->next; 
            temp->next=NULL;
            tail = temp; 
            q->head = head;
            q->tail = tail;
        }
    }
};

int main() 
{
    Node obj1(5);
    Node obj2(6);
    Node obj3(9);
    Node obj4(11);

    Queue line;
    line.push(&obj1);
    line.push(&obj2);
    line.push(&obj3);
    line.push(&obj4);
    line.emplace(3);
    line.Display();

    Queue line2;
    line2.emplace(19);
    line2.emplace(2);
    line2.emplace(4);
    line2.emplace(7);
    line2.Display();

    line.swap(&line,&line2);
    cout<<"After swapping\n";
    line.Display();
    line2.Display();

    line2.Rotate(&line2);
    line2.Display();
    return 0;
}
