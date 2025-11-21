#include <iostream>
using namespace std;

void heapify(int a[], int n, int i, bool isMax) {
    int extreme = i;
    int l = 2*i + 1, r = 2*i + 2;
    if (isMax) {
        if (l < n && a[l] > a[extreme]) extreme = l;
        if (r < n && a[r] > a[extreme]) extreme = r;
    } else {
        if (l < n && a[l] < a[extreme]) extreme = l;
        if (r < n && a[r] < a[extreme]) extreme = r;
    }
    if (extreme != i) {
        swap(a[i], a[extreme]);
        heapify(a, n, extreme, isMax);
    }
}

void heapSort(int a[], int n, bool isMax) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(a, n, i, isMax);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0, isMax);
    }
}

int main() {
    int n, choice;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << "\n1. Increasing Order\n2. Decreasing Order\nEnter choice: ";
    cin >> choice;
    heapSort(a, n, (choice == 1));
    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
