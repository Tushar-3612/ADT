#include<iostream>
using namespace std;

class Graph {
    int vertices;
    int edges;
    int AdjMatrices[10][10];

public:
    Graph(int v, int e) {
        vertices = v;
        edges = e;

        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                AdjMatrices[i][j] = 0;
            }
        }
    }

    void Accept() {
        int x, y;
        cout << "ENTER THE EDGES (pairs of vertices like (0 1))" << endl;

        for (int i = 0; i < edges; i++) {
            cout << "Enter edge " << i + 1 << ": ";
            cin >> x >> y;
            AdjMatrices[x][y] = 1;
            AdjMatrices[y][x] = 1;
        }
    }

    void show() {
        cout << "ADJACENCY MATRIX OF THE GRAPH :-" << endl;
        for(int i = 0; i < vertices; i++) {
            for(int j = 0; j < vertices; j++) {
                cout << AdjMatrices[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    Graph G(v, e);

    G.Accept();
    G.show();

    return 0;
}
