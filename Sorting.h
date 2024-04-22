#include<bits/stdc++.h>
using namespace std;


template<typename I>


int Insertion_sort_count(I arr[],int size)
{
    int i,j;
    I key;
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


template<typename S>

int Shell_sort(S arr[],int size)
{
    int step,j,k;
    S key;
    int sort_count=0;

    for(step=size/2;step>0;step=step/2) //starting from step size n/2 all the way up until step is not 1
    {
        for(j=step;j<size;j++)
        {
            key=arr[j];

            
            for(k=j;k>=step && key<arr[k-step];k=k-step)  
            {
                arr[k]=arr[k-step];
                sort_count++;
            }
            arr[k]=key;
        }
    }

    return sort_count;
}

template<typename P>

void print(P arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

template<typename b>

void bubble_sort(b arr[],int size)
{
    int i,j;
    b temp;
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


template<typename B>

int bubble_sort_count(B arr[],int size)
{
    int i,j;
    B temp;
    int sort_count=0;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-1;j++)
        {
            if(arr[j]>arr[i])
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
                sort_count++;
            }
        }
    }

    return sort_count;
}

template<typename i>

void insertion_sort(i arr[],int size)
{
    int k,j;
    i key;
    for(k=1;k<size;k++)
    {
        key=arr[k]; //storing the first element of the array, supposing that it is sorted

        j=k-1; //for comparing the element next to the first array element

        while(key<arr[j] && j>=0)
        {
            arr[j+1]=arr[j]; //sorting
            j--; //going to the next element
        }

        arr[j+1]=key;
    }
}

template<typename s>

void selection_sort(s arr[],int n)
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



int comb_sort(int arr[],int size)
{
    int i=0;
    int sort_count=0;
    int step=size; //step size to be altered
    bool flag=true;

    while(step!=1 || flag==true)
    {
        step=(step*10)/13; //formula founded emperically

        flag=false;

        for(i=0;i<size-step;i++)
        {
            if(arr[i]>arr[i+step])
            {
                swap(arr[i],arr[i+step]);
                flag=true;
                sort_count++;
            }
        }
    }

    return sort_count;
}

template <typename T>
void Merge(T left[], T right[], T arr[], int left_length, int right_length)
{
    int i, l, r;
    i = 0;
    l = 0;
    r = 0;

    while (l < left_length && r < right_length)
    {
        if (left[l] < right[r])
        {
            arr[i] = left[l];
            i++;
            l++;
        }
        else
        {
            arr[i] = right[r];
            i++;
            r++;
        }
    }

    // Catering the remaining elements in the left and right arrays
    while (l < left_length)
    {
        arr[i] = left[l];
        i++;
        l++;
    }

    while (r < right_length)
    {
        arr[i] = right[r];
        i++;
        r++;
    }
}

template <typename T>
void Mergesort(T arr[], int length)
{
    if (length <= 1)
        return;

    int mid = length / 2;
    T *left = new T[mid];
    T *right = new T[length - mid];

    int i, j = 0;

    for (int i = 0; i < length; i++)
    {
        if (i < mid)
        {
            left[i] = arr[i];
        }
        else
        {
            right[j] = arr[i];
            j++;
        }
    }

    // Recursive calls for left and right subarrays
    Mergesort(left, mid);
    Mergesort(right, length - mid);
    Merge(left, right, arr, mid, length - mid);

    // Free allocated memory
    delete[] left;
    delete[] right;
}