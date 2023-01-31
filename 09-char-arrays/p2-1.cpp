#include <iostream>

using namespace std;

int main() {
    string s;
    int cnt = 1;

    cin >> s;

    cout << s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == s[i]) {
            cnt++;
        } else {
            cout << cnt << '_' << s[i];
            cnt = 1;
        }
    }
    cout << cnt;
    cout << '\n';
}