#include <iostream>
using namespace std;

void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void insert(int a[], int &n, int val) {
    a[n] = val;
    int i = n;
    n++;
    while (i != 0 && a[(i-1)/2] < a[i]) {
        swap(a[i], a[(i-1)/2]);
        i = (i-1)/2;
    }
}

void deleteMax(int a[], int &n) {
    if (n == 0) return;
    cout << "Deleted: " << a[0] << endl;
    a[0] = a[n-1];
    n--;
    heapify(a, n, 0);
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[100], n = 0, ch, val;
    do {
        cout << "1.Insert  2.Delete Max  3.Display  4.Exit\n";
        cin >> ch;
        if (ch == 1) { cin >> val; insert(a, n, val); }
        else if (ch == 2) deleteMax(a, n);
        else if (ch == 3) display(a, n);
    } while (ch != 4);
    return 0;
}
