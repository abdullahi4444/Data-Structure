#include <iostream> 
using namespace std; 
#define MAX 100  // Maximum size of the stack 
class Stack { 
private: 
	int arr[MAX]; 
	int top; 
public: 
	Stack() { 
		top = -1; 
	} 
	// Check if the stack is empty 
	bool isEmpty() { 
		return top == -1; 
	} 
	// Check if the stack is full 
	bool isFull() { 
		return top == MAX - 1; 
	} 
	 
	    // Push operation 
	    void push(int value) { 
	        if (isFull()) { 
	            cout << "Stack Overflow! Cannot push " << value << endl; 
	        } else { 
	            top++; 
	            arr[top] = value; 
	            cout << value << " pushed to stack." << endl; 
	        } 
	    } 
	 
	    // Pop operation 
	    void pop() { 
	        if (isEmpty()) { 
	            cout << "Stack Underflow! Cannot pop." << endl; 
	        } else { 
	            cout << arr[top] << " popped from stack." << endl; 
	            top--; 
	        } 
	    } 
	 
	    // Peek (Top) operation 
	    void peek() { 
	        if (isEmpty()) { 
	            cout << "Stack is empty. No top element." << endl; 
	        } else { 
	            cout << "Top element: " << arr[top] << endl; 
	        } 
	    } 
	 
	    // Display the stack 
	    void display() { 
	        if (isEmpty()) { 
	            cout << "Stack is empty." << endl; 
	        } else { 
	            cout << "Stack elements (top to bottom): "; 
	            for (int i = top; i >= 0; i--) { 
	                cout << arr[i] << " "; 
	            } 
	            cout << endl; 
	        } 
	    } 
}; 
 
int main() { 
    Stack s; 
    int choice, value; 
 
    do { 
        cout << "\n--- Stack Operations ---" << endl; 
        cout << "1. Push" << endl; 
        cout << "2. Pop" << endl; 
        cout << "3. Peek" << endl; 
        cout << "4. isEmpty" << endl; 
        cout << "5. isFull" << endl; 
        cout << "6. Display" << endl; 
        cout << "0. Exit" << endl; 
 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
        case 1: 
            cout << "Enter value to push: "; 
            cin >> value; 
            s.push(value); 
            break; 
        case 2: 
            s.pop(); 
            break; 
        case 3: 
            s.peek(); 
            break; 
        case 4: 
            cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl; 
            break; 
        case 5: 
            cout << (s.isFull() ? "Stack is full." : "Stack is not full.") << endl; 
            break; 
        case 6: 
            s.display(); 
            break; 
        case 0: 
            cout << "Exiting program." << endl; 
            break; 
        default: 
            cout << "Invalid choice. Please try again." << endl; 
        } 
 
    } while (choice != 0); 
 
    return 0; 
} 
