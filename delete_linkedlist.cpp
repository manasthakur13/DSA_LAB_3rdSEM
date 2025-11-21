// Author: Manas Thakur, Roll No. 241475

/*
   Program 15:
   Delete a node from singly linked list by value or position.
*/

/*
   Approach:
   Delete by value: traverse and find matching node, unlink it.
   Delete by position: traverse to position-1, unlink position node.
   Handle edge case: if deleting first node, update head.
   Free memory after deletion using delete.
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
// Purpose: Manage a singly linked list with delete operations
class SinglyLinkedList {
private:
    Node* head;  // Pointer to first node

public:
    // Purpose: Initialize empty list
    // Logic: Set head to NULL indicating empty list
    SinglyLinkedList() {
        head = NULL;  // Initially no node exists, so head is NULL
    }

    // Purpose: Insert element at end of list (helper function)
    // Logic: Create new node, traverse to end, link
    void insertAtEnd(int value) {
        Node* newNode = new Node();  // Create new node
        newNode->data = value;  // Store value
        newNode->next = NULL;  // New node is last

        if (head == NULL) {  // If list is empty
            head = newNode;  // New node becomes head
            return;  // Exit function
        }

        Node* temp = head;  // Create temporary pointer at head
        while (temp->next != NULL) {  // While we haven't reached last node
            temp = temp->next;  // Move to next node
        }
        temp->next = newNode;  // Link last node to new node
    }

    // Purpose: Delete first node with matching value
    // Logic: Check if head matches, delete; else traverse and find
    int deleteByValue(int value) {
        if (head == NULL) {  // If list is empty (head is NULL)
            return -1;  // Return -1 indicating failure
        }

        if (head->data == value) {  // If head node has matching value
            Node* temp = head;  // Store pointer to head
            head = head->next;  // Move head to next node
            delete temp;  // Free memory of old head
            return 1;  // Return 1 for success
        }

        Node* temp = head;  // Create temporary pointer at head
        while (temp->next != NULL) {  // While there are more nodes
            if (temp->next->data == value) {  // If next node has matching value
                Node* toDelete = temp->next;  // Store pointer to node to delete
                temp->next = toDelete->next;  // Bypass the deleted node
                delete toDelete;  // Free memory
                return 1;  // Return 1 for success
            }
            temp = temp->next;  // Move to next node
        }
        return -2;  // Return -2 if value not found
    }

    // Purpose: Delete node at specified position
    // Logic: Validate position, traverse to pos-1, delete node at pos
    int deleteByPosition(int pos) {
        if (head == NULL || pos < 1) {  // If list is empty or position invalid
            return -1;  // Return -1 indicating failure
        }

        if (pos == 1) {  // If user wants to delete first node
            Node* temp = head;  // Store pointer to head
            head = head->next;  // Move head to next node
            delete temp;  // Free memory of deleted node
            return 1;  // Return 1 for success
        }

        Node* temp = head;  // Create temporary pointer at head
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {  // Traverse to position pos-1
            temp = temp->next;  // Move to next node
        }

        if (temp == NULL || temp->next == NULL) {  // If position is out of range
            return -2;  // Return -2 indicating out of range
        }

        Node* toDelete = temp->next;  // Store pointer to node to delete
        temp->next = toDelete->next;  // Bypass the deleted node
        delete toDelete;  // Free memory
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

    cout << "Initial list creation. Enter 5 values:\n";
    for (int i = 0; i < 5; i++) {  // Loop to input 5 elements
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;  // Get value from user
        list.insertAtEnd(value);  // Insert at end of list
    }

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- Delete Node Menu ---\n";
        cout << "1. Delete by Value\n";
        cout << "2. Delete by Position\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // If user chooses to delete by value
            cout << "Enter value to delete: ";
            cin >> value;  // Get value from user
            res = list.deleteByValue(value);  // Delete node with this value
            if (res == 1) {  // If deletion was successful
                cout << "Node with value " << value << " deleted.\n";
            } else if (res == -1) {  // If list was empty
                cout << "List is empty.\n";
            } else {  // If value not found
                cout << "Value not found in list.\n";
            }
        }
        else if (choice == 2) {  // If user chooses to delete by position
            cout << "Enter position to delete: ";
            cin >> pos;  // Get position from user
            res = list.deleteByPosition(pos);  // Delete node at this position
            if (res == 1) {  // If deletion was successful
                cout << "Node at position " << pos << " deleted.\n";
            } else {  // If deletion failed
                cout << "Invalid position.\n";
            }
        }
        else if (choice == 3) {  // If user chooses to display
            list.displayList();  // Display entire list
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