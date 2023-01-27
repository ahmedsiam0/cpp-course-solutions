#include <iostream>

using namespace std;

int main() {
    int min, max, n;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 1) {
            if (a[0] > a[1])
                min = a[1], max = a[0];
            else
                min = a[0], max = a[1];
        } else if (i > 1) {
            if (min > a[i])
                min = a[i];
            if (max < a[i])
                max = a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == min)
            a[i] = max;
        else if (a[i] == max)
            a[i] = min;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}