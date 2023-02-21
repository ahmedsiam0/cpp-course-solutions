#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string removeDuplicates(string s) {
    stack<char> stk;

    for (auto i : s) {
        if (stk.empty()) {
            stk.push(i);
        } else {
            if (stk.top() == i)
                stk.pop();
            else
                stk.push(i);
        }
    }
    s = "";
    while (!stk.empty())
        s.push_back(stk.top()), stk.pop();
    
    reverse(s.begin(), s.end());

    return s;
}
int main() {
    string s;

    cin >> s;

    s = removeDuplicates(s);

    cout << s << endl;
}