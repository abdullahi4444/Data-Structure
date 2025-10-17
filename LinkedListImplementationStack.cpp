#include <iostream> 
using namespace std; 
// Node structure for linked list 
struct Node { 
int data; 
Node* next; 
}; 
// Stack class using linked list 
class Stack { 
private: 
Node* top; 
public: 
Stack() { 
top = nullptr; 
} 
// Check if stack is empty 
bool isEmpty() { 
return top == nullptr; 
} 
// Push operation 
    void push(int value) { 
        Node* newNode = new Node(); 
        newNode->data = value; 
        newNode->next = top; 
        top = newNode; 
        cout << value << " pushed to stack." << endl; 
    } 
 
    // Pop operation 
    void pop() { 
        if (isEmpty()) { 
            cout << "Stack Underflow! Cannot pop." << endl; 
            return; 
        } 
 
        Node* temp = top; 
        cout << top->data << " popped from stack." << endl; 
        top = top->next; 
        delete temp; 
    } 
 
    // Peek (Top) operation 
    void peek() { 
        if (isEmpty()) { 
            cout << "Stack is empty. No top element." << endl; 
        } else { 
            cout << "Top element: " << top->data << endl; 
        } 
    } 
 
    // Display stack 
    void display() { 
        if (isEmpty()) { 
            cout << "Stack is empty." << endl; 
        } else { 
            cout << "Stack elements (top to bottom): "; 
            Node* temp = top; 
            while (temp != nullptr) { 
                cout << temp->data << " "; 
                temp = temp->next; 
            } 
            cout << endl; 
        } 
    } 
 
    // Destructor to clean memory 
    ~Stack() { 
        while (!isEmpty()) { 
            pop(); 
        } 
    } 
}; 
 
// Main program with console interface 
int main() { 
    Stack s; 
    int choice, value; 
 
    do { 
        cout << "\n--- Stack Operations (Linked List) ---" << endl; 
        cout << "1. Push" << endl; 
        cout << "2. Pop" << endl; 
        cout << "3. Peek" << endl; 
        cout << "4. isEmpty" << endl; 
        cout << "5. Display" << endl; 
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
