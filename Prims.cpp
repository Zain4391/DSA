#include <iostream>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

#define I INT_MAX

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
        for (int k = 0; k < V; k++)
        {
            visited[k] = 0;
        }

        adj_matrix = new int *[V];
        for (int i = 0; i < V; i++)
        {
            adj_matrix[i] = new int[V];
        }

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                adj_matrix[i][j] = I; // all nodes are NULL
            }
        }
    }

    void set_visited()
    {
        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
        }
    }

    void populate(int s, int d, int w)
    {
        adj_matrix[s][d] = w;
        adj_matrix[d][s] = w;
    }

    // 2 traversals of the graphs: BFS and DFS
    void BFS(int source)
    {
        set_visited(); // no nodes visited
        queue<int> q;
        cout << source << " ";
        visited[source] = 1;
        q.push(source);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int j = 0; j < V; j++)
            {
                if (adj_matrix[u][j] == 1 && visited[j] == 0)
                {
                    cout << j << " ";
                    visited[j] = 1;
                    q.push(j);
                }
            }
        }
    }

    void DFS(int source)
    {
        if (visited[source] == 0)
        {
            cout << source << " ";
            visited[source] = 1;

            for (int i = 0; i < V; i++)
            {
                if (adj_matrix[source][i] == 1 && visited[i] == 0)
                {
                    DFS(i);
                }
            }
        }
    }

  void PrimMST()
  {
    int u,v,min = I;
    int *near = new int[V];
    int t[2][6]; //the col are initialized by V-2 

    //find min edge in graph
    for(int i=0;i<V;i++)
    {
        near[i] = I; //all near indices are holding Infinite values

        for(int j=i;j<V;j++)
        {
            if(adj_matrix[i][j] < min)
            {
                min  = adj_matrix[i][j];
                u = i;
                v = j;
            }
        }
    }

    t[0][0]=u;
    t[1][0]=v;
    near[u] = near[v] = 0;

    for(int i=0;i<v;i++)
    {
        if(near[i] != 0)
        {
            if(adj_matrix[i][u] < adj_matrix[i][v])
            {
                near[i]=u;
            }
            else
            {
                near[i]=v;
            }
        }
    }

    //repeating steps
    for (int i=1; i<V-1; i++)
	{
        int k;
        min = I;
        for (int j=1; j<V; j++)
		{
            if (near[j] != 0 && adj_matrix[j][near[j]] < min)
			{
                k = j;
                min = adj_matrix[j][near[j]];
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;
 
        // Update near array to near min cost edges
        for (int j=1; j<V; j++)
		{
            if (near[j] != 0 && adj_matrix[j][k] < adj_matrix[j][near[j]])
			{
                near[j] = k;
            }
        }
    }

    for(int i =0; i<2;i++)
    {
        for(int j=0;j<6;j++)
        {
            cout<<t[i][j]<<" ";
        }

        cout<<endl;
    }

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
    g.PrimMST();
    return 0;
}
