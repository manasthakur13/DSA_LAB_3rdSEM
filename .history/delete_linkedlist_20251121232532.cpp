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

    int deleteByValue(int value) {
        if (head == NULL) {
            return -1;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return 1;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            if (temp->next->data == value) {
                Node* toDelete = temp->next;
                temp->next = toDelete->next;
                delete toDelete;
                return 1;
            }
            temp = temp->next;
        }
        return -2;
    }

    int deleteByPosition(int pos) {
        if (head == NULL || pos < 1) {
            return -1;
        }

        if (pos == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return 1;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            return -2;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
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

    cout << "Initial list creation. Enter 5 values:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        list.insertAtEnd(value);
    }

    while (true) {
        cout << "\n--- Delete Node Menu ---\n";
        cout << "1. Delete by Value\n";
        cout << "2. Delete by Position\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to delete: ";
            cin >> value;
            res = list.deleteByValue(value);
            if (res == 1) {
                cout << "Node with value " << value << " deleted.\n";
            } else if (res == -1) {
                cout << "List is empty.\n";
            } else {
                cout << "Value not found in list.\n";
            }
        }
        else if (choice == 2) {
            cout << "Enter position to delete: ";
            cin >> pos;
            res = list.deleteByPosition(pos);
            if (res == 1) {
                cout << "Node at position " << pos << " deleted.\n";
            } else {
                cout << "Invalid position.\n";
            }
        }
        else if (choice == 3) {
            list.displayList();
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
