#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char evaluate(char op1, char op2, char op)
{
    int n1 = op1 - '0';
    int n2 = op2 - '0';
    int r = 0;

    if(op == '+')
    {
        r = n1 + n2;
    }
    else if(op == '-')
    {
        if(n1 > n2)
        {
            r = n1 - n2;
        }
        else
        {
            r = n2 - n1;
        }
    }
    else if(op == '*')
    {
        r = n1 * n2;
    }
    else if( op == '/')
    {
        r = n1 / n2;
    }
    else if(op == '^')
    {
        r = pow(n1,n2);
    }

    char ans = '0' + r;

    return ans;
}
void evalRPN(string expression)
{
    stack<char> s;
    char ch;
    int result;
    for(int i=0; i<expression.size();i++)
    {
        ch = expression[i];
        if(isalnum(ch))
        {
            s.push(ch);
        }
        else if(isOperator(ch))
        {
            char op1 = s.top();
            s.pop();
            char op2 = s.top();
            s.pop();

            s.push(evaluate(op1,op2,ch));
        }
    }

    result = s.top() - '0';
    s.pop();

    cout<<result<<endl;
}

int main()
{
    string val = "35+7*8-";
    evalRPN(val);

    return 0;
}