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
    int data;
    Node* next;
};

class StackLL {
private:
    Node* top;  // Pointer to top of stack

public:
    // Purpose: Initialize empty stack
    // Logic: Set top to NULL indicating empty stack
    StackLL() {
        top = NULL;
    }

    // Purpose: Add element to top of stack
    // Logic: Create new node, set data, link to current top, update top
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " successfully.\n";
    }

    // Purpose: Remove and return top element
    // Logic: Check if empty, get value, delete node, update top
    int pop() {
        if (top == NULL) {
            return -1;  // Stack underflow
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    // Purpose: View top element without removing
    // Logic: Check if stack empty, then return top data
    int peek() {
        if (top == NULL) {
            return -1;
        }
        return top->data;
    }

    // Purpose: Check if stack is empty
    // Logic: Check if top is NULL
    int isEmpty() {
        return top == NULL;
    }

    // Purpose: Display all elements in stack
    // Logic: Traverse from top and print each element
    void displayStack() {
        if (top == NULL) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Purpose: Clean up memory
    // Logic: Delete all nodes from top to end
    ~StackLL() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    StackLL s;
    int choice, value, res;

    while (true) {
        cout << "\n--- Stack (Linked List) Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
        }
        else if (choice == 2) {
            res = s.pop();
            if (res != -1) {
                cout << "Popped: " << res << "\n";
            } else {
                cout << "Stack underflow!\n";
            }
        }
        else if (choice == 3) {
            res = s.peek();
            if (res != -1) {
                cout << "Top element: " << res << "\n";
            } else {
                cout << "Stack is empty!\n";
            }
        }
        else if (choice == 4) {
            s.displayStack();
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

