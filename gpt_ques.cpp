#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
    int V;
    list<int> *adj_list;

public:
    Graph(int n)
    {
        V = n;
        adj_list = new list<int>[V];
    }

    void addEdge(int v, int w)
    {
        adj_list[v].push_back(w);
        adj_list[w].push_back(v); // For an undirected graph
    }

    void dfs(int i)
    {
        static vector<bool> visited(V,false); //only initialize once
        visited[i] = true;
        cout<<i<<" ";
            for(auto it = adj_list[i].begin(); it!= adj_list[i].end();it++)
            {
                if(!visited[*it])
                {
                    dfs(*it);
                }
            }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "DFS starting from vertex 0:" << endl;
    g.dfs(0);

    return 0;
}