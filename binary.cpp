#include<iostream>
using namespace std;

int binary_search(int arr[],int val,int size)
{
    int low=0;
    int high=size-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(arr[mid]==val)
        {
            return mid;
        }
        else if(arr[mid]<val)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }

    return -1;
}

int main()
{
    int num[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(num)/sizeof(num[0]);
    int result=binary_search(num,6,size);
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