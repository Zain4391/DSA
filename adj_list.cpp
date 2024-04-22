#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Graph
{
    int V;
    list<int> *adj_list;

    public:
    Graph(int vertices)
    {
        V = vertices;
        adj_list = new list<int>[V];
    }

    void add_edge(int src, int dest)
    {
        adj_list[src].push_back(dest);
        adj_list[dest].push_back(src);
    }

    void BFS(int i)
    {
        vector<bool> visited(V,false); //no nodes visited
        queue<int> q;
        cout<<i<<" ";
        visited[i] = true;
        q.push(i);

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(auto i = adj_list[u].begin(); i!=adj_list[u].end();i++)
            {
                if(!visited[*i])
                {
                    cout<<*i<<" ";
                    visited[*i]=true;
                    q.push(*i);
                }
            }
        }
    }

    void DFS(int i)
    {
        static vector<bool> visited(V,false); //no nodes visited,will be initialized once
        if(visited[i] == 0)
        {
            cout<<i<<" ";
            visited[i] = true;
            
            for(auto j = adj_list[i].begin(); j!=adj_list[i].end();j++)
            {
                if(!visited[*j])
                {
                    DFS(*j);
                }
            }
        }   
    }
};

int main()
{
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 3);

    cout<<"Breadth First Traversal (starting from vertex 2) ";
    g.BFS(2);
    cout<<endl;
    cout<<"Depth First Traversal (starting from vertex 2) ";
    g.DFS(2);

    return 0;
}