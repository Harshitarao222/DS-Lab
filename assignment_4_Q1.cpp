#include <iostream>
using namespace std;
class Queue {
   int* arr;
   int front, rear, capacity;
public:
   Queue(int size) {
       capacity = size;
       arr = new int[capacity];
       front = -1;
       rear = -1;
   }
   bool isEmpty() {
       return (front == -1);
   }
   bool isFull() {
       return (rear == capacity - 1);
   }
   void enqueue(int x) {
       if (isFull()) {
           cout << "The queue is already full!" << endl;
           return;
       }
       if (isEmpty()) {
           front = 0; // first element
       }
       arr[++rear] = x;
       cout << x << " inserted into queue" << endl;
   }
   int dequeue() {
       if (isEmpty()) {
           cout << "The queue is empty!!" << endl;
           return -1;
       }
       int val = arr[front];
       if (front == rear) {
           // only one element left
           front = rear = -1;
       } else {
           front++;
       }
       cout << val << " removed from queue" << endl;
       return val;
   }
   int peek() {
       if (isEmpty()) {
           cout << "Queue empty!!" << endl;
           return -1;
       }
       return arr[front];
   }
   void display() {
       if (isEmpty()) {
           cout << "Queue is empty." << endl;
           return;
       }
       cout << "The elements are: ";
       for (int i = front; i <= rear; i++) {
           cout << arr[i] << " ";
       }
       cout << endl;
   }
};
int main() {
   int n;
   cout << "Enter size of queue: ";
   cin >> n;
   Queue q(n);
   int choice, val;


   do {
       cout << "\n--- Queue Menu ---\n";
       cout << "1. Enqueue (Insert)\n";
       cout << "2. Dequeue (Remove)\n";
       cout << "3. Peek (Front element)\n";
       cout << "4. isEmpty()\n";
       cout << "5. isFull()\n";
       cout << "6. Display Queue\n";
       cout << "7. Exit\n";
       cout << "Enter your choice: ";
       cin >> choice;


       switch (choice) {
           case 1:
               cout << "Value to insert: ";
               cin >> val;
               q.enqueue(val);
               break;
           case 2:
               q.dequeue();
               break;
           case 3:
               val = q.peek();
         if (val != -1) cout << "Front element is: " << val << endl;
               break;
           case 4:
               if (q.isEmpty())
                   cout << "Queue is empty" << endl;
               else
                   cout << "Queue is not empty" << endl;
               break;
           case 5:
               if (q.isFull())
                   cout << "The queue is full" << endl;
               else
                   cout << "The queue is not full" << endl;
               break;
           case 6:
               q.display();
               break;
           case 7:
               cout << "Exit" << endl;
               break;
           default:
               cout << "Invalid choice! Try again." << endl;
       }
   } while (choice != 7);


   return 0;
}
