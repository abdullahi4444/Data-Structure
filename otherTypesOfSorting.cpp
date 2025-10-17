#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // For pow()
using namespace std;

// Function to print the array
void printArray(vector<int>& arr) {
    cout << "Sorted Array: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ============ 1. Counting Sort =============
void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> count(range, 0);
    vector<int> output(arr.size());

    // Count occurrences
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - minVal]++;

    // Cumulative count
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // Build output
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    arr = output;
}

// ============ 2. Comb Sort =============
void combSort(vector<int>& arr) {
    int gap = arr.size();
    bool swapped = true;
    while (gap != 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;

        swapped = false;

        for (int i = 0; i < arr.size() - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

// ============ 3. Shell Sort =============
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// ============ 4. Heap Sort =============
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // root
    int l = 2 * i + 1; // left
    int r = 2 * i + 2; // right

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// ============ 5. Bucket Sort =============
void bucketSort(vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int bucketCount = arr.size();

    vector<vector<int> > buckets(bucketCount);

    for (int i = 0; i < arr.size(); i++) {
        int index = (arr[i] - minVal) * (bucketCount - 1) / (maxVal - minVal);
        buckets[index].push_back(arr[i]);
    }

    arr.clear();
    for (int i = 0; i < bucketCount; i++) {
        sort(buckets[i].begin(), buckets[i].end());
        for (int j = 0; j < buckets[i].size(); j++)
            arr.push_back(buckets[i][j]);
    }
}

// ============ 6. Radix Sort =============
int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

void countingSortForRadix(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    int count[10] = {0};

    for (int i = 0; i < arr.size(); i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    arr = output;
}

void radixSort(vector<int>& arr) {
    int maxNum = getMax(arr);
    for (int exp = 1; maxNum / exp > 0; exp *= 10)
        countingSortForRadix(arr, exp);
}

// ============ 7. Cycle Sort =============
void cycleSort(vector<int>& arr) {
    int writes = 0;
    int n = arr.size();

    for (int cycleStart = 0; cycleStart <= n - 2; cycleStart++) {
        int item = arr[cycleStart];
        int pos = cycleStart;

        for (int i = cycleStart + 1; i < n; i++)
            if (arr[i] < item)
                pos++;

        if (pos == cycleStart)
            continue;

        while (item == arr[pos])
            pos++;

        if (pos != cycleStart) {
            swap(item, arr[pos]);
            writes++;
        }

        while (pos != cycleStart) {
            pos = cycleStart;
            for (int i = cycleStart + 1; i < n; i++)
                if (arr[i] < item)
                    pos++;

            while (item == arr[pos])
                pos++;

            if (item != arr[pos]) {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }
}

// Main program with menu
int main() {
    int choice;
    do {
        cout << "\n--- Sorting Algorithms Menu ---\n";
        cout << "1. Counting Sort\n";
        cout << "2. Comb Sort\n";
        cout << "3. Shell Sort\n";
        cout << "4. Heap Sort\n";
        cout << "5. Bucket Sort\n";
        cout << "6. Radix Sort\n";
        cout << "7. Cycle Sort\n";
        cout << "0. Exit\n";
        cout << "Choose an option (0-7): ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting program...\n";
            break;
        }

        int n;
        cout << "Enter number of elements: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter elements:\n";
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        switch (choice) {
            case 1: countingSort(arr); break;
            case 2: combSort(arr); break;
            case 3: shellSort(arr); break;
            case 4: heapSort(arr); break;
            case 5: bucketSort(arr); break;
            case 6: radixSort(arr); break;
            case 7: cycleSort(arr); break;
            default: cout << "Invalid choice.\n"; continue;
        }

        printArray(arr);  // Print the sorted array

    } while (choice != 0);

    return 0;
}

