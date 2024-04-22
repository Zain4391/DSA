#include<iostream>
#include<stack>
using namespace std;

string rev(string val)
{
    stack<char> s;
    string revval = "";

    for(int i=0; i<val.size(); i++)
    {
        s.push(val[i]);
    }

    while(!s.empty())
    {
        revval+=s.top();
        s.pop();
    }

    return revval;
}

int main()
{
    string name = "Zain Rasool Hashmi";
    cout << "Original Name : "<<name<<endl;
    cout << "Reversed Name  : "<<rev(name);
    return 0;
}