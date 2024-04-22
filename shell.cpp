#include<bits/stdc++.h>
using namespace std;

int Insertion_sort(int arr[],int size)
{
    int i,j,key;
    int sort_count=0;
    for(i=1;i<size;i++)
    {
        key=arr[i]; //storing the first element of the array, supposing that it is sorted

        j=i-1; //for comparing the element next to the first array element

        while(key<arr[j] && j>=0)
        {
            arr[j+1]=arr[j]; //sorting
            j--; //going to the next element
            sort_count++;
        }

        arr[j+1]=key;
    }

    return sort_count;
}

int Shell_sort(int arr[],int size)
{
    int step,j,k;
    int key;
    int sort_count=0;

    for(step=size/2;step>0;step=step/2) //starting from step size n/2 all the way up until step is not 1
    {
        for(j=step;j<size;j++)
        {
            key=arr[j];

            
            for(k=j;k>=j && key<arr[k-step];k=k-step)  
            {
                arr[k]=arr[k-step];
                sort_count++;
            }
            arr[k]=key;
            //^in arr[]={12,34,54,2,3}, key is 54, as elements left to 54 are <, no change
            //now key is 2, elements left to 2 are >, hence swaping will take place
            //values of indexes 3 and 1 will swap places
            //values of indexes 4 and 2 will swap places (3 is the key and elements to the left of 3 are >)
        }
    }

    return sort_count;
}

void print(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int insertion_count=0,shell_count=0;
    int arr[]={60,80,-400,57,33,26};
    int arr2[]={12,34,54,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    cout<<"\n Array 1 and 2 before sorting: "<<endl;
    print(arr,n);
    cout<<endl;
    print(arr2,n2);
    insertion_count=Insertion_sort(arr,n);
    shell_count=Shell_sort(arr2,n2);
    cout<<"\n Array 1 and 2 after sorting: "<<endl;
    print(arr,n);
    cout<<endl;
    print(arr2,n2);
    if(insertion_count>shell_count)
    {
        cout<<"\nShell is more efficent"<<endl;
    }
    else
    {
        cout<<"\nInsertion Sort is more efficient";
    }
    return 0;
}