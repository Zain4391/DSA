#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class MaxHeap
{
    int capacity, size;
    int *maxheap;

    void heapifyup(int i)
    {
        if(i <= 0)
        {
            return;
        }

        int p = (i - 1) / 2;
        if(maxheap[i] > maxheap[p])
        {
            swap(maxheap[i], maxheap[p]);
            i = p;
            heapifyup(i);
        }
    }

    void heapifydown(int i)
    {
        int l = 2 * i + 1, r = 2 * i + 2, largest = i;
        if(l < size && maxheap[l] > maxheap[largest])
        {
            largest = l;
        }
        if(r < size && maxheap[r] > maxheap[largest])
        {
            largest = r;
        }

        if(largest != i)
        {
            swap(maxheap[i], maxheap[largest]);
            heapifydown(largest);
        }
    }

public:
    MaxHeap()
    {
        capacity = size = -1;
        maxheap = NULL;
    }

    MaxHeap(int n)
    {
        capacity = n;
        size = 0;
        maxheap = new int[capacity];

        for(int i = 0; i < capacity; i++)
        {
            maxheap[i] = -1;
        }
    }

    void insert(int n)
    {
        if(size == capacity)
        {
            cerr << "Heap Full" << endl;
            return;
        }

        maxheap[size] = n;
        heapifyup(size);
        size++;
    }

    int extract_max()
    {
        if(size == -1)
        {
            cerr << "Heap empty\n";
            return -1;
        }

        int temp = maxheap[0];
        maxheap[0] = maxheap[size - 1];
        size--;
        heapifydown(0);
        return temp;
    }

    void Delete(int val)
    {
        if(size == -1)
        {
            cerr << "Heap empty\n";
        }

        int index = -1;

        for(int i = 0; i < size; i++)
        {
            if(maxheap[i] == val)
            {
                index = i;
            }
        }

        if(index == -1)
        {
            cerr<<"Key not found."<<endl;
            return;
        }

        // delete the element
        maxheap[index] = maxheap[size - 1];
        size--;

        if(index < size && maxheap[index] > maxheap[(index - 1) / 2])
        {
            heapifyup(index);
        }
        else
        {
            heapifydown(index);
        }
    }

    void Show()
    {
        for(int i = 0; i < size; i++)
        {
            cout << maxheap[i] << " ";
        }

        cout << endl;
    }

    void HeapSort()
    {
        vector<int> sorted;

        for(int i=0;i<capacity;i++)
        {
            sorted.push_back(extract_max());
        }

        for(int i =0; i<sorted.size() ;i++)
        {
            cout<<sorted[i]<<" ";
        }

        cout << endl;
    }
};

int main()
{
    priority_queue<int> pq;
    int arr[] = {16, 11, 2, 4, 19, 20, 21};
    int size = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < size; i++)
    {
        pq.push(arr[i]);
    }

    MaxHeap h(size);
    while(!pq.empty())
    {
        h.insert(pq.top());
        pq.pop();
    }

    h.Show();

    cout<<"After sorting: \n";
    h.HeapSort();

    return 0;
}