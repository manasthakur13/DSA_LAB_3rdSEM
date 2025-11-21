// Author: Manas Thakur, Roll No. 241475
/*
   Program 1:
   Recursive Fibonacci series up to N terms.
*/
/*
   Approach:
   Used recursion to find Fibonacci numbers. 
   Fibonacci series starts with 0, 1 and every next term = sum of previous two.
   Example: 0 1 1 2 3 5 …
   A loop in main prints all terms one by one.
*/

#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 1) { 
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

void displayFibo(int n) {
    for (int i = 0; i < n; i++) {
        cout << fib(i) << " ";
    }
    cout << "\n";
}

int main() {
    int choice, n;

    while (true) {
        cout << "\n--- Fibonacci Menu ---\n";
        cout << "1. Generate Fibonacci Series\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter number of terms: ";
            cin >> n;
            cout << "Fibonacci series: ";
            displayFibo(n);
        }
        else if (choice == 2) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
