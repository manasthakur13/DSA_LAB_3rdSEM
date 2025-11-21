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
    int data;  // Store element value
    Node* next;  // Pointer to next node in linked list
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
        head = NULL;  // Initially no node exists, so head is NULL
    }

    // Purpose: Insert element at start of list
    // Logic: Create new node, link to current head, update head
    void insertAtBeginning(int value) {
        Node* newNode = new Node();  // Create new node dynamically
        newNode->data = value;  // Store value in data field
        newNode->next = head;  // Link new node to current head
        head = newNode;  // Update head to point to new node
    }

    // Purpose: Insert element at end of list
    // Logic: Create new node, traverse to end, link last node to new node
    void insertAtEnd(int value) {
        Node* newNode = new Node();  // Create new node dynamically
        newNode->data = value;  // Store value in data field
        newNode->next = NULL;  // New node is last, so its next is NULL

        if (head == NULL) {  // If list is empty (head is NULL)
            head = newNode;  // New node becomes head
            return;  // Exit function
        }

        Node* temp = head;  // Create temporary pointer at head
        while (temp->next != NULL) {  // While we haven't reached the last node
            temp = temp->next;  // Move to next node
        }
        temp->next = newNode;  // Link last node to new node
    }

    // Purpose: Insert element at specified position
    // Logic: Validate position, traverse to pos-1, insert new node
    int insertAtPosition(int value, int pos) {
        if (pos < 1) {  // If position is less than 1
            return -1;  // Invalid position, return -1
        }

        if (pos == 1) {  // If user wants to insert at beginning
            insertAtBeginning(value);  // Call insertAtBeginning function
            return 1;  // Return 1 for success
        }

        Node* newNode = new Node();  // Create new node
        newNode->data = value;  // Store value

        Node* temp = head;  // Create temporary pointer at head
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {  // Traverse to position pos-1
            temp = temp->next;  // Move to next node
        }

        if (temp == NULL) {  // If position is beyond list length
            return -2;  // Return -2 indicating out of range
        }

        newNode->next = temp->next;  // Link new node to next
        temp->next = newNode;  // Link current node to new node
        return 1;  // Return 1 for success
    }

    // Purpose: Display all elements in list
    // Logic: Traverse from head and print each element
    void displayList() {
        if (head == NULL) {  // If head is NULL, list is empty
            cout << "List is empty.\n";
            return;  // Exit function
        }
        cout << "List: ";
        Node* temp = head;  // Create temporary pointer starting from head
        while (temp != NULL) {  // While we have nodes to traverse
            cout << temp->data << " -> ";  // Print current node's data
            temp = temp->next;  // Move to next node
        }
        cout << "NULL\n";  // Print NULL at end to show list termination
    }

    // Purpose: Clean up memory
    // Logic: Delete all nodes from head to end
    ~SinglyLinkedList() {
        while (head != NULL) {  // While there are nodes to delete
            Node* temp = head;  // Store pointer to current head
            head = head->next;  // Move head to next node
            delete temp;  // Free memory of current node
        }
    }
};

int main() {
    SinglyLinkedList list;  // Create linked list object
    int choice, value, pos, res;

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // If user chooses to insert at beginning
            cout << "Enter value: ";
            cin >> value;  // Get value from user
            list.insertAtBeginning(value);  // Insert at beginning
            cout << "Inserted at beginning.\n";
        }
        else if (choice == 2) {  // If user chooses to insert at end
            cout << "Enter value: ";
            cin >> value;  // Get value from user
            list.insertAtEnd(value);  // Insert at end
            cout << "Inserted at end.\n";
        }
        else if (choice == 3) {  // If user chooses to insert at position
            cout << "Enter position: ";
            cin >> pos;  // Get position from user
            cout << "Enter value: ";
            cin >> value;  // Get value from user
            res = list.insertAtPosition(value, pos);  // Insert at position
            if (res == 1) {  // If insertion was successful
                cout << "Inserted at position " << pos << ".\n";
            } else {  // If insertion failed
                cout << "Invalid position.\n";
            }
        }
        else if (choice == 4) {  // If user chooses to display
            list.displayList();  // Display entire list
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
