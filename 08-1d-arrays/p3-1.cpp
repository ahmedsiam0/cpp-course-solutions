#include <iostream>

using namespace std;

int main() {
    int reca[201] = {0};
    bool oc[1000] = {0};
    int in, temp;
    cin >> in;

    for (int i = 1; i <= in; i++) {
        temp = reca[i - 1] - (i - 1) - 1;
        if (temp > 0 && oc[temp] == 0) {
            oc[temp] = 1;
            reca[i] = temp;
        } else {
            reca[i] = reca[i - 1] + (i - 1) + 1;
            oc[reca[i]] = 1;
        }
    }

    cout << reca[in] << '\n';
    return 0;
}