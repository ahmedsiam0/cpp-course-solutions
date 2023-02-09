#include <iostream>

using namespace std;

int my_pow(int value, int p = 2) {
    if (p == 0)
        return 1;
    return value * my_pow(value, p - 1);
}
int main() {
    int value, p;
    cin >> value >> p;
    cout << my_pow(value, p) << endl;
}