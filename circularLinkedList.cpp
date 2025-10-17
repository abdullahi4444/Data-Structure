#include <iostream>
#ifndef nullptr
#define nullptr 0
#endif
using namespace std;

// Node structure
class Node {
public:
    int data;  // Stores the value of the node
    Node* next;  // Pointer to the next node in the circular linked list

    // Constructor to initialize a new node with a given value
    Node(int value) {
        data = value;
        next = nullptr;  // Initially, the next pointer is set to null
    }
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* head;  // Pointer to the first node of the list
public:
    // Constructor to initialize an empty list
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);  // Create a new node
        if (!head) {  // If the list is empty
            head = newNode;
            newNode->next = head;  // Point the node to itself to maintain circular structure
            return;
        }
        Node* temp = head;
        while (temp->next != head)  // Traverse to the last node
            temp = temp->next;
        temp->next = newNode;  // Point the last node to the new node
        newNode->next = head;  // Point the new node to the old head
        head = newNode;  // Update head to the new node
        cout << "Inserted " << value << " at the beginning.\n"; 
    }

    // Insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);  // Create a new node
        if (!head) {  // If the list is empty
            head = newNode;
            newNode->next = head;  // Maintain circular structure
            return;
        }
        Node* temp = head;
        while (temp->next != head)  // Traverse to the last node
            temp = temp->next;
        temp->next = newNode;  // Link last node to new node
        newNode->next = head;  // Link new node back to head
        cout << "Inserted " << value << " at the end.\n";
    }

    // Insert a node at a specific position
    void insertAtPosition(int value, int pos) {
    	if (pos <= 0) {
            cout << "Invalid position!\n";
            return;
        }
        if (pos <= 1) {  // If position is 1 or less, insert at the beginning
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; temp->next != head && i < pos - 1; i++)  // Traverse to (pos-1)th node
            temp = temp->next;
        if (temp == nullptr || temp->next == head) {
                cout << "Position out of range!\n";
                return;
    	}
        newNode->next = temp->next;  // Point new node to next node of the temp
        temp->next = newNode;  // Point previous node to new node
        cout << "Inserted " << value << " at position " << pos << ".\n"; 
    }

    // Delete the first node of the list
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == head) {  // If only one node exists
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != head)  // Traverse to the last node
            temp = temp->next;
        temp->next = head->next;  // Link last node to second node (next the head not the head)
        cout << "Deleted " << head->data << " from the beginning." << endl;
        delete head;  // Delete old head
        head = temp->next;  // Update head to new first node
    }

    // Delete the last node of the list
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == head) {  // If only one node exists
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != head) {  // Traverse to the last node
            prev = temp;  //the node previous the temp node = prev
            temp = temp->next;
        }
        cout << "Deleted " << temp->data << " from the end.\n"; 
        prev->next = head;  // Link second last node to head
        delete temp;  // Delete last node
    }

    // Delete a node from a specific position
    void deleteAtPosition(int pos) {
    	if (head == nullptr || pos <= 0) {
            cout << "Invalid position or list is empty!\n";
            return;
        }
        if (pos <= 1) {  // If position is 1, delete from beginning
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        for (int i = 1; temp->next != head && i < pos; i++) {  // Traverse to position
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == head) {
            cout << "Position out of range!\n";
            return;
        }
        prev->next = temp->next;  // Link previous node to next node
        cout << "Deleted " << temp->data << " from position " << pos << ".\n";
        delete temp;  // Delete node at position
    }

    // Display the elements of the list
    void display() {
        if (!head) {  // If list is empty
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";  // Print node value
            temp = temp->next;
        } while (temp != head);  // Continue until we reach the head again
        cout << "(head)\n";
    }
};


// Main function with switch cases
int main() {
    CircularLinkedList cll;
    int choice, value, position;

    do {
        cout << "\n--- Circular Linked List Menu ---\n"; 
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
                cll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                cll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> position;
                cll.insertAtPosition(value, position);
                break;
            case 4:
                cll.deleteFromBeginning();
                break;
            case 5:
                cll.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> position;
                cll.deleteAtPosition(position);
                break;
            case 7:
                cll.display();
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

