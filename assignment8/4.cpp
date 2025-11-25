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

Node* insert(Node* r, int v) {
    if (r == NULL)
        return newNode(v);
    if (v < r->data)
        r->left = insert(r->left, v);
    else
        r->right = insert(r->right, v);
    return r;
}

bool isBST(Node* r, Node* min = NULL, Node* max = NULL) {
    if (r == NULL)
        return true;
    if (min != NULL && r->data <= min->data)
        return false;
    if (max != NULL && r->data >= max->data)
        return false;
    return isBST(r->left, min, r) && isBST(r->right, r, max);
}

int main() {
    Node* root = NULL;
    int a[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++)
        root = insert(root, a[i]);

    if (isBST(root))
        cout << "BST";
    else
        cout << "Not BST";
}
