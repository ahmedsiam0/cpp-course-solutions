#include <iostream>

using namespace std;

int main() {
    int t, n, i = 0, j, min, num;

    cin >> t;

    while (i < t) {
        cin >> n;
        cin >> min;
        j = 1;
        while (j < n) {
            cin >> num;
            if (num < min)
                min = num;
            j++;
        }
        cout << min << endl;
        i++;
    }
    
    return 0;
}