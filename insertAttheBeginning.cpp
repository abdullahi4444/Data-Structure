#include <iostream>
#include <conio.h> > // Note: <conio.h> is specific to some compilers and may not be available on all C++ compilers
using namespace std;

int main() {
    int array[10], n, i, item;
	cout << "Enter the size of array: ";
	cin >> n;
	cout << "\nEnter Elements in array: ";
	
    for (i = 0; i < n; i++) {
		cin >> array[i];
    }
    
	cout << "\nEnter the element to insert at the beginning: ";
    cin >> item;
    
    // Increment array size
	n++; 
	
	// Shift elements to the right
    for (i = n; i > 1; i--) {
        array[i - 1] = array[i - 2];
    }
    
	// Insert the item at the beginning
	array[0] = item;
	cout << "Resultant array elements:";
	
	for (i = 0; i < n; i++) {
		cout << "\n" << array[i];
	}
	_getch();// Using _getch() from conio.h, but it's not standard C++ and not recommended
	
	return 0;
}


