#include <iostream>

using namespace std;

int main() {
    int x = 1, n, i = 1;

    cin >> n;

    while (i <= n) {
        while (x <= (n + 1 - i)) {
            cout << '*';
            x++;
        }
        x = 1;
        cout << '\n';
        i++;
    }
    return 0;
}