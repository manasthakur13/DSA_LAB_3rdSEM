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

const int MAX = 100;

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear < MAX - 1) {
            arr[++rear] = value;
        }
    }

    int dequeue() {
        if (front > rear) {
            return -1;
        }
        return arr[front++];
    }

    int isEmpty() {
        return front > rear;
    }
};

class GraphBFS {
private:
    int adjMatrix[MAX][MAX];
    int vertices;

public:
    GraphBFS(int v) {
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

    void bfs(int start) {
        int visited[MAX];
        for (int i = 0; i < vertices; i++) {
            visited[i] = 0;
        }

        Queue q;
        visited[start] = 1;
        q.enqueue(start);

        cout << "BFS traversal starting from vertex " << start << ": ";

        while (!q.isEmpty()) {
            int u = q.dequeue();
            cout << u << " ";

            for (int v = 0; v < vertices; v++) {
                if (adjMatrix[u][v] == 1 && !visited[v]) {
                    visited[v] = 1;
                    q.enqueue(v);
                }
            }
        }
        cout << "\n";
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
};

int main() {
    int choice, v, u, vertices, start;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    GraphBFS g(vertices);

    while (true) {
        cout << "\n--- BFS Traversal Menu ---\n";
        cout << "1. Add Edge\n";
        cout << "2. BFS Traversal\n";
        cout << "3. Display Adjacency Matrix\n";
        cout << "4. Exit\n";
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
            cout << "Enter starting vertex: ";
            cin >> start;
            if (start >= 0 && start < vertices) {
                g.bfs(start);
            } else {
                cout << "Invalid vertex!\n";
            }
        }
        else if (choice == 3) {
            g.displayMatrix();
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
