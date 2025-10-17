#include <iostream>
#ifndef nullptr
#define nullptr 0
#endif
using namespace std;

// Define a Node class to represent each element in the doubly linked list
struct Node {
public:
    Node* prev;    // Pointer to the previous node
    int data;      // Stores the value of the node
    Node* next;    // Pointer to the next node

    // Constructor to initialize the node with a given value
    Node(int value) {
        data = value;   // Assigns the value to the node
        next = prev = nullptr;  // Initially, next and prev pointers are NULL
    }
};

// Define a DoublyLinkedList class to manage the list
class DoublyLinkedList {
private:
    Node* head;  // Pointer to the first node (head) of the list

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() {
        head = nullptr;  // Initially, the list is empty
    }

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);  // Create a new node
        if (head) {   // If list is not empty
            newNode->next = head;  // Point new node's next to current head
            head->prev = newNode;  // Update current head's prev to new node
        }
        head = newNode;  // Update head to the new node
        cout << "Inserted " << value << " at the beginning.\n"; 
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);  // Create a new node
        if (!head) {  // If the list is empty
            head = newNode;  // Set new node as head
            return;
        }
        Node* temp = head;  // Temporary pointer to traverse the list
        while (temp->next) temp = temp->next;  // Move to the last node
        temp->next = newNode;  // Link last node's next to new node
        newNode->prev = temp;  // Set new node's prev to last node
        cout << "Inserted " << value << " at the end.\n";
    }

    // Function to insert a node at a specific position
    void insertAtPosition(int value, int pos) {
    	if (pos <= 0) { 
            cout << "Invalid position!\n"; 
            return; 
        }
        if (pos <= 1) {  // If position is 1 or less, insert at beginning
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);  // Create a new node
        Node* temp = head;  // Temporary pointer to traverse the list
        for (int i = 1; temp && i < pos - 1; i++)  // Move to (pos-1)th node
            temp = temp->next;
        if (temp == nullptr) { 
            cout << "Position out of range!\n"; 
            return; 
        } 
        newNode->next = temp->next;  // Link new node's next to temp's next
        if (temp->next) temp->next->prev = newNode;  // Update next node's prev
        temp->next = newNode;  // Set temp's next to new node
        newNode->prev = temp;  // Set new node's prev to temp
        cout << "Inserted " << value << " at position " << pos << ".\n"; 
    }

    // Function to delete a node from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;  // Store head node
        head = head->next;  // Move head to the next node
        if (head) head->prev = nullptr;  // Update new head's prev to NULL
        cout << "Deleted " << temp->data << " from the beginning.\n"; 
        delete temp;  // Free memory of deleted node
    }

    // Function to delete a node from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        if (!head->next) {  // If only one node exists
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;  // Temporary pointer to traverse the list
        while (temp->next) temp = temp->next;  // Move to the last node
        cout << "Deleted " << temp->data << " from the end.\n"; 
        temp->prev->next = nullptr;  // Remove reference to last node
        delete temp;  // Free memory of deleted node
    }

    // Function to delete a node from a specific position
    void deleteAtPosition(int pos) {
    	if (head == nullptr || pos <= 0) { 
            cout << "Invalid position or list is empty!\n"; 
            return; 
        } 
        if (pos <= 1) {  // If position is 1, delete from beginning
            deleteFromBeginning();
            return;
        }
        Node* temp = head;  // Temporary pointer to traverse the list
        for (int i = 1; temp && i < pos; i++)  // Move to the pos-th node
            temp = temp->next;
        if (temp == NULL) {
            cout << "Position out of range!\n";
            return;
        }
        if (temp->prev) temp->prev->next = temp->next;  // Adjust previous node
        if (temp->next) temp->next->prev = temp->prev;  // Adjust next node
        cout << "Deleted " << temp->data << " from position " << pos << ".\n";
        delete temp;  // Free memory of deleted node
    }

    // Function to display the list
    void display() {
        Node* temp = head;  // Temporary pointer to traverse the list
        while (temp) {  // Loop until we reach NULL
            cout << temp->data << " <-> ";  // Print the node's data
            temp = temp->next;  // Move to the next node
        }
        cout << "NULL\n";  // Indicate the end of the list
    }
};

// Main function with switch cases
int main() {
    DoublyLinkedList dll;
    int choice, value, position;

    do {
	    cout << "\n--- Doubly Linked List Menu ---\n"; 
        cout << "1. Insert at Beginning\n"; 
        cout << "2. Insert at End\n"; 
        cout << "3. Insert at Position\n"; 
        cout << "4. Delete from Beginning\n"; 
        cout << "5. Delete from End\n"; 
        cout << "6. Delete from Position\n"; 
        cout << "7. Display List\n"; 
        cout << "8. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                dll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> position;
                dll.insertAtPosition(value, position);
                break;
            case 4:
                dll.deleteFromBeginning();
                break;
            case 5:
                dll.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> position;
                dll.deleteAtPosition(position);
                break;
            case 7:
                dll.display();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    return 0;
}

