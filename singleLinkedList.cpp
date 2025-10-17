#include <iostream> 
#ifndef nullptr
#define nullptr 0
#endif
using namespace std; 

// Node structure 
struct Node { 
    int data; 
    Node* next; 
    Node(int val) { 
        data = val; 
        next = nullptr; 
    }
}; 

// Singly Linked List class 
class SinglyLinkedList {
private: 
    Node* head; 
public: 
    // Constructor 
    SinglyLinkedList() { 
        head = nullptr; 
    } 

    // Insert at the beginning 
    void insertAtBeginning(int val) { 
        Node* newNode = new Node(val); 
        newNode->next = head; 
        head = newNode; 
        cout << "Inserted " << val << " at the beginning.\n"; 
    } 

    // Insert at the end 
    void insertAtEnd(int val) { 
        Node* newNode = new Node(val); 
        if (head == nullptr) { 
            head = newNode; 
        } else { 
            Node* temp = head; 
            while (temp->next != nullptr) { 
                temp = temp->next; 
            } 
            temp->next = newNode; 
        }
        cout << "Inserted " << val << " at the end.\n"; 
    } 

    // Insert at a given position (1-based index) 
    void insertAtPosition(int val, int pos) { 
        if (pos <= 0) { 
            cout << "Invalid position!\n"; 
            return; 
        } 
        Node* newNode = new Node(val); 
        if (pos == 1) { 
            newNode->next = head; 
            head = newNode; 
            cout << "Inserted " << val << " at position " << pos << ".\n"; 
            return; 
        } 
        Node* temp = head; 
        for (int i = 1; temp != nullptr && i < pos - 1; i++) { 
            temp = temp->next; 
        } 
        if (temp == nullptr) { 
            cout << "Position out of range!\n"; 
            return; 
        } 
        newNode->next = temp->next; 
        temp->next = newNode; 
        cout << "Inserted " << val << " at position " << pos << ".\n"; 
    } 

    // Delete from the beginning 
    void deleteFromBeginning() { 
        if (head == nullptr) { 
            cout << "List is empty!\n"; 
            return; 
        } 
        Node* temp = head; 
        head = head->next; 
        cout << "Deleted " << temp->data << " from the beginning.\n"; 
        delete temp; 
    } 

    // Delete from the end 
    void deleteFromEnd() { 
        if (head == nullptr) { 
            cout << "List is empty!\n"; 
            return; 
        } 
        if (head->next == nullptr) { 
            cout << "Deleted " << head->data << " from the end.\n"; 
            delete head; 
            head = nullptr; // Fix: Ensure head is set to nullptr
            return; 
        } 
        Node* temp = head; 
        while (temp->next->next != nullptr) { 
            temp = temp->next; 
        } 
        cout << "Deleted " << temp->next->data << " from the end.\n"; 
        delete temp->next; 
        temp->next = nullptr; 
    } 

    // Delete from a given position 
    void deleteAtPosition(int pos) { 
        if (head == nullptr || pos <= 0) { 
            cout << "Invalid position or list is empty!\n"; 
            return; 
        } 
        Node* temp = head; 
        if (pos == 1) { 
            head = head->next; 
            cout << "Deleted " << temp->data << " from position " << pos << ".\n"; 
            delete temp; 
            return; 
        } 
        Node* prev = nullptr; 
        for (int i = 1; temp != nullptr && i < pos; i++) { 
            prev = temp; 
            temp = temp->next; 
        } 
        if (temp == nullptr) { 
            cout << "Position out of range!\n"; 
            return; 
        } 
        prev->next = temp->next; 
        cout << "Deleted " << temp->data << " from position " << pos << ".\n"; 
        delete temp; 
    } 

    // Display the linked list 
    void display() { 
        if (head == nullptr) { 
            cout << "List is empty!\n"; 
            return; 
        } 
        Node* temp = head; 
        cout << "Linked List: "; 
        while (temp != nullptr) { 
            cout << temp->data << " -> "; 
            temp = temp->next; 
        } 
        cout << "NULL\n"; 
    } 

    // Destructor to free memory 
    ~SinglyLinkedList() { 
        Node* temp; 
        while (head != nullptr) { 
            temp = head; 
            head = head->next; 
            delete temp; 
        } 
    } 
}; 
// Main function 
int main() { 
    SinglyLinkedList list; 
    int choice, value, position; 
 
    while (true) { 
        cout << "\n--- Singly Linked List Menu ---\n"; 
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
                list.insertAtBeginning(value); 
                break; 
            case 2: 
                cout << "Enter value: "; 
                cin >> value; 
                list.insertAtEnd(value); 
                break; 
            case 3: 
                cout << "Enter value and position: "; 
                cin >> value >> position; 
                list.insertAtPosition(value, position); 
                break; 
            case 4: 
                list.deleteFromBeginning(); 
                break; 
            case 5: 
                list.deleteFromEnd(); 
                break; 
            case 6: 
                cout << "Enter position: "; 
                cin >> position; 
                list.deleteAtPosition(position); 
                break; 
            case 7: 
                list.display(); 
                break; 
            case 8: 
                cout << "Exiting program...\n"; 
                return 0; 
            default: 
                cout << "Invalid choice! Please try again.\n"; 
        } 
    } 
}
