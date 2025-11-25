#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int v) {
    Node* p = new Node;
    p->data = v;
    p->left = p->right = NULL;
    return p;
}

void preorder(Node* r) {
    if (r == NULL) return;
    cout << r->data << " ";
    preorder(r->left);
    preorder(r->right);
}

void inorder(Node* r) {
    if (r == NULL) return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

void postorder(Node* r) {
    if (r == NULL) return;
    postorder(r->left);
    postorder(r->right);
    cout << r->data << " ";
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<"Preorder: "; preorder(root); cout<<endl;
    cout<<"Inorder: "; inorder(root); cout<<endl;
    cout<<"Postorder: "; postorder(root); cout<<endl;
}
