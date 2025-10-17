#include <iostream>
using namespace std;

// Function to perform Linear Search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to perform Binary Search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid; // Found
        else if (arr[mid] < target)
            left = mid + 1; // Search right half
        else
            right = mid - 1; // Search left half
    }
    return -1; // Not found
}

int main() {
    int size, target, choice;

    // Step 1: Enter array size and elements
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Step 2: Select search type
    cout << "\nChoose search type:\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search (array must be sorted in ascending order)\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    // Step 3: Enter target to search
    cout << "Enter the value to search for: ";
    cin >> target;

    // Step 4: Call appropriate search function
    int result = -1;
    if (choice == 1) {
        result = linearSearch(arr, size, target);
        if (result != -1)
            cout << "Linear Search: Value " << target << " found at index " << result << ".\n";
        else
            cout << "Linear Search: Value " << target << " not found in the array.\n";
    } else if (choice == 2) {
        result = binarySearch(arr, size, target);
        if (result != -1)
            cout << "Binary Search: Value " << target << " found at index " << result << ".\n";
        else
            cout << "Binary Search: Value " << target << " not found in the array.\n";
    } else {
        cout << "Invalid choice. Please run the program again.\n";
    }

    return 0;
}

