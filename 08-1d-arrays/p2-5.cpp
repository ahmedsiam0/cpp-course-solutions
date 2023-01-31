#include <iostream>

using namespace std;

int main() {
    bool a[501] = {false};
    int n, x;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (!a[x]) {
            a[x] = true;
            cout << x << ' ';
        }
    }
    cout << '\n';
    return 0;
}