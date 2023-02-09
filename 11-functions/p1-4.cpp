#include <iostream>

using namespace std;

bool is_palin(int a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - 1 - i])
            return false;
    }
    return true;
}

int main() {
    int a[1000];
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    if (is_palin(a, n))
        cout << "YES";
    else
        cout << "NO";
    
    cout << '\n';
    return 0;
}