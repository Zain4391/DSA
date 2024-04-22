#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Look up is in O(n), not that efficent for duplicates

int hash_func(int key)
{
    return key % 11; //can be any prime number
}

int Pattern_alog(vector<int> arr,int p)
{
    int hashog = hash_func(p);
    int count =0;
    string num;

    for(int i =0; i<arr.size()-1; i++)
    {
        int temp = arr[i];
        int temp2 = arr[i+1];

        num = to_string(temp);
        num += to_string(temp2);

        temp = stoi(num);
        temp2 = hash_func(temp);

        if(temp2 == hashog)
        {
            if(temp == p)
            {
                count++;
            }
            else
            {
                cout<<"Superior detection found"<<endl;
            }
        }
    }

    return count;
}

int main()
{
    vector<int> input = {1, 2, 3, 4, 5, 6, 2, 3};
    int p = 23; // Change this to the value you want to check against
    int result = Pattern_alog(input, p);
    cout << "Count of matches: " << result << endl;

    return 0;
}