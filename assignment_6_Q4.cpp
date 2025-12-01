#include <iostream>
using namespace std;
struct Node {
    char data;
    Node *prev, *next;
};
Node* head = NULL;
Node* tail = NULL;
void insert(char c) {
    Node* n = new Node();
    n->data = c;
    n->next = NULL;
    n->prev = tail;
    if (!head) head = n;
    else tail->next = n;

    tail = n;
}
bool isPalindrome() {
    if (!head) return true;
    Node *left = head, *right = tail;
    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        insert(c);
    }
    if (isPalindrome()) 
        cout << "Palindrome";
    else 
        cout << "Not Palindrome";
    return 0;
}