#include <iostream>
using namespace std;

int main() {
    int array[100], pos, size, val;
    cout << "Enter size of the array: ";
    cin >> size;
    
    // Ensure the size is within the bounds of the declared array
    if (size < 1 || size > 100) {
        cout << "Size must be between 1 and 100." << endl;
        return 1;
    }
    cout << "\nEnter " << size << " elements\n";
    for (int i = 0; i < size; i++)
        cin >> array[i];

    cout << "Enter the position to insert: ";
    cin >> pos;
    
    // Ensure the position is within the bounds of the current array size
    if (pos < 1 || pos > size + 1) {
        cout << "Position must be between 1 and " << size + 1 << "." << endl;
        return 1;
    }

    cout << "Enter the value to insert: ";
    cin >> val;
    
    for (int i = size; i >= pos; i--)
        array[i] = array[i - 1];
	
	// Insert the new value
    array[pos - 1] = val;
    
    // Increment size after insertion
    size++;

    cout << "Resultant array is\n";
    for (int i = 0; i < size; i++)
        cout << array[i] << endl;

    return 0;
}



