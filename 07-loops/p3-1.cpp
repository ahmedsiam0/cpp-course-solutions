#include <iostream>

using namespace std;

int main() {
    int n, i = 0;
    bool out;
    string s;

    cin >> n;

    while (i < n) {
        cin >> s;
        out = (s == "NO") ||
              (s == "No") ||
              (s == "nO") ||
              (s == "no") ||
              (s == "ON") ||
              (s == "oN") ||
              (s == "On") ||
              (s == "on");
        
        if (out)
            cout << s << ' ';
        i++;
    }
    cout << '\n';
    return 0;
}