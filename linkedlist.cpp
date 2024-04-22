#include<iostream>
using namespace std;

class Node
{
    public:
    int number;
    Node *next_ptr;

    Node()
    {
        number=0;
        next_ptr=NULL;
    }

    Node(int x)
    {
        number=x; //assign first element 
        this->next_ptr=NULL; 
    }
};

class Linkedlist
{
    public:

    Node *head;

    Linkedlist()
    {
        head=NULL;
    }

    void insert()
    {
        int element;
        cout<<"Enter the element value: ";
        cin>>element;

        Node *newNode=new Node(element); //allocating memeory to the new element of the list
        
        //if list empty store the element in the first position
        //if not then place the element at the last of the list
        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            Node *temp=head;
            //traversing the Linked List
            while(temp->next_ptr!=NULL)
            {
                temp=temp->next_ptr; 
            }

            temp->next_ptr=newNode; //assigning the value at the end of the list
        }
    }

    void printlist()
    {
        Node *temp=head;
        
        //check if the list is empty 
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
        }
        else
        {
            while(temp->next_ptr!=NULL)
            {
                cout<<"Element : "<<temp->number<<" ";
                temp=temp->next_ptr; //traversing the list
            }
            cout<<"Element : "<<temp->number<<" "; //printing the last element
        }
    }

    
    void deleteNode(int pos)
{
	Node *temp1 = head, *temp2 = NULL;
	int ListLen = 0;

	if (head == NULL) 
    {
		cout << "List empty." << endl;
		return;
	}

	// Find length of the linked-list.
	while (temp1 != NULL) 
    {
		temp1 = temp1->next_ptr;
		ListLen++;
	}


	if (pos>ListLen) 
    {
		cout << "Index out of range"<< endl;
		return;
	}

	temp1 = head; //temp1 needs to be reassigned after going through the while loop

	if (pos==1) 
    {
		head = head->next_ptr;
		delete temp1;
		return;
	}

	// Traverse the list
	while (pos-->1)
    {

		temp2=temp1;
		temp1=temp1->next_ptr;
	}

	// Change the next pointer of the previous node.
	temp2->next_ptr=temp1->next_ptr;
	delete temp1;
}


    void delete_Node(int element)
    {
        int listlen=0,i;
        Node *temp=head,*temp2;
        
        if (head==NULL)
        {
            cout<<"\nThe linked list is Empty\n";
        }

        while (temp!=NULL)
        {
            temp=temp->next_ptr;
            listlen++;
        }

        temp=head; //temp1 needs to be reassigned after going through the while loop

        if(head->number==element)
        {
            head=head->next_ptr;
            delete temp;
            return;
        }

        while(temp!=NULL)
        {
            temp2=temp;
            temp=temp->next_ptr;

            if(temp->number==element)
            {
                temp2->next_ptr=temp->next_ptr;
                delete temp;
                return;
            }
            else
            {
                cout<<"Element not found"<<endl;
                return;
            }
        }

        
    }

    void insert(int pos)
    {
        int element,count=0;
        cout<<"Enter the element value: ";
        cin>>element;

        Node *newNode=new Node(element); //allocating memeory to the new element of the list
        Node *temp=head;
        //if list empty store the element in the first position
        //if not then place the element at the last of the list
        if(head==NULL)
        {
            head=newNode;
            return;
        }

        int listlen=0;
        while(temp!=NULL)
        {
            temp=temp->next_ptr;
            listlen++;
        }  
        count=listlen;
        temp=head;
        //check for valid position
        if(pos>listlen)
        {
            newNode->number=element;
            newNode->next_ptr=NULL;
            return;
        }

        //traversing the list to find the required node
        for(int i=1;i<pos;i++)
        {
            if(temp!=NULL)
            {
                temp=temp->next_ptr;
            }
        }

        if(temp!=NULL)
        {
            newNode->next_ptr=temp->next_ptr;
            temp->next_ptr=newNode;
        }
     }
   
     void search_list(int element)
     {
        Node *temp=head;

        if(head==NULL)
        {
            cout<<"\n List Empty"<<endl;
        }

        if(head->number==element)
        {
            cout<<"Element found: "<<head->number<<endl;
        }
       else if(head->number!=element)
       {
        while(temp->next_ptr!=NULL)
        {
            temp=temp->next_ptr;

            if(temp->number==element)
            {
                cout<<"Element found: "<<temp->number<<endl;
                return;
            }
        }
       }

       else
       {
        cout<<"Element not found"<<endl;
        return;
       }
        
     }


     void reverse_list(Node *Headref)
     {
        Node *current=Headref;
        Node *prev=NULL,*next=NULL;
        while ( current != NULL )
        {
            next=current->next_ptr;
            current->next_ptr=prev;
            prev=current;
            current=next;
        }

        head=prev;
     }

     //utility func for palindrome
     Node* reverselist(Node *Headref)
     {
        Node *current=Headref;
        Node *prev=NULL,*next=NULL;
        while ( current != NULL )
        {
            next=current->next_ptr;
            current->next_ptr=prev;
            prev=current;
            current=next;
        }

        return prev;
     }

     Node *find_middle()
     {
        Node *slow_ptr=head;
        Node *fast_ptr=head;

        while(fast_ptr!=NULL && fast_ptr->next_ptr!=NULL)
        {
            slow_ptr=slow_ptr->next_ptr;
            fast_ptr=fast_ptr->next_ptr->next_ptr;
        }

        if(fast_ptr!=NULL)
        {
            return slow_ptr->next_ptr;
        }
        else
        {
            return slow_ptr;
        }
     }

     bool isPalindrome()
     {
        if(head==NULL)
        {
            return true;
        }

        Node *middle=find_middle();
        Node *last=reverselist(middle);
        Node *current=head;

        while(last!=NULL)
        {
            if(last->number!=current->number)
            {
                return false;
            }

            last=last->next_ptr;
            current=current->next_ptr;
        }

        return true;

     }

     void sort_list()
     {
        Node *sorted=NULL;
        if(head==NULL || head->next_ptr==NULL)
        {
            cout<<"List is either empty or sorted"<<endl;
            return;
        }
        
        while(head != NULL)
        {
            Node *current=head;
            head=head->next_ptr;

            if(sorted==NULL || current->number<sorted->number)
            {
                current->next_ptr=sorted;
                sorted=current;
            }
            else
            {
                Node *temp=sorted;
                while(temp->next_ptr!=NULL && current->number > temp->next_ptr->number)
                {
                    temp=temp->next_ptr;
                }

                current->next_ptr=temp->next_ptr;
                temp->next_ptr=current;
            }
        }

        head=sorted;
     }

void search_and_delete_Dup()
{
    Node *current = head;

    while (current != nullptr) 
    {
        Node *inner_curr = current;
        while (inner_curr->next_ptr != nullptr) 
        {
            if (inner_curr->next_ptr->number == current->number) 
            {
                Node *duplicate = inner_curr->next_ptr;
                inner_curr->next_ptr = inner_curr->next_ptr->next_ptr;
                delete duplicate;
            } 
            else 
            {
                inner_curr = inner_curr->next_ptr;
            }
        }
        current = current->next_ptr;
    }
}

};

int main()
{
    Linkedlist numbers;
    char ch='n';
    do
    {
        numbers.insert();
        cout<<"Do you want to insert more elements? y=Yes, n=No ."<<endl;
        cin>>ch;
    }while(ch!='n');
    numbers.insert(3);
    numbers.printlist();
    cout<<endl;
    //numbers.deleteNode(1);
    //numbers.delete_Node(12);
    //numbers.search_list(13);
    //bool check = numbers.isPalindrome();
    //numbers.reverse_list(numbers.head);
    numbers.sort_list();
    //numbers.printlist();
   //2 numbers.search_and_delete_Dup();
    cout<<endl;
    numbers.printlist();
    return 0;
}