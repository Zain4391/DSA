#include<iostream>
#include<stack>
using namespace std;

class MinStack
{
    stack<int> regular;
    stack<int> min;

    public:
    int getmin()
    {
        if(min.empty())
        {
            return -1;
        }
        return min.top();
    }

    void push(int x)
    {
        regular.push(x);

        if(min.empty() || x <= getmin())
        {
            min.push(x);
        }
    }

    void pop()
    {
        if(!regular.empty() && regular.top() == getmin())
        {
            min.pop();
        }
        else
        {
            regular.pop();
        }
    }

    int top()
    {
        return regular.top();
    }
};

int main() 
{
    // Create an instance of MinStack
    MinStack minStack;

    // Push elements onto the stack
    minStack.push(3);
    minStack.push(5);
    minStack.push(2);
    minStack.push(7);
    minStack.push(11);

    // Display the top element
    cout << "Top element: " << minStack.top() << std::endl;

    // Display the minimum element
    cout << "Minimum element: " << minStack.getmin() << std::endl;

    // Pop an element
    minStack.pop();

    // Display the top element after pop
    cout << "Top element after pop: " << minStack.top() << std::endl;

    // Display the minimum element after pop
    cout << "Minimum element after pop: " << minStack.getmin() << std::endl;

    return 0;
}