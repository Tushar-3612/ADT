#include <iostream>
#include <vector>
#define N 100

using namespace std;

void addEdege(int graph[N][N], int u, int v, int w)
{
    graph[u][v] = w;
    graph[v][u] = w;
}
void display(int graph[N][N], int V)
{
    cout << "  ";
    for (int i = 0; i < V; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << " ";
        for (int j = 0; j < V; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
void prism(int graph[N][N], int V)
{
    vector<int> inMST(V, 0);
   
    
    inMST[0]=1;
    int count = 0;
    int minw = 0;
   
    while (count < V - 1)
    {
         int min = INT8_MAX,u=-1,v=-1;

       
        for (int i = 0; i < V; i++)
        {
            if (inMST[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (graph[i][j] < min && !inMST[j] && graph[i][j] != 0)
                    {
                       
                        min = graph[i][j];
                        u=i;
                        v=j;
                    }
                   
                }
              
            }
            
        }

       if(u!=-1 && v!=-1)
       {
        cout<<"Edge "<<u<<"-"<<v<<" weight: z"<<min<<endl;
        inMST[v]=1;
        minw+=min;
        count++;
       }
      
    }
    cout <<"Minimum Weight :" <<minw << endl;
}
int main()
{
    int V, E, u, v, w;
    int graph[N][N] = {0};
    cout << "Enter the No Of Vertices :";
    cin >> V;
    cout << "Enter the No Of Edges :";
    cin >> E;
    for (int i = 0; i < E; i++)
    {
       
        addEdege(graph, u, v, w);
    }
    display(graph, V);
    cout<<endl;
    cout<<"MST"<<endl;
    prism(graph, V);
    return 0;
}
