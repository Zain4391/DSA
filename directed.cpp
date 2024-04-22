#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define I INT_MAX
typedef pair<char,int> pci;
class Graph
{
    vector<char> nodes;
    int V;
    int**cost_matrix;

    int find_parent(vector<int>&p,int i)
    {
        if(p[i] == -1)
        {
            return i;
        }

        return find_parent(p,p[i]);
    }

    void unify(vector<int> &p,int x,int y)
    {
        int xset = find_parent(p,x);
        int yset = find_parent(p,y);
        p[xset] = yset;
    }

    public:
    Graph(int x)
    {
        V = x;
        cost_matrix = new int*[V];

        for(int i=0;i<V;i++)
        {
            cost_matrix[i] = new int[V];
        }

        for(int k=0;k<V;k++)
        {
            for(int l=0;l<V;l++)
            {
                cost_matrix[k][l] = I; //all nodes are INFINTE distance apart
            }
        }
    }

    void addNodes(char n)
    {
        nodes.push_back(n);
    }

    void link_nodes(int src,int dest,int cost)
    {
        cost_matrix[src][dest] = cost; //directed graph
    }

    void PrimMST(char source)
    {
        int sourceIndex = -1;
        priority_queue<pci, vector<pci>, greater<pci>> pq;

        for (int i = 0; i < V; i++)
        {
            if (nodes[i] == source)
            {
                sourceIndex = i;
                break;
            }
        }

        if (sourceIndex == -1)
        {
            cout << "No such node in the graph" << endl;
            return;
        }

        vector<int> key(V, I);
        vector<pci> result(V, make_pair(' ', -1)); // store the result of Prims
        vector<bool> visited(V, false);

        int src = sourceIndex;
        key[src] = 0;
        pq.push(make_pair(nodes[src], 0));

        while (!pq.empty())
        {
            char u = pq.top().first; // the vertex
            int uIndex = -1;

            //get the index of node
            for (int i = 0; i < V; i++) 
            {
                if (nodes[i] == u) 
                {
                    uIndex = i;
                    break;
                }
            }

            pq.pop();

            visited[uIndex] = true;

            //Explore the node
            for (int v = 0; v < V; v++)
            {
                if (cost_matrix[uIndex][v] != I && !visited[v] && cost_matrix[uIndex][v] < key[v])
                {
                    key[v] = cost_matrix[uIndex][v];
                    result[v] = make_pair(nodes[uIndex], key[v]);
                    pq.push(make_pair(nodes[v], key[v]));
                }
            }
        }

        cout << "Minimum Spanning Tree (MST) using Prim's algorithm:" << endl;
        cout << "Edge \tWeight" << endl;

        for (int i = 1; i < V; i++)
        {
            if (result[i].second != I)
            {
                cout << result[i].first << " - " << nodes[i] << "\t" << result[i].second << endl;
            }
        }
    }

    void kruskal()
    {
        vector<pair<int,pci>> edges;
        vector<pair<int,pci>> result;
        vector<int> parent(nodes.size(),-1);

        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                edges.push_back({cost_matrix[i][j],{i,j}});
            }
        }

        priority_queue<pair<int,pci>,vector<pair<int,pci>>,greater<pair<int,pci>>> pq;

        for(auto edge : edges)
        {
            pq.push(edge);
        }

        while(!pq.empty())
        {
            auto edge = pq.top();
            pq.pop();

            if(find_parent(parent,edge.second.first) != find_parent(parent,edge.second.second))
            {
                result.push_back(edge);
                unify(parent,find_parent(parent,edge.second.first),find_parent(parent,edge.second.second));
            }
        }

        cout<<"Kruskal's MST:\n";
        for(int i=0;i<result.size();i++)
        {
            cout<<nodes[result[i].second.first]<<" ---- "<<nodes[result[i].second.second]<<"\tWeight: "<<result[i].first<<endl;   
        }
    }

    void Dijkstra(char source)
    {
        priority_queue<pci, vector<pci>, greater<pci>> pq;
        vector<int> distance(V, I);
        vector<pci> result;

        int sindex = -1;

        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i] == source)
            {
                sindex = i;
                break;
            }
        }

        if (sindex == -1)
        {
            cerr << "Source not found.\n";
            return;
        }

        distance[sindex] = 0;
        pq.push(make_pair(nodes[sindex], 0));

        while (!pq.empty())
        {
            char u = pq.top().first;
            int uIndex = -1;

            // get the index of node
            for (int i = 0; i < V; i++)
            {
                if (nodes[i] == u)
                {
                    uIndex = i;
                    break;
                }
            }

            pq.pop();

            // Explore the node
            for (int v = 0; v < V; v++)
            {
                if (cost_matrix[uIndex][v] != I && distance[uIndex] + cost_matrix[uIndex][v] < distance[v])
                {
                    distance[v] = distance[uIndex] + cost_matrix[uIndex][v];
                    pq.push(make_pair(nodes[v], distance[v]));
                }
            }
        }

        cout << "Dijkstra's Shortest Path from node " << source << ":\n";
        cout << "Node \tDistance from Source\n";
        for (int i = 0; i < V; i++)
        {
            if (distance[i] != I)
            {
                cout << nodes[i] << " \t" << distance[i] << endl;
            }
        }
    }

};

int main()
{
    Graph g(6);
    g.addNodes('S');
    g.addNodes('A');
    g.addNodes('C');
    g.addNodes('E');
    g.addNodes('D');
    g.addNodes('B');

    g.link_nodes(0,1,1);
    g.link_nodes(0,5,5);
    g.link_nodes(1,2,2);
    g.link_nodes(1,4,1);
    g.link_nodes(1,5,2);
    g.link_nodes(2,3,1);
    g.link_nodes(2,4,3);
    g.link_nodes(4,3,2);
    g.link_nodes(5,4,2);

    g.PrimMST('S');
    cout<<endl;
    g.kruskal();
    cout<<endl;
    g.Dijkstra('S');

    return 0;

}