#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int v) {
    Node* x = new Node;
    x->data = v;
    x->left = x->right = NULL; 
    return x;
}

Node* insertNode(Node* r, int v) {
    if (!r) return newNode(v);
    if (v < r->data) r->left = insertNode(r->left, v);
    else if (v > r->data) r->right = insertNode(r->right, v);
    return r;
}

Node* searchRec(Node* r, int v) {
    if (!r || r->data == v) return r;
    if (v < r->data) return searchRec(r->left, v);
    return searchRec(r->right, v);
}

Node* searchNonRec(Node* r, int v) {
    while (r) {
        if (r->data == v) return r;
        if (v < r->data) r = r->left;
        else r = r->right;
    }
    return NULL;
}

Node* findMin(Node* r) {
    while (r && r->left) r = r->left;
    return r;
}

Node* findMax(Node* r) {
    while (r && r->right) r = r->right;
    return r;
}

Node* inorderSucc(Node* r, Node* t) {
    Node* s = NULL;
    while (r) {
        if (t->data < r->data) { s = r; r = r->left; }
        else r = r->right;
    }
    return s;
}

Node* inorderPred(Node* r, Node* t) {
    Node* p = NULL;
    while (r) {
        if (t->data > r->data) { p = r; r = r->right; }
        else r = r->left;
    }
    return p;
}

int main() {
    Node* root = NULL;
    int arr[5] = {50, 30, 70, 20, 40};
    for (int i = 0; i < 5; i++) root = insertNode(root, arr[i]);

    cout << (searchRec(root, 40) ? "Found Recursive" : "Not Found") << endl;
    cout << (searchNonRec(root, 70) ? "Found Non-Recursive" : "Not Found") << endl;

    cout << "Min: " << findMin(root)->data << endl;
    cout << "Max: " << findMax(root)->data << endl;

    Node* x = searchNonRec(root, 50);
    cout << "Successor: " << inorderSucc(root, x)->data << endl;
    cout << "Predecessor: " << inorderPred(root, x)->data << endl;
}
