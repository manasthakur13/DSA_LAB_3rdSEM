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

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[MAX], R[MAX];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

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
            mergeSort(arr, 0, len - 1);
            cout << "Sorting completed.\n";
        }
        else if (choice == 2) {
            display(arr, len);
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}