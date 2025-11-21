// Author: Manas Thakur, Roll No. 241475
/*
   Program 3:
   Insert, delete and traverse operations on a 1-D array.
*/
/*
   Approach:
   Used a static array of size 100.
   Insert shifts elements right, delete shifts elements left.
   Length variable keeps track of used positions.
*/

#include <iostream>
using namespace std;

const int MAX = 100;

void traverse(int arr[], int len) {
    cout << "Array: ";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int insertElement(int arr[], int len, int pos, int value) {
    if (len == MAX) {
        return -1; 
    }
    if (pos < 0 || pos > len) {
        return -2; 
    }
    for (int i = len; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    return 1;
}

int deleteElement(int arr[], int len, int pos) {
    if (pos < 0 || pos >= len) {
        return -1;
    }
    for (int i = pos; i < len - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return 1;
}

int main() {
    int arr[MAX], len = 0;
    int choice, pos, value, res;

    while (true) {
        cout << "\n--- Array Operation Menu ---\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Traverse Array\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> value;

            res = insertElement(arr, len, pos, value);
            if (res == 1) {
                len++;
                cout << "Inserted successfully.\n";
            } else {
                cout << "Insertion failed.\n";
            }
        }
        else if (choice == 2) {
            cout << "Enter position: ";
            cin >> pos;

            res = deleteElement(arr, len, pos);
            if (res == 1) {
                len--;
                cout << "Deleted successfully.\n";
            } else {
                cout << "Deletion failed.\n";
            }
        }
        else if (choice == 3) {
            traverse(arr, len);
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
