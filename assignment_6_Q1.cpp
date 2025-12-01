#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
};
Node* head = NULL;
void insertFirst(int val) {
    Node* n = new Node();
    n->data = val;
    if (!head) {
        n->next = n;
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != head) temp = temp->next;
    n->next = head;
    temp->next = n;
    head = n;
}
void insertLast(int val) {
    Node* n = new Node();
    n->data = val;
    if (!head) {
        n->next = n;
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = n;
    n->next = head;
}
void insertAfter(int key, int val) {
    if (!head) return;
    Node* temp = head;
    do {
        if (temp->data == key) {
            Node* n = new Node();
            n->data = val;
            n->next = temp->next;
            temp->next = n;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}
void insertBefore(int key, int val) {
    if (!head) return;
    if (head->data == key) {
        insertFirst(val);
        return;
    }
    Node* temp = head;
    do {
        if (temp->next != head && temp->next->data == key) {
            Node* n = new Node();
            n->data = val;
            n->next = temp->next;
            temp->next = n;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}
void deleteNode(int key) {
    if (!head) return;
    if (head->data == key) {
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        Node* del = head;
        head = head->next;
        temp->next = head;
        delete del;
        return;
    }
    Node* temp = head;
    do {
        if (temp->next != head && temp->next->data == key) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}
Node* search(int key) {
    if (!head) return NULL;
    Node* temp = head;
    do {
        if (temp->data == key) return temp;
        temp = temp->next;
    } while (temp != head);
    return NULL;
}
void display() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main() {
    int ch, val, key;
    do {
        cout << "\nCircular Linked List Menu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete a node\n";
        cout << "6. Search a node\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1:
                cin >> val;
                insertFirst(val);
                break;
            case 2:
                cin >> val;
                insertLast(val);
                break;
            case 3:
                cin >> key >> val;
                insertAfter(key, val);
                break;
            case 4:
                cin >> key >> val;
                insertBefore(key, val);
                break;
            case 5:
                cin >> key;
                deleteNode(key);
                break;
            case 6:
                cin >> key;
                if (search(key)) cout << "Found\n";
                else cout << "Not Found\n";
                break;
            case 7:
                display();
                break;
        }
    } while (ch != 8);
    return 0;
}