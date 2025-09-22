#include <iostream>
using namespace std;

class StackOneQueue {
public:
    int q[100];
    int front = 0, rear = 0;

    int isEmpty() {
        return front == rear ? 1 : 0;
    }

    void push(int val) {
        int size = rear - front;
        q[rear++] = val;
        for (int i = 0; i < size; i++) {
            q[rear++] = q[front++];
        }
        front = 0;
        rear = size + 1;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
        } else {
            cout << q[front++] << " popped\n";
        }
    }

    int top() {
        if (isEmpty()) return -1;
        return q[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = front; i < rear; i++) cout << q[i] << " ";
        cout << endl;
    }
};

int main() {
    StackOneQueue stack;
    int choice, val;

    do {
        cout << "\n--- Stack Using One Queue ---\n";
        cout << "1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                stack.push(val);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                val = stack.top();
                if (val != -1) cout << "Top element: " << val << endl;
                else cout << "Stack is empty\n";
                break;
            case 4:
                stack.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 5);

    return 0;
}
