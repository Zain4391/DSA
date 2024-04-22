#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

class Graph
{
    int V;
    list<pii> *prims;
    list<pair<int, pii>> *kruskal;

    int findparent(vector<int> &p,int i)
    {
        if(p[i] == -1)
        {
            return i;
        }

        return findparent(p,p[i]);
    }

    void unify(vector<int> &p,int x, int y)
    {
        int xset = findparent(p,x);
        int yset = findparent(p,y);
        p[xset] = yset;
    }

public:
    Graph(int N)
    {
        V = N;
        prims = new list<pii>[V];
        kruskal = new list<pair<int, pii>>[2*V]; //2 pairs
    }
    void addedge(int src, int dest, int w)
    {
        //for prims
        prims[src].push_back(make_pair(dest, w));
        prims[dest].push_back(make_pair(src, w));

        //for kruskal
        kruskal[src].push_back(make_pair(w, make_pair(src, dest)));
        kruskal[dest].push_back(make_pair(w, make_pair(dest, src)));
    }

    void displayPrims()
    {
        cout << "Prim's List: ";
        for (int i = 0; i < V; ++i)
        {
            for (const auto &edge : prims[i])
            {
                cout << "(" << i << ", " << edge.first << ", " << edge.second << ") ";
            }
        }
        cout << endl;
    }

    void displayKruskal()
    {
        cout << "Kruskal's List: ";
        for (int i = 0; i < 2 * V; ++i)
        {
            for (const auto &edge : kruskal[i])
            {
                cout << "(" << edge.second.first << ", " << edge.second.second << ") ";
            }
        }
        cout << endl;
    }
    
    void PrimMST(int start)
    {
        int cost = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<pii> result;
        vector<bool> visited(V, false);
        vector<int> key(V, INT_MAX);

        key[start] = 0;
        pq.push({0, start});

        while (!pq.empty())
        {
            int u = pq.top().second;
            int weight = pq.top().first;
            pq.pop();

            if(visited[u])
            {
                continue;
            }

            visited[u] = true;
            cost+=weight;
            for (auto it = prims[u].begin(); it != prims[u].end(); ++it)
            {
                int v = it->first;
                int w = it->second;

                if (!visited[v] && w < key[v])
                {
                    key[v] = w;
                    pq.push({key[v], v});
                    result.push_back({u, v});
                }
            }


        }

        //print MST :
        cout << "Edges of the Minimum Spanning Tree (Prim's algorithm):" << endl;
        for (auto it = result.begin(); it != result.end(); ++it)
        {
            int u = it->first;
            int v = it->second;

            cout << u << "----" << v << endl;
        }

        cout << "Total Cost of MST: " << cost << endl;
    }

    void Kruskal()
    {
        int cost = 0;
        vector<pair<int,pii>> edges;
        for(int i=0; i<V; i++)
        {
            for (auto it = prims[i].begin(); it != prims[i].end(); ++it)
            {
                int v = it->first;
                int w = it->second;
                edges.push_back({w, {i, v}});
            }   
        }

        priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;
        for(int i=0; i<edges.size(); i++)
        {
            pq.push(edges[i]);
        }

        vector<int> parent(V,-1);
        vector<pair<int,pii>> result;

        while(!pq.empty())
        {
            auto edge = pq.top();
            pq.pop();

            int x = findparent(parent,edge.second.first);
            int y = findparent(parent,edge.second.second);

            if(x!=y)
            {
                result.push_back(edge);
                cost+=edge.first;
                unify(parent,x,y);   
            }
        }

        for(int i=0; i<result.size();i++)
        {
            cout<<result[i].second.first<<"---"<<result[i].second.second<<endl;
        }
        cout<<"Total cost of Kruskal's MST: "<<cost<<endl;
    }

    void Dijkstra(int start)
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(V, INT_MAX);

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty())
        {
            int u = pq.top().second;
            int dist_u = pq.top().first;
            pq.pop();

            if (dist_u > dist[u])
            {
                continue;
            }

            for (auto it = prims[u].begin(); it != prims[u].end(); ++it)
            {
                int v = it->first;
                int weight = it->second;

                if (dist[u] + weight < dist[v])
                {   
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }

        }

        cout << "Shortest Distances from vertex " << start << endl;
        for (int i = 0; i < V; ++i)
        {
            cout << "Vertex " << i << ": " << dist[i] << endl;
        }
    }
};

int main()
{
    Graph g(8);
    g.addedge(0, 1, 11);
    g.addedge(0, 6, 18);
    g.addedge(1, 2, 12);
    g.addedge(2, 3, 13);
    g.addedge(2, 7, 4);
    g.addedge(3, 4, 21);
    g.addedge(3, 7, 15);
    g.addedge(4, 5, 23);
    g.addedge(5, 6, 14);
    g.addedge(6, 7, 3);

    g.PrimMST(0);
    g.Kruskal();
    g.Dijkstra(0);

    return 0;
}
