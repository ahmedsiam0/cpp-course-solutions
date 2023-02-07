#include <iostream>

using namespace std;

int main() {
    int mtrx[100][100];
    int n;
    int out1 = 0, out2 = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mtrx[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            out1 += mtrx[i][j];
            out2 += mtrx[n - i - 1][n - j - 1];
        }
    }

    cout << out1 << ' ' << out2 << '\n';
}