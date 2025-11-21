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

// Purpose: Calculate the nth Fibonacci number using recursion
// Logic: Base case returns n if n <= 1, otherwise returns sum of previous two terms
int fib(int n) {
    if (n <= 1) {  // If n is 0 or 1, return n itself (base case)
        return n;  // Base case: fib(0) = 0, fib(1) = 1
    }
    return fib(n - 1) + fib(n - 2);  // Recursive case: add previous two Fibonacci numbers
}

// Purpose: Display first n Fibonacci numbers
// Logic: Loop from 0 to n-1 and call fib() for each position
void displayFibo(int n) {
    for (int i = 0; i < n; i++) {  // Loop through positions 0 to n-1
        cout << fib(i) << " ";  // Calculate and print ith Fibonacci number
    }
    cout << "\n";  // New line after printing all numbers
}

int main() {
    int choice, n;

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- Fibonacci Menu ---\n";
        cout << "1. Generate Fibonacci Series\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // If user chooses to generate series
            cout << "Enter number of terms: ";
            cin >> n;  // Get number of terms from user
            cout << "Fibonacci series: ";
            displayFibo(n);  // Display n Fibonacci terms
        }
        else if (choice == 2) {  // If user chooses to exit
            break;  // Exit the while loop and end program
        }
        else {  // If user enters invalid choice
            cout << "Invalid choice!\n";
        }
    }

    return 0;  // Program ends successfully
}


