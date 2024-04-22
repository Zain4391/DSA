#include<iostream>
using namespace std;

int linear_Search(int arr[],int val,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        if (arr[i]==val)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int num[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(num)/sizeof(num[0]);
    int result=linear_Search(num,6,size);
    if(result!=-1)
    {
        cout<<"Value found at index: "<<result<<endl;
    }
    else
    {
        cout<<"Value not found."<<endl;
    }
    
    return 0;
}