#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = NULL;
void insert(int val) {
    Node* n = new Node();
    n->data = val;
    if (!head) {
        head = n;
        n->next = n;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = n;
    n->next = head;
}
int sizeCLL() {
    if (!head) return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}
int main() {
    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(x);
    }
    cout << "Size of Circular Linked List: " << sizeCLL();
    return 0;
}