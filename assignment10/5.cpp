#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct HNode {
    Node* addr;
    HNode* next;
};

HNode* table[1000] = {0};

int h(Node* p) {
    return ((unsigned long long)p) % 1000;
}

bool add(Node* p) {
    int i = h(p);
    HNode* t = table[i];
    while (t) {
        if (t->addr == p) return false;
        t = t->next;
    }
    HNode* n = new HNode;
    n->addr = p;
    n->next = table[i];
    table[i] = n;
    return true;
}

bool hasLoop(Node* head) {
    Node* t = head;
    while (t) {
        if (!add(t)) return true;
        t = t->next;
    }
    return false;
}

int main() {
    Node* a = new Node{1,0};
    Node* b = new Node{2,0};
    Node* c = new Node{3,0};
    Node* d = new Node{4,0};

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;

    if (hasLoop(a)) cout<<"true";
    else cout<<"false";
}
