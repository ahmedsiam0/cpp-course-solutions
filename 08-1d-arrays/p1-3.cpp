#include <iostream>

using namespace std;

int main() {
    int n, u, a;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (i == 0 || u != a) {
            cout << a << ' ';
            u = a;
        }
    }
    cout << '\n';
    return 0;
}