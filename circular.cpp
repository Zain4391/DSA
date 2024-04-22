#include <iostream>
#include <vector>
using namespace std;

class CircularQueue 
{
    private:
    std::vector<int> data;
    int front;
    int rear;
    int size;
    int capacity;

    public:
    CircularQueue(int k) 
    {
        capacity = k;
        size = 0;
        front = -1;
        rear = -1;
        data.resize(capacity);
    }

    bool enqueue(int value) 
    {
        if(size == capacity)
        {
            return false;
        }
        
        if(front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
        return true;
    }

    bool dequeue() 
    {
        if(size == 0)
        {
            return false;
        }
        else
        {
            if(front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % capacity;
            }
        }

        size --;
        return true;
    }

    int front_val() 
    {
        return front == -1 ? -1 : data[front];
    }

    int rear_val() 
    {
        return rear == -1 ? -1 : data[rear];
    }

    bool isEmpty() 
    {
        return size == 0;
    }

    bool isFull() 
    {
        return size == capacity;
    }
};

int main() 
{
    // Example usage of the CircularQueue class
    CircularQueue myCircularQueue(3);

    cout << "Is the circular queue empty? " << (myCircularQueue.isEmpty() ? "Yes" : "No") << std::endl;

    myCircularQueue.enqueue(1);
    myCircularQueue.enqueue(2);
    myCircularQueue.enqueue(3);

    cout<<myCircularQueue.front_val()<<endl;
    cout<<myCircularQueue.rear_val()<<endl;

    cout << "Is the circular queue full? " << (myCircularQueue.isFull() ? "Yes" : "No") << std::endl;

    myCircularQueue.dequeue();

    cout << "Is the circular queue empty? " << (myCircularQueue.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
