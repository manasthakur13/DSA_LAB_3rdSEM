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
    int data;  // Store element value
    Node* next;  // Pointer to next node in linked list
};

class QueueLL {
private:
    Node* front;  // Pointer to front of queue
    Node* rear;  // Pointer to rear of queue

public:
    // Purpose: Initialize empty queue
    // Logic: Set front and rear to NULL indicating empty queue
    QueueLL() {
        front = NULL;  // Initially no node exists at front, so front is NULL
        rear = NULL;  // Initially no node exists at rear, so rear is NULL
    }

    // Purpose: Add element at rear of queue
    // Logic: Create new node, set data, link rear to new node, update rear
    void enqueue(int value) {
        Node* newNode = new Node();  // Create new node dynamically
        newNode->data = value;  // Store value in data field
        newNode->next = NULL;  // New node is last, so its next is NULL

        if (rear == NULL) {  // If queue is empty (rear is NULL)
            front = rear = newNode;  // Both front and rear point to new node
        } else {  // If queue already has elements
            rear->next = newNode;  // Link current rear to new node
            rear = newNode;  // Update rear to point to new node
        }
        cout << "Enqueued " << value << " successfully.\n";
    }

    // Purpose: Remove and return front element
    // Logic: Check if empty, get front value, delete node, update front
    int dequeue() {
        if (front == NULL) {  // If front is NULL, queue is empty
            return -1;  // Queue underflow, return -1
        }
        int value = front->data;  // Get data from front node
        Node* temp = front;  // Store pointer to front node
        front = front->next;  // Move front to next node
        if (front == NULL) {  // If new front is NULL (queue now empty)
            rear = NULL;  // Rear should also be NULL
        }
        delete temp;  // Free memory of deleted node
        return value;  // Return the dequeued value
    }

    // Purpose: View front element without removing
    // Logic: Check if queue empty, then return front data
    int peek() {
        if (front == NULL) {  // If front is NULL, queue is empty
            return -1;  // Return -1 indicating queue is empty
        }
        return front->data;  // Return data from front node
    }

    // Purpose: Check if queue is empty
    // Logic: Check if front is NULL
    int isEmpty() {
        return front == NULL;  // If front is NULL, return 1 (true), else return 0 (false)
    }

    // Purpose: Display all elements in queue
    // Logic: Traverse from front and print each element
    void displayQueue() {
        if (front == NULL) {  // If front is NULL, queue is empty
            cout << "Queue is empty.\n";
            return;  // Exit function
        }
        cout << "Queue (front to rear): ";
        Node* temp = front;  // Create temporary pointer starting from front
        while (temp != NULL) {  // While we have nodes to traverse
            cout << temp->data << " ";  // Print current node's data
            temp = temp->next;  // Move to next node
        }
        cout << "\n";  // New line after printing
    }

    // Purpose: Clean up memory
    // Logic: Delete all nodes from front to end
    ~QueueLL() {
        while (front != NULL) {  // While there are nodes to delete
            Node* temp = front;  // Store pointer to current front
            front = front->next;  // Move front to next node
            delete temp;  // Free memory of current node
        }
    }
};

int main() {
    QueueLL q;  // Create queue object
    int choice, value, res;

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- Queue (Linked List) Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // If user chooses to enqueue
            cout << "Enter value: ";
            cin >> value;  // Get value from user
            q.enqueue(value);  // Enqueue value to queue
        }
        else if (choice == 2) {  // If user chooses to dequeue
            res = q.dequeue();  // Dequeue element from queue
            if (res != -1) {  // If dequeue was successful
                cout << "Dequeued: " << res << "\n";
            } else {  // If dequeue failed
                cout << "Queue underflow!\n";
            }
        }
        else if (choice == 3) {  // If user chooses to peek
            res = q.peek();  // Get front element without removing
            if (res != -1) {  // If peek was successful
                cout << "Front element: " << res << "\n";
            } else {  // If peek failed
                cout << "Queue is empty!\n";
            }
        }
        else if (choice == 4) {  // If user chooses to display
            q.displayQueue();  // Display all elements
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
