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
    return base + ((i * cols) + j) * size;
}

// Purpose: Calculate address of element at (i,j) in column-major order
// Logic: In column-major, elements are stored column by column, address = base + ((j * rows) + i) * size
int calculateColMajor(int base, int rows, int cols, int i, int j, int size) {
    return base + ((j * rows) + i) * size;
}

int main() {
    int choice;
    int base, rows, cols, i, j, size;

    while (true) {
        cout << "\n--- 2D Array Address Calculator ---\n";
        cout << "1. Calculate Address (Row-Major)\n";
        cout << "2. Calculate Address (Column-Major)\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter base address: ";
            cin >> base;
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;
            cout << "Enter row index i: ";
            cin >> i;
            cout << "Enter column index j: ";
            cin >> j;
            cout << "Enter element size (bytes): ";
            cin >> size;

            int address = calculateRowMajor(base, rows, cols, i, j, size);
            cout << "Address (Row-Major) = " << address << "\n";
        }
        else if (choice == 2) {
            cout << "Enter base address: ";
            cin >> base;
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;
            cout << "Enter row index i: ";
            cin >> i;
            cout << "Enter column index j: ";
            cin >> j;
            cout << "Enter element size (bytes): ";
            cin >> size;

            int address = calculateColMajor(base, rows, cols, i, j, size);
            cout << "Address (Column-Major) = " << address << "\n";
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

