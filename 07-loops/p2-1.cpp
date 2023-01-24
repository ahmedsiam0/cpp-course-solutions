#include <iostream>

using namespace std;

int main() {
    int n, x = 0, i = 0;

    cin >> n;

    while (x < n) {
        while (i < (n - 1 - x)) {
            cout << ' ';
            i++;
        }
        i = 0;
        while (i < (2 * x + 1)) {
            cout << '*';
            i++;
        }
        i = 0;
        cout << '\n';
        x++;
    }
    x = 0;
    while (x < n) {
        while (i < x) {
            cout << ' ';
            i++;
        }
        i = 0;
        while (i < 2 * (n - x) - 1) {
            cout << '*';
            i++;
        }
        i = 0;
        cout << '\n';
        x++;
    }

    return 0;
}