#include <iostream>
using namespace std;

class StackTwoQueues {
public:
    int q1[100], q2[100];
    int front1 = 0, rear1 = 0;
    int front2 = 0, rear2 = 0;

    int isEmpty() {
        return front1 == rear1 ? 1 : 0;
    }

    void enqueue1(int val) {
        q1[rear1++] = val;
    }

    int dequeue1() {
        return q1[front1++];
    }

    void enqueue2(int val) {
        q2[rear2++] = val;
    }

    int dequeue2() {
        return q2[front2++];
    }

    void push(int val) {
        enqueue2(val);
        while (front1 < rear1) {
            enqueue2(dequeue1());
        }
        swap(q1, q2);
        swap(front1, front2);
        swap(rear1, rear2);
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
        } else {
            cout << q1[front1++] << " popped\n";
            if (front1 == rear1) front1 = rear1 = 0;
        }
    }

    int top() {
        if (isEmpty()) return -1;
        return q1[front1];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = front1; i < rear1; i++) cout << q1[i] << " ";
        cout << endl;
    }
};

int main() {
    StackTwoQueues stack;
    int choice, val;

    do {
        cout << "\n--- Stack Using Two Queues ---\n";
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
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 5);

    return 0;
}
