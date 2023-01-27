#include <iostream>

using namespace std;

int main() {
    int n, min;

    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < (n - 1); i++) {
        for (int j = i + 1; j < n; j++) {
            if (j == 1 || min > (a[i] + a[j] + j - i))
                min = a[i] + a[j] + j - i;
        }
    }

    cout << min << '\n';
    return 0;
}