#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <climits> // Include this for INT_MAX
using namespace std;

typedef pair<string, int> psi;

class Location
{
    float longitude;
    float latitude;
    string name;

public:
    Location(float lon, float lat, string n)
    {
        longitude = lon;
        latitude = lat;
        name = n;
    }

    Location()
    {
        longitude = 0.0f;
        latitude = 0.0f;
        name = "NULL";
    }

    float getLongitude() const
    {
        return longitude;
    }

    float getLatitude() const
    {
        return latitude;
    }

    string getName() const
    {
        return name;
    }
};

class Graph
{
    vector<Location> locations;
    int num;
    list<psi> *adj_list;

public:
    Graph(int n)
    {
        num = n;
        locations.resize(num);
        adj_list = new list<psi>[n];
    }

    void addLocation(int index, Location l_name)
    {
        locations[index] = l_name;
    }

    void link_location(int src, int dest, int cost)
    {
        adj_list[src].push_back(make_pair(locations[dest].getName(), cost));
        adj_list[dest].push_back(make_pair(locations[src].getName(), cost));
    }

    void BFS(string startLocation)
    {
        int startIndex = -1;
        for (int i = 0; i < locations.size(); ++i)
        {
            if (locations[i].getName() == startLocation)
            {
                startIndex = i;
                break;
            }
        }

        if (startIndex == -1)
        {
            cerr << "Start location not found in the graph." << endl;
            return;
        }

        queue<int> q;
        vector<bool> visited(locations.size(), false);

        cout << "Visited: " << locations[startIndex].getName() << " ";

        q.push(startIndex);
        visited[startIndex] = true;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (auto it = adj_list[current].begin(); it != adj_list[current].end(); ++it)
            {
                auto &neighbor = *it;
                int neighborIndex = -1;
                for (int i = 0; i < locations.size(); ++i)
                {
                    if (locations[i].getName() == neighbor.first)
                    {
                        neighborIndex = i;
                        break;
                    }
                }

                if (neighborIndex != -1 && !visited[neighborIndex])
                {
                    cout << locations[neighborIndex].getName() << " ";
                    q.push(neighborIndex);
                    visited[neighborIndex] = true;
                }
            }
        }

        cout << endl;
    }

    void primMST()
    {
        priority_queue<psi, vector<psi>, greater<psi>> pq;

        int startIndex = -1;
        for (int i = 0; i < locations.size(); ++i)
        {
            if (locations[i].getName() == "Delivery Station (Karachi)")
            {
                startIndex = i;
                break;
            }
        }

        if (startIndex == -1)
        {
            cerr << "Start location not found in the graph." << endl;
            return;
        }

        int src = startIndex;

        vector<int> key(num, INT_MAX);
        vector<psi> parent(num, make_pair("", -1)); // Initialize parent vector correctly
        vector<bool> inMST(num, false);

        pq.push(make_pair(locations[src].getName(), 0));
        key[src] = 0;
        while (!pq.empty())
        {
            int uIndex = -1;
            string uName = pq.top().first;
            int u = -1;

            for (int i = 0; i < locations.size(); ++i)
            {
                if (locations[i].getName() == uName)
                {
                    uIndex = i;
                    u = i;
                    break;
                }
            }

            pq.pop();

            inMST[uIndex] = true;

            for (const auto &neighbor : adj_list[u])
            {
                int vIndex = -1;
                for (int i = 0; i < locations.size(); ++i)
                {
                    if (locations[i].getName() == neighbor.first)
                    {
                        vIndex = i;
                        break;
                    }
                }

                int v = vIndex;
                int weight = neighbor.second;

                if (!inMST[v] && weight < key[v])
                {
                    key[v] = weight;
                    pq.push(make_pair(locations[v].getName(), key[v]));
                    parent[v] = make_pair(locations[u].getName(), v); // Corrected order
                }
            }
        }

        int totalCost = 0;
        int j = 1;
        cout << "Prim's MST starting from delivery station :" << endl;
        for (int i = 0; i < parent.size(); ++i)
        {
            if (parent[i].second != -1)
            {
                cout << "Edge: " << parent[i].first << " - " << locations[i].getName() << " Weight: " << key[j] << endl;
                totalCost += key[j];
                j++;
            }
        }

        cout << "Total Cost of MST: " << totalCost << endl;
    }
};


int main()
{
    // Creating a graph with 6 locations
    Graph graph(6);

    // Adding locations to the graph
    graph.addLocation(0, Location(24.8607, 67.0011, "Delivery Station (Karachi)"));
    graph.addLocation(1, Location(24.8918, 67.0341, "Clifton"));
    graph.addLocation(2, Location(24.9123, 67.0525, "Saddar"));
    graph.addLocation(3, Location(24.9500, 67.0374, "DHA"));
    graph.addLocation(4, Location(24.9772, 67.0508, "Gulshan-e-Iqbal"));
    graph.addLocation(5, Location(25.0107, 67.0711, "Karachi University"));

    // Linking all locations with different costs
    graph.link_location(0, 1, 5); 
    graph.link_location(0, 2, 8);
    graph.link_location(0, 3, 6); 
    graph.link_location(0, 4, 3);
    graph.link_location(0, 5, 7); 

    graph.link_location(1, 2, 2);
    graph.link_location(1, 3, 9);
    graph.link_location(1, 4, 4);
    graph.link_location(1, 5, 1);

    //graph.link_location(2, 3, 7); 
    graph.link_location(2, 4, 5); 
    graph.link_location(2, 5, 2);

    graph.link_location(3, 4, 8);
    graph.link_location(3, 5, 6); 

    graph.link_location(4, 5, 3);


    // Finding Minimum Spanning Tree (MST) using Prim's algorithm starting from the delivery station in Karachi
    graph.primMST();

    return 0;
}
