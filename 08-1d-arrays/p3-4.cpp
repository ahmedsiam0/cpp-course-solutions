#include <iostream>

using namespace std;

int main() {
    bool people[200] = {0}; // 1 removed, 0 not removed
    int removed[200] = {0};
    int n, k, rest, nextr = 0, steps;

    cin >> n >> k;

    rest = n;
    n++;
    int i = 1;
    int j = 0;
    while (rest != 0) {
        for (int i = 1; i < n; i++) {

            if (people[i] == 0)
                j++;
            
            if (rest >= k)
                steps = k;
            else if ((k % rest) == 0)
                steps = rest;
            else
                steps = k % rest;
    
            if (j == steps) {
                people[i] = 1;
                j = 0;
                removed[nextr] = i;
                nextr++;
                rest--;
                if (nextr == (n - 1))
                    break;
            }
            // cout << j << ' ' << people[i] << ' ' << i << ' ' << steps << ' ' << rest << ' ' << k << ' ' << nextr << '\n';
        }
        if (nextr == (n - 1))
            break;
    }

    n--;
    for (int i = 0; i < n; i++) {
        cout << removed[i] << ' ';
    }
    cout << '\n';
    return 0;
}