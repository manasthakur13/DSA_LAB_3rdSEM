// Author: Manas Thakur, Roll No. 241475

/*
   Program 4:
   Binary search on a sorted array.
*/

/*
   Approach:
   Used normal binary search logic with low, high and mid.
   Array must be sorted before searching.
*/

#include <iostream>
using namespace std;

const int MAX = 100;

// Purpose: Search for a key in sorted array using binary search
// Logic: Maintain low and high pointers, calculate mid, compare with key, adjust pointers
int binarySearch(int arr[], int len, int key) {
    int low = 0, high = len - 1;

    while (low <= high) {
        int mid = (low + high) / 2;  // Calculate middle index

        if (arr[mid] == key) {
            return mid;  // Element found at mid
        }
        else if (key < arr[mid]) {
            high = mid - 1;  // Search in left half
        }
        else {
            low = mid + 1;  // Search in right half
        }
    }
    return -1;  // Element not found
}

// Purpose: Display all elements in array
// Logic: Loop and print each element
void display(int arr[], int len) {
    cout << "Array: ";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[MAX], len, key;

    cout << "Enter number of elements: ";
    cin >> len;

    cout << "Enter elements (sorted): ";
    for (int i = 0; i < len; i++) {
        cin >> arr[i];  // Input sorted array
    }

    while (true) {
        cout << "\n--- Binary Search Menu ---\n";
        cout << "1. Search Element\n";
        cout << "2. Display Array\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        int ch;
        cin >> ch;

        if (ch == 1) {
            cout << "Enter key: ";
            cin >> key;

            int pos = binarySearch(arr, len, key);  // Search for key
            if (pos != -1)
                cout << "Element found at index " << pos << "\n";
            else
                cout << "Element not found.\n";
        }
        else if (ch == 2) {
            display(arr, len);  // Display array
        }
        else if (ch == 3) {
            break;  // Exit program
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
