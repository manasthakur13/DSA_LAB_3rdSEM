// Author: Manas Thakur, Roll No. 241475

/*
   Program 17:
   Perform preorder, inorder, and postorder traversal of a binary tree.
*/

/*
   Approach:
   Used recursive traversal functions.
   Preorder: Visit node, then left, then right.
   Inorder: Visit left, then node, then right.
   Postorder: Visit left, then right, then node.
   Pointer based binary tree with recursion.
*/

#include <iostream>
using namespace std;

// Structure: TreeNode
// Purpose: Represents each node in binary tree
// Members: data (element value), left (left child), right (right child)
struct TreeNode {
    int data;  // Data stored in node
    TreeNode* left;  // Pointer to left child
    TreeNode* right;  // Pointer to right child
};

// Class: BinaryTree
// Purpose: Binary search tree implementation with traversals
class BinaryTree {
private:
    TreeNode* root;  // Pointer to root node

public:
    // Purpose: Initialize empty tree
    // Logic: Set root to NULL indicating empty tree
    BinaryTree() {
        root = NULL;  // Tree is empty
    }

    // Purpose: Create a new tree node
    // Logic: Allocate memory, initialize left and right to NULL
    TreeNode* createNode(int value) {
        TreeNode* newNode = new TreeNode();  // Allocate memory for new node
        newNode->data = value;  // Store value
        newNode->left = NULL;  // No left child initially
        newNode->right = NULL;  // No right child initially
        return newNode;  // Return new node
    }

    // Purpose: Insert value into BST
    // Logic: Call helper function to recursively insert
    void insertValue(int value) {
        if (root == NULL) {  // If tree is empty
            root = createNode(value);  // Create root node
        } else {  // If tree has elements
            insertHelper(root, value);  // Use helper to insert
        }
    }

    // Purpose: Recursively find correct position and insert
    // Logic: Compare with node, go left if less, right if more
    void insertHelper(TreeNode* node, int value) {
        if (value < node->data) {  // If value is less than current node
            if (node->left == NULL) {  // If left child doesn't exist
                node->left = createNode(value);  // Create left child
            } else {  // If left child exists
                insertHelper(node->left, value);  // Recurse on left subtree
            }
        } else {  // If value is greater than or equal to current node
            if (node->right == NULL) {  // If right child doesn't exist
                node->right = createNode(value);  // Create right child
            } else {  // If right child exists
                insertHelper(node->right, value);  // Recurse on right subtree
            }
        }
    }

    // Purpose: Visit node, then left, then right (NLR)
    // Logic: Print current, recurse left, recurse right
    void preorderTraversal(TreeNode* node) {
        if (node == NULL) {  // If node is NULL (base case)
            return;  // Exit function
        }
        cout << node->data << " ";  // Visit and print current node
        preorderTraversal(node->left);  // Traverse left subtree
        preorderTraversal(node->right);  // Traverse right subtree
    }

    // Purpose: Visit left, then node, then right (LNR)
    // Logic: Recurse left, print current, recurse right
    void inorderTraversal(TreeNode* node) {
        if (node == NULL) {  // If node is NULL (base case)
            return;  // Exit function
        }
        inorderTraversal(node->left);  // Traverse left subtree
        cout << node->data << " ";  // Visit and print current node
        inorderTraversal(node->right);  // Traverse right subtree
    }

    // Purpose: Visit left, then right, then node (LRN)
    // Logic: Recurse left, recurse right, print current
    void postorderTraversal(TreeNode* node) {
        if (node == NULL) {  // If node is NULL (base case)
            return;  // Exit function
        }
        postorderTraversal(node->left);  // Traverse left subtree
        postorderTraversal(node->right);  // Traverse right subtree
        cout << node->data << " ";  // Visit and print current node
    }

    // Purpose: Display tree in preorder
    // Logic: Call preorderTraversal on root
    void displayPreorder() {
        cout << "Preorder: ";
        preorderTraversal(root);  // Start preorder traversal from root
        cout << "\n";
    }

    // Purpose: Display tree in inorder
    // Logic: Call inorderTraversal on root
    void displayInorder() {
        cout << "Inorder: ";
        inorderTraversal(root);  // Start inorder traversal from root
        cout << "\n";
    }

    // Purpose: Display tree in postorder
    // Logic: Call postorderTraversal on root
    void displayPostorder() {
        cout << "Postorder: ";
        postorderTraversal(root);  // Start postorder traversal from root
        cout << "\n";
    }

    // Purpose: Clean up memory
    // Logic: Delete all nodes
    ~BinaryTree() {
        deleteTree(root);  // Delete all nodes starting from root
    }

    // Purpose: Recursively delete all nodes
    // Logic: Recurse left, recurse right, delete current
    void deleteTree(TreeNode* node) {
        if (node == NULL) {  // If node is NULL (base case)
            return;  // Exit function
        }
        deleteTree(node->left);  // Delete left subtree
        deleteTree(node->right);  // Delete right subtree
        delete node;  // Delete current node
    }
};

int main() {
    BinaryTree tree;  // Create binary tree object
    int choice, value;

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- Binary Tree Traversals Menu ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // If user chooses to insert
            cout << "Enter value: ";
            cin >> value;  // Get value from user
            tree.insertValue(value);  // Insert value into tree
            cout << "Node inserted.\n";
        }
        else if (choice == 2) {  // If user chooses preorder
            tree.displayPreorder();  // Display tree in preorder
        }
        else if (choice == 3) {  // If user chooses inorder
            tree.displayInorder();  // Display tree in inorder
        }
        else if (choice == 4) {  // If user chooses postorder
            tree.displayPostorder();  // Display tree in postorder
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