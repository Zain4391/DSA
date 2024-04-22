#include <iostream>
#include<string>
#include <vector>
#include <list>
#include <queue>
using namespace std;


class User 
{
    private:
        string name;
        string dateOfBirth;
        int height;

    public:
        User()
        {
            name = " ";
            dateOfBirth = " ";
            height =0;
        }
        // Constructor
        User(string n, string dob, int h) : name(n), dateOfBirth(dob), height(h) {}

        // Getter for the name
        string getName() const 
        {
            return name;
        }

        // Getter for the date of birth
        string getDateOfBirth() const 
        {
            return dateOfBirth;
        }

        // Getter for the height
        int getHeight() const 
        {
            return height;
        }
    };


class SocialNetwork 
{
    private:
    vector<User> users;               // Vector to store user data
    int numUsers;                          // Number of users
    list<int>* adjacencyList;         // Array of linked lists to represent friend relationships

    public:
    // Constructor
    SocialNetwork(int num) : numUsers(num) 
    {
        adjacencyList = new std::list<int>[numUsers];
    }

    // Destructor to free allocated memory
    ~SocialNetwork() 
    {
        delete[] adjacencyList;
    }

    
    void addUser(User user) 
    {
        users.push_back(user); //scattered user
    }

    // connect the two scattered users
    void addFriendship(int user1, int user2) 
    {
        adjacencyList[user1].push_back(user2); 
        adjacencyList[user2].push_back(user1);
    }

    void BFS(int startNode) 
    {
        vector<bool> visited(numUsers, false);  // Mark all nodes as not visited
        queue<int> q;  // Queue for BFS

        visited[startNode] = true;
        q.push(startNode);

        while (!q.empty()) 
        {
            int currentNode = q.front();
            q.pop();

            // Display the name of the current user
            std::cout << users[currentNode].getName() << " ";

            // Enqueue adjacent nodes that are not visited
            for (int neighbor : adjacencyList[currentNode]) 
            {
                if (!visited[neighbor]) 
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        std::cout << std::endl;
    }

    void DFS(int currentNode) 
    {
        static vector<bool>visited (users.size(),false);
        
        cout << users[currentNode].getName() << " ";
        visited[currentNode] = true;

    
        for (int neighbor : adjacencyList[currentNode]) 
        {
            if (!visited[neighbor]) 
            {
                DFS(neighbor);
            }
        }
    }

    void showProfile(string username)
    {
        for(int i=0; i<numUsers; i++)
        {
            if(users[i].getName() == username)
            {
                cout<<users[i].getName()<<" "<<users[i].getHeight()<<" "<<users[i].getDateOfBirth()<<" ";
            }
        }

        cout<<endl;
    }

    void checkBirthdaysByMonth(int month) 
    {
            for (const User& user : users) 
            {
                // Extract the month from the date of birth (assuming dateOfBirth is in the format "YYYY-MM-DD")
                int userMonth = stoi(user.getDateOfBirth().substr(5, 2));

                if (userMonth == month) 
                {
                    cout << user.getName() << "'s birthday is in the specified month." << std::endl;
                }
            }
    }

    User Tallest()
    {
        int tallestUserIndex = -1;
        int max = 0;

        for(int i=0;i<numUsers;i++)
        {
            if(users[i].getHeight() > max)
            {
                max=users[i].getHeight();
                tallestUserIndex=i;
            }
        }

        return users[tallestUserIndex];
        
    }

    
};
int main() 
{
    SocialNetwork socialNetwork(6);

    // Adding users to the social network
    socialNetwork.addUser(User("Alice", "1990-05-15", 160));
    socialNetwork.addUser(User("Bob", "1985-02-20", 175));
    socialNetwork.addUser(User("Charlie", "1993-11-10", 165));
    socialNetwork.addUser(User("David", "1988-08-05", 180));
    socialNetwork.addUser(User("Alvin", "2001-08-05", 181));
    socialNetwork.addUser(User("Dravid", "2005-08-05", 185));

    // Establishing friendships
    socialNetwork.addFriendship(0, 1);
    socialNetwork.addFriendship(1, 2);
    socialNetwork.addFriendship(2, 3);
    socialNetwork.addFriendship(3, 4);
    socialNetwork.addFriendship(4, 5);

    // Performing BFS starting from the first user
    cout << "BFS starting from Alice: ";
    socialNetwork.BFS(0);
    cout << endl;

    // Performing DFS starting from the first user
    cout << "DFS starting from Alice: ";
    socialNetwork.DFS(0);
    cout << endl;

    cout << "Alice's user profile:-----" << endl;
    socialNetwork.showProfile("Alice");

    cout << "User with the tallest height: ";
    User tallest = socialNetwork.Tallest();
    cout << tallest.getName() << endl;

    // Check birthdays in a specific month (e.g., month 8)
    cout <<"Users with birthdays in month 8:\n ";
    socialNetwork.checkBirthdaysByMonth(8);

    return 0;
}

