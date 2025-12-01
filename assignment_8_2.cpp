#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
Node(int v) { data = v; left = right = NULL; }
};
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}
// (a) Search – Recursive
Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}
// (a) Search – Non-Recursive
Node* searchNonRec(Node* root, int key) {
    while (root) {
        if (root->data == key) return root;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}
// (b) Minimum element
Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}
// (c) Maximum element
Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}
// (d) In-order Successor
Node* inorderSuccessor(Node* root, Node* x) {
    if (x->right) return findMin(x->right);
    Node* succ = NULL;
    while (root) {
        if (x->data < root->data) {
            succ = root;
            root = root->left;
        } else if (x->data > root->data) {
            root = root->right;
        } else break;
    }
    return succ;
}

// (e) In-order Predecessor
Node* inorderPredecessor(Node* root, Node* x) {
    if (x->left) return findMax(x->left);
    Node* pred = NULL;
    while (root) {
        if (x->data > root->data) {
            pred = root;
            root = root->right;
        } else if (x->data < root->data) {
            root = root->left;
        } else break;
    }
    return pred;
}
int main() {
    Node* root = NULL;
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        root = insert(root, x);
    }
    int key;
    cout << "Search: "; 
    cin >> key;
    if (searchRec(root, key)) cout << "Found (Recursive)\n";
    else cout << "Not Found (Recursive)\n";
    if (searchNonRec(root, key)) cout << "Found (Non-recursive)\n";
    else cout << "Not Found (Non-recursive)\n";
    cout << "Min: " << findMin(root)->data << endl;
    cout << "Max: " << findMax(root)->data << endl;
    Node* temp = searchRec(root, key);
    if (temp) {
        Node* s = inorderSuccessor(root, temp);
        Node* p = inorderPredecessor(root, temp);
        if (s) cout << "Successor: " << s->data << endl;
        else cout << "No Successor\n";
        if (p) cout << "Predecessor: " << p->data << endl;
        else cout << "No Predecessor\n";
    }
return 0;