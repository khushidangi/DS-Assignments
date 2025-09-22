#include <iostream>
using namespace std;

const int MAX = 100;

class Queue {
public:
    int arr[MAX];
    int front = -1;
    int rear = -1;

    int isEmpty() {
        return front == -1 ? 1 : 0;
    }

    int isFull() {
        return rear == MAX - 1 ? 1 : 0;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow\n";
        } else {
            if (front == -1) front = 0;
            rear++;
            arr[rear] = val;
            cout << val << " enqueued\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
        } else {
            cout << arr[front] << " dequeued\n";
            front++;
            if (front > rear) {
                front = rear = -1;
            }
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        } else {
            return arr[front];
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                value = q.peek();
                if (value != -1) cout << "Front element: " << value << endl;
                break;
            case 4:
                if (q.isEmpty()) cout << "Queue is empty\n";
                else cout << "Queue is not empty\n";
                break;
            case 5:
                if (q.isFull()) cout << "Queue is full\n";
                else cout << "Queue is not full\n";
                break;
            case 6:
                q.display();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 7);

    return 0;
}
