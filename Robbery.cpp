#include<iostream>
#include<vector>
#include<stack>
#include <cstdlib>
#include<algorithm>
using namespace std;

void populate_deck(stack<int> &cards,int size)
{
    srand(time(NULL));

    for(int i = 0 ; i < size ; i++)
    {
        int num =  rand() % 53; //random numbers between 1 and 52
        cards.push(num);
    }
}

void SHuffle_deck(stack<int> &cards)
{
    vector<int> temp;

    while(!cards.empty())
    {
        temp.push_back(cards.top());
        cards.pop();
    }

    random_shuffle (temp.begin(),temp.end()); //shuffling the cards

    while(!temp.empty())
    {
        cards.push(temp.back());
        temp.pop_back();
    }
    
}

void Play(stack<int> &cards,int players)
{
    int rounds = cards.size()/players;
    int *arr = new int[players];
    stack<int>*pile = new stack<int> [players]; //pile for each respective player

    int i=0;

    while(i<rounds && !cards.empty())
    {
        for(int j=0;j<players;j++)
        {
            if(!cards.empty())
            {
                arr[j] = cards.top();
                cards.pop();
            }
        }

        int max_index=0;

        for(int k=0;k<players;k++)
        {
            if(arr[k] > arr[max_index])
            {
                max_index = k;
            }
        }

        for(int k =0;k<players;k++)
        {
            pile[max_index].push(arr[k]);
        }

        cout<<"Round "<<i+1<<" won by player "<<max_index+1<<endl;

        i++;
    }

    //for winner of the game
    int winner=0;
    for(int k =1 ;k<players;k++)
    {
        if(pile[k].size() > pile[winner].size())
        {
            winner = k;
        }
    }

    cout<<"Winner is player : "<<winner+1<<endl;

    delete[] arr;
    delete[] pile;

}

int main()
{
    stack<int> cards;

    populate_deck(cards,52);
    SHuffle_deck(cards);
    Play(cards,4);

    return 0;
}