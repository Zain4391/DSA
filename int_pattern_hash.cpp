#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

//more efficeint as it envolves hahsing through undordered sets. Look up is in O(1)

int hash_func(int key)
{
    return key % 11; //can be any prime number
}

int Pattern_algo(vector<int> arr,int p)
{
    int hashog = hash_func(p);
    int count =0;
    string num;
    unordered_set<int> seen;

    for(int i=0;i<arr.size() -1 ;i++)
    {
        int temp = arr[i];
        int temp2 = arr[i+1];

        num = to_string(temp);
        num += to_string(temp2);

        temp = stoi(num);
        temp2 = hash_func(temp);

        if(hashog == temp2)
        {
            if(p == temp && seen.find(temp) == seen.end())
            {
                count++;
            }
            else
            {
                seen.insert(temp);
                cout<<"Superior detection found."<<endl;
            }
        }
    }

    return count;

}

int main()
{
    vector<int> input = {1, 2, 3, 4, 5, 6, 2, 3};
    int p = 23; // Change this to the value you want to check against
    int result = Pattern_algo(input, p);
    cout << "Count of matches: " << result << endl;

    return 0;
}