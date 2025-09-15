#include <iostream>
#include <queue>
using namespace std;

class StackOneQ {
    queue<int> q;
public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (!q.empty()) q.pop();
        else cout << "Stack is empty\n";
    }
    int top() {
        if (!q.empty()) return q.front();
        return -1;
    }
    bool empty() {
        return q.empty();
    }
};

int main() {
    StackOneQ st;
    st.push(5);
    st.push(15);
    st.push(25);

    cout << st.top() << endl; // 25
    st.pop();
    cout << st.top() << endl; // 15
    return 0;
}
