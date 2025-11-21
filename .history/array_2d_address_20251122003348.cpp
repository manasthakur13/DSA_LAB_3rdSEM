// Author: Manas Thakur, Roll No. 241475

/*
   Program 8:
   Calculate address of an element in a 2D array using row-major and column-major.
*/

/*
   Approach:
   Used address formulas for 2D arrays.
   Row-major: address = base + ((i * cols) + j) * size
   Column-major: address = base + ((j * rows) + i) * size
   User provides base address, dimensions, element position and element size.
*/

#include <iostream>
using namespace std;

// Purpose: Calculate address of element at (i,j) in row-major order
// Logic: In row-major, elements are stored row by row, address = base + ((i * cols) + j) * size
int calculateRowMajor(int base, int rows, int cols, int i, int j, int size) {
    return base + ((i * cols) + j) * size;  // Calculate row-major address using formula
}

// Purpose: Calculate address of element at (i,j) in column-major order
// Logic: In column-major, elements are stored column by column, address = base + ((j * rows) + i) * size
int calculateColMajor(int base, int rows, int cols, int i, int j, int size) {
    return base + ((j * rows) + i) * size;  // Calculate column-major address using formula
}

int main() {
    int choice;
    int base, rows, cols, i, j, size;

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- 2D Array Address Calculator ---\n";
        cout << "1. Calculate Address (Row-Major)\n";
        cout << "2. Calculate Address (Column-Major)\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // If user chooses row-major
            cout << "Enter base address: ";
            cin >> base;  // Get base address from user
            cout << "Enter number of rows: ";
            cin >> rows;  // Get number of rows
            cout << "Enter number of columns: ";
            cin >> cols;  // Get number of columns
            cout << "Enter row index i: ";
            cin >> i;  // Get row index
            cout << "Enter column index j: ";
            cin >> j;  // Get column index
            cout << "Enter element size (bytes): ";
            cin >> size;  // Get element size

            int address = calculateRowMajor(base, rows, cols, i, j, size);  // Calculate address
            cout << "Address (Row-Major) = " << address << "\n";  // Display calculated address
        }
        else if (choice == 2) {  // If user chooses column-major
            cout << "Enter base address: ";
            cin >> base;  // Get base address from user
            cout << "Enter number of rows: ";
            cin >> rows;  // Get number of rows
            cout << "Enter number of columns: ";
            cin >> cols;  // Get number of columns
            cout << "Enter row index i: ";
            cin >> i;  // Get row index
            cout << "Enter column index j: ";
            cin >> j;  // Get column index
            cout << "Enter element size (bytes): ";
            cin >> size;  // Get element size

            int address = calculateColMajor(base, rows, cols, i, j, size);  // Calculate address
            cout << "Address (Column-Major) = " << address << "\n";  // Display calculated address
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


