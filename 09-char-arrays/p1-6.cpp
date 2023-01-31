#include <iostream>

using namespace std;

int main() {
    string s;
    bool same = false;

    cin >> s;

    cout << s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] != s[i])
            cout << ' ';
        cout << s[i];
    }
    cout << '\n';
}