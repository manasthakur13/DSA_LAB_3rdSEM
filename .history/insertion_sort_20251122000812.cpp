// Author: Manas Thakur, Roll No. 241475

/*
   Program 6:
   Insertion Sort implementation.
*/

/*
   Approach:
   Used insertion sort where each element is inserted at correct position in sorted part.
   Start from second element, compare with previous elements.
   Shift larger elements to right and insert current element.
*/

#include <iostream>
using namespace std;

const int MAX = 100;

// Purpose: Sort array using insertion sort algorithm
// Logic: For each element from index 1 to len-1, find correct position in sorted part and insert it by shifting larger elements right
void insertionSort(int arr[], int len) {
    for (int i = 1; i < len; i++) {
        int key = arr[i];  // Element to be inserted in sorted part
        int j = i - 1;  // Start comparing from previous element

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Shift element right
            j--;
        }
        arr[j + 1] = key;  // Insert key at correct position
    }
}

// Purpose: Display array contents
// Logic: Loop and print each element
void display(int arr[], int len) {
    cout << "Array: ";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[MAX], len;
    int choice;

    cout << "Enter number of elements: ";
    cin >> len;

    cout << "Enter elements: ";
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    while (true) {
        cout << "\n--- Insertion Sort Menu ---\n";
        cout << "1. Sort Array\n";
        cout << "2. Display Array\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            insertionSort(arr, len);  // Sort using insertion sort
            cout << "Sorting completed.\n";
        }
        else if (choice == 2) {
            display(arr, len);  // Display array
        }
        else if (choice == 3) {
            break;  // Exit program
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

