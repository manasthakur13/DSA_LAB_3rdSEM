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

long long factorial(int n) {
    if (n == 0) { 
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int choice, n;

    while (true) {
        cout << "\n--- Factorial Menu ---\n";
        cout << "1. Find Factorial\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter a number: ";
            cin >> n;
            cout << "Factorial = " << factorial(n) << "\n";
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
