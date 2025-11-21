// Author: Manas Thakur, Roll No. 241475

/*
   Program 10:
   Implement stack using linked list with dynamic memory allocation.
*/

/*
   Approach:
   Used a node structure with data and next pointer.
   Top pointer points to first node (top of stack).
   Push creates new node and inserts at top.
   Pop deletes top node and returns its data.
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

class StackLL {
private:
    Node* top;  // Pointer to top of stack

public:
    // Purpose: Initialize empty stack
    // Logic: Set top to NULL indicating empty stack
    StackLL() {
        top = NULL;  // Initially no node exists, so top is NULL
    }

    // Purpose: Add element to top of stack
    // Logic: Create new node, set data, link to current top, update top
    void push(int value) {
        Node* newNode = new Node();  // Create new node dynamically
        newNode->data = value;  // Store value in data field
        newNode->next = top;  // Link new node to current top
        top = newNode;  // Update top to point to new node
        cout << "Pushed " << value << " successfully.\n";
    }

    // Purpose: Remove and return top element
    // Logic: Check if empty, get value, delete node, update top
    int pop() {
        if (top == NULL) {  // If top is NULL, stack is empty
            return -1;  // Return -1 indicating underflow
        }
        int value = top->data;  // Get data from top node
        Node* temp = top;  // Store pointer to top node
        top = top->next;  // Move top to next node
        delete temp;  // Free memory of deleted node
        return value;  // Return the popped value
    }

    // Purpose: View top element without removing
    // Logic: Check if stack empty, then return top data
    int peek() {
        if (top == NULL) {  // If top is NULL, stack is empty
            return -1;  // Return -1 indicating stack is empty
        }
        return top->data;  // Return data from top node
    }

    // Purpose: Check if stack is empty
    // Logic: Check if top is NULL
    int isEmpty() {
        return top == NULL;  // If top is NULL, return 1 (true), else return 0 (false)
    }

    // Purpose: Display all elements in stack
    // Logic: Traverse from top and print each element
    void displayStack() {
        if (top == NULL) {  // If top is NULL, stack is empty
            cout << "Stack is empty.\n";
            return;  // Exit function
        }
        cout << "Stack (top to bottom): ";
        Node* temp = top;  // Create temporary pointer starting from top
        while (temp != NULL) {  // While we have nodes to traverse
            cout << temp->data << " ";  // Print current node's data
            temp = temp->next;  // Move to next node
        }
        cout << "\n";  // New line after printing
    }

    // Purpose: Clean up memory
    // Logic: Delete all nodes from top to end
    ~StackLL() {
        while (top != NULL) {  // While there are nodes to delete
            Node* temp = top;  // Store pointer to current top
            top = top->next;  // Move top to next node
            delete temp;  // Free memory of current node
        }
    }
};

int main() {
    StackLL s;  // Create stack object
    int choice, value, res;

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- Stack (Linked List) Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // If user chooses to push
            cout << "Enter value: ";
            cin >> value;  // Get value from user
            s.push(value);  // Push value to stack
        }
        else if (choice == 2) {  // If user chooses to pop
            res = s.pop();  // Pop element from stack
            if (res != -1) {  // If pop was successful
                cout << "Popped: " << res << "\n";
            } else {  // If pop failed
                cout << "Stack underflow!\n";
            }
        }
        else if (choice == 3) {  // If user chooses to peek
            res = s.peek();  // Get top element without removing
            if (res != -1) {  // If peek was successful
                cout << "Top element: " << res << "\n";
            } else {  // If peek failed
                cout << "Stack is empty!\n";
            }
        }
        else if (choice == 4) {  // If user chooses to display
            s.displayStack();  // Display all elements
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

