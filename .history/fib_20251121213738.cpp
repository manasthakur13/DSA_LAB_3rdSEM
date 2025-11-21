// Author: Manas Thakur | Roll No: 241475

/*
    QUESTION:
    Write a program to recursively generate the Fibonacci series up to N terms.
*/

/*
    APPROACH:
    - Create a recursive function fib(n) that returns the nth Fibonacci number.
    - In main(), use a loop to print Fibonacci numbers from 0 to N−1.
    - The main function runs inside a menu-driven infinite loop.
*/

#include <iostream>
using namespace std;

// Recursive function to get Fibonacci number
int fib(int n) {
    if (n == 0) return 0;        // Base case
    if (n == 1) return 1;        // Base case
    return fib(n-1) + fib(n-2);  // Recursive definition
}

// Function to print Fibonacci series
void generateFibonacci() {
    int n;

    cout << "Enter how many terms to print: ";
    cin >> n;

    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        cout << fib(i) << " ";
    }
    cout << "\n";
}

int main() {
    while (true) {
        int choice;

        cout << "\n===== FIBONACCI MENU =====\n";
        cout << "1. Generate Fibonacci Series\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: generateFibonacci(); break;
            case 2: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}