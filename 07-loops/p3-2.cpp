#include <iostream>

using namespace std;

int main() {
    int n, r = 0;

    cin >> n;

    while (n != 0) {
        r *= 10;
        r += n % 10;
        n /= 10;
    }

    cout << r << ' ' << 3 * r << '\n';

    return 0;
}