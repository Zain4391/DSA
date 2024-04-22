#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>
#include <utility>
#include<algorithm>
using namespace std;

#define I INT_MAX
typedef pair<int,int> pii;

class Graph
{
    int V;
    int **adj_matrix;

public:
    Graph()
    {
        V = 0;
        adj_matrix = NULL;
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

    int PrimMST()
    {
        int cost = 0;
        vector<bool> visited(V,false);
        priority_queue<pii,vector<pii>,greater<pii>> minheap; //min heap
        vector<int> key(V,I);
        vector<pii> result;

        int start = 0;
        minheap.push({0,start});
        key[start] = 0;

        while(!minheap.empty())
        {
            int u = minheap.top().second; //dest vertex
            int w = minheap.top().first; //weight of the vertex
            minheap.pop();

            if(visited[u])
            {
                continue;
            }

            visited[u]=true;
            cost+=w;

            for(int i=0;i<V;i++)
            {
                if(adj_matrix[u][i]!=I && !visited[i] && adj_matrix[u][i] < key[i])
                {
                    minheap.push({adj_matrix[u][i],i});
                    key[i] = adj_matrix[u][i];
                    result.push_back({u,i});
                }
            }
        }

        //Print the MST

        for(int i =0; i<result.size();i++)
        {
            cout<<result[i].first<<"---"<<result[i].second<<endl;
        }


        return cost;
    }
};

int main()
{
    Graph g(8);
    g.populate(0, 1, 11);
    g.populate(0, 6, 18);
    g.populate(1, 2, 12);
    g.populate(2, 3, 13);
    g.populate(2, 7, 4);
    g.populate(3, 4, 21);
    g.populate(3, 7, 15);
    g.populate(4, 5, 23);
    g.populate(5, 6, 14);
    g.populate(6, 7, 3);
    cout << endl;
    cout<<g.PrimMST();
    return 0;
}
