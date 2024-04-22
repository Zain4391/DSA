#include<iostream>
using namespace std;


//based on guesses calc by a formula
//if search value is not equal to the probe then depending on the value the upper or lower half is discarded

int interpolation_search(int arr[],int val,int size)
{
    int lower_bound=0;
    int higher_bound=size-1;

    while(val>=arr[lower_bound] && val<=arr[higher_bound] && lower_bound<=higher_bound)
    {
        int guess = lower_bound+(higher_bound-lower_bound)*(val-arr[lower_bound])/(arr[higher_bound]-arr[lower_bound]); //formula

        if(arr[guess]==val)
        {
            return guess;
        }
        else if(arr[guess]<val)
        {
            lower_bound=guess+1; //discard the lower half
        }
        else
        {
            higher_bound=guess-1; //discard the upper half
        }
    }

    return -1;
}

int main()
{
    int num[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(num)/sizeof(num[0]);
    int result=interpolation_search(num,6,size);
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



