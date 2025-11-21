// Author: Manas Thakur, Roll No. 241475

/*
   Program 11:
   Implement queue using array with enqueue, dequeue, peek, and display operations.
*/

/*
   Approach:
   Used a static array with front and rear pointers.
   Front starts at 0, rear at -1.
   Enqueue adds element at rear++.
   Dequeue removes from front.
   Queue is FIFO (First In First Out).
*/

#include <iostream>
using namespace std;

const int MAX = 100;

class Queue {
private:
    int arr[MAX];  // Array to store queue elements
    int front, rear;  // Front and rear pointers

public:
    // Purpose: Initialize empty queue
    // Logic: Set front to 0, rear to -1 indicating empty queue
    Queue() {
        front = 0;
        rear = -1;
    }

    // Purpose: Add element at rear of queue
    // Logic: Check if queue full, then add at rear++
    int enqueue(int value) {
        if (rear == MAX - 1) {
            return -1;  // Queue overflow
        }
        arr[++rear] = value;
        return 1;
    }

    // Purpose: Remove and return front element
    // Logic: Check if queue empty, then return front and increment front
    int dequeue() {
        if (front > rear) {
            return -1;  // Queue underflow
        }
        return arr[front++];
    }

    // Purpose: View front element without removing
    // Logic: Check if queue empty, then return front element
    int peek() {
        if (front > rear) {
            return -1;
        }
        return arr[front];
    }

    // Purpose: Check if queue is empty
    // Logic: Compare front > rear
    int isEmpty() {
        return front > rear;
    }

    // Purpose: Display all elements in queue
    // Logic: Print elements from front to rear
    void displayQueue() {
        if (front > rear) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front to rear): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    int choice, value, res;

    while (true) {
        cout << "\n--- Queue Menu ---\n";
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
            res = q.enqueue(value);
            if (res == 1) {
                cout << "Enqueued " << value << " successfully.\n";
            } else {
                cout << "Queue overflow!\n";
            }
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
