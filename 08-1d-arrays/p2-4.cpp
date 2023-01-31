#include <iostream>

using namespace std;

int main() {
    int a[10] = {0};
    int n, x;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;

        if (x == 0)
            a[0]++;
        
        while (x != 0) {
            a[(x % 10)]++;
            x /= 10;
        }
    }
    
    for (int i = 0; i < 10; i++) {
        cout << i << ' ' << a[i] << '\n';
    }
    return 0;
}