// Author: Manas Thakur, Roll No. 241475

/*
   Program 20:
   Perform Breadth-First Search (BFS) traversal of a graph.
*/

/*
   Approach:
   Used a queue for BFS traversal.
   Start from a vertex, mark visited, add to queue.
   Dequeue vertex, add unvisited neighbors to queue.
   Continue until queue is empty.
   BFS explores level by level.
*/

#include <iostream>
using namespace std;

const int MAX = 100;  // Maximum number of vertices

// Class: Queue
// Purpose: Simple queue for BFS implementation
class Queue {
private:
    int arr[MAX];  // Array to store queue elements
    int front, rear;  // Front and rear pointers

public:
    // Purpose: Initialize empty queue
    // Logic: Set front to 0, rear to -1
    Queue() {
        front = 0;  // Front pointer
        rear = -1;  // Rear pointer (initially empty)
    }

    // Purpose: Add element to queue
    // Logic: Add at rear
    void enqueue(int value) {
        if (rear < MAX - 1) {  // If there is space in queue
            arr[++rear] = value;  // Increment rear and add element
        }
    }

    // Purpose: Remove and return front element
    // Logic: Return front and move pointer
    int dequeue() {
        if (front > rear) {  // If queue is empty
            return -1;  // Return -1 indicating failure
        }
        return arr[front++];  // Return front element and increment front
    }

    // Purpose: Check if queue is empty
    // Logic: Compare front and rear
    int isEmpty() {
        return front > rear;  // If front > rear, queue is empty, return 1, else return 0
    }
};

// Class: GraphBFS
// Purpose: Graph implementation with BFS traversal
class GraphBFS {
private:
    int adjMatrix[MAX][MAX];  // 2D array for adjacency matrix
    int vertices;  // Number of vertices

public:
    // Purpose: Initialize empty graph
    // Logic: Set vertex count and initialize matrix with 0
    GraphBFS(int v) {
        vertices = v;  // Set number of vertices
        // Initialize matrix with 0
        for (int i = 0; i < vertices; i++) {  // Loop through rows
            for (int j = 0; j < vertices; j++) {  // Loop through columns
                adjMatrix[i][j] = 0;  // Set all positions to 0
            }
        }
    }

    // Purpose: Add undirected edge
    // Logic: Set both directions to 1
    void addEdge(int u, int v) {
        if (u < vertices && v < vertices) {  // If both vertices are valid
            adjMatrix[u][v] = 1;  // Forward edge
            adjMatrix[v][u] = 1;  // Reverse edge (undirected)
        }
    }

    // Purpose: Perform BFS traversal from start vertex
    // Logic: Use queue, mark visited, explore neighbors level by level
    void bfs(int start) {
        int visited[MAX];  // Array to track visited vertices
        // Initialize visited array
        for (int i = 0; i < vertices; i++) {  // Loop through all vertices
            visited[i] = 0;  // Mark all as unvisited (0)
        }

        Queue q;  // Create queue for BFS
        visited[start] = 1;  // Mark start vertex as visited
        q.enqueue(start);  // Add start vertex to queue

        cout << "BFS traversal starting from vertex " << start << ": ";

        // Process queue until empty
        while (!q.isEmpty()) {  // While queue has elements
            int u = q.dequeue();  // Get front vertex from queue
            cout << u << " ";  // Print current vertex

            // Add unvisited neighbors to queue
            for (int v = 0; v < vertices; v++) {  // Loop through all vertices
                if (adjMatrix[u][v] == 1 && !visited[v]) {  // If edge exists AND vertex not visited
                    visited[v] = 1;  // Mark vertex as visited
                    q.enqueue(v);  // Add to queue for processing
                }
            }
        }
        cout << "\n";
    }

    // Purpose: Display adjacency matrix
    // Logic: Print matrix in 2D format
    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";
        cout << "  ";
        for (int i = 0; i < vertices; i++) {  // Loop through vertices
            cout << i << " ";  // Print vertex number
        }
        cout << "\n";

        for (int i = 0; i < vertices; i++) {  // Loop through rows
            cout << i << " ";  // Print row header
            for (int j = 0; j < vertices; j++) {  // Loop through columns
                cout << adjMatrix[i][j] << " ";  // Print matrix element
            }
            cout << "\n";
        }
    }
};

int main() {
    int choice, v, u, vertices, start;

    cout << "Enter number of vertices: ";
    cin >> vertices;  // Get number of vertices from user

    GraphBFS g(vertices);  // Create graph with given vertices

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- BFS Traversal Menu ---\n";
        cout << "1. Add Edge\n";
        cout << "2. BFS Traversal\n";
        cout << "3. Display Adjacency Matrix\n";
        cout << "4. Exit\n";
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
        else if (choice == 2) {  // If user chooses BFS traversal
            cout << "Enter starting vertex: ";
            cin >> start;  // Get starting vertex
            if (start >= 0 && start < vertices) {  // If starting vertex is valid
                g.bfs(start);  // Perform BFS from starting vertex
            } else {  // If starting vertex is invalid
                cout << "Invalid vertex!\n";
            }
        }
        else if (choice == 3) {  // If user chooses to display matrix
            g.displayMatrix();  // Display adjacency matrix
        }
        else if (choice == 4) {  // If user chooses to exit
            break;  // Exit the while loop and end program
        }
        else {  // If user enters invalid choice
            cout << "Invalid choice!\n";
        }
    }

    return 0;  // Program ends successfully
}