// Author: Manas Thakur, Roll No. 241475

/*
   Program 9:
   Implement stack using array with push, pop, peek, and display operations.
*/

/*
   Approach:
   Used a static array with a top pointer starting at -1.
   Push adds element at ++top position.
   Pop removes from top position and returns element.
   Peek shows top element without removing.
   Stack is LIFO (Last In First Out).
*/

#include <iostream>
using namespace std;

const int MAX = 100;

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    int push(int value) {
        if (top == MAX - 1) {
            return -1;
        }
        arr[++top] = value;
        return 1;
    }

    int pop() {
        if (top == -1) {
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            return -1;
        }
        return arr[top];
    }

    int isEmpty() {
        return top == -1;
    }

    int isFull() {
        return top == MAX - 1;
    }

    void displayStack() {
        if (top == -1) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Stack s;
    int choice, value, res;

    while (true) {
        cout << "\n--- Stack Menu ---\n";
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
            res = s.push(value);
            if (res == 1) {
                cout << "Pushed " << value << " successfully.\n";
            } else {
                cout << "Stack overflow!\n";
            }
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
