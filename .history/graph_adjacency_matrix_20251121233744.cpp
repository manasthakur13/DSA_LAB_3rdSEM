// Author: Manas Thakur, Roll No. 241475

/*
   Program 19:
   Represent a graph using adjacency matrix.
*/

/*
   Approach:
   Used 2D array to store graph connections.
   If edge exists between vertex i and j, matrix[i][j] = 1.
   For undirected graph, matrix[i][j] = matrix[j][i].
   Display matrix and list connections for each vertex.
*/

#include <iostream>
using namespace std;

const int MAX = 100;

class Graph {
private:
    int adjMatrix[MAX][MAX];
    int vertices;

public:
    Graph(int v) {
        vertices = v;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        if (u < vertices && v < vertices) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
    }

    void removeEdge(int u, int v) {
        if (u < vertices && v < vertices) {
            adjMatrix[u][v] = 0;
            adjMatrix[v][u] = 0;
        }
    }

    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";
        cout << "  ";
        for (int i = 0; i < vertices; i++) {
            cout << i << " ";
        }
        cout << "\n";

        for (int i = 0; i < vertices; i++) {
            cout << i << " ";
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void displayAdjacency() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ": ";
            for (int j = 0; j < vertices; j++) {
                if (adjMatrix[i][j] == 1) {
                    cout << j << " ";
                }
            }
            cout << "\n";
        }
    }
};

int main() {
    int choice, v, u, vertices;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    while (true) {
        cout << "\n--- Graph (Adjacency Matrix) Menu ---\n";
        cout << "1. Add Edge\n";
        cout << "2. Remove Edge\n";
        cout << "3. Display Adjacency Matrix\n";
        cout << "4. Display Adjacency List\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter vertex u: ";
            cin >> u;
            cout << "Enter vertex v: ";
            cin >> v;
            g.addEdge(u, v);
            cout << "Edge added between " << u << " and " << v << ".\n";
        }
        else if (choice == 2) {
            cout << "Enter vertex u: ";
            cin >> u;
            cout << "Enter vertex v: ";
            cin >> v;
            g.removeEdge(u, v);
            cout << "Edge removed between " << u << " and " << v << ".\n";
        }
        else if (choice == 3) {
            g.displayMatrix();
        }
        else if (choice == 4) {
            g.displayAdjacency();
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
