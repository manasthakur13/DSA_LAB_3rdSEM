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

// Structure: Node
// Members: data (element value), next (pointer to next node)
struct Node {
    int data;
    Node* next;
};

// Class: SinglyLinkedList
// Purpose: Manage a singly linked list with insertions
class SinglyLinkedList {
private:
    Node* head;  // Pointer to first node

public:
    // Purpose: Initialize empty list
    // Logic: Set head to NULL indicating empty list
    SinglyLinkedList() {
        head = NULL;
    }

    // Purpose: Insert element at start of list
    // Logic: Create new node, link to current head, update head
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Purpose: Insert element at end of list
    // Logic: Create new node, traverse to end, link last node to new node
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

    // Purpose: Insert element at specified position
    // Logic: Validate position, traverse to pos-1, insert new node
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

    // Purpose: Display all elements in list
    // Logic: Traverse from head and print each element
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

    // Purpose: Clean up memory
    // Logic: Delete all nodes from head to end
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
            break;  // Exit program
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
