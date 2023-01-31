#include <iostream>

using namespace std;

int main() {
    string s;
    int n = 0;

    cin >> s;

    int digit;
    for (int i = 0; i < s.size(); i++) {
        digit = s[i] - '0';
        n = (n * 10) + digit;
    }

    cout << n << ' ' << n * 3 << '\n';
}