#include<iostream>
using namespace std;

class Heap
{
    int size;
    int *heap;
    int capacity;

    public:

    Heap()
    {
        capacity=0;
        size=0;
        heap=NULL;
    }

    Heap(int n)
    {
        size = 0;
        capacity=n;
        heap = new int[capacity];

        for(int i=0;i<capacity;i++)
        {
            heap[i]=-1;
        }
    }

    void heapifyUp(int i)
    {
        if(i<=0)
        {
            return;
        }

        int parent = (i-1)/2;
        if(heap[i] < heap[parent])
        {
            swap(heap[i],heap[parent]);
            i=parent;
            heapifyUp(i);
        }
    }

    void heapifyDown(int i)
    {
        int left = 2*i+1;
        int rigth = 2*i+2;
        int smallest = i;
        if(left < size && heap[left] < heap[smallest])
        {
            smallest=left;
        }
        if(rigth < size && heap[rigth] < heap[smallest])
        {
            smallest=rigth;
        }
        if(smallest != i)
        {
            swap(heap[i],heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void insert(int x) 
    {
        if(size == capacity)
        {
            cerr<<"Heap Full"<<endl;
            return;
        }
        else
        {
            heap[size]=x;
            heapifyUp(size);
            size++;
        }
    }

    void Show()
    {
        for(int i=0;i<size;i++)
        {
            cout<<heap[i]<<" ";
        }

        cout<<endl;
    }

    int getmin()
    {
        if(size <= 0)
        {
            cerr<<"Heap empty"<<endl;
            return -1;
        }
        else
        {
            return heap[0];
        }
    }

    int getlast()
    {
        if(size <= 0)
        {
            return -1;
        }
        else
        {
            return heap[size-1];
        }
    }

    int extract_min()
    {
        if(size <= 0)
        {
            return -1;
        }
        else
        {
            int temp = heap[0];
            heap[0] = getlast();
            size--;
            heapifyDown(0);
            return temp;
        }
    }

    void Delete(int key)
    {
        int index=-1;

        for(int i=0;i<size;i++)
        {
            if(heap[i]==key)
            {
                index=i;
                break;
            }
        }

        if(index == -1)
        {
            cerr<<"Key not found."<<endl;
        }

        //delete the specified element 
        heap[index] = heap[size - 1];
        size--;

        if(index < size && heap[index] < heap[(index-1)/2])
        {
            heapifyUp(index);
        }
        else
        {
            heapifyDown(index);
        }
    }

    void heapsort()
    {
        int *sorted = new int[capacity];

        for(int i = 0; i < capacity; i++)
        {
            sorted[i]=extract_min();
        }

        for(int i =0; i<capacity; i++)
        {
            cout<<sorted[i]<<" ";
        }

        cout<<endl;
        delete[] sorted;
    }
};

int main()
{
    Heap minheap(4);

    minheap.insert(5);
    minheap.insert(6);
    minheap.insert(11);
    minheap.insert(12);
    minheap.Show();

    cout<<"the min element in heap : "<<minheap.getmin()<<endl;
    //cout<<"Extracted min: "<<minheap.extract_min()<<endl;

    //cout<<"Heap after extraction: ";
    //minheap.Show();

    //cout<<"Heap after deletion: ";
    //minheap.Delete(11);
    //minheap.Show();
    minheap.heapsort();
    return 0;
}