#include <iostream>

using namespace std;

int main() {
    int n;
    bool is_prime = true;

    cin >> n;

    for (int i = 2; i <= (n / 2); i++) {
        if (n % i == 0) {
            is_prime = false;
            break;
        }
    }

    if (is_prime)
        cout << "YES";
    else
        cout << "NO";
    cout << '\n';
    return 0;
}