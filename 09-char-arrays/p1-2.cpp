#include <iostream>

using namespace std;

int main() {
    string s1, s2;
    bool is_prefix = true;
    cin >> s1 >> s2;

    if (s2.size() > s1.size()) {
        cout << "NO\n";
        return 0;
    }
    
    for (int i = 1; i <= s2.size(); i++) {
        if (s1[s1.size() - i] != s2[s2.size() - i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}