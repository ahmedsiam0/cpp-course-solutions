#include <iostream>

using namespace std;

int main() {
    int x;
    char c;

    cin >> x >> c;

    while (x > 0) {
        cout << c;
        x--;
    }
    cout << '\n';
    return 0;
}