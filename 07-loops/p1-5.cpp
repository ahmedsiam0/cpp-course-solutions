#include <iostream>

using namespace std;

int main() {
    int n, x = 1;
    double e = 0, o = 0, se = 0, so = 0, s;

    cin >> n;

    while (x <= n) {
        cin >> s;
        if (x % 2 == 0) {
            se += s;
            e++;
        } else {
            so += s;
            o++;
        }
        x++;
    }

    cout << so / o << ' ' << se / e << endl;
    return 0;
}