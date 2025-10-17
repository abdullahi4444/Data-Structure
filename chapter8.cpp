#include <iostream>
using namespace std;

// Swap helper function
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        if (min_index != i)
            swap(arr[i], arr[min_index]);
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Quick Sort Helper - Partition
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort Helper - Merge
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// Copy array
void copyArray(int original[], int copy[], int n) {
    for (int i = 0; i < n; i++) copy[i] = original[i];
}

// Main program
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int original[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> original[i];
    }

    int arr[n];
    int choice;

    cout << "\nOriginal array: ";
    printArray(original, n);

    cout << "\nChoose Sorting Algorithm:\n";
    cout << "1. Insertion Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Quick Sort\n";
    cout << "5. Merge Sort\n";
    cout << "Enter choice (1-5): ";
    cin >> choice;

    // Copy original array to arr for sorting
    copyArray(original, arr, n);

    switch (choice) {
        case 1:
            insertionSort(arr, n);
            cout << "Sorted using Insertion Sort: ";
            break;
        case 2:
            selectionSort(arr, n);
            cout << "Sorted using Selection Sort: ";
            break;
        case 3:
            bubbleSort(arr, n);
            cout << "Sorted using Bubble Sort: ";
            break;
        case 4:
            quickSort(arr, 0, n - 1);
            cout << "Sorted using Quick Sort: ";
            break;
        case 5:
            mergeSort(arr, 0, n - 1);
            cout << "Sorted using Merge Sort: ";
            break;
        default:
            cout << "Invalid choice!";
            return 1;
    }

    printArray(arr, n);
    return 0;
}

