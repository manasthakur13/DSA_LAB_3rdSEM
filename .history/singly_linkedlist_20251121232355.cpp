// Author: Manas Thakur, Roll No. 241475

/*
   Program 14:
   Create a singly linked list and perform insertion at beginning, middle, and end.
*/

/*
   Approach:
   Used a node structure with data and next pointer.
   Head pointer tracks start of list.
   Insert at beginning: new node becomes head.
   Insert at end: traverse to last and link new node.
   Insert at middle: traverse to position and insert.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    int insertAtPosition(int value, int pos) {
        if (pos < 1) {
            return -1;
        }

        if (pos == 1) {
            insertAtBeginning(value);
            return 1;
        }

        Node* newNode = new Node();
        newNode->data = value;

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            return -2;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        return 1;
    }

    void displayList() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        cout << "List: ";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~SinglyLinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, pos, res;

    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            cout << "Inserted at beginning.\n";
        }
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            cout << "Inserted at end.\n";
        }
        else if (choice == 3) {
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> value;
            res = list.insertAtPosition(value, pos);
            if (res == 1) {
                cout << "Inserted at position " << pos << ".\n";
            } else {
                cout << "Invalid position.\n";
            }
        }
        else if (choice == 4) {
            list.displayList();
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
