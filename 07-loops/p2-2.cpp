#include <iostream>

using namespace std;

int main() {
    int n, x = 0;

    cin >> n;

    while (x <= n) {
        if (x % 8 == 0)
            cout << x << ' ';
        else if (x % 3 == 0 && x % 4 == 0)
            cout << x << ' ';
        x++;
    }
    
    cout << '\n';
    return 0;
}