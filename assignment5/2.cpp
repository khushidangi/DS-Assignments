#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head = nullptr;

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

    int countKey(int key) {
        Node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            if (temp->data == key) count++;
            temp = temp->next;
        }
        return count;
    }

    void deleteAll(int key) {
        while (head != nullptr && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->data == key) {
                Node* delNode = temp->next;
                temp->next = temp->next->next;
                delete delNode;
            } else {
                temp = temp->next;
            }
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int values[] = {1, 2, 1, 2, 1, 3, 1};
    int n = 7;
    int key = 1;

    for (int i = 0; i < n; i++) {
        list.insertAtEnd(values[i]);
    }

    int count = list.countKey(key);
    cout << "Count: " << count << endl;

    list.deleteAll(key);

    cout << "Updated Linked List: ";
    list.display();

    return 0;
}
