#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int start,int end)
{
    int pivot = arr[end];

    int i=start;

    for(int j=start;j<=end-1;j++)
    {
        if(arr[j]<pivot) //values at the left should be less than pivot and values at the right should be greater than pivot
        {
            swap(arr[j],arr[i]);
            i++;
        }
    }
    swap(arr[i],arr[end]);

    return i; //location of the pivot
}


void quick_sort(int arr[],int start,int end)
{
    if(end <= start)
    {
        return;
    }

    int pivot = partition(arr,start,end);
    quick_sort(arr,start,pivot - 1);
    quick_sort(arr,start+pivot,end);
}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int list[]={10,4,8,2,-1,17,1,0};
    int n = sizeof(list)/sizeof(list[0]);
    cout<<"Original Array: ";
    print(list,n);
    quick_sort(list,0,n-1);
    cout<<"Sorted array :";
    print(list,n);
    return 0;
}