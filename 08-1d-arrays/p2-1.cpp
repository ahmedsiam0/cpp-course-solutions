#include <iostream>

using namespace std;

int main() {
    int n, m1, m2, m3, a;

    cin >> n;
    cin >> m1 >> m2 >> m3;
    
    if (m1 > m2) {
        a = m1;
        m1 = m2;
        m2 = a;
    }
    if (m2 > m3) {
        a = m2;
        m2 = m3;
        m3 = a;
    }
    if (m1 > m2) {
        a = m1;
        m1 = m2;
        m2 = a;
    }

    for (int i = 3; i < n; i++) {
        cin >> a;
        if (a < m1) {
            m3 = m2;
            m2 = m1;
            m1 = a;
        } else if (a < m2) {
            m3 = m2;
            m2 = a;
        } else if (a < m3) {
            m3 = a;
        }
    }

    cout << m1 << ' '
         << m2 << ' '
         << m3 << ' '
         << '\n';
    return 0;
}