#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head = nullptr;

    void insertAtBeginning(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }

    void insertBeforeAfter(int target, int val, bool before) {
        Node* newNode = new Node;
        newNode->data = val;

        if (head == nullptr) return;

        if (before && head->data == target) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != target) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        if (before) {
            newNode->next = temp;
            if (prev != nullptr) prev->next = newNode;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteFromBeginning() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteSpecific(int val) {
        if (head == nullptr) return;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) temp = temp->next;

        if (temp->next == nullptr) return;

        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }

    int search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == val) return pos;
            temp = temp->next;
            pos++;
        }
        return -1;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, val, target;
    bool before;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before/after a node\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete specific node\n";
        cout << "7. Search for a node\n";
        cout << "8. Display list\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Insert before(1) or after(0): ";
                cin >> before;
                list.insertBeforeAfter(target, val, before);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter node value to delete: ";
                cin >> val;
                list.deleteSpecific(val);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> val;
                int pos;
                pos = list.search(val);
                if (pos != -1) cout << "Node found at position " << pos << endl;
                else cout << "Node not found\n";
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 9);

    return 0;
}
