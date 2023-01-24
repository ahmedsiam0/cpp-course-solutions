#include <iostream>

using namespace std;

int main() {
    int x, y;

    cin >> x >> y;

    while (x <= y) {
        cout << x << ' ';
        x++;
    }
    cout << endl;
    return 0;
}