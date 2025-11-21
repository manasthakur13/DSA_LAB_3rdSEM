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

const int MAX = 100;  // Maximum size of array

// Purpose: Search for a key in sorted array using binary search
// Logic: Maintain low and high pointers, calculate mid, compare with key, adjust pointers
int binarySearch(int arr[], int len, int key) {
    int low = 0, high = len - 1;  // Initialize low to start, high to end of array

    while (low <= high) {  // Continue until search space is exhausted
        int mid = (low + high) / 2;  // Calculate middle index

        if (arr[mid] == key) {  // If middle element matches key
            return mid;  // Element found, return index
        }
        else if (key < arr[mid]) {  // If key is smaller than middle element
            high = mid - 1;  // Search in left half, adjust high
        }
        else {  // If key is larger than middle element
            low = mid + 1;  // Search in right half, adjust low
        }
    }
    return -1;  // Element not found in array
}

// Purpose: Display all elements in array
// Logic: Loop and print each element
void display(int arr[], int len) {
    cout << "Array: ";
    for (int i = 0; i < len; i++) {  // Loop through entire array
        cout << arr[i] << " ";  // Print element at index i
    }
    cout << "\n";  // New line after printing all elements
}

int main() {
    int arr[MAX], len, key;

    cout << "Enter number of elements: ";
    cin >> len;  // Get array size from user

    cout << "Enter elements (sorted): ";
    for (int i = 0; i < len; i++) {  // Loop to input all elements
        cin >> arr[i];  // Store element at index i
    }

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- Binary Search Menu ---\n";
        cout << "1. Search Element\n";
        cout << "2. Display Array\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        int ch;
        cin >> ch;

        if (ch == 1) {  // If user chooses to search
            cout << "Enter key: ";
            cin >> key;  // Get search key from user

            int pos = binarySearch(arr, len, key);  // Perform binary search
            if (pos != -1)  // If element was found
                cout << "Element found at index " << pos << "\n";
            else  // If element was not found
                cout << "Element not found.\n";
        }
        else if (ch == 2) {  // If user chooses to display
            display(arr, len);  // Display all array elements
        }
        else if (ch == 3) {  // If user chooses to exit
            break;  // Exit the while loop and end program
        }
        else {  // If user enters invalid choice
            cout << "Invalid choice!\n";
        }
    }

    return 0;  // Program ends successfully
}
