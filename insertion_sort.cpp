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

const int MAX = 100;  // Maximum size of array

// Purpose: Sort array using insertion sort algorithm
// Logic: For each element from index 1 to len-1, find correct position in sorted part and insert it by shifting larger elements right
void insertionSort(int arr[], int len) {
    for (int i = 1; i < len; i++) {  // Start from second element (index 1)
        int key = arr[i];  // Element to be inserted in the already sorted part
        int j = i - 1;  // j points to last element in sorted part

        while (j >= 0 && arr[j] > key) {  // While j is valid AND element at j is greater than key
            arr[j + 1] = arr[j];  // Shift current element one position to the right
            j--;  // Move j to previous element
        }
        arr[j + 1] = key;  // Insert key at correct position (j+1)
    }
}

// Purpose: Display array contents
// Logic: Loop and print each element
void display(int arr[], int len) {
    cout << "Array: ";
    for (int i = 0; i < len; i++) {  // Loop through entire array from 0 to len-1
        cout << arr[i] << " ";  // Print element at index i
    }
    cout << "\n";  // New line after printing all elements
}

int main() {
    int arr[MAX], len;
    int choice;

    cout << "Enter number of elements: ";
    cin >> len;  // Get array size from user

    cout << "Enter elements: ";
    for (int i = 0; i < len; i++) {  // Loop to input all elements
        cin >> arr[i];  // Store element at index i
    }

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- Insertion Sort Menu ---\n";
        cout << "1. Sort Array\n";
        cout << "2. Display Array\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // If user chooses to sort
            insertionSort(arr, len);  // Sort array using insertion sort
            cout << "Sorting completed.\n";
        }
        else if (choice == 2) {  // If user chooses to display
            display(arr, len);  // Display all array elements
        }
        else if (choice == 3) {  // If user chooses to exit
            break;  // Exit the while loop and end program
        }
        else {  // If user enters invalid choice
            cout << "Invalid choice!\n";
        }
    }

    return 0;  // Program ends successfully
}


