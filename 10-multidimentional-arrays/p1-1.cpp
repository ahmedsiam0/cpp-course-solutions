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

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> first >> second;
        first--;
        second--;

        for (int j = 0; j < m; j++) {
            if (mtrx[first][j] > mtrx[second][j]) {
                out = false;
                break;
            }
        }

        if (out)
            cout << "YES\n";
        else {
            cout << "NO\n";
            out = true;
        }
    }
}