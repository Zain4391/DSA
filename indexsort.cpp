#include<iostream>
using namespace std;

int *IndexSort(int X[], int N)
{
    int *index = new int[N];
    for (int i=0;i<N;i++)
    {
        int k = 0;

        for(int j=0; j<N; j++)
        {
            if(X[j] < X[i])
            {
                k++;
            }
        }

        index[k] = i;
    }

    return index;
}

void print(int *arr,int N)
{
    for(int i=0; i< N; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

int main()
{
    int arr[] = {13,29,91,34,56};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Follow the following Index Sort notation:\n";
    int *index = IndexSort(arr,n);
    print(index,n);
    delete [] index;
    return 0;
}