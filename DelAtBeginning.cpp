#include <iostream>
using namespace std;

int main() {
    int n, array[10];
    cout << "Enter the size of the array: ";
    cin >> n;
	
	
    // Check for valid array size
    if(n <= 0 || n > 10) {
        cout << "Invalid size. The size should be between 1 and 10." << endl;
        return 1;
    }

    cout << "Enter elements in the array: ";
    for (int i = 0; i < n; i++)
        cin >> array[i];
    
    // Check if there's more than one element for deletion
    if (n == 1) {
        cout << "Only one element in the array. No elements left after deletion." << endl;
        return 0; 
    }
    
    // Deleting the first element by shifting all elements one position to the left
    n--;
    
    for (int i = 0; i < n; i++)
        array[i] = array[i + 1];

    cout << "\nAfter deletion: ";
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
    return 0;
}


