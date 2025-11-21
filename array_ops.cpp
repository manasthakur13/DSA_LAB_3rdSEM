// Author: Manas Thakur, Roll No. 241475

/*
   Program 3:
   Insert, delete and traverse operations on a 1-D array.
*/

/*
   Approach:
   Used a static array of size 100.
   Insert shifts elements right, delete shifts elements left.
   Length variable keeps track of used positions.
*/

#include <iostream>
using namespace std;

const int MAX = 100;  // Maximum size of array

// Purpose: Display all elements in the array
// Logic: Loop through array and print each element
void traverse(int arr[], int len) {
    cout << "Array: ";
    for (int i = 0; i < len; i++) {  // Loop from index 0 to len-1
        cout << arr[i] << " ";  // Print element at index i
    }
    cout << "\n";  // New line after printing all elements
}

// Purpose: Insert element at specified position
// Logic: Check bounds, shift elements right from pos, insert value at pos
int insertElement(int arr[], int len, int pos, int value) {
    if (len == MAX) {  // If array is already full
        return -1;  // Return -1 indicating overflow
    }
    if (pos < 0 || pos > len) {  // If position is invalid
        return -2;  // Return -2 indicating invalid position
    }
    for (int i = len; i > pos; i--) {  // Loop from end to position, moving backwards
        arr[i] = arr[i - 1];  // Shift each element one position to the right
    }
    arr[pos] = value;  // Insert new value at desired position
    return 1;  // Return 1 indicating success
}

// Purpose: Delete element at specified position
// Logic: Check bounds, shift elements left from pos+1
int deleteElement(int arr[], int len, int pos) {
    if (pos < 0 || pos >= len) {  // If position is invalid or out of bounds
        return -1;  // Return -1 indicating invalid position
    }
    for (int i = pos; i < len - 1; i++) {  // Loop from position to second-last element
        arr[i] = arr[i + 1];  // Shift each element one position to the left
    }
    return 1;  // Return 1 indicating success
}

int main() {
    int arr[MAX], len = 0;  // Array and length variable (starts at 0)
    int choice, pos, value, res;

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- Array Operation Menu ---\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Traverse Array\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // If user chooses to insert
            cout << "Enter position: ";
            cin >> pos;  // Get position from user
            cout << "Enter value: ";
            cin >> value;  // Get value from user

            res = insertElement(arr, len, pos, value);  // Call insert function
            if (res == 1) {  // If insertion was successful
                len++;  // Increase array length by 1
                cout << "Inserted successfully.\n";
            } else {  // If insertion failed
                cout << "Insertion failed.\n";
            }
        }
        else if (choice == 2) {  // If user chooses to delete
            cout << "Enter position: ";
            cin >> pos;  // Get position from user

            res = deleteElement(arr, len, pos);  // Call delete function
            if (res == 1) {  // If deletion was successful
                len--;  // Decrease array length by 1
                cout << "Deleted successfully.\n";
            } else {  // If deletion failed
                cout << "Deletion failed.\n";
            }
        }
        else if (choice == 3) {  // If user chooses to traverse
            traverse(arr, len);  // Display all elements
        }
        else if (choice == 4) {  // If user chooses to exit
            break;  // Exit the while loop and end program
        }
        else {  // If user enters invalid choice
            cout << "Invalid choice!\n";
        }
    }
    return 0;  // Program ends successfully
}
