#include <iostream>

using namespace std;

int main() {
    int n, q, a;
    int y[501];

    for (int i = 0; i < 501; i++)
        y[i] = -1;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        y[a] = i;
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a;
        cout << y[a] << '\n';
    }
    return 0;
}