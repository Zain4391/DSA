#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node()
    {
        next=NULL;
    }

    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

class LinkedList
{
    public:
    Node *head;

    LinkedList()
    {
        head=NULL;
    }

    void insert(int val)
    {
        Node *newNode = new Node(val);

        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            Node*temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }

    void Display()
    {
        Node *current=head;

        while(current!=NULL)
        {
            cout<<current->data<<" ";
            current=current->next;
        }
    }

    void Insertion_sort()
    {
        Node *sorted=NULL;

        if(head==NULL || head->next==NULL) //list either sorted(one element only) or empty
        {
            return;
        }

        while(head!=NULL)
        {
            Node *current=head;
            head=head->next;

            if(sorted==NULL || current->data < sorted->data)
            {
                current->next=sorted;
                sorted=current;
            }
            else
            {
                Node *temp=sorted;
                while(temp->next!=NULL && temp->data < sorted->data)
                {
                    temp=temp->next;
                }
                current->next=temp->next;
                temp->next=current;
            }
        }
    }
};

void Bucketsort(int arr[],int size,int max_val)
{
    int B_num = max_val+1;

    LinkedList buckets[B_num];

    for(int i=0;i<size;i++)
    {
        //placing buckets in their respective lists
        int Bucket_index = arr[i];
        buckets[Bucket_index].insert(arr[i]);
    }

    //sorting the buckets
    for(int i=0;i<B_num;i++)
    {
        buckets[i].Insertion_sort();
    }

    int j=0;
    for(int i=0;i<B_num;i++)
    {
        Node *current=buckets[i].head;
        while(current!=NULL)
        {
            arr[j]=current->data;
            current=current->next;
            j++;
        }
    }
}

int find_max(int arr[],int size)
{
    int num=arr[0];
    for(int i=0;i<size;i++)
    {
        if(arr[i]>num)
        {
            num=arr[i];
        }
    }
    return num;
}

void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

int main()
{
    int arr[] = {61,42,67,27,17,75,56,93,76,46,63,55,70,59,98,9,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max_value = find_max(arr,size);

    cout << "Original Array: ";
    print(arr,size);

    Bucketsort(arr, size, max_value);

    cout << "Sorted Array: ";
    print(arr,size);

    return 0;
}


