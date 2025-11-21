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

const int MAX = 100;  // Maximum size of stack

class Stack {
private:
    int arr[MAX];  // Array to store stack elements
    int top;  // Index of top element

public:
    // Purpose: Initialize empty stack
    // Logic: Set top to -1 indicating empty stack
    Stack() {
        top = -1;  // Initially stack is empty, so top is -1
    }

    // Purpose: Add element to top of stack
    // Logic: Check if stack full, then increment top and store value
    int push(int value) {
        if (top == MAX - 1) {  // If top is at last position
            return -1;  // Stack is full, return -1
        }
        arr[++top] = value;  // Increment top first, then insert value
        return 1;  // Return 1 for successful insertion
    }

    // Purpose: Remove and return top element
    // Logic: Check if stack empty, then return and decrement top
    int pop() {
        if (top == -1) {  // If top is -1, stack is empty
            return -1;  // Return -1 indicating underflow
        }
        return arr[top--];  // Return top element and decrement top
    }

    // Purpose: View top element without removing
    // Logic: Check if stack empty, then return top element
    int peek() {
        if (top == -1) {  // If top is -1, stack is empty
            return -1;  // Return -1 indicating stack is empty
        }
        return arr[top];  // Return top element without removing
    }

    // Purpose: Check if stack is empty
    // Logic: Compare top with -1
    int isEmpty() {
        return top == -1;  // If top is -1, stack is empty, return 1, else return 0
    }

    // Purpose: Check if stack is full
    // Logic: Compare top with MAX-1
    int isFull() {
        return top == MAX - 1;  // If top is at MAX-1, stack is full, return 1, else return 0
    }

    // Purpose: Display all elements in stack
    // Logic: Print elements from top to bottom
    void displayStack() {
        if (top == -1) {  // If top is -1, stack is empty
            cout << "Stack is empty.\n";
            return;  // Exit function
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {  // Loop from top index down to 0
            cout << arr[i] << " ";  // Print each element
        }
        cout << "\n";  // New line after printing
    }
};

int main() {
    Stack s;  // Create stack object
    int choice, value, res;

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- Stack Menu ---\n";
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
            res = s.push(value);  // Push value to stack
            if (res == 1) {  // If push was successful
                cout << "Pushed " << value << " successfully.\n";
            } else {  // If push failed
                cout << "Stack overflow!\n";
            }
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


