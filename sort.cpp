#include <iostream>
#include <stack>
using namespace std;
stack<int> mergeSortedStacks(stack<int>& stack1, stack<int>& stack2) 
{
    stack<int> resultStack;

    while (!stack1.empty() && !stack2.empty()) 
    {
        if (stack1.top() < stack2.top()) 
        {
            resultStack.push(stack1.top());
            stack1.pop();
        } 
        else 
        {
            resultStack.push(stack2.top());
            stack2.pop();
        }
    }

    while (!stack1.empty()) 
    {
        resultStack.push(stack1.top());
        stack1.pop();
    }

    while (!stack2.empty()) 
    {
        resultStack.push(stack2.top());
        stack2.pop();
    }

    std::stack<int> final;
    while(!resultStack.empty())
    {
        final.push(resultStack.top());
        resultStack.pop();
    }

    return final;
}

int main() 
{
    stack<int> stack1, stack2;
    
    stack1.push(7);
    stack1.push(5);
    stack1.push(3);
    stack1.push(1);

    stack2.push(8);
    stack2.push(6);
    stack2.push(4);
    stack2.push(2);

    stack<int> result = mergeSortedStacks(stack1, stack2);

    // Print the merged and sorted stack
    while (!result.empty()) 
    {
        cout << result.top() << " ";
        result.pop();
    }

    return 0;
}
