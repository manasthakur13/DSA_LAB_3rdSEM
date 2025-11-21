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

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() {
        root = NULL;
    }

    TreeNode* createNode(int value) {
        TreeNode* newNode = new TreeNode();
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    void insertValue(int value) {
        if (root == NULL) {
            root = createNode(value);
        } else {
            insertHelper(root, value);
        }
    }

    void insertHelper(TreeNode* node, int value) {
        if (value < node->data) {
            if (node->left == NULL) {
                node->left = createNode(value);
            } else {
                insertHelper(node->left, value);
            }
        } else {
            if (node->right == NULL) {
                node->right = createNode(value);
            } else {
                insertHelper(node->right, value);
            }
        }
    }

    void preorderTraversal(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void inorderTraversal(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void postorderTraversal(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

    void displayPreorder() {
        cout << "Preorder: ";
        preorderTraversal(root);
        cout << "\n";
    }

    void displayInorder() {
        cout << "Inorder: ";
        inorderTraversal(root);
        cout << "\n";
    }

    void displayPostorder() {
        cout << "Postorder: ";
        postorderTraversal(root);
        cout << "\n";
    }

    ~BinaryTree() {
        deleteTree(root);
    }

    void deleteTree(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
};

int main() {
    BinaryTree tree;
    int choice, value;

    while (true) {
        cout << "\n--- Binary Tree Traversals Menu ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            tree.insertValue(value);
            cout << "Node inserted.\n";
        }
        else if (choice == 2) {
            tree.displayPreorder();
        }
        else if (choice == 3) {
            tree.displayInorder();
        }
        else if (choice == 4) {
            tree.displayPostorder();
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
