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

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top < MAX - 1) {
            arr[++top] = value;
        }
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
};

class QueueUsingStacks {
private:
    Stack stack1;
    Stack stack2;

public:
    void enqueue(int value) {
        stack1.push(value);
    }

    int dequeue() {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }
        return stack2.pop();
    }

    int peek() {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }
        return stack2.peek();
    }

    int isEmpty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        if (!stack2.isEmpty()) {
            cout << "(from stack2) ";
        }
        cout << "\n";
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
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
