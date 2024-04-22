#include<iostream>
#include<queue>
#include<string>
using namespace std;

void generateBinNumbers(int N)
{
    deque<int> dq;
    queue<string> ans;
    for(int i=1; i<=N; i++)
    {
        int num = i;
        while(num != 0)
        {
            int rem = num % 2;
            dq.push_back(rem);
            num /= 2;
        }

        string bin="";

        while(!dq.empty())
        {
            bin += to_string(dq.back());
            dq.pop_back();
        }

        ans.push(bin);
    }

    while(!ans.empty())
    {
        string val = ans.front();
        cout << val << " ";
        ans.pop();
    }
}

void GenerateBin(int N)
{
    queue<string> q;
    for(int i=1; i<=N; i++)
    {
        int num = i;

        string bin="";

        while(num != 0)
        {
            int rem = num % 2;
            char ch = '0' + rem;
            bin= ch + bin;
            num = num / 2;
        }
        q.push(bin);
    }

    cout<<"Binary Numbers from 1 to "<<N<<" : ";
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main()
{
    int N = 5;
    cout << "Binary Numbers from 1 to "<< N <<" : ";
    generateBinNumbers(N);
    cout<<endl;
    GenerateBin(N);
    return 0;
}