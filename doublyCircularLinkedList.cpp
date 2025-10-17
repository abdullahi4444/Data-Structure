#include <iostream> 
#ifndef nullptr 
#define nullptr 0 
#endif
using namespace std; 

// Node structure
class Node4 {
public:
    int data; // Data stored in the node
    Node4* next; // Pointer to the next node
    Node4* prev; // Pointer to the previous node
    
    // Constructor to initialize a node with a given value
    Node4(int value) {
        data = value; // Assign value to data
        next = prev = nullptr; // Initialize pointers to null
    }
};

// Doubly Circular Linked List class
class DoublyCircularLinkedList {
private:
    Node4* head; // Pointer to the head node
public:
    // Constructor to initialize an empty list
    DoublyCircularLinkedList() {
        head = nullptr; // Set head to null
    }

    // Insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node4* newNode = new Node4(value); // Create a new node
        if (!head) { // If list is empty
            head = newNode;
            head->next = head; // Point next to itself
            head->prev = head; // Point prev to itself
            return;
        }
        Node4* tail = head->prev; // Get the last node
        newNode->next = head; // New node points to the current head
        newNode->prev = tail; // New node points to the tail
        tail->next = newNode; // Tail's next points to the new node
        head->prev = newNode; // old Head's prev points to the new node
        head = newNode; // Update head to new node
        cout << "Inserted " << value << " at the beginning.\n";
    }

    // Insert a node at the end of the list
    void insertAtEnd(int value) {
        if (!head) { // If list is empty, insert at beginning
            insertAtBeginning(value);
            return;
        }
        Node4* newNode = new Node4(value); // Create a new node
        Node4* tail = head->prev; // Get the last node
        newNode->next = head; // New node points to head
        newNode->prev = tail; // New node points to tail
        tail->next = newNode; // Tail's next points to new node
        head->prev = newNode; // Head's prev points to new node
        cout << "Inserted " << value << " at the end.\n";
    }

    // Insert a node at a specific position
    void insertAtPosition(int value, int pos) {
    	if (pos <= 0) {
            cout << "Invalid position!\n";
            return;
        }
        if (pos <= 1) { // If position is 1 or less, insert at beginning
            insertAtBeginning(value);
            return;
        }
        Node4* newNode = new Node4(value); // Create a new node
        Node4* temp = head;
        for (int i = 1; temp->next != head && i < pos - 1; i++)
            temp = temp->next; // Traverse to the desired position
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << pos << "\n";
    }

    // Delete a node from the beginning of the list
    void deleteFromBeginning() {
    	if (!head) {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == head) { // If only one node exists
            delete head;
            head = nullptr;
            return;
        }
        Node4* tail = head->prev; // Get last node
        Node4* temp = head;
        tail->next = head->next; // Update tail's next
        head->next->prev = tail; // Update next node's prev
        head = head->next; // Move head forward
        cout << "Deleted " << temp->data << " from the beginning.\n";
        delete temp; // Free memory
    }

    // Delete a node from the end of the list
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == head) { // If only one node exists
            deleteFromBeginning();
            return;
        }
        Node4* tail = head->prev; // Get last node
        tail->prev->next = head; // Update second last node's next
        head->prev = tail->prev; // Update head's prev
        cout << "Deleted " << tail->data << " from the end.\n";
        delete tail; // Free memory
    }

    // Delete a node from a specific position
    void deleteAtPosition(int pos) {
    	if (!head || pos <= 0) {
            cout << "Invalid position or list is empty!\n";
            return;
        }
        if (pos <= 1) { // If position is 1, delete from beginning
            deleteFromBeginning();
            return;
        }
        
        Node4* temp = head;
        for (int i = 1; temp->next != head && i < pos; i++)
            temp = temp->next; // Traverse to the desired position
            
        if (temp == head) {
            cout << "Position out of range!\n";
            return;
        }
        
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        cout << "Deleted " << temp->data << " from position " << pos << "\n";
        delete temp; // Free memory
    }

    // Display the list
    void display() {
        if (!head) { // If list is empty
            cout << "List is empty\n";
            return;
        }
        Node4* temp = head;
        do {
            cout << temp->data << " <-> "; // Print data
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }
};

int main() {
    DoublyCircularLinkedList dcll; // Create a list object
    int choice, value, position;
    do {
        cout << "\n--- Doubly Circular Linked List Menu ---\n"; 
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
                dcll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                dcll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> position;
                dcll.insertAtPosition(value, position);
                break;
            case 4:
                dcll.deleteFromBeginning();
                break;
            case 5:
                dcll.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> position;
                dcll.deleteAtPosition(position);
                break;
            case 7:
                dcll.display();
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
