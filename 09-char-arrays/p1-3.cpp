#include <iostream>

using namespace std;

int main() {
    string s1, s2;
    bool is_substr = true;
    cin >> s1 >> s2;

    if (s2.size() > s1.size()) {
        cout << "NO\n";
        return 0;
    }
    
    for (int i = 0; i < s1.size(); i++) {
        for(int j = 0; j < s2.size(); j++) {
            if (s1[i + j] != s2[j]) {
                is_substr = false;
                break;
            }
        }
        if (is_substr) {
            cout << "YES\n";
            return 0;
        } else {
            is_substr = true;
        }
    }
    cout << "NO\n";
    return 0;
}