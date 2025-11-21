// Author: Manas Thakur, Roll No. 241475

/*
   Program 2:
   Recursive factorial of a number.
*/

/*
   Approach:
   Used simple recursion for factorial.
   Base case: 0! = 1.
   Main only prints the value returned by the function.
*/

#include <iostream>
using namespace std;

// Purpose: Calculate factorial of a number using recursion
// Logic: Base case returns 1 when n = 0, otherwise returns n * factorial(n-1)
long long factorial(int n) {
    if (n == 0) {  // If n is 0, factorial is 1 (base case)
        return 1;  // Base case: 0! = 1
    }
    return n * factorial(n - 1);  // Multiply n with factorial of (n-1)
}

int main() {
    int choice, n;

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- Factorial Menu ---\n";
        cout << "1. Find Factorial\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // If user chooses to find factorial
            cout << "Enter a number: ";
            cin >> n;  // Get number from user
            cout << "Factorial = " << factorial(n) << "\n";  // Calculate and display factorial
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

