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

const int MAX = 100;

// Purpose: Merge two sorted subarrays into one sorted subarray
// Logic: Create temp arrays for left and right halves, merge them in sorted order back to arr
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of left subarray
    int n2 = right - mid;  // Size of right subarray

    int L[MAX], R[MAX];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];  // Copy left subarray data to L[]
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];  // Copy right subarray data to R[]

    int i = 0, j = 0, k = left;  // Initial indexes for merging

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];  // Take from left if smaller
            i++;
        }
        else {
            arr[k] = R[j];  // Take from right if smaller
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];  // Copy remaining elements from L[]
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];  // Copy remaining elements from R[]
        j++;
        k++;
    }
}

// Purpose: Recursively divide array and sort using merge
// Logic: Base case when left < right, divide array at mid and recursively sort halves, then merge
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Calculate middle index

        mergeSort(arr, left, mid);  // Sort left half
        mergeSort(arr, mid + 1, right);  // Sort right half

        merge(arr, left, mid, right);  // Merge sorted halves
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
        cout << "\n--- Merge Sort Menu ---\n";
        cout << "1. Sort Array\n";
        cout << "2. Display Array\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            mergeSort(arr, 0, len - 1);  // Sort using merge sort
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
