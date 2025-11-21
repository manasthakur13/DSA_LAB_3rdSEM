// Author: Manas Thakur, Roll No. 241475

/*
   Program 13:
   Implement queue using two stacks.
*/

/*
   Approach:
   Used two stacks: stack1 for enqueue, stack2 for dequeue.
   Enqueue: push element into stack1.
   Dequeue: if stack2 empty, pop all from stack1 to stack2.
   Then pop from stack2 to get front element.
*/

#include <iostream>
using namespace std;

const int MAX = 100;  // Maximum size of each stack

// Class: Stack
// Purpose: Basic stack implementation for use in queue
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

    // Purpose: Add element to stack
    // Logic: Check bounds and add element at ++top
    void push(int value) {
        if (top < MAX - 1) {  // If there is space in stack
            arr[++top] = value;  // Increment top first, then insert value
        }
    }

    // Purpose: Remove and return top element
    // Logic: Check if empty and return top--
    int pop() {
        if (top == -1) {  // If top is -1, stack is empty
            return -1;  // Return -1 indicating underflow
        }
        return arr[top--];  // Return top element and decrement top
    }

    // Purpose: View top element
    // Logic: Check if empty and return top element
    int peek() {
        if (top == -1) {  // If top is -1, stack is empty
            return -1;  // Return -1 indicating stack is empty
        }
        return arr[top];  // Return top element without removing
    }

    // Purpose: Check if stack is empty
    // Logic: Compare top with -1
    int isEmpty() {
        return top == -1;  // If top is -1, return 1 (true), else return 0 (false)
    }
};

// Class: QueueUsingStacks
// Purpose: Queue implementation using two stacks
class QueueUsingStacks {
private:
    Stack stack1;  // For enqueue operations
    Stack stack2;  // For dequeue operations

public:
    // Purpose: Add element at rear of queue
    // Logic: Push to stack1
    void enqueue(int value) {
        stack1.push(value);  // Push value to stack1
    }

    // Purpose: Remove and return front element
    // Logic: If stack2 empty, move all from stack1 to stack2, then pop from stack2
    int dequeue() {
        if (stack2.isEmpty()) {  // If stack2 is empty
            while (!stack1.isEmpty()) {  // While stack1 has elements
                stack2.push(stack1.pop());  // Pop from stack1 and push to stack2
            }
        }
        return stack2.pop();  // Pop and return from stack2
    }

    // Purpose: View front element without removing
    // Logic: Similar to dequeue but use peek instead of pop
    int peek() {
        if (stack2.isEmpty()) {  // If stack2 is empty
            while (!stack1.isEmpty()) {  // While stack1 has elements
                stack2.push(stack1.pop());  // Pop from stack1 and push to stack2
            }
        }
        return stack2.peek();  // Peek at top of stack2
    }

    // Purpose: Check if queue is empty
    // Logic: Check if both stacks are empty
    int isEmpty() {
        return stack1.isEmpty() && stack2.isEmpty();  // Return true only if both stacks are empty
    }

    // Purpose: Display queue elements
    // Logic: Display status
    void displayQueue() {
        if (isEmpty()) {  // If queue is empty
            cout << "Queue is empty.\n";
            return;  // Exit function
        }
        cout << "Queue elements present.\n";
    }
};

int main() {
    QueueUsingStacks q;  // Create queue object
    int choice, value, res;

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- Queue (Using Two Stacks) Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // If user chooses to enqueue
            cout << "Enter value: ";
            cin >> value;  // Get value from user
            q.enqueue(value);  // Enqueue value to queue
            cout << "Enqueued " << value << " successfully.\n";
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
        else if (choice == 4) {  // If user chooses to exit
            break;  // Exit the while loop and end program
        }
        else {  // If user enters invalid choice
            cout << "Invalid choice!\n";
        }
    }

    return 0;  // Program ends successfully
}
