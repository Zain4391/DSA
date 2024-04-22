#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Graph
{
    int V;
    int **adj_matrix;
    int *visited;

    
    public:
    Graph()
    {
        V = 0;
        adj_matrix = NULL;
        visited = NULL;
    }

    Graph(int v)
    {
        V = v;
        visited = new int[V];
        for(int k =0; k<V;k++)
        {
            visited[k]=0;
        }

        adj_matrix = new int*[V];
        for(int i=0; i<V; i++)
        {
            adj_matrix[i] = new int[V];
        }

        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                adj_matrix[i][j] = 0; //all nodes are NULL
            }
        }
    }

    void set_visited()
    {
        for(int i = 0; i<V;i++)
        {
            visited[i] = 0;
        }
    }

    void populate()
   {
        int temp[][7]={{0,0,0,0,0,0,0},
                       {0,0,1,1,0,0,0},
                       {0,1,0,0,1,0,0},
                       {0,1,0,0,1,0,0},
                       {0,0,1,1,0,1,1},
                       {0,0,0,0,1,0,0},
                       {0,0,0,0,1,0,0}};
    
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            adj_matrix[i][j] = temp[i][j];
        }
    }

    }

    //2 traversals of the graphs : BFS and DFS
    void BFS(int source)
    {
        set_visited(); //no nodes visited
        queue <int> q;
        cout<<source<<" ";
        visited[source] = 1;
        q.push(source);

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(int j=0 ; j<V;j++)
            {
                if(adj_matrix[u][j] == 1 && visited[j] == 0)
                {
                    cout<<j<<" ";
                    visited[j]=1;
                    q.push(j);
                }
            }
        }
    }

    void DFS(int source)
    {
        if(visited[source] == 0)
        {
            cout<<source<<" ";
            visited[source] = 1;

            for(int i=1;i<V;i++)
            {
                if(adj_matrix[source][i] == 1 && visited[i] == 0)
                {
                    DFS(i);
                }
            }
        }
    }

};

int main()
{
    Graph g(7);
    g.populate();
    cout<<"Breadth First Search: ";
    g.BFS(1);
    cout<<endl;
    g.set_visited(); //now DFS from start
    cout<<"Depth First Search: ";
    g.DFS(1);
    return 0;
}