#include <iostream>
using namespace std;

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

int main()
{
    int intArr[] = {9, 3, 17, -1, 4, 2, 11};
    double doubleArr[] = {9.5, 3.2, 17.8, -1.1, 4.6, 2.0, 11.3};
    char charArr[] = {'c', 'a', 'r', 'b', 'o', 'n'};
    string names[] = {"Zain","Abuzar","Ali","Hamza","Shazam","Ammar"};
    int intLength = sizeof(intArr) / sizeof(intArr[0]);
    int doubleLength = sizeof(doubleArr) / sizeof(doubleArr[0]);
    int charLength = sizeof(charArr) / sizeof(charArr[0]);
    int stringlength = sizeof(names)/sizeof(names[0]);
    Mergesort(intArr, intLength);
    Mergesort(doubleArr, doubleLength);
    Mergesort(charArr, charLength);
    Mergesort(names, stringlength);
    cout << "Sorted intArr: ";
    for (int i = 0; i < intLength; i++)
    {
        cout << intArr[i] << " ";
    }
    cout << endl;

    cout << "Sorted doubleArr: ";
    for (int i = 0; i < doubleLength; i++)
    {
        cout << doubleArr[i] << " ";
    }
    cout << endl;

    cout << "Sorted charArr: ";
    for (int i = 0; i < charLength; i++)
    {
        cout << charArr[i] << " ";
    }
    cout << endl;

    cout<<"Sorted stringArr: ";
    for(int i = 0;i < stringlength; i++)
    {
        cout<<names[i]<<" ";
    }
    cout<<endl;
    return 0;
}
