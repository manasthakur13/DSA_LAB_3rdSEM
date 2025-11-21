// Author: Manas Thakur, Roll No. 241475

/*
   Program 12:
   Implement queue using linked list with dynamic memory allocation.
*/

/*
   Approach:
   Used a node structure with data and next pointer.
   Front and rear pointers track queue ends.
   Enqueue adds node at rear.
   Dequeue removes node from front.
   No size limit as memory is dynamically allocated.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class QueueLL {
private:
    Node* front;
    Node* rear;

public:
    QueueLL() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << value << " successfully.\n";
    }

    int dequeue() {
        if (front == NULL) {
            return -1;
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        return value;
    }

    int peek() {
        if (front == NULL) {
            return -1;
        }
        return front->data;
    }

    int isEmpty() {
        return front == NULL;
    }

    void displayQueue() {
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front to rear): ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    ~QueueLL() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    QueueLL q;
    int choice, value, res;

    while (true) {
        cout << "\n--- Queue (Linked List) Menu ---\n";
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
            q.enqueue(value);
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
