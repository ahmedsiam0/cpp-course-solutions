#include <iostream>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if (s2.size() > s1.size()) {
        cout << "NO\n";
        return 0;
    }

    int j = 0;
    for (int i = 0; i < s1.size() && j < s2.size(); i++) {
        if (s1[i] == s2[j])
            j++;
    }
    if (j == s2.size())
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}