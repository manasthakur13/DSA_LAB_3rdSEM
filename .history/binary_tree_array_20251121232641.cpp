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

const int MAX = 100;

class BinaryTreeArray {
private:
    int arr[MAX];
    int size;

public:
    BinaryTreeArray() {
        size = 0;
        for (int i = 0; i < MAX; i++) {
            arr[i] = -1;
        }
    }

    void insert(int pos, int value) {
        if (pos >= MAX || pos < 0) {
            cout << "Invalid position.\n";
            return;
        }
        arr[pos] = value;
        if (pos >= size) {
            size = pos + 1;
        }
    }

    int getLeft(int pos) {
        int leftPos = 2 * pos + 1;
        if (leftPos < size && arr[leftPos] != -1) {
            return leftPos;
        }
        return -1;
    }

    int getRight(int pos) {
        int rightPos = 2 * pos + 2;
        if (rightPos < size && arr[rightPos] != -1) {
            return rightPos;
        }
        return -1;
    }

    int getParent(int pos) {
        if (pos == 0) {
            return -1;
        }
        int parentPos = (pos - 1) / 2;
        if (arr[parentPos] != -1) {
            return parentPos;
        }
        return -1;
    }

    void displayTree() {
        cout << "Binary Tree (Array representation):\n";
        cout << "Index  Value  Left Child  Right Child\n";
        for (int i = 0; i < size; i++) {
            if (arr[i] != -1) {
                int left = getLeft(i);
                int right = getRight(i);
                cout << i << "      " << arr[i] << "      ";
                if (left != -1) cout << arr[left] << " (pos " << left << ")";
                else cout << "NULL";
                cout << "          ";
                if (right != -1) cout << arr[right] << " (pos " << right << ")";
                else cout << "NULL";
                cout << "\n";
            }
        }
    }
};

int main() {
    BinaryTreeArray tree;
    int choice, pos, value;

    while (true) {
        cout << "\n--- Binary Tree (Array) Menu ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Display Tree\n";
        cout << "3. Get Left Child\n";
        cout << "4. Get Right Child\n";
        cout << "5. Get Parent\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> value;
            tree.insert(pos, value);
            cout << "Node inserted at position " << pos << ".\n";
        }
        else if (choice == 2) {
            tree.displayTree();
        }
        else if (choice == 3) {
            cout << "Enter node position: ";
            cin >> pos;
            int leftPos = tree.getLeft(pos);
            if (leftPos != -1) {
                cout << "Left child at position " << leftPos << ".\n";
            } else {
                cout << "No left child.\n";
            }
        }
        else if (choice == 4) {
            cout << "Enter node position: ";
            cin >> pos;
            int rightPos = tree.getRight(pos);
            if (rightPos != -1) {
                cout << "Right child at position " << rightPos << ".\n";
            } else {
                cout << "No right child.\n";
            }
        }
        else if (choice == 5) {
            cout << "Enter node position: ";
            cin >> pos;
            int parentPos = tree.getParent(pos);
            if (parentPos != -1) {
                cout << "Parent found at position " << parentPos << ".\n";
            } else {
                cout << "No parent (root node).\n";
            }
        }
        else if (choice == 6) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
