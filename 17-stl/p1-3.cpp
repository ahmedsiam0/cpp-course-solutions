#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int reverse_num(int num) {
    stack<int> s;
    while (num != 0) {
        s.push(num % 10);
        num /= 10;
    }
    int i = 1;
    while (!s.empty()) {
        num += s.top() * i;
        s.pop();
        i *= 10;
    }

    return num;
}

int main() {
    int num = 1432;
    num = reverse_num(num);
    cout << num << endl;
}