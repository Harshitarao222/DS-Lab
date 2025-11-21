#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
    Node(int val) { 
        data = val; 
        next = NULL; 
    }
};

Node* head = NULL;

// Insert at beginning
void insertBeg(int val) {
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

// Insert at end
void insertEnd(int val) {
    Node* n = new Node(val);
    if (!head) { 
        head = n; 
        return; 
    }
    Node* temp = head;
    while (temp->next) 
        temp = temp->next;
    temp->next = n;
}

// Insert after a given node
void insertAfter(int key, int val) {
    Node* temp = head;
    while (temp && temp->data != key) 
        temp = temp->next;
    if (temp) {
        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }
}

// Insert before a given node
void insertBefore(int key, int val) {
    if (!head) return;
    if (head->data == key) { 
        insertBeg(val); 
        return; 
    }
    Node* temp = head;
    while (temp->next && temp->next->data != key) 
        temp = temp->next;
    if (temp->next) {
        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }
}

// Delete from beginning
void deleteBeg() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
void deleteEnd() {
    if (!head) return;
    if (!head->next) { 
        delete head; 
        head = NULL; 
        return; 
    }
    Node* temp = head;
    while (temp->next->next) 
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

// Delete specific node by key
void deleteNode(int key) {
    if (!head) return;
    if (head->data == key) { 
        deleteBeg(); 
        return; 
    }
    Node* temp = head;
    while (temp->next && temp->next->data != key) 
        temp = temp->next;
    if (temp->next) {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
}

// Search element
void search(int key) {
    int pos = 1;
    Node* temp = head;
    while (temp) {
        if (temp->data == key) { 
            cout << "Found at position " << pos << endl; 
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found" << endl;
}

// Display list
void display() {
    Node* temp = head;
    if (!temp) {
        cout << "List is empty" << endl;
        return;
    }
    while (temp) { 
        cout << temp->data << " "; 
        temp = temp->next; 
    }
    cout << endl;
}

// Main function
int main() {
    int ch, val, key;
    cout << "\n---- Singly Linked List Menu ----\n";
    cout << "1. Insert at Beginning\n";
    cout << "2. Insert at End\n";
    cout << "3. Insert Before\n";
    cout << "4. Insert After\n";
    cout << "5. Delete from Beginning\n";
    cout << "6. Delete from End\n";
    cout << "7. Delete Specific Node\n";
    cout << "8. Search Element\n";
    cout << "9. Display List\n";
    cout << "10. Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch(ch) {
            case 1: cout << "Enter value: "; cin >> val; insertBeg(val); break;
            case 2: cout << "Enter value: "; cin >> val; insertEnd(val); break;
            case 3: cout << "Enter key and value: "; cin >> key >> val; insertBefore(key, val); break;
            case 4: cout << "Enter key and value: "; cin >> key >> val; insertAfter(key, val); break;
            case 5: deleteBeg(); break;
            case 6: deleteEnd(); break;
            case 7: cout << "Enter key: "; cin >> key; deleteNode(key); break;
            case 8: cout << "Enter key: "; cin >> key; search(key); break;
            case 9: display(); break;
            case 10: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice, try again."; 
        }
    } while (ch != 10);

    return 0;
}
