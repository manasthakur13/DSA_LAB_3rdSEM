// Author: Manas Thakur, Roll No. 241475

/*
   Program 12:
   Implement queue using linked list with dynamic memory allocation.
*/

/*
   Approach:
   Used a node structure with data and next pointer.
   Front and rear pointers track queue ends.
   Enqueue adds node at rear.
   Dequeue removes node from front.
   No size limit as memory is dynamically allocated.
*/

#include <iostream>
using namespace std;

// Structure: Node
// Members: data (element value), next (pointer to next node)
struct Node {
    int data;
    Node* next;
};

class QueueLL {
private:
    Node* front;  // Pointer to front of queue
    Node* rear;  // Pointer to rear of queue

public:
    // Purpose: Initialize empty queue
    // Logic: Set front and rear to NULL indicating empty queue
    QueueLL() {
        front = NULL;
        rear = NULL;
    }

    // Purpose: Add element at rear of queue
    // Logic: Create new node, set data, link rear to new node, update rear
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;  // First element in queue
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << value << " successfully.\n";
    }

    // Purpose: Remove and return front element
    // Logic: Check if empty, get front value, delete node, update front
    int dequeue() {
        if (front == NULL) {
            return -1;  // Queue underflow
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        return value;
    }

    // Purpose: View front element without removing
    // Logic: Check if queue empty, then return front data
    int peek() {
        if (front == NULL) {
            return -1;
        }
        return front->data;
    }

    // Purpose: Check if queue is empty
    // Logic: Check if front is NULL
    int isEmpty() {
        return front == NULL;
    }

    // Purpose: Display all elements in queue
    // Logic: Traverse from front and print each element
    void displayQueue() {
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front to rear): ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Purpose: Clean up memory
    // Logic: Delete all nodes from front to end
    ~QueueLL() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    QueueLL q;
    int choice, value, res;

    while (true) {
        cout << "\n--- Queue (Linked List) Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
        }
        else if (choice == 2) {
            res = q.dequeue();
            if (res != -1) {
                cout << "Dequeued: " << res << "\n";
            } else {
                cout << "Queue underflow!\n";
            }
        }
        else if (choice == 3) {
            res = q.peek();
            if (res != -1) {
                cout << "Front element: " << res << "\n";
            } else {
                cout << "Queue is empty!\n";
            }
        }
        else if (choice == 4) {
            q.displayQueue();
        }
        else if (choice == 5) {
            break;  // Exit program
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

