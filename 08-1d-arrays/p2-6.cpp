#include <iostream>

using namespace std;

int main() {
    int a[501] = {0};
    int n, x;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < 501; i++) {
        while (a[i] != 0) {
            cout << i << ' ';
            a[i]--;
        }
    }
    cout << '\n';
    return 0;
}