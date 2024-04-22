#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int hash_func(string val)
{
    int hash = 0;
    for(int i=0; i <val.size();i++)
    {
        char c = val[i];
        hash+='0'+c;
    }

    return hash % 11;
}

void RabinKarp(string text, string p)
{
    int N = text.length();
    int M = p.length();
    int hashp = hash_func(p);
    int count = 0;
    string num="";
    unordered_map<string,bool> uniqueSubstrings;

    for(int i=0; i<N; i++)
    {
        string num = text.substr(i, M);

        int hash_num = hash_func(num);

        if(hash_num == hashp)
        {
            if(num == p && uniqueSubstrings.find(num) == uniqueSubstrings.end())
            {
                count++;
            }
            else
            {
                uniqueSubstrings.insert({num,true});
            }
        }
    }

    cout<<"Number of matches: "<<count<<endl;
}

int main()
{
    string text = "ABCDABCDFGH";
    string pattern;
    cout<<"The default pattern is as follows:\n"<<text<<endl;
    cout<<"Enter the pattern YOU want to find\n";
    cin>>pattern;
    RabinKarp(text,pattern);
    return 0;

}