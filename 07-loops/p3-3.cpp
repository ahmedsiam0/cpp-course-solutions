#include <iostream>

using namespace std;

int main() {
    int n, m, i = 1, j = 1;

    cin >> n >> m;

    while (i <= n) {
        while (j <= m) {
            cout << i << " x " << j << " = " << i * j << '\n';
            j++;
        }
        j = 1;
        i++;
    }
    
    return 0;
}