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
void display() {
    if (!head) {
        cout << "List is empty";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data;  
}
int main() {
    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(x);
    }
    display();
    return 0;
}