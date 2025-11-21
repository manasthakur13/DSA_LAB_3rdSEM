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

const int MAX = 100;  // Maximum size of array

// Purpose: Sort array using bubble sort with optimization
// Logic: Outer loop for passes, inner loop compares adjacent elements, swapped flag breaks early if no swaps occur
void bubbleSort(int arr[], int len) {
    bool swapped;  // Flag to track if any swap happened in current pass
    
    for (int i = 0; i < len - 1; i++) {  // Outer loop: n-1 passes needed
        swapped = false;  // Reset flag at start of each pass
        cout << "Pass " << i + 1 << ": ";
        
        for (int j = 0; j < len - i - 1; j++) {  // Inner loop: compare adjacent elements
            if (arr[j] > arr[j + 1]) {  // If current element is greater than next
                int temp = arr[j];  // Store current element in temp
                arr[j] = arr[j + 1];  // Move next element to current position
                arr[j + 1] = temp;  // Place temp value at next position
                swapped = true;  // Mark that a swap occurred
            }
        }
        
        for (int k = 0; k < len; k++) {  // Loop to display array after this pass
            cout << arr[k] << " ";  // Print each element
        }
        cout << "\n";  // New line after displaying pass
        
        if (!swapped) {  // If no swap occurred in this pass
            cout << "Array already sorted. Exiting early.\n";
            break;  // Array is sorted, no need for more passes
        }
    }
}

// Purpose: Display array contents
// Logic: Loop and print each element
void display(int arr[], int len) {
    cout << "Array: ";
    for (int i = 0; i < len; i++) {  // Loop through entire array
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
        cout << "\n--- Bubble Sort Menu ---\n";
        cout << "1. Sort Array\n";
        cout << "2. Display Array\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // If user chooses to sort
            bubbleSort(arr, len);  // Perform bubble sort with passes display
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


