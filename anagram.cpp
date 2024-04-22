#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool isAnagram(string s, string t)
{
    if(s.length() != t.length())
    {
        return false;
    }
    sort(s.begin(),s.end()); //sort the first string
    sort(t.begin(),t.end()); //sort the secong string

    return s == t;
}

int main() 
{
    string input1, input2;

    // Get user input for the first string
    cout << "Enter the first string: ";
    getline(cin,input1);

    fflush(stdin);

    // Get user input for the second string
    cout << "Enter the second string: ";
    getline(cin,input2);

    // Check if the input strings are anagrams
    if (isAnagram(input1, input2))
    {
        cout << "The strings are anagrams." <<endl;
    } 
    else
    {
        cout << "The strings are not anagrams." <<endl;
    }

    return 0;
}
