#include<iostream>
#include<algorithm>
using namespace std;

int kadane(int arr[],int N)
{
    int max = arr[0];
    int maxsofar = arr[0];

    for(int i=0; i<N; i++)
    {
        max = std::max(max + arr[i] , arr[i]);
        maxsofar = std::max(max,maxsofar);
    }

    return maxsofar;
}

int main()
{
    int nums[] = {-2, -1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    cout<<"The max sum of the num array is: "<<kadane(nums,size);
    return 0;
}