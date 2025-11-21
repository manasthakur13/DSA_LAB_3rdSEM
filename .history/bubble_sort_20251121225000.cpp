// Author: Manas Thakur, Roll No. 241475

/*
   Program 5:
   Bubble Sort with intermediate passes and pass optimization.
*/

/*
   Approach:
   Used bubble sort logic where largest element moves to end in each pass 
   with boolean flag optimization.
   If no swap occurs in a pass, array is already sorted, so break early.
   This reduces unnecessary iterations when array becomes sorted before all passes.
*/

#include <iostream>
using namespace std;

const int MAX = 100;

void bubbleSort(int arr[], int len) {
    bool swapped;
    
    for (int i = 0; i < len - 1; i++) {
        swapped = false;
        cout << "Pass " << i + 1 << ": ";
        
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        
        for (int k = 0; k < len; k++) {
            cout << arr[k] << " ";
        }
        cout << "\n";
        
        if (!swapped) {
            cout << "Array already sorted. Exiting early.\n";
            break;
        }
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
        cout << "\n--- Bubble Sort Menu ---\n";
        cout << "1. Sort Array\n";
        cout << "2. Display Array\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            bubbleSort(arr, len);
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
