#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = 6;

    for (int i = 0; i < n; i++) q.push(arr[i]);

    int half = n / 2;
    queue<int> firstHalf;

    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

   
    while (!firstHalf.empty()) {
        cout << firstHalf.front() << " ";
        firstHalf.pop();
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
