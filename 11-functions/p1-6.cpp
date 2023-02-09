#include <iostream>

using namespace std;

bool is_prime(int num) {
    
    for (int i = num / 2; i > 1; i--) {
        if (num % i == 0)
            return false;
    }

    return true;
}

int nth_prime(int n) {
    int out = 1;
    for (int i = 0; i < n;) {
        out++;
        if (is_prime(out))
            i++;
    }
    return out;
}

int main() {
    int n;

    cin >> n;

    cout << nth_prime(n) << endl;
    return 0;
}