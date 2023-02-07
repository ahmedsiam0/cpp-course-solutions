#include <iostream>

using namespace std;

int main() {
    int mtrx[100][100];
    int n, m, q, first, second;
    bool out = true;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mtrx[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cout << mtrx[i][j] << ' ';
        }
        cout << '\n';
    }
}