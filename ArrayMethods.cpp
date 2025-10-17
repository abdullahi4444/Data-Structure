#include <iostream>
using namespace std;

int main(){
	//method 1
	int a[6] = {2, 3, 5, 7, 11, 13};
	
	//method 2
	int arra[]= {2, 3, 5, 7, 11};
	
	//method 3
	int n; 
	cin >> n;
	int* array = new int[n];
	for(int i = 0; i < 5; ++i) { 
		cin >> array[i]; 
	} 
	delete[] array; 
	return 0;
	
	//method 4
	int arr[5];
	arr[0]=1;
	arr[1]=2;
	arr[2]=3;
	arr[3]=4;
	arr[4]=5;
	
	//Access element in an array
	int A[5] = {2, 3, 5, 7, 11};
	cout << A[0] << endl; 
	cout << A[1] << endl;
	cout << A[2] <<endl;
	cout << A[3] << endl;
	cout << A[4]; 
	return 0;
}
