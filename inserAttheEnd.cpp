#include <iostream>
using namespace std;
int main() {
    int array[10], i, values;
	cout << "Enter 5 Array Elements: ";
	
	for (i = 0; i < 5; i++)
		cin >> array[i];
		cout << "\nEnter Element to Insert: ";
		cin >> values;
	    array[i] = values;// This line will add the new element at the sixth position (index 5)
	    
	cout << "\nThe New Array is:\n";
	for (i = 0; i < 6; i++)
		cout << array[i] << " ";
	return 0;
}

