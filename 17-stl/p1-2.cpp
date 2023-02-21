#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct OurStack {
    queue<int> q;

    void push(int val) {
        q.push(val);
    }
    void pop() {
        if (!q.empty()) {
            q.pop();
        }
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};

int main() {
    OurStack s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.empty()) {
        cout << s.top() << endl, s.pop();
    }
}