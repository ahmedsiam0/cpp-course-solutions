#include <iostream>

using namespace std;

int main() {
    int n, x = 0, i = 0;

    cin >> n;

    while (i < n) {
        if (x % 3 == 0 && x % 4 != 0) {
            cout << x << ' ';
            i++;
        }
        x++;
    }
    
    cout << '\n';
    return 0;
}