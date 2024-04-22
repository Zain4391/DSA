#include<bits/stdc++.h>
using namespace std;

void Insertion_sort(int arr[],int size)
{
    int i,j,key;
    for(i=0;i<size-1;i++)
    {
        key=arr[i]; //storing the first element of the array, supposing that it is sorted

        j=i-1; //for comparing the element next to the first array element

        while(key<arr[j] && j>=0)
        {
            arr[j+1]=arr[j]; //sorting
            j--; //going to the next element
        }

        arr[j+1]=key;
    }
}

void print_array(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[]={5,4,9,8,11};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before sorting: "<<endl;
    print_array(arr,size);
    cout<<"\nArray after sorting: "<<endl;
    Insertion_sort(arr,size);
    print_array(arr,size);
    return 0;
}