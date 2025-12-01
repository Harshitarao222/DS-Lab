#include <iostream>
#include <limits.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int v) { data = v; left = right = NULL; }
};
Node* createTree() {
    int val;
    cin >> val;
    if (val == -1) return NULL;
    Node* root = new Node(val);
    root->left = createTree();
    root->right = createTree();
    return root;
}
bool isBST(Node* root, int minVal, int maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}
int main() {
    cout << "Enter nodes (-1 for NULL): ";
    Node* root = createTree();
    if (isBST(root, INT_MIN, INT_MAX))
        cout << "YES, it is a BST";
    else
        cout << "NO, it is NOT a BST";
return 0;
}