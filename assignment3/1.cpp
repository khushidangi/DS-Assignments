#include <iostream>
using namespace std;

const int MAX = 100;

class Stack {
public:
    int arr[MAX];
    int top = -1; // stack starts empty

    int isEmpty() {
        return top == -1 ? 1 : 0;
    }

    int isFull() {
        return top == MAX - 1 ? 1 : 0;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
        } else {
            top++;
            arr[top] = val;
            cout << val << " pushed to stack.\n";
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
        } else {
            cout << arr[top] << " popped from stack.\n";
            top--;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1; // indicates empty
        } else {
            return arr[top];
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, val;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek (Top element)\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                val = s.peek();
                if (val != -1)
                    cout << "Top element: " << val << endl;
                break;
            case 4:
                if (s.isEmpty())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;
            case 5:
                if (s.isFull())
                    cout << "Stack is full.\n";
                else
                    cout << "Stack is not full.\n";
                break;
            case 6:
                s.display();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 7);

    return 0;
}
