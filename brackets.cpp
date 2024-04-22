#include<iostream>
#include<stack>
using namespace std;

bool isValid(string brackets)
{
    stack<char> s;

    for (int i=0; i<brackets.size(); i++) 
    {
        char bracket = brackets[i];
        if (bracket == '(' || bracket == '[' || bracket == '{') 
        {
            s.push(bracket);
        }
        else 
        {
            if (s.empty()) 
            {
                return false;
            }

            char top = s.top();
            s.pop();

            if ((bracket == ')' && top != '(') || (bracket == ']' && top != '[') || (bracket == '}' && top != '{')) 
            {
                return false;
            }
        }
    }

    return s.empty();  
}

int main()
{
    string str = "({})";
    bool check = isValid(str);
    if (check) 
    {
        cout << "TRUE\n";
    } 
    else 
    {
        cout << "FALSE\n";
    }
    return 0;
}
