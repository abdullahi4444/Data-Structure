#include <iostream> 
using namespace std; 
int main() 
{ 
	int a = 5; int *b; 
	int **c; b = &a; c = &b; 
	cout << "value of a = " << a << endl; 
	cout << "value of a = " << *(&a) << endl; 
	cout << "value of a = " << *b << endl; 
	cout << "value of a = " << **c << endl; 
	cout << "value of b = address of a = " << b << endl; 
	cout << "value of c = address of b = " << c << endl; 
	cout << "address of a = " << &a << endl; 
	cout << "address of a = " << b << endl;
	 cout << "address of a = " << *c << endl; 
	cout << "address of b = " << &b << endl; 
	cout << "address of b = " << c << endl; 
	cout << "address of c = " << &c << endl; 
	
	return 0; 
}
