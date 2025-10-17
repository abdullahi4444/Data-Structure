#include <iostream>
#include <queue>
using namespace std;

// ========== 1. Simple Queue ==========
class SimpleQueue {
    int arr[100], front, rear;
public:
    SimpleQueue() : front(0), rear(0) {}

    void enqueue(int x) {
        if (rear == 100) {
            cout << "Queue is full!\n";
            return;
        }
        arr[rear++] = x;
    }

    void dequeue() {
        if (front == rear)
            cout << "Queue is empty!\n";
        else
            cout << "Removed: " << arr[front++] << endl;
    }

    void display() {
        if (front == rear) {
            cout << "Queue is empty!\n";
            return;
        }
        for (int i = front; i < rear; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// ========== 2. Circular Queue ==========
class CircularQueue {
    int arr[100], front, rear, size;
public:
    CircularQueue() : front(-1), rear(-1), size(100) {}

    void enqueue(int x) {
        if ((rear + 1) % size == front) {
            cout << "Circular Queue is full!\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = x;
    }

    void dequeue() {
        if (front == -1)
            cout << "Circular Queue is empty!\n";
        else {
            cout << "Removed: " << arr[front] << endl;
            if (front == rear)
                front = rear = -1;
            else
                front = (front + 1) % size;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty!\n";
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

// ========== 3. Double Ended Queue ==========
class Deque {
    int arr[100], front, rear, size;
public:
    Deque() : front(-1), rear(-1), size(100) {}

    void insertFront(int x) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
            cout << "Deque is full!\n";
        else {
            if (front == -1) front = rear = 0;
            else if (front == 0) front = size - 1;
            else front--;
            arr[front] = x;
        }
    }

    void insertRear(int x) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
            cout << "Deque is full!\n";
        else {
            if (front == -1) front = rear = 0;
            else if (rear == size - 1) rear = 0;
            else rear++;
            arr[rear] = x;
        }
    }

    void deleteFront() {
        if (front == -1)
            cout << "Deque is empty!\n";
        else {
            cout << "Removed from front: " << arr[front] << endl;
            if (front == rear)
                front = rear = -1;
            else if (front == size - 1) front = 0;
            else front++;
        }
    }

    void deleteRear() {
        if (front == -1)
            cout << "Deque is empty!\n";
        else {
            cout << "Removed from rear: " << arr[rear] << endl;
            if (front == rear)
                front = rear = -1;
            else if (rear == 0) rear = size - 1;
            else rear--;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Deque is empty!\n";
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

// ========== 4. Priority Queue (Max-Heap) ==========
class PriorityQueue {
    priority_queue<int> pq;
public:
    void enqueue(int x) {
        pq.push(x);
    }

    void dequeue() {
        if (pq.empty())
            cout << "Priority Queue is empty!\n";
        else {
            cout << "Removed: " << pq.top() << endl;
            pq.pop();
        }
    }

    void display() {
        if (pq.empty()) {
            cout << "Priority Queue is empty!\n";
            return;
        }
        priority_queue<int> temp = pq;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

// ========== Menus ==========
void simpleQueueMenu() {
    SimpleQueue q;
    int ch, val;
    do {
        cout << "\n--- Simple Queue ---\n1. Enqueue\n2. Dequeue\n3. Display\n4. Back\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
        }
    } while (ch != 4);
}

void circularQueueMenu() {
    CircularQueue q;
    int ch, val;
    do {
        cout << "\n--- Circular Queue ---\n1. Enqueue\n2. Dequeue\n3. Display\n4. Back\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
        }
    } while (ch != 4);
}

void dequeMenu() {
    Deque q;
    int ch, val;
    do {
        cout << "\n--- Deque ---\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Back\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; q.insertFront(val); break;
            case 2: cout << "Enter value: "; cin >> val; q.insertRear(val); break;
            case 3: q.deleteFront(); break;
            case 4: q.deleteRear(); break;
            case 5: q.display(); break;
        }
    } while (ch != 6);
}

void priorityQueueMenu() {
    PriorityQueue q;
    int ch, val;
    do {
        cout << "\n--- Priority Queue ---\n1. Enqueue\n2. Dequeue (highest priority)\n3. Display\n4. Back\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
        }
    } while (ch != 4);
}

// ========== Main ==========
int main() {
    int choice;
    do {
        cout << "\n=== Queue Menu ===\n";
        cout << "1. Simple Queue\n";
        cout << "2. Circular Queue\n";
        cout << "3. Double Ended Queue (Deque)\n";
        cout << "4. Priority Queue\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
            case 1: simpleQueueMenu(); break;
            case 2: circularQueueMenu(); break;
            case 3: dequeMenu(); break;
            case 4: priorityQueueMenu(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

