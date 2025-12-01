#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *prev, *next;
};
Node* head = NULL;
void insert(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = NULL;
    n->prev = NULL;
    if (!head) {
        head = n;
        return;
    }
   Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    n->prev = temp;
}
int sizeDLL() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}
int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(x);
    }
    cout << "Size of Doubly Linked List: " << sizeDLL();
    return 0;
}