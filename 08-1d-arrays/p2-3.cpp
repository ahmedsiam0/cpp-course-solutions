#include <iostream>

using namespace std;

int main() {
    int a[271] = {0}, na[501] = {0};
    int n, x;
    int freq = 0, vfreq;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x < 0) {
            na[-x]++;
            if (freq < na[-x]) {
                freq = na[-x];
                vfreq = x;
            }
        }
        else {
            a[x]++;
            if (freq < a[x]) {
                freq = a[x];
                vfreq = x;
            }
        }
    }

    cout << vfreq << '\n';
    return 0;
}