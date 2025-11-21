// Author: Manas Thakur, Roll No. 241475

/*
   Program 5:
   Bubble Sort with intermediate passes and pass optimization.
*/

/*
   Approach:
   Used bubble sort with boolean flag optimization.
   If no swap occurs in a pass, array is already sorted, so break early.
   This reduces unnecessary iterations when array becomes sorted before all passes.
*/

#include <iostream>
using namespace std;

const int MAX = 100;

// Purpose: Sort array using bubble sort with optimization
// Logic: Outer loop for passes, inner loop compares adjacent elements, swapped flag breaks early if no swaps occur
void bubbleSort(int arr[], int len) {
    bool swapped;  // Flag to check if any swap occurred in pass
    
    for (int i = 0; i < len - 1; i++) {
        swapped = false;  // Initialize flag for current pass
        cout << "Pass " << i + 1 << ": ";
        
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;  // Swap adjacent elements
                swapped = true;  // Mark that swap occurred
            }
        }
        
        for (int k = 0; k < len; k++) {
            cout << arr[k] << " ";  // Print array after each pass
        }
        cout << "\n";
        
        if (!swapped) {
            cout << "Array already sorted. Exiting early.\n";
            break;  // Exit early if no swaps
        }
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
        cout << "\n--- Bubble Sort Menu ---\n";
        cout << "1. Sort Array\n";
        cout << "2. Display Array\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            bubbleSort(arr, len);  // Sort using bubble sort
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

