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

const int MAX = 100;

// Class: Stack
// Purpose: Basic stack implementation for use in queue
class Stack {
private:
    int arr[MAX];
    int top;

public:
    // Purpose: Initialize empty stack
    // Logic: Set top to -1 indicating empty stack
    Stack() {
        top = -1;
    }

    // Purpose: Add element to stack
    // Logic: Check bounds and add element at ++top
    void push(int value) {
        if (top < MAX - 1) {
            arr[++top] = value;
        }
    }

    // Purpose: Remove and return top element
    // Logic: Check if empty and return top--
    int pop() {
        if (top == -1) {
            return -1;
        }
        return arr[top--];
    }

    // Purpose: View top element
    // Logic: Check if empty and return top element
    int peek() {
        if (top == -1) {
            return -1;
        }
        return arr[top];
    }

    // Purpose: Check if stack is empty
    // Logic: Compare top with -1
    int isEmpty() {
        return top == -1;
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
        stack1.push(value);
    }

    // Purpose: Remove and return front element
    // Logic: If stack2 empty, move all from stack1 to stack2, then pop from stack2
    int dequeue() {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }
        return stack2.pop();
    }

    // Purpose: View front element without removing
    // Logic: Similar to dequeue but use peek instead of pop
    int peek() {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }
        return stack2.peek();
    }

    // Purpose: Check if queue is empty
    // Logic: Check if both stacks are empty
    int isEmpty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }

    // Purpose: Display queue elements
    // Logic: Display status
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements present.\n";
    }
};

int main() {
    QueueUsingStacks q;
    int choice, value, res;

    while (true) {
        cout << "\n--- Queue (Using Two Stacks) Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            cout << "Enqueued " << value << " successfully.\n";
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
            break;  // Exit program
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

