#include<iostream>
#include<cmath>
#include<string>
#include<stack>
using namespace std;

int BintoDec(string Bin)
{
    int result=0;
    for(int i =0; i <Bin.size(); i++)
    {
        if(Bin[i] == '1')
        {
            result+=pow(2,Bin.size() - 1-i);
        }
    }

    return result;
}

string DectoBin(int dec)
{
    stack<int> rem;

    while(dec > 0)
    {
        int r = dec % 2;
        rem.push(r);
        dec /= 2;
    }

    string ans ="";
    while(!rem.empty())
    {
        ans.append(to_string(rem.top()));
        rem.pop();
    }

    return ans;
}

string DectoBase(int dec,int base)
{
    stack<int> rem;

    string digits[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

    while(dec > 0)
    {
        int r = dec % base;
        rem.push(r);
        dec /= base;
    }

    string ans ="";
    while(!rem.empty())
    {
        ans.append(digits[rem.top()]);
        rem.pop();
    }

    return ans;
}

int main()
{
    string binary = "1001";
    cout<<BintoDec(binary)<<endl;
    int dec = 9;
    cout<<DectoBin(dec)<<endl;
    int num = 25;
    cout<<DectoBase(num,16)<<endl;
    return 0;
}