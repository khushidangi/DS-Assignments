#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct HNode {
    int val;
    HNode* next;
};

HNode* table[1000] = {0};

int h(int x) {
    return x % 1000;
}

bool add(int x) {
    int i = h(x);
    HNode* t = table[i];
    while (t) {
        if (t->val == x) return false;
        t = t->next;
    }
    HNode* n = new HNode;
    n->val = x;
    n->next = table[i];
    table[i] = n;
    return true;
}

bool found = false;

void dfs(Node* root) {
    if (!root || found) return;
    if (!add(root->data)) {
        found = true;
        return;
    }
    dfs(root->left);
    dfs(root->right);
}

int main() {
    Node* a = new Node{5,0,0};
    Node* b = new Node{3,0,0};
    Node* c = new Node{7,0,0};
    Node* d = new Node{3,0,0};

    a->left = b;
    a->right = c;
    b->left = d;

    dfs(a);

    if (found) cout << "Duplicates Found";
    else cout << "No Duplicates";
}
