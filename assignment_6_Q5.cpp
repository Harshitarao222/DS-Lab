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
    n->next = NULL;
    if (!head) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = n;
}
bool isCircular() {
    if (!head) return false;
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        if (slow == fast) return true;   // cycle found
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;  // reached NULL → not circular
}
int main() {
    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(x);
    }
    if (isCircular())
        cout << "Circular Linked List";
    else
        cout << "Not Circular";
    return 0;
}