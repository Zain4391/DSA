#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
using namespace std;

typedef pair<string, int> psi;

class Location
{
    float longitude;
    float latitude;
    string name;

public:
    // Constructor
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

    // Getters
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
        locations[index] = l_name; // Assign directly at the specified index
    }

    void link_location(int src, int dest, int cost)
    {
        adj_list[src].push_back(make_pair(locations[dest].getName(), cost));
        adj_list[dest].push_back(make_pair(locations[src].getName(), cost));
    }

    void BFS(string startLocation)
    {
        // Find the index of the startLocation in the locations vector
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
        vector<bool> visited(locations.size(), false); //initially all false

        cout << "Visited: " << locations[startIndex].getName() << " ";

        q.push(startIndex);
        visited[startIndex] = true;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            // Traverse neighbors
            for (const auto &neighbor : adj_list[current])
            {
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

        // Find the index of "Delivery Station (Karachi)" in the locations vector
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

        // Start with the specified location
        int src = startIndex;

        vector<int> key(num, INT_MAX);  // Key values used to pick the minimum weight edge
        vector<psi> parent;             // Array to store constructed MST
        vector<bool> inMST(num, false); // To keep track of vertices included in MST

        // Start from the specified node:
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
                    uIndex = i; // index of vertex
                    u = i;      // vertex itself
                    break;
                }
            }

            pq.pop();

            inMST[uIndex] = true; // Include vertex in MST

            // Traverse neighbors
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

                // If v is not in MST and weight of (u, v) is smaller than the current key of v, include in MST
                if (!inMST[v] && weight < key[v])
                {
                    key[v] = weight;
                    pq.push(make_pair(locations[v].getName(), key[v]));
                    parent.push_back({locations[v].getName(), u}); // Corrected order
                }
            }
        }

        int totalCost = 0;
        int j = 0, k = 1;
        cout << "Prim's MST starting from Location1:" << endl;
        for (auto it = parent.begin(); it != parent.end(); ++it)
        {
            cout << "Edge: " << it->first << " - " << key[k] << " Cost" << endl;
            totalCost += key[j];
            j++;
            k++;
        }

        cout << "Total Cost of MST: " << totalCost << endl;
    }
};

int main()
{
    // Create a graph with 6 locations in Karachi
    Graph karachiGraph(6);

    // Add locations to the graph
    Location deliveryStation(67.0306, 24.8607, "Delivery Station (Karachi)");
    Location location1(67.0348, 24.8607, "Clifton");
    Location location2(67.0424, 24.9056, "Saddar");
    Location location3(67.0694, 24.9295, "Gulshan-e-Iqbal");
    Location location4(67.0728, 24.9228, "Tariq Road");
    Location location5(67.0982, 24.9303, "Karachi Airport");

    karachiGraph.addLocation(0, deliveryStation);
    karachiGraph.addLocation(1, location1);
    karachiGraph.addLocation(2, location2);
    karachiGraph.addLocation(3, location3);
    karachiGraph.addLocation(4, location4);
    karachiGraph.addLocation(5, location5);

    // Link the locations with edges and costs
    karachiGraph.link_location(0, 1, 8);  // Distance from Delivery Station to Clifton
    karachiGraph.link_location(1, 2, 5);  // Distance from Clifton to Saddar
    karachiGraph.link_location(1, 3, 12); // Distance from Clifton to Gulshan-e-Iqbal
    karachiGraph.link_location(2, 4, 10); // Distance from Saddar to Tariq Road
    karachiGraph.link_location(3, 5, 15); // Distance from Gulshan-e-Iqbal to Karachi Airport

    // Perform BFS starting from the "Delivery Station (Karachi)"
    cout << "BFS starting from Delivery Station (Karachi): ";
    karachiGraph.BFS("Delivery Station (Karachi)");

    // Perform Prim's MST starting from the "Delivery Station (Karachi)"
    karachiGraph.primMST();

    return 0;
}
