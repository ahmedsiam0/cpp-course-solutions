#include <iostream>

using namespace std;

int sum(int arr[], int len) {
    if (len == 1)
        return arr[0];
    return arr[len - 1] + sum(arr, len - 1);
}

int main() {
    int n;
    int arr[100];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sm = sum(arr, n);
    cout << sm << '\n';
}