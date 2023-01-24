#include <iostream>

using namespace std;

int main() {
    int a, b, l = 0, r = 0;

    cin >> a;

    cin >> b;
    if (b <= a)
        l++;
    else
        r++;
    cin >> b;
    if (b <= a)
        l++;
    else
        r++;
    cin >> b;
    if (b <= a)
        l++;
    else
        r++;
    cin >> b;
    if (b <= a)
        l++;
    else
        r++;
    cin >> b;
    if (b <= a)
        l++;
    else
        r++;

    cout << l << ' ' << r << '\n';
    return 0;
}