#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#define I INT_MAX
typedef pair<int, int> pii;

class Graph 
{
    int V;
    int **adj_matrix;

public:
    Graph() 
    {
        V = 0;
        adj_matrix = nullptr;
    }

    Graph(int v) 
    {
        V = v;
        adj_matrix = new int *[V];
        for (int i = 0; i < V; i++) 
        {
            adj_matrix[i] = new int[V];
        }

        for (int i = 0; i < V; i++) 
        {
            for (int j = 0; j < V; j++) 
            {
                adj_matrix[i][j] = I; // all nodes are INFINITY
            }
        }
    }

    void populate(int s, int d, int w) 
    {
        adj_matrix[s][d] = w;
        adj_matrix[d][s] = w;
    }

    int findParent(vector<int> &parent, int i) 
    {
        if (parent[i] == -1)
            return i;
        return findParent(parent, parent[i]);
    }

    void unionSets(vector<int> &parent, int x, int y) 
    {
        int xset = findParent(parent, x);
        int yset = findParent(parent, y);
        parent[xset] = yset;
    }

    int KruskalMST() 
    {
        int cost = 0;
        vector<pair<int, pii>> edges;
        vector<int> parent(V, -1);
        vector<pair<int,pii>> result;

        for (int i = 0; i < V; i++) 
        {
            for (int j = 0; j < V; j++)
             {
                if (adj_matrix[i][j] != I) 
                {
                    edges.push_back({adj_matrix[i][j], {i, j}}); // weight, (source,dest) -> format of pair<int,pii>
                }
            }
        }

        // min heap
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> minHeap;

        // Add all edges to the min heap
        for (auto edge : edges) 
        {
            minHeap.push(edge);
        }

        
        while (!minHeap.empty()) 
        {
            pair<int,pii> edge = minHeap.top();
            minHeap.pop();

            int x = findParent(parent, edge.second.first);
            int y = findParent(parent, edge.second.second);

            if (x != y) //check for cycle, if not then add to MST and union the sets
            {
                result.push_back(edge);
                cost += edge.first;
                unionSets(parent, x, y);
            }
        }

        //print the MST
        for(int i=0; i<result.size();i++)
        {
            cout<<result[i].second.first<<"---"<<result[i].second.second<<endl;
        }

        return cost;
    }

    void Disjktra(int src)
    {
        priority_queue<pii,vector<pii>,greater<pii>> minheap;
        vector<int> dist(V,I);

        dist[src] = 0;
        minheap.push({0,src});

        while(!minheap.empty())
        {
            int u = minheap.top().second;
            minheap.pop();

            for(int v =0; v<V; v++)
            {
                if(adj_matrix[u][v] != I)
                {
                    int weight = adj_matrix[u][v];

                    if (dist[v] > dist[u] + weight) 
                    {
                        dist[v] = dist[u] + weight;
                        minheap.push({dist[v], v});
                    }
                }
            }
        }

        int cost=0;

        cout << "\nShortest Distances from Source (" << src << "):\n";
        for (int i = 0; i < dist.size(); ++i) 
        {
            cout << "To " << i << ": " << dist[i] << endl;
            cost+=dist[i];
        }

        cout<<"\nTotal Cost : ";
        cout<<cost<<endl;
    }

};

int main() 
{
    Graph g(9);
    g.populate(0, 1, 4);
    g.populate(0, 7, 8);
    g.populate(1, 2, 8);
    g.populate(1, 7, 11);
    g.populate(2, 8, 2);
    g.populate(2, 5, 4);
    g.populate(3, 2, 7);
    g.populate(3, 5, 14);
    g.populate(4, 5, 10);
    g.populate(5, 6, 2);
    g.populate(6, 7, 1);
    g.populate(6, 8, 6);
    g.populate(7, 8, 7);


    cout << "\nKruskal's MST:\n";
    cout << g.KruskalMST() << endl;

    cout<<"Shortest Path from (0) \n";
    g.Disjktra(0);
    return 0;
}
