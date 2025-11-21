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

const int MAX = 100;  // Maximum size of queue

class Queue {
private:
    int arr[MAX];  // Array to store queue elements
    int front, rear;  // Front and rear pointers

public:
    // Purpose: Initialize empty queue
    // Logic: Set front to 0, rear to -1 indicating empty queue
    Queue() {
        front = 0;  // Front pointer starts at 0
        rear = -1;  // Rear pointer starts at -1 (no elements yet)
    }

    // Purpose: Add element at rear of queue
    // Logic: Check if queue full, then add at rear++
    int enqueue(int value) {
        if (rear == MAX - 1) {  // If rear is at last position (queue full)
            return -1;  // Queue overflow, return -1
        }
        arr[++rear] = value;  // Increment rear first, then insert value
        return 1;  // Return 1 for successful insertion
    }

    // Purpose: Remove and return front element
    // Logic: Check if queue empty, then return front and increment front
    int dequeue() {
        if (front > rear) {  // If front pointer crosses rear (queue empty)
            return -1;  // Queue underflow, return -1
        }
        return arr[front++];  // Return front element and increment front
    }

    // Purpose: View front element without removing
    // Logic: Check if queue empty, then return front element
    int peek() {
        if (front > rear) {  // If front pointer crosses rear (queue empty)
            return -1;  // Return -1 indicating queue is empty
        }
        return arr[front];  // Return front element without removing
    }

    // Purpose: Check if queue is empty
    // Logic: Compare front > rear
    int isEmpty() {
        return front > rear;  // If front > rear, queue is empty, return 1, else return 0
    }

    // Purpose: Display all elements in queue
    // Logic: Print elements from front to rear
    void displayQueue() {
        if (front > rear) {  // If front > rear, queue is empty
            cout << "Queue is empty.\n";
            return;  // Exit function
        }
        cout << "Queue (front to rear): ";
        for (int i = front; i <= rear; i++) {  // Loop from front index to rear index
            cout << arr[i] << " ";  // Print element at index i
        }
        cout << "\n";  // New line after printing
    }
};

int main() {
    Queue q;  // Create queue object
    int choice, value, res;

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // If user chooses to enqueue
            cout << "Enter value: ";
            cin >> value;  // Get value from user
            res = q.enqueue(value);  // Enqueue value to queue
            if (res == 1) {  // If enqueue was successful
                cout << "Enqueued " << value << " successfully.\n";
            } else {  // If enqueue failed
                cout << "Queue overflow!\n";
            }
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
        else if (choice == 4) {  // If user chooses to display
            q.displayQueue();  // Display all elements
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
