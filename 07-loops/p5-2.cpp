#include <iostream>

using namespace std;

int main() {
    int t, n, a;

    cin >> t;

    for (int i = 0; i < t; i++) {
        int sum = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int k = 1;
            cin >> a;
            for (int x = 0; x <= j; x++) {
                k *= a;
            }
            sum += k;
        }
        cout << sum << endl;
    }

    return 0;
}