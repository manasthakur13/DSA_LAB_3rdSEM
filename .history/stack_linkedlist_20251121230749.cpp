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

struct Node {
    int data;
    Node* next;
};

class StackLL {
private:
    Node* top;

public:
    StackLL() {
        top = NULL;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " successfully.\n";
    }

    int pop() {
        if (top == NULL) {
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    int peek() {
        if (top == NULL) {
            return -1;
        }
        return top->data;
    }

    int isEmpty() {
        return top == NULL;
    }

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
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
