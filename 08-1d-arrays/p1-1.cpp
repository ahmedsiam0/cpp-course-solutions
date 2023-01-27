#include <iostream>

using namespace std;

int main() {
    int n, b;
    bool inc = true;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            inc = false;
            break;
        }
    }

    if (inc)
        cout << "YES";
    else
        cout << "NO";
    cout << '\n';
    return 0;
}