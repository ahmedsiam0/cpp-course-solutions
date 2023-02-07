#include <iostream>

using namespace std;

int main() {
    int arr[200], sum[200] = {0};
    int k, n, imax;

    cin >> k >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < k; i++)
        sum[0] += arr[i];
    imax = 0;
    for (int i = 1; i <= (n - k); i++) {
        sum[i] = sum[i - 1] - arr[i - 1] + arr[i + k - 1];
        if (sum[i] > sum[imax]) {
            imax = i;
        }
    }

    cout << imax << ' ' << imax + k - 1 << ' ' << sum[imax];
    cout << '\n';
    return 0;
}