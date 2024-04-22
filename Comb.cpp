#include<iostream>
using namespace std;

int bubble_sort(int arr[],int size)
{
    int i,j,temp=0;
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

        if(step < 1)
        {
            break;
        }

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
    int bubble_result,comb_result;
    bubble_result=0;
    comb_result=0;
    int numbers[]={ 8, 4, 1, 56, 3, -44, 23, -6, 28, 0 };
    int size=sizeof(numbers)/sizeof(numbers[0]);
    cout<<"\nUnsorted array: "<<endl;
    print(numbers,size);
    //bubble_result=bubble_sort(numbers,size);
    comb_result=comb_sort(numbers,size);
    cout<<"\nSorted Array: "<<endl;
    print(numbers,size);
    //cout<<"\nComb sort count: "<<comb_result<<" VS Bubble sort count: "<<bubble_result<<endl;
    /*if(bubble_result>comb_result)
    {
        cout<<"\nComb sort is more efficent"<<endl;
    }
    else
    {
        cout<<"\nBubble Sort is the most efficient one";
    }*/
    return 0;
}
