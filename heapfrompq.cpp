#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Heap
{
    int capacity,size;
    int *minheap;

    void heapifyup(int i)
    {
        if(i<=0)
        {
            return;
        }

        int p = (i-1)/2;
        if(minheap[i] < minheap[p])
        {
            swap(minheap[i],minheap[p]);
            i = p;
            heapifyup(i);
        }
    }

    void heapifydown(int i)
    {
        int l=2*i+1, r=2*i+2, smallest = i;
        if(l<size && minheap[l] < minheap[smallest])
        {
            smallest=l;
        }
        if(r<size && minheap[r] < minheap[smallest])
        {
            smallest=r;
        }

        if(smallest!=i)
        {
            swap(minheap[i],minheap[smallest]);
            heapifydown(smallest);
        }
    }
    public:
    Heap()
    {
        capacity = size = -1;
        minheap = NULL;
    }

    Heap(int n)
    {
        capacity = n;
        size = 0;
        minheap = new int[capacity];

        for(int i =0; i<capacity;i++)
        {
            minheap[i]=-1;
        }
    }

    void insert(int n)
    {
        if(size == capacity)
        {
            cerr<<"Heap Full"<<endl;
            return;
        }

        minheap[size] = n;
        heapifyup(size);
        size++;
    }

    int extract_min()
    {
        if(size == -1)
        {
            cerr<<"Heap empty\n";
            return -1;
        }
        
        int temp = minheap[0];
        minheap[0] = minheap[size - 1];
        size--;
        heapifydown(0);
        return temp;
    }

    void Delete(int val)
    {
        if(size == -1)
        {
            cerr<<"Heap empty\n";
        }

        int index=-1;

        for(int i =0;i<size;i++)
        {
            if(minheap[i] == val)
            {
                index=i;
            }
        }

        //delete the element
        minheap[index] = minheap[size-1];
        size--;

        if(index < size && minheap[index] < minheap[(index-1)/2])
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
        for(int i=0;i<size;i++)
        {
            cout<<minheap[i]<<" ";
        }

        cout<<endl;
    }

    void HeapSort()
    {
        vector<int> sorted;

        for(int i=0;i<capacity;i++)
        {
            sorted.push_back(extract_min());
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
    priority_queue<int>pq;
    int arr[]={16,11,2,4,19,20,21};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<size;i++)
    {
        pq.push(arr[i]);
    }

    Heap h(size);
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