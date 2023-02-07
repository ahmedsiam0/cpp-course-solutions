#include <iostream>

using namespace std;

int main() {
    int arr[1001] = {0};
    int n, x;
    int max = 0;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x;

        if (x == 0)
            arr[i] = arr[i - 1] - 1;
        else
            arr[i] = arr[i - 1] + 1;
    }

    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[i] - arr[j] == 0 && max < (i - j))
                max = i - j;
        }
    }
    cout << max << '\n';
    return 0;
}