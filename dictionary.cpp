#include<bits/stdc++.h>
using namespace std;

class Dictionary
{
    int size;
    list<string> *table;

    int hash_func(string val)
    {
        int hash = 0;
        for(int i=0; i<val.size(); i++)
        {
            char c = val[i];
            hash+='0'+c;
        }

        return hash % size;
    }

    public:
    Dictionary()
    {
        size = 100;
        table = new list<string>[size];
    }

    void Add_word(string word)
    {
        int index = hash_func(word);
        table[index].push_back(word);
    }

    void Search_Word(string word)
    {
        int index = hash_func(word);
        for(auto it = table[index].begin(); it != table[index].end(); it++)
        {
            string val = *it;
            if(val == word)
            {
                cout<<word<<" found !"<<endl;
                return;
            }
        }

        cout<<"Word not found."<<endl;
    }

    void Display()
    {
        for(int i=0; i<100; i++)
        {
            cout<<"INDEX "<<i<<" : ";
            for(auto it = table[i].begin(); it!= table[i].end(); it++)
            {
                cout<<*it<<" ";
            }

            cout<<endl;
        }
    }
};

int main() 
{
    Dictionary myDictionary;

    myDictionary.Add_word("apple");
    myDictionary.Add_word("banana");
    myDictionary.Add_word("cat");
    myDictionary.Add_word("dog");
    myDictionary.Add_word("elephant");
    myDictionary.Add_word("fish");

    // Searching for words in the dictionary
    myDictionary.Search_Word("cat");
    myDictionary.Search_Word("bird"); 

    myDictionary.Display();

    return 0;
}