#include <iostream>
#ifndef nullptr
#define nullptr 0
#endif
using namespace std;

//************************************************************************************************************************************//
//*********************************************  SINGLY LINKED LIST ******************************************************************//
//************************************************************************************************************************************//
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
void sllContainer(){
    SinglyLinkedList list; 
    int choice, value, position; 

    while (true) { 
        cout << "\033[3;33m";
	    cout << "\n    						 ---Singly Linked List Menu---  \n\n";
	    cout << "			+--------------------------+-----------------------+--------------------------+\n";
	    cout << "			|    1. Insert at Begin    |    2. Insert at End   |     3. Insert at Pos.    |\n";
	    cout << "			+--------------------------+-----------------------+--------------------------+\n";
	    cout << "			|    4. Delete from Begin  |    5. Delete from End |     6. Delete from Pos   |\n";
	    cout << "			+----------------------------------------+------------------------------------+\n";
	    cout << "			|    7. Display List                     |               8. Exit              |\n";
	    cout << "			+----------------------------------------+------------------------------------+\n";
	    cout << "\033[0m";
        cout << "\nEnter your choice: "; 
        cin >> choice; 

        if (cin.fail()) { // Handle invalid input
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

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
                cout << "Exiting...\n";
                return; // Exit function properly
            default: 
                cout << "Invalid choice! Please try again.\n"; 
        } 
    } 
}



//************************************************************************************************************************************//
//*********************************************  DOUBLY LINKED LIST ******************************************************************//
//************************************************************************************************************************************//
// Node structure
class Node2 {
public:
    int data;
    Node2* next;
    Node2* prev;

    Node2(int value) {
        data = value;
        next = prev = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node2* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node2* newNode = new Node2(value);
        if (head) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
        cout << "Inserted " << value << " at the beginning.\n"; 
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node2* newNode = new Node2(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node2* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        cout << "Inserted " << value << " at the end.\n";
    }

    // Insert at a specific position
    void insertAtPosition(int value, int pos) {
    	if (pos <= 0) { 
            cout << "Invalid position!\n"; 
            return; 
        }
        if (pos <= 1) {
            insertAtBeginning(value);
            return;
        }
        Node2* newNode = new Node2(value);
        Node2* temp = head;
        for (int i = 1; temp && i < pos - 1; i++)
            temp = temp->next;
        if (temp == nullptr) { 
            cout << "Position out of range!\n"; 
            return; 
        }
        if (!temp) return;
        newNode->next = temp->next;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        cout << "Inserted " << value << " at position " << pos << ".\n";
    }

    // Delete from the beginning
    void deleteFromBeginning() {
    	if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        if (!head) return;
        Node2* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        cout << "Deleted " << temp->data << " from the beginning.\n"; 
        delete temp;
    }

    // Delete from the end
    void deleteFromEnd() {
    	if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
	    if (!head) return; // List is empty
	    if (!head->next) {  // Only one node in the list
	        delete head;
	        head = nullptr;
	        return;
	    }
	    // Traverse to the last node
	    Node2* temp = head;
	    while (temp->next) temp = temp->next;
	    // Print the data of the node before deleting
	    cout << "Deleted " << temp->data << " from the end.\n"; 
	    // Delete the last node
	    temp->prev->next = nullptr;  // Remove the reference to the last node
	    delete temp;
	}

    // Delete from a specific position
    void deleteAtPosition(int pos) {
    	if (head == nullptr || pos <= 0) { 
            cout << "Invalid position or list is empty!\n"; 
            return; 
        } 
        if (pos <= 1) {
            deleteFromBeginning();
            return;
        }
        Node2* temp = head;
        for (int i = 1; temp && i < pos; i++)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Position out of range!\n";
            return;
        }
        if (!temp) return;
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        cout << "Deleted " << temp->data << " from position " << pos << ".\n";
        delete temp;
    }

    // Display the list
    void display() {
        Node2* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
void dllContainer(){
    DoublyLinkedList dll;
    int choice, value, position;

    while (true) {
        cout << "\033[3;35m";
	    cout << "\n    						 ---Doubly Linked List Menu---  \n\n";
	    cout << "			+--------------------------+-----------------------+--------------------------+\n";
	    cout << "			|    1. Insert at Begin    |    2. Insert at End   |     3. Insert at Pos.    |\n";
	    cout << "			+--------------------------+-----------------------+--------------------------+\n";
	    cout << "			|    4. Delete from Begin  |    5. Delete from End |     6. Delete from Pos   |\n";
	    cout << "			+----------------------------------------+------------------------------------+\n";
	    cout << "			|    7. Display List                     |               8. Exit              |\n";
	    cout << "			+----------------------------------------+------------------------------------+\n";
	    cout << "\033[0m";
        cout << "\nEnter your choice: "; 
        cin >> choice;

        if (cin.fail()) { // Handle invalid input
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

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
                return; // Exit function properly
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

//**************************************************************************************************************************************//
//*********************************************  CIRCULAR LINKED LIST ******************************************************************//
//**************************************************************************************************************************************//
// Node structure
class Node3 {
public:
    int data;
    Node3* next;

    Node3(int value) {
        data = value;
        next = nullptr;
    }
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node3* head;
public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node3* newNode = new Node3(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node3* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node3* newNode = new Node3(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node3* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    // Insert at a specific position
    void insertAtPosition(int value, int pos) {
    	if (pos <= 0) {
            cout << "Invalid position!\n";
            return;
        }
        if (pos <= 1) {
            insertAtBeginning(value);
            return;
        }
        Node3* newNode = new Node3(value);
        Node3* temp = head;
        for (int i = 1; temp->next != head && i < pos - 1; i++)
            temp = temp->next;
        if (temp == nullptr || temp->next == head) {
                cout << "Position out of range!\n";
                return;
    	}
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete from the beginning
    void deleteFromBeginning() {
    	if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node3* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = head->next;
        delete head;
        head = temp->next;
    }

    // Delete from the end
    void deleteFromEnd() {
    	if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node3* temp = head;
        Node3* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
    }

    // Delete from a specific position
    void deleteAtPosition(int pos) {
    	if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        if (pos <= 1) {
            deleteFromBeginning();
            return;
        }
        Node3* temp = head;
        Node3* prev = nullptr;
        for (int i = 1; temp->next != head && i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp || temp == head) return;
        prev->next = temp->next;
        delete temp;
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node3* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }
};
void cllContainer(){
	CircularLinkedList cll;
    int choice, value, position;

    do {
        cout << "\033[3;36m";
	    cout << "\n    						 ---Circular Linked List Menu---  \n\n";
	    cout << "			+--------------------------+-----------------------+--------------------------+\n";
	    cout << "			|    1. Insert at Begin    |    2. Insert at End   |     3. Insert at Pos.    |\n";
	    cout << "			+--------------------------+-----------------------+--------------------------+\n";
	    cout << "			|    4. Delete from Begin  |    5. Delete from End |     6. Delete from Pos   |\n";
	    cout << "			+----------------------------------------+------------------------------------+\n";
	    cout << "			|    7. Display List                     |               8. Exit              |\n";
	    cout << "			+----------------------------------------+------------------------------------+\n";
	    cout << "\033[0m";
        cout << "\nEnter your choice: "; 
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
}

//************************************************************************************************************************************//
//*********************************************  DOUBLY CIRCULAR LINKED LIST ******************************************************************//
//************************************************************************************************************************************//
// Node structure
class Node4 {
public:
    int data;
    Node4* next;
    Node4* prev;
    
    Node4(int value) {
        data = value;
        next = prev = nullptr;
    }
};

// Doubly Circular Linked List class
class DoublyCircularLinkedList {
private:
    Node4* head;
public:
    DoublyCircularLinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node4* newNode = new Node4(value);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        Node4* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
        cout << "Inserted " << value << " at the beginning.\n";
    }

    // Insert at the end
    void insertAtEnd(int value) {
        if (!head) {
            insertAtBeginning(value);
            return;
        }
        Node4* newNode = new Node4(value);
        Node4* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        cout << "Inserted " << value << " at the end.\n";
    }

    // Insert at a specific position
    void insertAtPosition(int value, int pos) {
    	if (pos <= 0) {
            cout << "Invalid position!\n";
            return;
        }
        if (pos <= 1) {
            insertAtBeginning(value);
            return;
        }
        Node4* newNode = new Node4(value);
        Node4* temp = head;
        for (int i = 1; temp->next != head && i < pos - 1; i++)
            temp = temp->next;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << pos << "\n";
    }

    // Delete from the beginning
    void deleteFromBeginning() {
    	if (!head) {
            cout << "List is empty!\n";
            return;
        }
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node4* tail = head->prev;
        Node4* temp = head;
        tail->next = head->next;
        head->next->prev = tail;
        head = head->next;
        cout << "Deleted " << temp->data << " from the beginning.\n";
        delete temp;
    }

    // Delete from the end
    void deleteFromEnd() {
    	if (!head) {
            cout << "List is empty!\n";
            return;
        }
        if (!head) return;
        if (head->next == head) {
            deleteFromBeginning();
            return;
        }
        Node4* tail = head->prev;
        tail->prev->next = head;
        head->prev = tail->prev;
        cout << "Deleted " << tail->data << " from the end.\n";
        delete tail;
    }

    // Delete from a specific position
    void deleteAtPosition(int pos) {
    	if (!head || pos <= 0) {
            cout << "Invalid position or list is empty!\n";
            return;
        }
        if (pos <= 1) {
            deleteFromBeginning();
            return;
        }
        Node4* temp = head;
        for (int i = 1; temp->next != head && i < pos; i++)
            temp = temp->next;
        if (temp == head) return;
        if (temp == head) {
            cout << "Position out of range!\n";
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        cout << "Deleted " << temp->data << " from position " << pos << "\n";
        delete temp;
    }

    // Display list
    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node4* temp = head;
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }
};
void dcllContainer(){
	DoublyCircularLinkedList dcll;
    int choice, value, position;

    do {
        cout << "\033[3;32m";
	    cout << "\n    						 ---Doubly Circular Linked List Menu---  \n\n";
	    cout << "			+--------------------------+-----------------------+--------------------------+\n";
	    cout << "			|    1. Insert at Begin    |    2. Insert at End   |     3. Insert at Pos.    |\n";
	    cout << "			+--------------------------+-----------------------+--------------------------+\n";
	    cout << "			|    4. Delete from Begin  |    5. Delete from End |     6. Delete from Pos   |\n";
	    cout << "			+----------------------------------------+------------------------------------+\n";
	    cout << "			|    7. Display List                     |               8. Exit              |\n";
	    cout << "			+----------------------------------------+------------------------------------+\n";
	    cout << "\033[0m";
        cout << "\nEnter your choice: "; 
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
}

//************************************************************************************************************************************//
//*********************************************  MAIN ******************************************************************//
//************************************************************************************************************************************//

void displayHeader() {
    cout << "\033[5;31m"; 
    cout << "+-------------------------------------+------------------------------------------+-------------------------------------+" << endl;
    cout << "|   Abdullahhi Abdiweli Adam          |           Jazeera University             |              Teacher: Anisa         |" << endl;
    cout << "+-------------------------------------+------------------------------------------+-------------------------------------+" << endl;
    cout << "\033[0m"; 
}

int main() {
    int choice;
    displayHeader();
    while (true) {
	    cout << "\033[7;34m";
        cout << "\nLinked List Types :\n";
        cout << "\033[0m";
        
        cout << "\033[3;33m";
        cout << "  1. Singly Linked List\n";
        cout << "\033[0m";
        
        cout << "\033[3;35m";
        cout << "  2. Doubly Linked List\n";
        cout << "\033[0m";
        
        cout << "\033[3;36m";
        cout << "  3. Circular Linked List\n";
        cout << "\033[0m";
        
        cout << "\033[3;32m";
        cout << "  4. Doubly Circular Linked List\n";
        cout << "\033[0m";
        
		cout << "\033[3;31m";
        cout << "  5. Exit\n";
        cout << "\033[0m";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                sllContainer();
                break;
            case 2:
                dllContainer();
                break;
            case 3:
                cllContainer();
                break;
            case 4:
                dcllContainer();
                break;
            case 5:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
};
