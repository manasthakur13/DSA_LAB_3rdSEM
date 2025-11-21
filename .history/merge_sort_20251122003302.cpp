// Author: Manas Thakur, Roll No. 241475

/*
   Program 7:
   Merge Sort using recursion.
*/

/*
   Approach:
   Used divide and conquer with recursion.
   Array divided into two halves until single element remains.
   Then merge function combines sorted halves.
   Temporary array used during merging.
*/

#include <iostream>
using namespace std;

const int MAX = 100;  // Maximum size of array

// Purpose: Merge two sorted subarrays into one sorted subarray
// Logic: Create temp arrays for left and right halves, merge them in sorted order back to arr
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Calculate size of left subarray
    int n2 = right - mid;  // Calculate size of right subarray

    int L[MAX], R[MAX];  // Temporary arrays for left and right subarrays

    for (int i = 0; i < n1; i++)  // Loop to copy left subarray
        L[i] = arr[left + i];  // Copy element from arr to L at index i
    
    for (int j = 0; j < n2; j++)  // Loop to copy right subarray
        R[j] = arr[mid + 1 + j];  // Copy element from arr to R at index j

    int i = 0, j = 0, k = left;  // i for L array, j for R array, k for main array

    while (i < n1 && j < n2) {  // While both arrays have elements to compare
        if (L[i] <= R[j]) {  // If left element is smaller or equal
            arr[k] = L[i];  // Place left element in main array
            i++;  // Move to next element in left array
        }
        else {  // If right element is smaller
            arr[k] = R[j];  // Place right element in main array
            j++;  // Move to next element in right array
        }
        k++;  // Move to next position in main array
    }

    while (i < n1) {  // If left array has remaining elements
        arr[k] = L[i];  // Copy remaining left elements
        i++;  // Move to next element in left array
        k++;  // Move to next position in main array
    }

    while (j < n2) {  // If right array has remaining elements
        arr[k] = R[j];  // Copy remaining right elements
        j++;  // Move to next element in right array
        k++;  // Move to next position in main array
    }
}

// Purpose: Recursively divide array and sort using merge
// Logic: Base case when left < right, divide array at mid and recursively sort halves, then merge
void mergeSort(int arr[], int left, int right) {
    if (left < right) {  // If there are elements to sort
        int mid = left + (right - left) / 2;  // Calculate middle index

        mergeSort(arr, left, mid);  // Recursively sort left half
        mergeSort(arr, mid + 1, right);  // Recursively sort right half

        merge(arr, left, mid, right);  // Merge the two sorted halves
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
        cout << "\n--- Merge Sort Menu ---\n";
        cout << "1. Sort Array\n";
        cout << "2. Display Array\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // If user chooses to sort
            mergeSort(arr, 0, len - 1);  // Sort entire array using merge sort
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

