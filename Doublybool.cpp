#include<iostream>
using namespace std;

class Node
{
public:
    bool data;
    Node* next;
    Node* prev;

    Node()
    {
        next = nullptr;
        prev = nullptr;
    }

    Node(bool x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
public:
    Node* head, * tail;

    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert(bool val)
    {
        Node* node = new Node(val);

        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    Node* BitwiseAND(Node* list1, Node* list2)
    {
        Node* result_head = nullptr;
        Node* result_tail = nullptr;

        while (list1 != nullptr && list2 != nullptr)
        {
            bool and_result = list1->data && list2->data;
            Node* node = new Node(and_result);

            if (result_head == nullptr)
            {
                result_head = node;
                result_tail = node;
            }
            else
            {
                result_tail->next = node;
                node->prev = result_tail;
                result_tail = node;
            }

            list1 = list1->next;
            list2 = list2->next;
        }

        return result_head;
    }

    void Display()
    {
        Node* temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

void show(Node* headptr)
{
    Node* temp = headptr;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    DoublyLinkedList list1, list2;
    list1.insert(true);
    list1.insert(true);
    list1.insert(true);
    list1.Display();
    list2.insert(true);
    list2.insert(false);
    list2.insert(true);
    list2.Display();
    Node* list3 = list1.BitwiseAND(list1.head, list2.head);
    show(list3);
    return 0;
}
