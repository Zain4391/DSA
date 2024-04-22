#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n)
{
    int i,j,min_index;

    for(i=0;i<n-1;i++)
    {
        min_index=i; //considering the first element as the lowest

        for(j=i+1;j<n;j++) //comparing the next element
        {
            if(arr[j]<arr[min_index])
            {
                min_index=j; //finding the lowest element in the unsorted array
            }
        }

        if(min_index!=i)
        {
            swap(arr[i],arr[min_index]); //swapping the elements in the sorted block
        }
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
    int numbers[]={5,16,18,3};
    int arr_size=sizeof(numbers)/sizeof(numbers[0]);
    cout<<"Array before sorting: "<<endl;
    print_array(numbers,arr_size);
    cout<<"\nArray after sorting: "<<endl;
    selection_sort(numbers , arr_size);
    print_array(numbers,arr_size);
    return 0;
}