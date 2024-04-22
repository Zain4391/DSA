#include <iostream>
using namespace std;

class Queue 
{
    int front, rear, size, cap;
    int* arr;

public:
    Queue(int x) 
    {
        cap = x;
        front = -1;
        rear = -1;
        size = 0;
        arr = new int[cap];
    }

    bool isFull() 
    {
        return size == cap;
    }

    bool isEmpty() 
    {
        return size == 0;
    }

    void push_front(int x) 
    {
        if (isFull()) 
        {
            cout << "Queue is full. Cannot push_front " << x << endl;
            return;
        }

        if (isEmpty()) 
        {
            front = rear = 0;
        } 
        else 
        {
            front = (front -1 + cap) % cap;
        }
        arr[front] = x;
        size++;
    }

    void push_back(int x)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot push_back " << x << endl;
            return;
        }

        if(isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear+1)%cap;   
        }
        arr[rear] = x;
        size++;
    }

    int pop_front() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty." << endl;
            return -1;
        }

        int removed = arr[front];

        if (front == rear) 
        {
            front = rear = -1;
        } 
        else 
        {
            front = (front + 1) % cap;
        }

        size--;

        return removed;
    }

    int pop_back(int x)
    {
        if(isEmpty())
        {
            cout<<"Queue Empty."<<endl;
            return -1;
        }

        int removed = arr[rear];

        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            rear = (rear -1 + cap)%cap;
        }

        size--;
        return removed;
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty." << endl;
            return;
        }

        int i = front;
        do 
        {
            cout << arr[i] << " ";
            i = (i + 1) % cap;
        } while (i != (rear + 1) % cap);

        cout << endl;
    }
};

int main() {
    Queue q(6);

    for (int i = 0; i <= 4; i++) 
    {
        q.push_front(i);
    }
    q.push_back(11);
    q.display();

    cout << "Popped element: " << q.pop_front() << endl;
    q.display();

    return 0;
}
