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

const int MAX = 100;  // Maximum number of vertices

// Class: Graph
// Purpose: Represent and manage graph using adjacency matrix
class Graph {
private:
    int adjMatrix[MAX][MAX];  // 2D array for adjacency matrix
    int vertices;  // Number of vertices

public:
    // Purpose: Initialize empty graph
    // Logic: Set vertex count and initialize matrix with 0
    Graph(int v) {
        vertices = v;  // Set number of vertices
        // Initialize matrix with 0 (no edges)
        for (int i = 0; i < vertices; i++) {  // Loop through rows
            for (int j = 0; j < vertices; j++) {  // Loop through columns
                adjMatrix[i][j] = 0;  // Set all positions to 0
            }
        }
    }

    // Purpose: Add undirected edge between vertices u and v
    // Logic: Set matrix[u][v] and matrix[v][u] to 1
    void addEdge(int u, int v) {
        if (u < vertices && v < vertices) {  // If both vertices are valid
            adjMatrix[u][v] = 1;  // Add edge from u to v
            adjMatrix[v][u] = 1;  // Add edge from v to u (undirected)
        }
    }

    // Purpose: Remove edge between vertices u and v
    // Logic: Set matrix[u][v] and matrix[v][u] to 0
    void removeEdge(int u, int v) {
        if (u < vertices && v < vertices) {  // If both vertices are valid
            adjMatrix[u][v] = 0;  // Remove edge from u to v
            adjMatrix[v][u] = 0;  // Remove edge from v to u
        }
    }

    // Purpose: Display adjacency matrix
    // Logic: Print matrix in 2D format
    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";
        cout << "  ";
        // Print column headers (0, 1, 2, ...)
        for (int i = 0; i < vertices; i++) {  // Loop through vertices
            cout << i << " ";  // Print vertex number
        }
        cout << "\n";

        // Print matrix rows with row headers
        for (int i = 0; i < vertices; i++) {  // Loop through rows
            cout << i << " ";  // Print row header (vertex number)
            for (int j = 0; j < vertices; j++) {  // Loop through columns
                cout << adjMatrix[i][j] << " ";  // Print matrix element
            }
            cout << "\n";
        }
    }

    // Purpose: Display adjacency list representation
    // Logic: Print connected vertices for each vertex
    void displayAdjacency() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < vertices; i++) {  // Loop through all vertices
            cout << "Vertex " << i << ": ";
            // Print all vertices connected to i
            for (int j = 0; j < vertices; j++) {  // Loop through all vertices
                if (adjMatrix[i][j] == 1) {  // If edge exists between i and j
                    cout << j << " ";  // Print connected vertex
                }
            }
            cout << "\n";
        }
    }
};

int main() {
    int choice, v, u, vertices;

    cout << "Enter number of vertices: ";
    cin >> vertices;  // Get number of vertices from user

    Graph g(vertices);  // Create graph with given vertices

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- Graph (Adjacency Matrix) Menu ---\n";
        cout << "1. Add Edge\n";
        cout << "2. Remove Edge\n";
        cout << "3. Display Adjacency Matrix\n";
        cout << "4. Display Adjacency List\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // If user chooses to add edge
            cout << "Enter vertex u: ";
            cin >> u;  // Get first vertex
            cout << "Enter vertex v: ";
            cin >> v;  // Get second vertex
            g.addEdge(u, v);  // Add edge between u and v
            cout << "Edge added between " << u << " and " << v << ".\n";
        }
        else if (choice == 2) {  // If user chooses to remove edge
            cout << "Enter vertex u: ";
            cin >> u;  // Get first vertex
            cout << "Enter vertex v: ";
            cin >> v;  // Get second vertex
            g.removeEdge(u, v);  // Remove edge between u and v
            cout << "Edge removed between " << u << " and " << v << ".\n";
        }
        else if (choice == 3) {  // If user chooses to display matrix
            g.displayMatrix();  // Display adjacency matrix
        }
        else if (choice == 4) {  // If user chooses to display list
            g.displayAdjacency();  // Display adjacency list
        }
        else if (choice == 5) {  // If user chooses to exit
            break;  // Exit the while loop and end program
        }
        else {  // If user enters invalid choice
            cout << "Invalid choice!\n";
        }
    }

    return 0;  // Program ends successfully
}