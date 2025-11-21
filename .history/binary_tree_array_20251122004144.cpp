// Author: Manas Thakur, Roll No. 241475

/*
   Program 16:
   Create a binary tree using array representation.
*/

/*
   Approach:
   Used array to store binary tree.
   For node at index i:
   Left child at 2*i + 1
   Right child at 2*i + 2
   Parent at (i-1)/2
   Array index 0 is root node.
*/

#include <iostream>
using namespace std;

const int MAX = 100;  // Maximum size of tree array

// Class: BinaryTreeArray
// Purpose: Represent binary tree using array
class BinaryTreeArray {
private:
    int arr[MAX];  // Array to store tree elements
    int size;  // Number of elements in tree

public:
    // Purpose: Initialize empty tree
    // Logic: Set size to 0 and initialize array with -1
    BinaryTreeArray() {
        size = 0;  // No elements initially
        for (int i = 0; i < MAX; i++) {  // Loop through entire array
            arr[i] = -1;  // Initialize each position with -1 (empty)
        }
    }

    // Purpose: Insert element at specified position
    // Logic: Store value at position, update size if needed
    void insert(int pos, int value) {
        if (pos >= MAX || pos < 0) {  // If position is invalid
            cout << "Invalid position.\n";
            return;  // Exit function
        }
        arr[pos] = value;  // Store value at position
        if (pos >= size) {  // If position is beyond current size
            size = pos + 1;  // Update size to include new position
        }
    }

    // Purpose: Get left child position of node at pos
    // Logic: Left child at 2*pos+1
    int getLeft(int pos) {
        int leftPos = 2 * pos + 1;  // Calculate left child position
        if (leftPos < size && arr[leftPos] != -1) {  // If left child exists and has value
            return leftPos;  // Return left child position
        }
        return -1;  // No left child exists
    }

    // Purpose: Get right child position of node at pos
    // Logic: Right child at 2*pos+2
    int getRight(int pos) {
        int rightPos = 2 * pos + 2;  // Calculate right child position
        if (rightPos < size && arr[rightPos] != -1) {  // If right child exists and has value
            return rightPos;  // Return right child position
        }
        return -1;  // No right child exists
    }

    // Purpose: Get parent position of node at pos
    // Logic: Parent at (pos-1)/2, special case for root at pos 0
    int getParent(int pos) {
        if (pos == 0) {  // If position is 0 (root node)
            return -1;  // Root has no parent
        }
        int parentPos = (pos - 1) / 2;  // Calculate parent position
        if (arr[parentPos] != -1) {  // If parent has value
            return parentPos;  // Return parent position
        }
        return -1;  // No parent exists
    }

    // Purpose: Display tree structure with relationships
    // Logic: Print each node with its children
    void displayTree() {
        cout << "\nBinary Tree (Array representation):\n";
        cout << "Index  Value  Left Child  Right Child\n";
        for (int i = 0; i < size; i++) {  // Loop through all positions
            if (arr[i] != -1) {  // If position has a value
                int left = getLeft(i);  // Get left child position
                int right = getRight(i);  // Get right child position
                cout << i << "      " << arr[i] << "      ";
                if (left != -1)  // If left child exists
                    cout << arr[left] << " (pos " << left << ")";
                else  // If no left child
                    cout << "NULL";
                cout << "          ";
                if (right != -1)  // If right child exists
                    cout << arr[right] << " (pos " << right << ")";
                else  // If no right child
                    cout << "NULL";
                cout << "\n";
            }
        }
    }
};

int main() {
    BinaryTreeArray tree;  // Create binary tree object
    int choice, pos, value;

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- Binary Tree (Array) Menu ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Display Tree\n";
        cout << "3. Get Left Child\n";
        cout << "4. Get Right Child\n";
        cout << "5. Get Parent\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // If user chooses to insert
            cout << "Enter position: ";
            cin >> pos;  // Get position from user
            cout << "Enter value: ";
            cin >> value;  // Get value from user
            tree.insert(pos, value);  // Insert value at position
            cout << "Node inserted at position " << pos << ".\n";
        }
        else if (choice == 2) {  // If user chooses to display
            tree.displayTree();  // Display entire tree
        }
        else if (choice == 3) {  // If user chooses to get left child
            cout << "Enter node position: ";
            cin >> pos;  // Get position from user
            int leftPos = tree.getLeft(pos);  // Get left child position
            if (leftPos != -1) {  // If left child exists
                cout << "Left child at position " << leftPos << ".\n";
            } else {  // If no left child
                cout << "No left child.\n";
            }
        }
        else if (choice == 4) {  // If user chooses to get right child
            cout << "Enter node position: ";
            cin >> pos;  // Get position from user
            int rightPos = tree.getRight(pos);  // Get right child position
            if (rightPos != -1) {  // If right child exists
                cout << "Right child at position " << rightPos << ".\n";
            } else {  // If no right child
                cout << "No right child.\n";
            }
        }
        else if (choice == 5) {  // If user chooses to get parent
            cout << "Enter node position: ";
            cin >> pos;  // Get position from user
            int parentPos = tree.getParent(pos);  // Get parent position
            if (parentPos != -1) {  // If parent exists
                cout << "Parent found at position " << parentPos << ".\n";
            } else {  // If no parent (root node)
                cout << "No parent (root node).\n";
            }
        }
        else if (choice == 6) {  // If user chooses to exit
            break;  // Exit the while loop and end program
        }
        else {  // If user enters invalid choice
            cout << "Invalid choice!\n";
        }
    }

    return 0;  // Program ends successfully
}
