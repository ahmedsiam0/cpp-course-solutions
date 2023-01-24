#include <iostream>

using namespace std;

int main() {
    int a, b, c, max = -1;

    cin >> a >> b >> c;

    if (a < 100 && a > max)
        max = a;
    if (b < 100 && b > max)
        max = b;
    if (c < 100 && c > max)
        max = c;
    
    cout << max << '\n';
    return 0;
}