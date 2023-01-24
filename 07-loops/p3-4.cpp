#include <iostream>

using namespace std;

int main() {
    int t, n, a, x, y, z, temp;
    long long sum = 0;

    cin >> t;

    x = 0;
    while (x < t) {
        cin >> n;
        y = 0;
        sum = 0;
        while (y < n) {
            cin >> a;
            z = 0;
            temp = 1;
            while (z <= y) {
                temp *= a;
                z++;
            }
            sum += temp;
            y++;
        }
        cout << sum << endl;
        x++;
    }
    return 0;
}