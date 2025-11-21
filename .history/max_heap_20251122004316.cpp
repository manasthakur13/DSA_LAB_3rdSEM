// Author: Manas Thakur, Roll No. 241475

/*
   Program 18:
   Build a max heap and perform heapify operation.
*/

/*
   Approach:
   Used array to store heap elements.
   For node at index i: left child at 2*i+1, right at 2*i+2, parent at (i-1)/2.
   Max heap: parent >= children.
   Heapify: adjust node to maintain heap property.
   Build heap by heapifying all non-leaf nodes.
*/

#include <iostream>
using namespace std;

const int MAX = 100;  // Maximum size of heap

// Class: MaxHeap
// Purpose: Implement max heap data structure
class MaxHeap {
private:
    int arr[MAX];  // Array to store heap
    int size;  // Number of elements in heap

    // Purpose: Move node down to maintain heap property
    // Logic: Compare with children, swap with larger, recurse if swapped
    void heapifyDown(int pos) {
        int largest = pos;  // Assume pos is the largest
        int left = 2 * pos + 1;  // Calculate left child position
        int right = 2 * pos + 2;  // Calculate right child position

        if (left < size && arr[left] > arr[largest]) {  // If left child is larger than largest
            largest = left;  // Update largest to left child
        }
        if (right < size && arr[right] > arr[largest]) {  // If right child is larger than largest
            largest = right;  // Update largest to right child
        }

        if (largest != pos) {  // If largest is not pos (element needs to move down)
            int temp = arr[pos];  // Store current element
            arr[pos] = arr[largest];  // Place largest element at pos
            arr[largest] = temp;  // Place original element at largest position
            heapifyDown(largest);  // Recursively heapify at new position
        }
    }

    // Purpose: Move node up to maintain heap property
    // Logic: Compare with parent, swap if greater, recurse
    void heapifyUp(int pos) {
        if (pos == 0) {  // If we're at root (position 0)
            return;  // Exit function
        }
        int parent = (pos - 1) / 2;  // Calculate parent position
        if (arr[pos] > arr[parent]) {  // If current element is larger than parent
            int temp = arr[pos];  // Store current element
            arr[pos] = arr[parent];  // Place parent at current position
            arr[parent] = temp;  // Place current element at parent position
            heapifyUp(parent);  // Recursively heapify at parent position
        }
    }

public:
    // Purpose: Initialize empty heap
    // Logic: Set size to 0
    MaxHeap() {
        size = 0;  // No elements initially
    }

    // Purpose: Insert element into heap
    // Logic: Add at end, heapify up to maintain property
    void insert(int value) {
        if (size >= MAX) {  // If heap is full
            cout << "Heap overflow!\n";
            return;  // Exit function
        }
        arr[size] = value;  // Add element at end
        heapifyUp(size);  // Heapify up from new position
        size++;  // Increase heap size
    }

    // Purpose: Remove and return maximum element
    // Logic: Store root, move last to root, heapify down
    int extractMax() {
        if (size == 0) {  // If heap is empty
            return -1;  // Return -1 indicating failure
        }
        int max = arr[0];  // Store root (maximum element)
        arr[0] = arr[size - 1];  // Move last element to root
        size--;  // Decrease heap size
        heapifyDown(0);  // Heapify down from root
        return max;  // Return maximum element
    }

    // Purpose: Build heap from array of elements
    // Logic: Copy elements, heapify from middle to root
    void buildHeap(int data[], int n) {
        size = n;  // Set heap size to n
        for (int i = 0; i < n; i++) {  // Loop through all elements
            arr[i] = data[i];  // Copy element to heap array
        }
        // Heapify from last non-leaf node to root
        for (int i = (n / 2) - 1; i >= 0; i--) {  // Loop backwards from middle
            heapifyDown(i);  // Heapify down at each position
        }
    }

    // Purpose: Display heap elements
    // Logic: Print all elements
    void displayHeap() {
        if (size == 0) {  // If heap is empty
            cout << "Heap is empty.\n";
            return;  // Exit function
        }
        cout << "Heap: ";
        for (int i = 0; i < size; i++) {  // Loop through all elements
            cout << arr[i] << " ";  // Print each element
        }
        cout << "\n";
    }
};

int main() {
    MaxHeap heap;  // Create heap object
    int choice, value, n, res;

    while (true) {  // Infinite loop for menu-driven program
        cout << "\n--- Max Heap Menu ---\n";
        cout << "1. Insert Element\n";
        cout << "2. Extract Maximum\n";
        cout << "3. Build Heap from Array\n";
        cout << "4. Display Heap\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // If user chooses to insert
            cout << "Enter value: ";
            cin >> value;  // Get value from user
            heap.insert(value);  // Insert value into heap
            cout << "Inserted " << value << " successfully.\n";
        }
        else if (choice == 2) {  // If user chooses to extract maximum
            res = heap.extractMax();  // Extract maximum element
            if (res != -1) {  // If extraction was successful
                cout << "Maximum extracted: " << res << "\n";
            } else {  // If extraction failed
                cout << "Heap is empty!\n";
            }
        }
        else if (choice == 3) {  // If user chooses to build heap
            cout << "Enter number of elements: ";
            cin >> n;  // Get number of elements
            int temp[MAX];  // Create temporary array
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++) {  // Loop to input all elements
                cin >> temp[i];  // Read element
            }
            heap.buildHeap(temp, n);  // Build heap from array
            cout << "Heap built successfully.\n";
        }
        else if (choice == 4) {  // If user chooses to display
            heap.displayHeap();  // Display heap
        }
        else if (choice == 5) {  // If user chooses to exit
            break;  // Exit the while loop and end program
        }
        else {  // If user enters invalid choice
            cout << "Invalid choice!\n";
        }
    }

    return 0;  // Program ends successfully
}