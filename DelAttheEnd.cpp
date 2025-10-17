#include <iostream>
using namespace std;

int main() {
    int n, array[10];
    cout << "Enter the size of the array (1-10): ";
    cin >> n;
    
    if (n < 1 || n > 10) {
        cout << "Invalid array size. Please enter a value between 1 and 10." << endl;
        return 1;
    }

    cout << "Enter elements in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

	// Assuming deletion of the last element
    n--;  // Adjust the size to simulate deletion

    cout << "\nAfter deletion, array elements are: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

