#include <iostream>
using namespace std;

class Node {
public:
    string city;
    int cost;
    Node* next;
    
    static string cities[100];  // City names
    static Node* adjlist[100];  // Adjacency list (linked list representation)
    static int numcities;

    Node(string cityName, int cost, int n) {
        city = cityName;
        this->cost = cost;
        next = NULL;
        
        if (numcities == 0) { // Initialize only once
            numcities = n;
            for (int i = 0; i < n; i++) {
                adjlist[i] = NULL; // Initialize adjacency list
            }
        }
    }

    static void addCity(int index, string cityName) {
        if (index < numcities) {
            cities[index] = cityName;
        }
    }

    static int findIndex(string city) {
        for (int i = 0; i < numcities; i++) {
            if (cities[i] == city) return i;
        }
        return -1; // City not found
    }

    static void addEdge(string cityA, string cityB, int cost) {
        int u = findIndex(cityA);
        int v = findIndex(cityB);
        if (u == -1 || v == -1) {
            cout << "Invalid city name!" << endl;
            return;
        }

        Node* newNode = new Node(cityB, cost, numcities);
        newNode->next = adjlist[u];
        adjlist[u] = newNode;
    }

    static void displayGraph() {
        for (int i = 0; i < numcities; i++) {
            cout << cities[i] << " -> ";
            Node* temp = adjlist[i];
            while (temp) {
                cout << "(" << temp->city << ", " << temp->cost << ") -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

// Define static members
string Node::cities[100];
Node* Node::adjlist[100];
int Node::numcities = 0;

int main() {
    int n, e;
    cout << "Enter number of cities: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string cityName;
        cin >> cityName;
        Node::addCity(i, cityName);
    }

    cout << "Enter number of flight paths: ";
    cin >> e;

    cout << "Enter flight paths (CityA CityB Cost): " << endl;
    for (int i = 0; i < e; i++) {
        string cityA, cityB;
        int cost;
        cin >> cityA >> cityB >> cost;
        Node::addEdge(cityA, cityB, cost);
    }

    cout << "Flight Path Representation (Adjacency List): " << endl;
    Node::displayGraph();

    return 0;
}
