#include <iostream>

using namespace std;

int main() {
    string s1, s2;

    cin >> s1 >> s2;

    for (int i = 0; i < s1.size() && i < s2.size(); i++) {
        if (s1[i] < s2[i]) {
            cout << "YES\n";
            return 0;
        } else if (s1[i] > s2[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    if (s1.size() <= s2.size())
        cout << "YES\n";
    else
        cout << "NO\n";
}