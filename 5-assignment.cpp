#include <iostream>
using namespace std;
class Graph
{
public:
    int V;
    int graph[100][100];

    Graph(int V)
    {
        this->V = V;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                 graph[i][j] = (i == j) ? 0 : 9999;
            }
        }
    }

    void addEdge()
    {
        int E, u, v, w;
        cout << "Enter the number of Ways: ";
        cin >> E;
        for (int i = 0; i < E; i++)
        {
            cout << "Enter The Source,Destination,Distane (u,v,w): ";
            cin >> u;
            cin >> v;
            cin >> w;
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

  

    int findMinDistance(int dist[], bool processed[])
    {
        int mindist = 9999, minidx = -1;

        for (int i = 0; i < V; i++)
        {
            if (!processed[i] && dist[i] < mindist)
            {
                mindist = dist[i];
                minidx = i;
            }
        }
        return minidx;
    }

    void dijkstra(int start)
    {
        int dist[100];
        bool processed[100] = {false};

        for (int i = 0; i < V; i++)
        {
            dist[i] = 9999;
        }
        dist[start] = 0;

        for (int i = 0; i < V - 1; i++)
        {
            int u = findMinDistance(dist, processed);
            processed[u] = true;

            for (int v = 0; v < V; v++)
            {
                if (!processed[v]&& graph[u][v] != 9999 && dist[u] + graph[u][v] < dist[v]  )
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
        printsolution(dist,start);
    }
    void printsolution(int dist[],int src)
    {
        cout<<"Shortest Distance Path To Marriage Hall From Source :" <<src<<endl;
        for (int i = 0; i < V; i++)
        {
            cout << "To :" << i << "(hall):" << dist[i] << endl;
        }
    }
};
int main()
{
    int V;
    cout << "Number of Mairage Hall :";
    cin >> V;
    Graph g(V);

    g.addEdge();
 
    int start;
    cout << "Enter the source index ;";
    cin >> start;

    g.dijkstra(start);

    return 0;
} 