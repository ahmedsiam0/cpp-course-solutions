#include <iostream>

using namespace std;

int main() {
    int n;
    bool is_prime = true;

    cin >> n;

    cout << "2"; 
    for (int i = 3; i <= n; i++) {
        for (int j = 2; j <= (i / 2); j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            cout << "," << i;
        is_prime = true;
    }
    cout << '\n';
    return 0;
}