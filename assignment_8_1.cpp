#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* insert() {
    int val;
    cin >> val;
    if(val == -1) return NULL;
    Node* root = new Node(val);
    root->left = insert();
    root->right = insert();
    return root;
}
void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node* root) {
    if(!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main() {
    cout << "Enter tree (-1 for NULL):\n";
    Node* root = insert();
    cout << "\nIn-order: ";
    inorder(root);
    cout << "\nPre-order: ";
    preorder(root);
    cout << "\nPost-order: ";
    postorder(root);
return 0;
}