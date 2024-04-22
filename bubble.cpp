#include<iostream>
using namespace std;

void bubble_sort(int arr[],int size)
{
    int i,j,temp=0;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-1;j++)
        {
            if(arr[j]>arr[i])
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
}

void print(int arr[],int size)
{
    int k;
    for(k=0;k<size;k++)
    {
        cout<<arr[k]<<" ";
    }
}

int main()
{
    int num[]={5,8,9,16,45,18,200,65,3};
    int n=sizeof(num)/sizeof(num[0]);
    cout<<"\nBefore sorting: "<<endl;
    print(num,n);
    cout<<"\nAfter sorting: "<<endl;
    bubble_sort(num,n);
    print(num,n);
    return 0;
}