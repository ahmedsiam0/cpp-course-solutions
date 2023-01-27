#include <iostream>

using namespace std;

int main() {
    int n, a, b, sumd, t, sum = 0;

    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++) {
        sumd = 0;
        t = i;
        while (t != 0) {
            sumd += t % 10;
            t /= 10;
        }
        if (sumd >= a && sumd <= b) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}
