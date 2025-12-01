#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int v) { data = v; left = right = NULL; }
};
// Insert (no duplicates)
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;  // Skip duplicate
}
// Find Minimum Value Node (for deleting)
Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}
// Delete a node
Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* r = root->right;
            delete root;
            return r;
        }
        else if (!root->right) {
            Node* l = root->left;
            delete root;
            return l;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
// Maximum depth (height of tree)
int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
// Minimum depth
int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}
// Inorder Traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    Node* root = NULL;
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        root = insert(root, x);
    }
    cout << "Inorder: ";
    inorder(root); cout << endl;
    cout << "Delete element: ";
    cin >> x;
    root = deleteNode(root, x);
    cout << "Inorder after delete: ";
    inorder(root); cout << endl;
    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;
return 0;
}