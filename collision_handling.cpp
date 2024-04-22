#include<iostream>
#include<algorithm>
using namespace std;


class Node
{
    public:
    int data;
    int key;
    Node *next;

    Node()
    {
        next=NULL;
        data=0;
        key=0;
    }

    Node(int key,int value)
    {
        this->key=key;
        this->data=value;
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

    void insert(int key,int val)
    {
        Node *newNode = new Node(key,val);

        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            Node *current=head;
            while(current->next!=NULL)
            {
                current=current->next;
            }

            current->next=newNode;
        }

        Sort_List();
    }

    void Sort_List()
    {
        for(Node *temp=head;temp!=NULL;temp=temp->next)
        {
            for(Node * temp2=temp->next;temp2!=NULL;temp2=temp2->next)
            {
                if(temp2->data < temp->data)
                {
                    swap(temp2->data,temp->data);
                }
            }
        }
    }

    bool Search(int val)
    {
        if(head==NULL)
        {
            return false;
        }
        else
        {
            Node *current = head;
            while(current!=NULL)
            {
                if(current->data==val)
                {
                    return true;
                }
                else
                {
                    current=current->next;
                }
            }
        }

        return false;
    }
};

class Hashmap
{
    private:
    int table_size;
    LinkedList *table;

    public:
    Hashmap()
    {
        table=NULL;
    }
    Hashmap(int n)
    {
        table_size = n;
        table = new LinkedList[n];
    }

    int hash_func(int x)
    {
        return x % table_size;
    }

    void insert(int val)
    {
        int index = hash_func(val);
        table[index].insert(index,val);
    }

    bool Search(int key)
    {
        int index = hash_func(key);
        return table[index].Search(key);
    }

    void Show()
    {
        for(int i =0 ;i<table_size;i++)
        {
            Node * current = table[i].head;
            cout<<"Values at index "<<i+1<<" : ";
            while(current!=NULL)
            {
                cout<<current->data<<" ";
                current=current->next;
            }

            cout<<endl;
        }

        cout<<endl;
    }

    void Delete(int key)
    {
        int index = hash_func(key);
        Node *current = table[index].head;
        Node *temp = NULL;
        if(current->data == key)
        {
            table[index].head = current->next;
            delete current;
            return;
        }
        while(current!=NULL)
        {
            if(current->data==key)
            {
                temp->next = current->next;
                delete current;
                return;
            }
            temp = current;
            current=current->next;
        }
    }
};

int main()
{
    Hashmap myhashmap(10);
    myhashmap.insert(100);
    myhashmap.insert(101);
    myhashmap.insert(211);
    myhashmap.insert(111);
    myhashmap.insert(10);
    myhashmap.insert(89);
    myhashmap.insert(75);
    myhashmap.insert(16);
    myhashmap.insert(115);
    
    if(myhashmap.Search(115))
    {
        cout<<"Found\n";
    }
    else
    {
        cout<<"Not found\n";
    }
    myhashmap.Show();
    myhashmap.Delete(211);
    myhashmap.Show();
    return 0;
}