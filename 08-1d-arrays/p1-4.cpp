#include <iostream>

using namespace std;

int main() {
    int n;
    bool out = true;

    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - 1 - i]) {
            out = false;
            break;
        }
    }

    if (out)
        cout << "YES";
    else
        cout << "NO";
    cout << '\n';
    return 0;
}