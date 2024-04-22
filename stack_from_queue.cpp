#include <iostream>
#include <stack>
using namespace std;
class Queue 
{
    private:
    stack<int> q;
    stack<int> temp;

    public:
    void enqueue(int x) 
    {
        q.push(x);
    }

    int dequeue() 
    {
        if(!q.empty())
        {
            while(!q.empty())
            {
                temp.push(q.top());
                q.pop();
            }
        }

        int val = temp.top();
        temp.pop();

        //copy it back to the original stack

        while(!temp.empty())
        {
            q.push(temp.top());
            temp.pop();
        }

        return val;
    }

    bool isEmpty() 
    {
        return q.empty();
    }
};

int main() 
{
    Queue myQueue;

    // Example usage:
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    std::cout << "Dequeued: " << myQueue.dequeue() << std::endl;

    std::cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
