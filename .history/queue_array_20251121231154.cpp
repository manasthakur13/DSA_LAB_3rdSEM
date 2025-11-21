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
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    int enqueue(int value) {
        if (rear == MAX - 1) {
            return -1;
        }
        arr[++rear] = value;
        return 1;
    }

    int dequeue() {
        if (front > rear) {
            return -1;
        }
        return arr[front++];
    }

    int peek() {
        if (front > rear) {
            return -1;
        }
        return arr[front];
    }

    int isEmpty() {
        return front > rear;
    }

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
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
