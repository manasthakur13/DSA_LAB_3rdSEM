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

const int MAX = 100;

class MaxHeap {
private:
    int arr[MAX];
    int size;

    void heapifyDown(int pos) {
        int smallest = pos;
        int left = 2 * pos + 1;
        int right = 2 * pos + 2;

        if (left < size && arr[left] > arr[smallest]) {
            smallest = left;
        }
        if (right < size && arr[right] > arr[smallest]) {
            smallest = right;
        }

        if (smallest != pos) {
            int temp = arr[pos];
            arr[pos] = arr[smallest];
            arr[smallest] = temp;
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int pos) {
        if (pos == 0) {
            return;
        }
        int parent = (pos - 1) / 2;
        if (arr[pos] > arr[parent]) {
            int temp = arr[pos];
            arr[pos] = arr[parent];
            arr[parent] = temp;
            heapifyUp(parent);
        }
    }

public:
    MaxHeap() {
        size = 0;
    }

    void insert(int value) {
        if (size >= MAX) {
            cout << "Heap overflow!\n";
            return;
        }
        arr[size] = value;
        heapifyUp(size);
        size++;
    }

    int extractMax() {
        if (size == 0) {
            return -1;
        }
        int max = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
        return max;
    }

    void buildHeap(int data[], int n) {
        size = n;
        for (int i = 0; i < n; i++) {
            arr[i] = data[i];
        }
        for (int i = (n / 2) - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    void displayHeap() {
        if (size == 0) {
            cout << "Heap is empty.\n";
            return;
        }
        cout << "Heap: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    MaxHeap heap;
    int choice, value, n, res;

    while (true) {
        cout << "\n--- Max Heap Menu ---\n";
        cout << "1. Insert Element\n";
        cout << "2. Extract Maximum\n";
        cout << "3. Build Heap from Array\n";
        cout << "4. Display Heap\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            heap.insert(value);
            cout << "Inserted " << value << " successfully.\n";
        }
        else if (choice == 2) {
            res = heap.extractMax();
            if (res != -1) {
                cout << "Maximum extracted: " << res << "\n";
            } else {
                cout << "Heap is empty!\n";
            }
        }
        else if (choice == 3) {
            cout << "Enter number of elements: ";
            cin >> n;
            int temp[MAX];
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++) {
                cin >> temp[i];
            }
            heap.buildHeap(temp, n);
            cout << "Heap built successfully.\n";
        }
        else if (choice == 4) {
            heap.displayHeap();
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
