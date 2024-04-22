#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char op) 
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixToPrefix(const string& infix) 
{
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end()); //reversing the original expression
    stack<char> operators;
    string output;

    for (char c : reversedInfix) 
    {
        if (isalnum(c)) //check to see if the character is a number/variable
        {
            output += c; // Operand, add to output
        } 
        else if (isOperator(c)) 
        {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) 
            {
                output += operators.top(); // Pop higher or equal precedence operators
                operators.pop();
            }
            operators.push(c); // Push current operator onto the stack
        } 
        else if (c == ')') 
        {
            operators.push(c);
        }
         else if (c == '(') 
         {
            while (!operators.empty() && operators.top() != ')') 
            {
                output += operators.top(); // Pop operators until matching ')'
                operators.pop();
            }
            if (!operators.empty() && operators.top() == ')') 
            {
                operators.pop(); // Remove the matching ')'
            }
        }
    }

    while (!operators.empty()) 
    {
        output += operators.top(); // Pop any remaining operators
        operators.pop();
    }

    reverse(output.begin(), output.end()); //reverse the reverseinfinix expression to get prefix
    return output;
}

int main() 
{
    string infixExpression;
    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    string prefixExpression = infixToPrefix(infixExpression);
    cout << "Prefix expression: " << prefixExpression << std::endl;

    return 0;
}
